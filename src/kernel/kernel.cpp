#include "../include/terminal.hpp"
#include "../include/vga.hpp"

void kernel_main() {
  terminal_initialize();
  terminal_setcolor(COLOR_GREEN, COLOR_BLACK);
  terminal_writestring("wellcome to fgOS!");
  for(;;);
}
