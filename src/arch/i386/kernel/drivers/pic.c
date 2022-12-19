#include "../include/libc/include/types.h"
#include "../include/isr.h"
#include "../include/idt.h"
#include "../include/io.h"
#include "../include/drivers/pic.h"

void pic_init() {
    printf("initiating PIC...\n");
    u8 a1, a2;

    a1 = inportb(PIC1_DATA);
    a2 = inportb(PIC2_DATA);

    outportb(PIC1_COMMAND, ICW1);
    outportb(PIC2_COMMAND, ICW1);

    outportb(PIC1_DATA, 0x20);
    outportb(PIC2_DATA, 0x28);

    outportb(PIC1_DATA, 4);
    outportb(PIC2_DATA, 2);

    outportb(PIC1_DATA, ICW4_8086);
    outportb(PIC2_DATA, ICW4_8086);

    outportb(PIC1_DATA, a1);
    outportb(PIC2_DATA, a2);
}

void pic_eoi(u8 irq) {
    if(irq >= 0x28)
        outportb(PIC2, PIC_EOI);
    outportb(PIC1, PIC_EOI);
}
