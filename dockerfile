FROM randomdude/gcc-cross-x86_64-elf

RUN apt-get update && apt-get upgrade -y && apt-get install -y nasm xorriso grub-commom grub-pc-bin

VOLUME /root/env
WORKDIR /root/env
