#ifndef PIC_H
#define PIC_H

#include "../libc/include/types.h"

#define PIC1            0x20  //master PIC
#define PIC2            0xA0  //slave PIC
#define PIC1_COMMAND    PIC1
#define PIC1_DATA       (PIC1+1)    //master data
#define PIC2_COMMAND    PIC2
#define PIC2_DATA       (PIC2+1)    //slave data

#define PIC_EOI         0x20

#define ICW1            0x11    /* interrupt control command word PIC for initialization */
#define ICW4_8086       0x01    /* 8086/88 (MCS-80/85) mode */

void init_pic();

void pic_eoi(u8 irq);

#endif
