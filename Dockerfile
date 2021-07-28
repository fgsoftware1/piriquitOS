FROM randomdude/gcc-cross-x86_64-elf

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt autoremove -y
RUN apt-get install -y apt-utils
RUN apt-get install -y git gcc ninja-build grub-common
RUN git clone https://github.com/fgsoftware1/fgOS-BETA.git

VOLUME /home/amin/Desktop/projects/fgOS-BETA
WORKDIR /home/amin/Desktop/projects/fgOS-BETA
