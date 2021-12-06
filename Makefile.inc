# programs
CXX	= g++
ASM = nasm
LD = ld
RM = rm -rf
ECHO = echo
# flags
CXXFLAGS = -c -I ../include/ -ffreestanding -fno-exceptions -fno-rtti -fpermissive
# directories
BINDIR = ./build/bin
KERNELDIR = ./src/kernel
BOOTLOADER = ./src/bootloader