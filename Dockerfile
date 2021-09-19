FROM ubuntu

VOLUME /home/admin/Desktop/projects
WORKDIR /home/admin/Desktop/projects

RUN apt-get update && apt-get install -y git nasm gcc ninja-build gcc-multilib xorriso grub-pc --no-install-recommends

