#! /bin/bash

apt-get update -y && apt-get upgrade -y
apt-get install -y apt-utils
apt-get install -y git gcc ninja-build grub-common build-essential gcc-multilib
git clone --depth 1 https://github.com/fgsoftware1/fgOS-BETA.git
