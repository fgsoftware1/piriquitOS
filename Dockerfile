FROM ubuntu:20.04

VOLUME /home/admin/Desktop/projects
WORKDIR /home/admin/Desktop/projects

RUN apt-get update && apt-get install -y git nasm gcc ninja-build gcc-multilib xorriso grub-pc make automake autoconf m4 --no-install-recommends

