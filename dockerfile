FROM randomdude/gcc-cross-x86_64-elf

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install nasm -Y
RUN xorriso -y
RUN grub-commom  -y
RUN grub-pc-bin -y

VOLUME /root/env
WORKDIR /root/env
