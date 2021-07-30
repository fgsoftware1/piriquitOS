#! /bin/bash

apt-get update -y && apt-get upgrade -y
apt-get install -y apt-utils=2.0.6 --no-install-recommends
apt-get install -y git=2.25.1-1ubuntu3.1 gcc=9.3.0-1ubuntu2 ninja-build1.2.0 grub-common:2.04-1ubuntu26.12 build-essential:12.8ubuntu1.1 gcc-multilib=9.3.0-1ubuntu2 --no-install-recommends
apt-get install --reinstall ca-certificates:20.04.1 -y
mkdir /usr/local/share/ca-certificates/cacert.org
wget -P /usr/local/share/ca-certificates/cacert.org http://www.cacert.org/certs/root.crt http://www.cacert.org/certs/class3.crt
update-ca-certificates
git config --global http.sslCAinfo /etc/ssl/certs/ca-certificates.crt
git clone --depth 1 https://github.com/fgsoftware1/fgOS-BETA.git
