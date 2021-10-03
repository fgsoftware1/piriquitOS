#! /bin/bash
aclocal
automake --add-missing
autoreconf
./configure
make
