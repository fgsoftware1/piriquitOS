FROM library/ubuntu:rolling

VOLUME /home/admin/Desktop/projects/fgOS
WORKDIR /home/admin/Desktop/projects/fgOS

RUN apt-get update -y
RUN apt-get install -y apt-utils --no-install-recommends
RUN apt-get install -y git g++ gcc clang ninja-build grub-common xorriso build-essential gcc-multilib wget openssl --no-install-recommends
RUN apt-get install --reinstall ca-certificates -y --no-install-recommends
RUN apt-get update -y
RUN apt autoremove
RUN apt-get clean
RUN rm -rf /var/lib/apt/lists/*
RUN mkdir /usr/local/share/ca-certificates/cacert.org
RUN wget -P /usr/local/share/ca-certificates/cacert.org http://www.cacert.org/certs/root.crt http://www.cacert.org/certs/class3.crt
RUN update-ca-certificates
RUN git config --global http.sslCAinfo /etc/ssl/certs/ca-certificates.crt
RUN git clone --depth 1 https://github.com/fgsoftware1/fgOS-BETA.git
