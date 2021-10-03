#! /bin/bashclear
automake --add-missing
autoreconf
./configure
make
