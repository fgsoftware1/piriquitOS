#include "../include/drivers/pit.h"
#include "../include/console.h"
#include "../include/io.h"
#include "../include/isr.h"

u64 ticks;
const u32 freq = 100;

void pit_handler(struct registers_t *r) { ticks += 1; }

void init_pit() {
  printf("Initiating PIT...\n");
  isr_register_interrupt_handler(IRQ_BASE + IRQ_TIMER, pit_handler);
  start_pit_timer();
}

void start_pit_timer() {
  if (freq == 0) {
    printf("Can't divide by zero!");
    return;
  }

  u16 divisor = 1193180 / freq;

  outportb(PIT_COMMAND_PORT, PIT_COMMAND_REGISTER);
  outportb(PIT_CH0_DATA_PORT, (u8)(divisor & 0xFF)); // Send the low byte
  outportb(PIT_CH0_DATA_PORT, (u8)((divisor >> 8) & 0xFF)); // Send the high byte
}

void stop_pit_timer() { outportb(PIT_COMMAND_PORT, 0x30); }

u8 read_pit(u8 channel) {
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

void write_pit(u8 channel, u8 value) {
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

void sleep(u32 milliseconds) {
    // Calculate the number of PIT ticks needed for the delay
    u32 ticks = milliseconds * 1000 / ticks;

    // Save the current PIT channel 0 count
    u8 initialCounter = inportb(PIT_CH0_DATA_PORT);

    start_pit_timer();

    while (ticks > 0) {
        // Wait for PIT interrupt
        ticks--;
    }

    // Restore the initial PIT channel 0 count
    outportb(PIT_COMMAND_REGISTER, 0x36); // Set the operating mode to square wave generator
    outportb(PIT_CH0_DATA_PORT, initialCounter); // Set the initial counter value
}
