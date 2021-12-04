include ../../Makefile.inc

objects = ../../build/bin/main.o \
					../../build/bin/header.o \
					../../build/bin/main64.o \
					../../build/bin/string.o \
					../../build/bin/vga.o \
					../../build/bin/terminal.o \
					../../build/bin/kernel.o

.PHONY: all
all:	../../build/bin/kernel.o \
			../../build/bin/string.o \
			../../build/bin/vga.o \
			../../build/bin/terminal.o \
			../../build/bin/main.o \
			../../build/bin/main64.o \
			../../build/bin/header.o \
			../../isodir/boot/kernel.bin \
			../../build/fgOS.iso \
			../../build/fgOS.flp

../../build/bin/kernel.o: ./kernel.cpp ../include/terminal.hpp ../include/vga.hpp
	@$(ECHO) --CXX compiling $<
	@$(CXX) $(CXXFLAGS) -o $@ $<

../../build/bin/string.o: ./string.cpp ../include/string.hpp
	@$(ECHO) --CXX compiling $<
	@$(CXX) $(CXXFLAGS) -o $@ $<

../../build/bin/vga.o: ./vga.cpp ../include/vga.hpp
	@$(ECHO) --CXX compiling $<
	@$(CXX) $(CXXFLAGS) -o $@ $<

../../build/bin/terminal.o: ./terminal.cpp ../include/terminal.hpp ../include/string.hpp ../include/vga.hpp
	@$(ECHO) --CXX compiling $<
	@$(CXX) $(CXXFLAGS) -o $@ $<

../../build/bin/main.o: ./main.asm
	@$(ECHO) --NASM compiling $<
	@nasm $(ASFLAGS) -o $@ $<

../../build/bin/main64.o: ./main64.asm
	@$(ECHO) --NASM compiling $<
	@nasm $(ASFLAGS) -o $@ $<

../../build/bin/header.o: ./header.asm
	@$(ECHO) --NASM compiling $<
	@nasm $(ASFLAGS) -o $@ $<

../../isodir/boot/kernel.bin: ../linker.ld $(objects)
	@$(ECHO) --LD linking $<
	@$(LD) -T $< -o $@ $(objects)

../../build/fgOS.iso: ../../isodir/
	@$(ECHO) --GRUB-MKRESCUE making iso $<
	@grub-mkrescue /usr/lib/grub/i386-pc -o $@ $<

../../build/fgOS.flp: ../../isodir/
	@$(ECHO) --GRUB-MKRESCUE making floppy $<
	@grub-mkrescue /usr/lib/grub/i386-pc -o $@ $<
