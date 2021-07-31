#include "include/types.h"
#include "include/gdt.h"

void printf (char* str) {
  static std::uint16_t* VideoMemory = (std::uint16_t*)0xb8000;
  for (int i = 0; str[i] != '\0'; ++i) {
    VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
  }
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
  for(constructor* i = &start_ctors; i != &end_ctors; i++)
    (*i)();
}

extern "C" void fgosMain (const void* multiboot_structure, std::uint32_t) {
  printf("Hello World");
  GlobalDescriptorTable gdt;
  while(1);
}
