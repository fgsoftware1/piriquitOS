#include "./include/types.hpp"
#include "./gdt.hpp"
#include "./include/drivers/vga.hpp"

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for (constructor *i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}

extern "C" void kernelMain(const void *multiboot_structure, tui)
{
    GlobalDescriptorTable gdt;
    terminal_initialize();
    terminal_setcolor(COLOR_GREEN, COLOR_BLACK);
    terminal_writestring("welcome to fgOS!");
    while(1);
}
