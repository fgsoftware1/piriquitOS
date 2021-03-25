nasm -f bin bootloader/src/graphical.asm -o bootloader/bin/graphical.bin
nasm -f bin bootloader/src/main.asm -o bootloader/bin/main.bin
nasm -f bin kernel/boot.s -o kernel/bin/boot.bin

nasm -f bin bootloader/src/graphical.asm -o bootloader/bin/graphical.o
nasm -f bin bootloader/src/main.asm -o bootloader/bin/main.o
nasm -f bin kernel/boot.s -o kernel/bin/boot.o