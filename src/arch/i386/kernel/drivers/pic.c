#include "../include/libc/include/types.h"
#include "../include/io.h"
#include "../include/drivers/pic.h"

void init_pic() {
    printf("Initiating PIC...\n");
    u8 a1, a2;

    a1 = inportb(PIC_MASTER_DATA);
    a2 = inportb(PIC_SLAVE_DATA);

    outportb(PIC_MASTER_COMMAND, PIC_ICW1);
    outportb(PIC_SLAVE_COMMAND, PIC_ICW1);

    outportb(PIC_MASTER_DATA, 0x20);
    outportb(PIC_SLAVE_DATA, 0x28);

    outportb(PIC_MASTER_DATA, 4);
    outportb(PIC_SLAVE_DATA, 2);

    outportb(PIC_MASTER_DATA, PIC_ICW4_8086);
    outportb(PIC_SLAVE_DATA, PIC_ICW4_8086);

    outportb(PIC_MASTER_DATA, a1);
    outportb(PIC_SLAVE_DATA, a2);
}

void pic_eoi(u8 irq) {
    if(irq >= 0x28)
        outportb(PIC_SLAVE_COMMAND, PIC_EOI);
    outportb(PIC_MASTER_COMMAND, PIC_EOI);
}
