#include "../include/drivers/pit.h"
#include "../include/drivers/pic.h"
#include "../include/isr.h"
#include "../include/io.h"
#include "../include/console.h"

void pit_handler(struct registers_t *r){
    u8 dummy = inportb(PIT_CH0_DATA_PORT);

    pic_eoi(IRQ_BASE);
}

void init_pit(){
    printf("Initiating PIT...\n");
    isr_register_interrupt_handler(IRQ_TIMER, pit_handler);

    //setup PIT into PIC
    outportb(PIC_MASTER_COMMAND, PIC_ICW1 | PIC_ICW4_8086);
    outportb(PIC_SLAVE_COMMAND, PIC_ICW1 | PIC_ICW4_8086);
    outportb(PIC_MASTER_DATA, 1 << IRQ_TIMER);
    outportb(PIC_SLAVE_DATA, IRQ_TIMER);
    u8 current_mask = inportb(PIC_MASTER_DATA);
    current_mask &= ~(1 << IRQ_TIMER);  // Clear the bit to enable the PIT interrupt
    outportb(PIC_MASTER_DATA, current_mask);
}

void start_pit_timer(u16 frequency){
    if (frequency == 0) {
        printf("Can't divide by zero!");
        return;
    }

    u16 divisor = 1193180 / frequency; // Calculate the divisor for the desired frequency

    // Set the PIT to the desired frequency
    outportb(PIT_COMMAND_PORT, PIT_COMMAND_REGISTER);
    outportb(PIT_CH0_DATA_PORT, divisor & 0xFF); // Send the low byte
    outportb(PIT_CH0_DATA_PORT, divisor >> 8);   // Send the high byte
}

void stop_pit_timer(){
    outportb(PIT_COMMAND_PORT, 0x30);
}

void sleep(u32 milliseconds){
    u32 ticks = milliseconds * 1000 / PIT_TICKS_PER_SECOND; // Calculate the number of ticks

    // Save the current PIT counter value
    u8 initialCounter = inportb(PIT_CH0_DATA_PORT);

    // Start the PIT timer
    start_pit_timer((u16)PIT_TICKS_PER_SECOND);

    // Wait for the specified number of ticks
    while (ticks > 0) {
        // Wait for the PIT interrupt

        // Decrement the remaining ticks
        ticks--;
    }

    // Stop the PIT timer
    stop_pit_timer();

    // Restore the initial PIT counter value
    outportb(PIT_COMMAND_PORT, PIT_COMMAND_REGISTER); // Set the PIT back to the initial state
    outportb(PIT_CH0_DATA_PORT, initialCounter & 0xFF); // Restore the low byte
    outportb(PIT_CH0_DATA_PORT, initialCounter >> 8);   // Restore the high byte
}

u8 read_pit(u8 channel){
    u8 port;
    switch (channel) {
        case 0:
            port = PIT_CH0_DATA_PORT;
            break;
        case 1:
            port = PIT_CH1_DATA_PORT;
            break;
        case 2:
            port = PIT_CH2_DATA_PORT;
            break;
        default:
            // Handle invalid channel
            break;
    }

    // Read from the specified channel
    u8 value = inportb(port);
    return value;
}

void write_pit(u8 channel, u8 value){
    u8 port;
    switch (channel) {
        case 0:
            port = PIT_CH0_DATA_PORT;
            break;
        case 1:
            port = PIT_CH1_DATA_PORT;
            break;
        case 2:
            port = PIT_CH2_DATA_PORT;
            break;
        default:
            // Handle invalid channel
            break;
    }

    // Write to the specified channel
    outportb(port, value);
}
