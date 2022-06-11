#include "include/kernel.hpp"
#include "include/memory.hpp"
#include "include/timer.hpp"
#include "include/shell.hpp"
#include "include/disks.hpp"
#include "include/drivers/acpi.hpp"
#include "include/interrupts.hpp"
#include "include/arch.hpp"
#include "include/e820.hpp"

extern "C" void kernel_main() {
  terminal_initialize();
  terminal_setcolor(COLOR_GREEN, COLOR_BLACK);
  terminal_writestring("welcome to fgOS!");
  for(;;);
}
