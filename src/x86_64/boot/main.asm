global start

section .text
bits32
start:
    mov dword [0xb8000], 0x2f4b2f4f
    hlt