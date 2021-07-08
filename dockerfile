FROM randomdude/gcc-cross-x86_64-elf

RUN rm /var/lib/apt/lists/*
RUN apt-get update
RUN apt-get upgrade -y --no-install-recommends
RUN apt-get install nasm -y --no-install-recommends
RUN apt-get install xorriso -y --no-install-recommends
RUN apt-get install grub-common -y --no-install-recommends
RUN apt-get install grub-pc-bin -y --no-install-recommends

VOLUME /root/env
WORKDIR /root/env
