[bits 16]
section .multiboot_header
header_start:
    ; magic number(multiboot 2)
    dd 0xe85250d6
    ; protected mode
    dd 0
	dd header_end - header_start
	; checksum
	dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))
	dw 0
	dw 0
	dd 8
header_end:

[bits 32]
global loader
extern callConstructors
extern kernelMain

.section .text
start:
	mov esp, stack_top
    call callConstructors
	call check_multiboot
	call check_cpuid
	call check_long_mode
	call setup_page_tables
	call enable_paging

	lgdt [gdt64.pointer]
	jmp gdt64.code_segment:long_mode_start

	hlt

check_multiboot:
	cmp eax, 0x36d76289
	jne .no_multiboot
	ret
.no_multiboot:
	mov al, "M"
	jmp error
    
loader:
    mov $kernel_stack, %esp

    push %eax
    push %ebx
    call kernelMain

_stop:
    cli
    hlt
    jmp _stop

.section .bss
align 4096
page_table_l4:
	resb 4096
page_table_l3:
	resb 4096
page_table_l2:
	resb 4096
stack_bottom:
	resb 4096 * 4
stack_top:
.space 2*1024*1024;
kernel_stack:
