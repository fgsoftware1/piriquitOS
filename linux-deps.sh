#! /bin/bash

apt-get update -y && apt-get upgrade -y
apt-get install -y apt-utils --no-install-recommends
apt-get install -y git gcc ninja-build grub-common build-essential gcc-multilib --no-install-recommends
apt-get install --reinstall ca-certificates -y
mkdir /usr/local/share/ca-certificates/cacert.org
wget -P /usr/local/share/ca-certificates/cacert.org http://www.cacert.org/certs/root.crt http://www.cacert.org/certs/class3.crt
update-ca-certificates
git config --global http.sslCAinfo /etc/ssl/certs/ca-certificates.crt
git clone --depth 1 https://github.com/fgsoftware1/fgOS-BETA.git
