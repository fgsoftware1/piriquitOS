FROM library/ubuntu:focal

VOLUME /home/admin/Desktop/projects
WORKDIR /home/admin/Desktop/projects

RUN apt-get update -y
RUN apt-get install -y git nasm gcc ninja-build grub-common gcc-multilib ca-certificates xorriso --no-install-recommends
RUN apt-get autoremove && apt-get clean && rm -rf /var/lib/apt/lists/*
RUN mkdir /usr/local/share/ca-certificates/cacert.org
RUN git config --global http.sslCAinfo /etc/ssl/certs/ca-certificates.crt
RUN git clone --depth 1 https://github.com/fgsoftware1/fgOS.git
