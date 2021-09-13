.set FLAGS,    ALIGN | MEMINFO  
.set MAGIC,    0x1BADB002       /* magic number */
.set CHECKSUM, -(MAGIC + FLAGS) /* multiboot checksum */

.section .multiboot

.long MAGIC
.long FLAGS
.long CHECKSUM

stack_bottom:
.skip 16384 # 16 KiB

stack_top:
.section .text
.global _start
.type _start, @function

_start:
mov $stackTop, %esp
call kernel_main
cli

hltLoop:
hlt
jmp hltLoop

.size _start, . - _start
