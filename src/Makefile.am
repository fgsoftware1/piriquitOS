GCCFLAGS = -c -I include/ -ffreestandinng -fno-exceptions -fno-rtti -fpermissive
ASFLAGS = -f elf64
LDFLAGS = -nostdlib -nodefaultlibs
objects = ../build/bin/main.o \
					../build/bin/header.o \
					../build/bin/main64.o \
					../build/bin/string.o \
          ../build/bin/vga.o \
          ../build/bin/terminal.o \
					../build/bin/kernel.o

.PHONY: all
all:  ../build/bin/kernel.o \
      ../build/bin/string.o \
      ../build/bin/vga.o \
      ../build/bin/terminal.o \
      ../build/bin/main.o \
      ../build/bin/main64.o \
      ../build/bin/header.o \
      ../isodir/boot/kernel.bin \
      ../build/fgOS.iso

../build/bin/kernel.o: ./kernel/kernel.cpp ./include/terminal.hpp ./include/vga.hpp
	g++ $(GCCFLAGS) -o $@ $<

../build/bin/string.o: ./kernel/string.cpp ./include/string.hpp
	g++ $(GCCFLAGS) -o $@ $<

../build/bin/vga.o: ./kernel/vga.cpp ./include/vga.hpp
	g++ $(GCCFLAGS) -o $@ $<

../build/bin/terminal.o: ./kernel/terminal.cpp ./include/terminal.hpp ./include/string.hpp ./include/vga.hpp
	g++ $(GCCFLAGS) -o $@ $<

../build/bin/main.o: kernel/main.asm
	nasm $(ASFLAGS) -o $@ $<

../build/bin/main64.o: kernel/main64.asm
	nasm $(ASFLAGS) -o $@ $<

../build/bin/header.o: kernel/header.asm
	nasm $(ASFLAGS) -o $@ $<

../isodir/boot/kernel.bin: linker.ld $(objects)
	ld -T $< -o $@ $(objects) $(LDFLAGS)

../build/fgOS.iso: ../isodir/
	grub-mkrescue /usr/lib/grub/i386-pc -o $@ $<
