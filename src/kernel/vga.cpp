#include "./include/vga.hpp"

uint8_t vga_entry_color(uint8_t fg, uint8_t bg)
{
  return fg | bg << 4;
}

uint16_t vga_entry(unsigned char uc, uint8_t color)
{
  return (uint16_t)uc | (uint16_t)color << 8;
}
