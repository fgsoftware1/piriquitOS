AC_DEFUN([AC_PROG_NASM], [
  AC_ARG_VAR([NASM], [The NASM assembler program])
  if test -z "$NASM"; then
    AC_PATH_PROG([NASM], [nasm])
  fi
  AS_IF([test -z "$NASM"], [
    AC_MSG_ERROR([NASM assembler not found.])
  ])
])
