#! /bin/bash

apt-get update -y && apt-get upgrade -y
apt-get install -y apt-utils
apt-get install -y git gcc ninja-build grub-common build-essential
