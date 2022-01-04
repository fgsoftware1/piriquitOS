#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <stdint.h>
#include <stddef.h>

extern size_t terminal_row;
extern size_t terminal_column;
extern uint8_t terminal_color;
extern uint16_t* terminal_buffer;

void terminal_initialize();
void terminal_setcolor(uint8_t fg, uint8_t bg);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(char c);
void terminal_writestring(const char* data);

#endif