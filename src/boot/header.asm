section .multiboot_header
header_start:
    ;magic number
    dd 0xe85250d6
    ;protected mode
    dd 0
    ;header lenght
    dd header_end - header_start
    ;checksum
    dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))
    ;end tag
    dw 0
    dw 0
    dw 8
header_end: