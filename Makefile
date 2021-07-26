GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386
objects = ./src/loader.o ./src/kernel.o

%.o: %.cpp g++ $(GPPPARAMS) -o $@ -c $<
%.o: %.s as $(ASPARAMS) -o $@ $<

kernel.bin: ./src/linker.ld ld -T $< -o $@ $(objects)

install: ./src/kernel.bin sudo cp $< ./src/boot/kernel.bin
