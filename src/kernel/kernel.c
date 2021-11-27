#include<stdio.h>
#include "../include/print.h"

void kernel_main() {
  int number;

  printf("Provide the number of asterisks by side: \n");
  scanf("%d", &number);

  for (int i = 1; i <= number; i++) {
    for (int j = 1; j <= number; j++) {
      if (i == 1 || i == number || j == 1 || j == number){
        printf("* ");
      }else{
        printf("  ");
      }
    }

    printf("\n");
  }
  print_clear();
  print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
  print_str("Welcome to fgOS!");
}
