#! /bin/bash

apt-get update -y && apt-get upgrade -y
apt-get install -y apt-utils --no-install-recommends
apt-get install -y git gcc ninja-build grub-common gcc-multilib ca-certificates --no-install-recommends
apt-get autoremove && apt-get clean
mkdir /usr/local/share/ca-certificates/cacert.org
git config --global http.sslCAinfo /etc/ssl/certs/ca-certificates.crt
git clone --depth 1 https://github.com/fgsoftware1/fgOS.git
