#include "include/console.h"
#include "include/libc/include/types.h"
#include "include/libc/include/string.h"
#include "include/drivers/keyboard.h"
#include "include/drivers/vga.h"

static u16 *g_vga_buffer;
static u32 g_vga_index;
static u8 cursor_pos_x = 0, cursor_pos_y = 0;
static u16 g_temp_pages[MAXIMUM_PAGES][VGA_TOTAL_ITEMS];

u8 g_fore_color = COLOR_WHITE, g_back_color = COLOR_BLACK;
u32 g_current_temp_page = 0;

void console_clear(VGA_COLOR_TYPE fore_color, VGA_COLOR_TYPE back_color)
{
    u32 i;

    for (i = 0; i < VGA_TOTAL_ITEMS; i++)
    {
        g_vga_buffer[i] = vga_item_entry(NULL, fore_color, back_color);
    }
    g_vga_index = 0;
    cursor_pos_x = 0;
    cursor_pos_y = 0;
    vga_set_cursor_pos(cursor_pos_x, cursor_pos_y);
}

void console_init(VGA_COLOR_TYPE fore_color, VGA_COLOR_TYPE back_color)
{
    g_vga_buffer = (u16 *)VGA_ADDRESS;
    g_fore_color = fore_color;
    g_back_color = back_color;
    cursor_pos_x = 0;
    cursor_pos_y = 0;
    console_clear(fore_color, back_color);
}

void console_scroll(int type)
{
    u32 i;
    if (type == SCROLL_UP)
    {

        if (g_current_temp_page > 0)
            g_current_temp_page--;
        g_current_temp_page %= MAXIMUM_PAGES;
        for (i = 0; i < VGA_TOTAL_ITEMS; i++)
        {
            g_vga_buffer[i] = g_temp_pages[g_current_temp_page][i];
        }
    }
    else
    {

        g_current_temp_page++;
        g_current_temp_page %= MAXIMUM_PAGES;
        for (i = 0; i < VGA_TOTAL_ITEMS; i++)
        {
            g_vga_buffer[i] = g_temp_pages[g_current_temp_page][i];
        }
    }
}

static void console_newline()
{
    u32 i;

    if (cursor_pos_y >= VGA_HEIGHT)
    {
        for (i = 0; i < VGA_TOTAL_ITEMS; i++)
            g_temp_pages[g_current_temp_page][i] = g_vga_buffer[i];
        g_current_temp_page++;
        cursor_pos_x = 0;
        cursor_pos_y = 0;
        console_clear(g_fore_color, g_back_color);
    }
    else
    {
        for (i = 0; i < VGA_TOTAL_ITEMS; i++)
            g_temp_pages[g_current_temp_page][i] = g_vga_buffer[i];

        g_vga_index += VGA_WIDTH - (g_vga_index % VGA_WIDTH);
        cursor_pos_x = 0;
        ++cursor_pos_y;
        vga_set_cursor_pos(cursor_pos_x, cursor_pos_y);
    }
}

void console_putchar(char ch)
{
    if (ch == ' ')
    {
        g_vga_buffer[g_vga_index++] = vga_item_entry(' ', g_fore_color, g_back_color);
        vga_set_cursor_pos(cursor_pos_x++, cursor_pos_y);
    }
    if (ch == '\t')
    {
        for (int i = 0; i < 4; i++)
        {
            g_vga_buffer[g_vga_index++] = vga_item_entry(' ', g_fore_color, g_back_color);
            vga_set_cursor_pos(cursor_pos_x++, cursor_pos_y);
        }
    }
    else if (ch == '\n')
    {
        console_newline();
    }
    else
    {
        if (ch > 0)
        {
            g_vga_buffer[g_vga_index++] = vga_item_entry(ch, g_fore_color, g_back_color);
            vga_set_cursor_pos(++cursor_pos_x, cursor_pos_y);
        }
    }
}

void console_ungetchar()
{
    if (g_vga_index > 0)
    {
        g_vga_buffer[g_vga_index--] = vga_item_entry(0, g_fore_color, g_back_color);
        if (cursor_pos_x > 0)
        {
            vga_set_cursor_pos(cursor_pos_x--, cursor_pos_y);
        }
        else
        {
            cursor_pos_x = VGA_WIDTH;
            if (cursor_pos_y > 0)
                vga_set_cursor_pos(cursor_pos_x--, --cursor_pos_y);
            else
                cursor_pos_y = 0;
        }
    }

    g_vga_buffer[g_vga_index] = vga_item_entry(0, g_fore_color, g_back_color);
}

void console_ungetchar_bound(u8 n)
{
    if (((g_vga_index % VGA_WIDTH) > n) && (n > 0))
    {
        g_vga_buffer[g_vga_index--] = vga_item_entry(0, g_fore_color, g_back_color);
        if (cursor_pos_x >= n)
        {
            vga_set_cursor_pos(cursor_pos_x--, cursor_pos_y);
        }
        else
        {
            cursor_pos_x = VGA_WIDTH;
            if (cursor_pos_y > 0)
                vga_set_cursor_pos(cursor_pos_x--, --cursor_pos_y);
            else
                cursor_pos_y = 0;
        }
    }

    g_vga_buffer[g_vga_index] = vga_item_entry(0, g_fore_color, g_back_color);
}

void console_gotoxy(u16 x, u16 y)
{
    g_vga_index = (80 * y) + x;
    cursor_pos_x = x;
    cursor_pos_y = y;
    vga_set_cursor_pos(cursor_pos_x, cursor_pos_y);
}

void console_putstr(const char *str)
{
    u32 index = 0;
    while (str[index])
    {
        if (str[index] == '\n')
            console_newline();
        else
            console_putchar(str[index]);
        index++;
    }
}

void printf(const char *format, ...)
{
    char **arg = (char **)&format;
    int c;
    char buf[32];

    arg++;

    memset(buf, 0, sizeof(buf));
    while ((c = *format++) != 0)
    {
        if (c != '%')
            console_putchar(c);
        else
        {
            char *p, *p2;
            int pad0 = 0, pad = 0;

            c = *format++;
            if (c == '0')
            {
                pad0 = 1;
                c = *format++;
            }

            if (c >= '0' && c <= '9')
            {
                pad = c - '0';
                c = *format++;
            }

            switch (c)
            {
            case 'd':
            case 'u':
            case 'x':
                itoa(buf, c, *((int *)arg++));
                p = buf;
                goto string;
                break;

            case 's':
                p = *arg++;
                if (!p)
                    p = "(null)";

            string:
                for (p2 = p; *p2; p2++)
                    ;
                for (; p2 < p + pad; p2++)
                    console_putchar(pad0 ? '0' : ' ');
                while (*p)
                    console_putchar(*p++);
                break;

            default:
                console_putchar(*((int *)arg++));
                break;
            }
        }
    }
}

void getstr(char *buffer)
{
    if (!buffer)
        return;
    while (1)
    {
        char ch = kb_getchar();
        if (ch == '\n')
        {
            printf("\n");
            return;
        }
        else
        {
            *buffer++ = ch;
            printf("%c", ch);
        }
    }
}

void getstr_bound(char *buffer, u8 bound)
{
    if (!buffer)
        return;
    while (1)
    {
        char ch = kb_getchar();
        if (ch == '\n')
        {
            printf("\n");
            return;
        }
        else if (ch == '\b')
        {
            console_ungetchar_bound(bound);
            buffer--;
            *buffer = '\0';
        }
        else
        {
            *buffer++ = ch;
            printf("%c", ch);
        }
    }
}
