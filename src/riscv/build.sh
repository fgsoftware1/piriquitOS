#!/bin/sh
riscv64-linux-gnu-gcc -Wall -Wextra -c -mcmodel=medany kernel.c -o kernel.o -ffreestanding
riscv64-linux-gnu-as -c main.S -o main.o
riscv64-linux-gnu-ld -T linker.ld -nostdlib kernel.o main.o -o fgOS-riscv.bin
