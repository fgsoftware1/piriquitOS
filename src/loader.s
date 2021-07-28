.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1 <<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
	.long MAGIC
	.long FLAGS
	.long CHECKSUM
	
.section .text
.extern fgosmain
.extern callContructors
.global loader 

loader:
    mov $kernal_stack, %esp # save stack top
    call callContructors #init each constructure
    push %eax 
    push %ebx
    call fgosmain
    
_stop:
    cli
    hlt
    jmp _stop

.section .bss
# 4 M stack 
.space 4*1024*1024
kernal_stack:
