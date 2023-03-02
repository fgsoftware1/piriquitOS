#include "../include/drivers/keyboard.h"
#include "../include/console.h"
#include "../include/idt.h"
#include "../include/io.h"
#include "../include/isr.h"
#include "../include/libc/include/types.h"
#include "../include/libc/include/string.h"

static BOOL g_caps_lock = FALSE;
static BOOL g_shift_pressed = FALSE;
char g_ch = 0, g_scan_code = 0;

char g_scan_code_chars[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' ',
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '-', 0, 0, 0, '+', 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0
};

static int get_scancode()
{
    int i, scancode = 0;

    for (i = 1000; i > 0; i++)
    {

        if ((inportb(KEYBOARD_STATUS_PORT) & 1) == 0)
            continue;

        scancode = inportb(KEYBOARD_DATA_PORT);
        break;
    }
    if (i > 0)
        return scancode;
    return 0;
}

char alternate_chars(char ch)
{
    switch (ch)
    {
    case '`':
        return '~';
    case '1':
        return '!';
    case '2':
        return '@';
    case '3':
        return '#';
    case '4':
        return '$';
    case '5':
        return '%';
    case '6':
        return '^';
    case '7':
        return '&';
    case '8':
        return '*';
    case '9':
        return '(';
    case '0':
        return ')';
    case '-':
        return '_';
    case '=':
        return '+';
    case '[':
        return '{';
    case ']':
        return '}';
    case '\\':
        return '|';
    case ';':
        return ':';
    case '\'':
        return '\"';
    case ',':
        return '<';
    case '.':
        return '>';
    case '/':
        return '?';
    default:
        return ch;
    }
}

void keyboard_handler(registers_t *r)
{
    int scancode;

    g_ch = 0;
    scancode = get_scancode();
    g_scan_code = scancode;
    if (scancode & 0x80)
    {
    }
    else
    {

        switch (scancode)
        {
        case SCAN_CODE_KEY_CAPS_LOCK:
            if (g_caps_lock == FALSE)
                g_caps_lock = TRUE;
            else
                g_caps_lock = FALSE;
            break;

        case SCAN_CODE_KEY_ENTER:
            g_ch = '\n';
            break;

        case SCAN_CODE_KEY_TAB:
            g_ch = '\t';
            break;

        case SCAN_CODE_KEY_LEFT_SHIFT:
            g_shift_pressed = TRUE;
            break;

        default:
            g_ch = g_scan_code_chars[scancode];

            if (g_caps_lock)
            {

                if (g_shift_pressed)
                {

                    g_ch = alternate_chars(g_ch);
                }
                else
                    g_ch = upper(g_ch);
            }
            else
            {
                if (g_shift_pressed)
                {
                    if (isalpha(g_ch))
                        g_ch = upper(g_ch);
                    else

                        g_ch = alternate_chars(g_ch);
                }
                else
                    g_ch = g_scan_code_chars[scancode];
                g_shift_pressed = FALSE;
            }
            break;
        }
    }
}

void init_keyboard()
{
    printf("Initiating keyboard...\n");
    isr_register_interrupt_handler(IRQ_BASE + IRQ_KEYBOARD, keyboard_handler);
}

char kb_getchar()
{
    char c;

    while (g_ch <= 0)
        ;
    c = g_ch;
    g_ch = 0;
    g_scan_code = 0;
    return c;
}

char kb_get_scancode()
{
    char code;

    while (g_scan_code <= 0)
        ;
    code = g_scan_code;
    g_ch = 0;
    g_scan_code = 0;
    return code;
}
