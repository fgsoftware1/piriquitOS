GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386
objects = ./src/loader.o ./src/kernel.o

all: main

main: ./src/kernel.o ./src/loader.o ./src/

kernel.o: ./src/kernel.cpp gcc $(GPPPARAMS) -c ./src/kernel.cpp
loader.o: ./src/loader.s as $(ASPARAMS) -o $@ $<

kernel.bin: ./src/linker.ld ld $(LDPARAMS) -T $< -o $@ $(objects)

install: ./src/kernel.bin sudo cp $< ./src/boot/kernel.bin
