#include "./include/driver/vga.hpp"

extern "C" void kernel_main() {
  terminal_initialize();
  terminal_setcolor(COLOR_GREEN, COLOR_BLACK);
  terminal_writestring("welcome to fgOS!");
  for(;;);
}
