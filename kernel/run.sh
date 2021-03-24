#assemble boot.s file
as --32 boot.s -o boot.o

#compile kernel.c file
gcc -m32 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

#linking the kernel with kernel.o and boot.o files
ld -m elf_i386 -T linker.ld kernel.o boot.o -o fg
OS.bin -nostdlib

#check MyOS.bin file is x86 multiboot file or not
grub-file --is-x86-multiboot fgOS.bin

#building the iso file
mkdir -p isodir/boot/grub
cp fgOS.bin isodir/boot/fgOS.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o fgOS.iso isodir

#run it in qemu
qemu-system-x86_64 -cdrom fgOS.iso