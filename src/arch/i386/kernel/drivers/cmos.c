#include "../include/drivers/cmos.h"
#include "../include/io.h"

void rtc_handler(struct registers_t *r) {
    u8 seconds = cmos_read(RTC_SECONDS);
    u8 minutes = cmos_read(RTC_MINUTES);
    u8 hours = cmos_read(RTC_HOURS);
    u8 day = cmos_read(RTC_DAY);
    u8 month = cmos_read(RTC_MONTH);
    u8 year = cmos_read(RTC_YEAR);
}

void init_cmos(){
    printf("Initializing CMOS...\n");
    isr_register_interrupt_handler(IRQ_BASE + IRQ_CMOS, rtc_handler);
    cmos_write(0x0A, cmos_read(0x0A) | 0x40);
}

u8 cmos_read(u8 reg) {
    outportb(CMOS_ADDR_REG, reg);
    return inportb(CMOS_DATA_REG);
}

void cmos_write(u8 reg, u8 val) {
    outportb(CMOS_ADDR_REG, reg);
    outportb(CMOS_DATA_REG, val);
}
