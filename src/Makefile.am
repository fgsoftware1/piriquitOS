GCCFLAGS = -c -I include/ -ffreestanding
LDFLAGS = -n -o -T linker.ld
ASFLAGS = -f elf64

../build/bin/kernel.o: ./kernel/kernel.c ./include/print.h
	gcc $(GCCFLAGS) -o $@ $<

../build/bin/print.o: ./include/print.h
	gcc $(GCCFLAGS) -o $@ $<

../build/bin/main.o: kernel/main.asm
	nasm $(ASFLAGS) -o $@ $<

../build/bin/main.o: kernel/main64.asm
	nasm $(ASFLAGS) -o $@ $<

../build/bin/main.o: kernel/header.asm
	nasm $(ASFLAGS) -o $@ $<

../isodir/boot/kernel.bin: linker.ld ../build/bin/main.o ../build/bin/header.o ../build/bin/main64.o ../build/bin/kernel.o ../build/bin/print.o
	ld $(LDFLAGS) -o $@ $<

../build/fgOS.iso: ../isodir/
	grub-mkrescue /usr/lib/grub/i386-pc -o $@ $<
