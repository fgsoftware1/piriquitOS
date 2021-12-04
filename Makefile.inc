# programs
CXX	= g++
ASM = nasm
LD = ld
RM = rm -rf
ECHO = echo
# flags
CXXFLAGS = -c -I ../include/ -ffreestanding -fno-exceptions -fno-rtti -fpermissive
ASFLAGS	= -f elf64
# directories
KERNELDIR = ./src/kernel
SUBDIRS = ./src/kernel
