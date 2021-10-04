#! /bin/bashclear
aclocal
automake --add-missing
autoheader
autoconf
./configure
make
