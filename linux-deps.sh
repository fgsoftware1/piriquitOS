#! /bin/bash

apt-get update
apt-get install -y git gcc ninja-build gcc-multilib ca-certificates xorriso nasm grub-pc --no-install-recommends
apt-get autoremove && apt-get clean
mkdir /usr/local/share/ca-certificates/cacert.org
git config --global http.sslCAinfo /etc/ssl/certs/ca-certificates.crt
