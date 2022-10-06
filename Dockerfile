#syntax=docker/dockerfile:1.3
FROM ubuntu:22.04

VOLUME /fgOS
WORKDIR /fgOS

RUN apt-get update && apt-get install -y nasm gcc g++ g++-multilib xorriso grub2-common grub-pc-bin ninja-build --no-install-recommends
