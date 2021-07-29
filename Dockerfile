FROM library/ubuntu

VOLUME /home/amdin/Desktop/projects/fgOS-BETA
WORKDIR /home/amdin/Desktop/projects/fgOS-BETA
RUN mkdir bin
RUN mkdir build
RUN mkdir src
RUN cd src
RUN mkdir include

ADD bin/** home/admin/Desktop/projects/fgOS-BETA/bin
ADD build/** home/admin/Desktop/projects/fgOS-BETA/build
ADD src/*.cpp home/admin/Desktop/projects/fgOS-BETA/src
ADD src/*.ld home/admin/Desktop/projects/fgOS-BETA/src
ADD src/*.s home/admin/Desktop/projects/fgOS-BETA/src
ADD src/include/*.h home/admin/Desktop/projects/fgOS-BETA/src7include
ADD .clang-format /home/admin/Desktop/projects/fgOS-BETA/
ADD .gitignore /home/admin/Desktop/projects/fgOS-BETA/
ADD .editorconfig /home/admin/Desktop/projects/fgOS-BETA/
ADD build.ninja /home/admin/Desktop/projects/fgOS-BETA/
ADD Dockerfile /home/admin/Desktop/projects/fgOS-BETA/
ADD LICENSE /home/admin/Desktop/projects/fgOS-BETA/
ADD README.md /home/admin/Desktop/projects/fgOS-BETA/

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y apt-utils
RUN apt-get install -y git gcc ninja-build grub-common
