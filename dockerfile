FROM randomdude/gcc-cross-x86_64-elf

RUN apt-get update -y
RUN apt-get upgrade -y --no-install-recommends
RUN apt-get install apt-utils -y --no-install-recommends
RUN apt-get install nasm -y --no-install-recommends
RUN apt-get install xorriso -y --no-install-recommends
RUN apt-get install grub-common -y --no-install-recommends
RUN apt-get install grub-pc-bin -y --no-install-recommends
RUN apt-get install ninja-build -y --no-install-recommends
RUN apt-get install cmake -y --no-install-recommends
RUN apt-get install make -y --no-install-recommends

VOLUME /root/env
WORKDIR /root/env