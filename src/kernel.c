#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "include/print.h"

void fgosMain () {
  print_clear();
  print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
  print_str("Welcome to fgOS");
}
