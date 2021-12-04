#include "../include/terminal.hpp"
#include "../include/vga.hpp"

extern "C" void kernel_main() {
  terminal_initialize();
  terminal_setcolor(COLOR_GREEN, COLOR_BLACK);
  terminal_writestring("wellcome to fgOS!");
  for(;;);
}
