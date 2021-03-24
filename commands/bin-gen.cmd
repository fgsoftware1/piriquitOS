cd C:\Users\gabri\Desktop\projects\fgOS\tools\NASM
nasm -f bin C:\Users\gabri\Desktop\projects\fgOS\bootloader\src\graphical.asm -o C:\Users\gabri\Desktop\projects\fgOS\bootloader\bin\graphical.bin
nasm -f bin C:\Users\gabri\Desktop\projects\fgOS\bootloader\src\main.asm -o C:\Users\gabri\Desktop\projects\fgOS\bootloader\bin\main.bin

nasm -f elf C:\Users\gabri\Desktop\projects\fgOS\bootloader\src\graphical.asm -o C:\Users\gabri\Desktop\projects\fgOS\bootloader\build\graphical.o
nasm -f win32 C:\Users\gabri\Desktop\projects\fgOS\bootloader\src\main.asm -o C:\Users\gabri\Desktop\projects\fgOS\bootloader\build\main.o