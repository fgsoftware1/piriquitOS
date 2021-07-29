FROM library/ubuntu

VOLUME /home/admin/Desktop/projects/fgOS-BETA
WORKDIR /home/admin/Desktop/projects/fgOS-BETA

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y apt-utils
RUN apt-get install -y git gcc ninja-build grub-common build-essential gcc-multilib
RUN cd /home/admin/Desktop/projects/
RUN git clone --depth 1 https://github.com/fgsoftware1/fgOS-BETA.git
