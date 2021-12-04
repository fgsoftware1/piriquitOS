include ../../Makefile.inc

BINDIR = ../../build
objects = $(BINDIR)/main.o \
					$(BINDIR)/header.o \
					$(BINDIR)/main64.o \
					$(BINDIR)/string.o \
					$(BINDIR)/vga.o \
					$(BINDIR)/terminal.o \
					$(BINDIR)/kernel.o

.PHONY: all
all:	$(BINDIR)/kernel.o \
			$(BINDIR)/string.o \
			$(BINDIR)/vga.o \
			$(BINDIR)/terminal.o \
			$(BINDIR)/main.o \
			$(BINDIR)/main64.o \
			$(BINDIR)/header.o \
			../../isodir/boot/kernel.bin \
			../../build/fgOS.iso \
			../../build/fgOS.flp

$(BINDIR)/kernel.o: ./kernel.cpp ../include/terminal.hpp ../include/vga.hpp
	@$(ECHO) --CXX compiling $<
	@$(CXX) $(CXXFLAGS) -o $@ $<

$(BINDIR)/string.o: ./string.cpp ../include/string.hpp
	@$(ECHO) --CXX compiling $<
	@$(CXX) $(CXXFLAGS) -o $@ $<

$(BINDIR)/vga.o: ./vga.cpp ../include/vga.hpp
	@$(ECHO) --CXX compiling $<
	@$(CXX) $(CXXFLAGS) -o $@ $<

$(BINDIR)/terminal.o: ./terminal.cpp ../include/terminal.hpp ../include/string.hpp ../include/vga.hpp
	@$(ECHO) --CXX compiling $<
	@$(CXX) $(CXXFLAGS) -o $@ $<

$(BINDIR)/main.o: ./main.asm
	@$(ECHO) --NASM compiling $<
	@nasm $(ASFLAGS) -o $@ $<

$(BINDIR)/main64.o: ./main64.asm
	@$(ECHO) --NASM compiling $<
	@nasm $(ASFLAGS) -o $@ $<

$(BINDIR)/header.o: ./header.asm
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
