ENTRY(start)

sections
{
    . = 1M;

    .boot:
    {
        KEEP(*(.multiboot_header))
    }

    .text:
    {
        *(.text)
    }
}