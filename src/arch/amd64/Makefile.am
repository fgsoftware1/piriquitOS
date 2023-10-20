CFLAGS = -I include/ -Wall -Wextra -ffreestanding -nostdlib -nodefaultlibs
ASFLAGS = -f elf64
objects = ../build/bin/boot.o \
					../build/bin/print.o \
					../build/bin/kernel.o

.PHONY: all
all: ../../../build/bin/boot.o	../../../build/bin/kernel.o

../../../build/bin/boot.o: ./boot.asm
	nasm $(ASFLAGS) -o $@ $<

../../../build/bin/kernel.o: ./kernel/kernel.cpp
	g++ $(CFLAGS) -c -o $@ $<
