FROM library/ubuntu:rolling

VOLUME /home/admin/Desktop/projects
WORKDIR /home/admin/Desktop/projects

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y apt-utils --no-install-recommends
RUN apt-get install -y git gcc nasm ninja-build grub-common xorriso gcc-multilib ca-certificates wget --no-install-recommends
RUN apt autoremove && apt-get clean && rm -rf /var/lib/apt/lists/*
RUN mkdir /usr/local/share/ca-certificates/cacert.org && wget -P /usr/local/share/ca-certificates/cacert.org http://www.cacert.org/certs/root.crt http://www.cacert.org/certs/class3.crt && update-ca-certificates
RUN git config --global http.sslCAinfo /etc/ssl/certs/ca-certificates.crt && git clone --depth 1 https://github.com/fgsoftware1/fgOS-BETA.git
RUN cd fgOS-BETA
