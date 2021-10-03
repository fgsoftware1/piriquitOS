GCCFLAGS = -c -I include/ -ffreestanding
ASFLAGS = -f elf64
objects = ../build/bin/main.o \
					../build/bin/header.o \
					../build/bin/main64.o \
					../build/bin/print.o \
					../build/bin/kernel.o

.PHONY: all
all: ../build/bin/kernel.o ../build/bin/main.o ../build/bin/main64.o ../build/bin/header.o ../isodir/boot/kernel.bin ../build/fgOS.iso

../build/bin/kernel.o: ./kernel/kernel.c ./include/print.h
	gcc $(GCCFLAGS) -o $@ $<

../build/bin/print.o: ./include/print.h
	gcc $(GCCFLAGS) -o $@ $<

../build/bin/main.o: kernel/main.asm
	nasm $(ASFLAGS) -o $@ $<

../build/bin/main64.o: kernel/main64.asm
	nasm $(ASFLAGS) -o $@ $<

../build/bin/header.o: kernel/header.asm
	nasm $(ASFLAGS) -o $@ $<

../isodir/boot/kernel.bin: linker.ld $(objects)
	ld -T $< -o $@ $(objects)

../build/fgOS.iso: ../isodir/
	grub-mkrescue /usr/lib/grub/i386-pc -o $@ $<
