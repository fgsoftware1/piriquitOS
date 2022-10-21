[bits 64]
global long_mode_start
extern kernelMain

section .text

long_mode_start:
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

	call kernelMain
    hlt
