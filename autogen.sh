#! /bin/bash
automake --add-missing
autoreconf
./configure
make
