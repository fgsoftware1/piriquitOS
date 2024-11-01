#include "multiboot.h"

__attribute__((section(".multiboot"), aligned(4), used))
static const struct MultibootHeader header = {
	.magic = MULTIBOOT_HEADER_MAGIC,
	.flags = MULTIBOOT_HEADER_FLAGS,
	.checksum = -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS),
    .padding = 0,
};

__attribute__((section(".bss"), aligned(16)))
static u8 stack_bytes[16 * 1024];

extern void kmain(void);

__attribute__((naked))
void _start(void) {
    __asm__ volatile (
        "movl $stack_bytes + %c0, %%esp\n"
        "movl %%esp, %%ebp\n"
        "call kmain\n"
        :
        : "i" (sizeof(stack_bytes))
    );
    while(1);
}
