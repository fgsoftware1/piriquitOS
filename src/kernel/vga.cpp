#include "./include/drivers/vga.hpp"
#include "./include/types.hpp"
#include "./include/string.hpp"

size_t terminal_row;
size_t terminal_column;
tuc terminal_color;
tus* terminal_buffer;

/*#######################################
###################VGA###################
#######################################*/
tuc vga_entry_color(enum vga_color fg, enum vga_color bg)
{
  return fg | bg << 4;
}

tus vga_entry(c c, tuc color)
{
  return (tus)c | (tus)color << 8;
}


/*##########################################
#################TERMINAL###################
##########################################*/
void terminal_initialize()
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = (tus*) 0xB8000;
	for ( size_t y = 0; y < VGA_HEIGHT; y++ )
	{
		for ( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(tuc fg, tuc bg)
{
	terminal_color = fg, bg;
}

void terminal_putentry(char c, tuc color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c)
{
	terminal_putentry(c, terminal_color, terminal_column, terminal_row);
	if ( ++terminal_column == VGA_WIDTH )
	{
		terminal_column = 0;
		if ( ++terminal_row == VGA_HEIGHT )
		{
			terminal_row = 0;
		}
	}
}

void terminal_writestring(const char* data)
{
	size_t datalen = strlen(data);
	for ( size_t i = 0; i < datalen; i++ )
		terminal_putchar(data[i]);
}
