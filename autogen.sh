#! /bin/bash

aclocal
autoconf
autoreconf
automake
--add-missing
./configure
make
