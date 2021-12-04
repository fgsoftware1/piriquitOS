FROM ubuntu:20.04

VOLUME /home/admin/Desktop/projects
WORKDIR /home/admin/Desktop/projects

RUN apt-get update && apt-get install -y git nasm gcc g++ ninja-build gcc-multilib xorriso grub2-common make automake autoconf m4 make mtools grub-pc-bin --no-install-recommends

