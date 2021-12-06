include Makefile.inc

KERNELOBJ = $(BINDIR)/main.o \
					$(BINDIR)/header.o \
					$(BINDIR)/main64.o \
					$(BINDIR)/string.o \
					$(BINDIR)/vga.o \
					$(BINDIR)/terminal.o \
					$(BINDIR)/kernel.o

BOOTLOADEROBJ = $(BINDIR)/bootloader.o

.PHONY: all clean kernel bootloader

all: bootloader kernel iso flp

clean:
	@$(ECHO) cleaning up
	@$(RM) build/bin/*.o \
				build/fgOS.iso \
				build/fgOS.flp \
				isodir/boot/kernel.bin

bootloader: $(BOOTLOADERDIR)
	cd $(BOOTLOADERDIR) && $(MAKE)

kernel: $(KERNELDIR)
	cd $(KERNELDIR) && $(MAKE)

./isodir/boot/kernel.bin: ./src/linker.ld $(KERNELOBJ) $(BOOTLOADEROBJ)
	@$(ECHO) --LD linking $<
	@$(LD) -T $< -o $@ $(KERNELOBJ) $(BOOTLOADEROBJ)

./build/fgOS.iso: ../../isodir/
	@$(ECHO) --GRUB-MKRESCUE making iso $<
	@grub-mkrescue /usr/lib/grub/i386-pc -o $@ $<

./build/fgOS.flp: ../../isodir/
	@$(ECHO) --GRUB-MKRESCUE making floppy $<
	@grub-mkrescue /usr/lib/grub/i386-pc -o $@ $<
