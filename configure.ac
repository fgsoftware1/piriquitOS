AC_INIT([piriquitOS], [1.0])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

m4_include([./m4/nasm.m4])
m4_include([./m4/mkrescue.m4])

AC_PROG_NASM
AC_PROG_CXX
AC_PROG_MKRESCUE

AC_CONFIG_FILES([
    Makefile
    src/arch/amd64/Makefile
])

AC_OUTPUT
