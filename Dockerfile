FROM ubuntu:impish-20211015

VOLUME /home/admin/Desktop/projects
WORKDIR /home/admin/Desktop/projects

RUN apt-get update && apt-get install -y git nasm gcc g++ g++-multilib xorriso grub2-common grub-pc-bin ninja-build mtools --no-install-recommends && rm -rf /var/lib/apt/lists/* && apt-get clean
