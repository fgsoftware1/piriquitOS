#! /bin/bash

docker pull fgygh/fgos-env:latest
docker run --rm -it -v $pwd:/home/admin/Desktop/projects/fgOS fgygh/fgos-env:latest
