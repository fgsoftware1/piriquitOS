ENTRY(loader)
OUTPUT_FORMAT(elf64)
OUTPUT_ARCH(i386:i386)

SECTIONS 
{
  . = 1M;

  .boot :
	{
		KEEP(*(.multiboot_header))
	}

  .text :
  {
    *(.multiboot_header)
    *(.text)
    *(.rodata)
  }

  .bss :
  {
    *(.bss)
  }
}
