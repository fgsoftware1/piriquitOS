FROM library/ubuntu

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y apt-utils
RUN apt-get install -y git gcc ninja-build grub-common

VOLUME /home/amin/Desktop/projects/fgOS-BETA
WORKDIR /home/amin/Desktop/projects/fgOS-BETA
