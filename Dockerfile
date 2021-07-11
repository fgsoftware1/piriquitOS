FROM randomdude/gcc-cross-x86_64-elf

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y apt-utils
RUN apt-get install -y gcc make

VOLUME /home/amin/Desktop/projects/fgOS-BETA
WORKDIR /home/amin/Desktop/projects/fgOS-BETA