AC_DEFUN([AC_PROG_MKRESCUE], [
  AC_ARG_VAR([MKRESCUE], [The grub-mkrescue program])
  if test -z "$MKRESCUE"; then
    AC_PATH_PROG([MKRESCUE], [grub-mkrescue])
  fi
  AS_IF([test -z "$MKRESCUE"], [
    AC_MSG_ERROR([grub-mkrescue not found.])
  ])
])
