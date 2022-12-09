#ifndef KERNEL_H
#define KERNEL_H

#include "libc/include/types.h"

extern u8 __kernel_section_start;
extern u8 __kernel_section_end;
extern u8 __kernel_text_section_start;
extern u8 __kernel_text_section_end;
extern u8 __kernel_data_section_start;
extern u8 __kernel_data_section_end;
extern u8 __kernel_rodata_section_start;
extern u8 __kernel_rodata_section_end;
extern u8 __kernel_bss_section_start;
extern u8 __kernel_bss_section_end;

#endif

