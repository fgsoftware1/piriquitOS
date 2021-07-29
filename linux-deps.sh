#! /bin/bash

sudo apt-get update -y && apt-get upgrade -y
sudo apt-get install -y apt-utils
sudo apt-get install -y git gcc ninja-build grub-common
git clone --depth 1 https://github.com/fgsoftware1/fgOS-BETA.git
cd fgOS-BETA
