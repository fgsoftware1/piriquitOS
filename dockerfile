FROM randomdude/gcc-cross-x86_64-elf

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install nasm -y
RUN apt-get install xorriso -y
RUN apt-get install grub-commom 
RUN apt-get install grub-pc-bin -y

VOLUME /root/env
WORKDIR /root/env
