ENTRY(start)
OUTPUT_ARCH(i386:i386)

SECTIONS 
{
  . = 1M;

  .text : ALIGN(0x1000)
  {
    *(.text)
  }

  .rodata : ALIGN(0x1000)
  {
    *(.rodata)
  }

  .bss : ALIGN(0x1000)
  {
    *(.bss)
  }
}
