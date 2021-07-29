.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
	.long MAGIC
	.long FLAGS
	.long CHECKSUM
	
.section .text
.extern fgosMain
.extern callConstructors
.global loader 

loader:
    mov $kernal_stack, %esp # save stack top
    call callConstructors
    push %eax 
    push %ebx
    call fgosMain
    
_stop:
    cli
    hlt
    jmp _stop

.section .bss
# 4 M stack 
.space 4*1024*1024
kernal_stack:
