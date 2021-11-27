#include "../include/print.h"

void kernel_main() {
  int number;

  for (int i = 1; i <= number; i++) {
    for (int j = 1; j <= number; j++) {
      if (i == 1 || i == number || j == 1 || j == number){
        print_char("* ");
      }else{
        print_char("  ");
      }
    }

    print_char("\n");
  }
  print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
  print_str("Welcome to fgOS!");
}
