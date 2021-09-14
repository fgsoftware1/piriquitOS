#! /bin/bash

apt-get update -y
apt-get install -y git gcc ninja-build grub-common gcc-multilib ca-certificates xorriso nasm --no-install-recommends
apt-get autoremove && apt-get clean
mkdir /usr/local/share/ca-certificates/cacert.org
git config --global http.sslCAinfo /etc/ssl/certs/ca-certificates.crt
