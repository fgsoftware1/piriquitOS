#!/bin/sh
aarch64-linux-gnu-gcc -c kernel.c -o kernel.o -ffreestanding
aarch64-linux-gnu-as -c boot.S -o boot.o
aarch64-linux-gnu-ld -T linker.ld kernel.o boot.o -o fgOS-aarch64.bin -nostdlib
