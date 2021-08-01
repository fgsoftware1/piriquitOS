ENTRY(start)
OUTPUT_ARCH(x86_64)

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
