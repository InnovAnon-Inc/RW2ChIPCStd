AC_INIT([librw2chipcstd], [1.0], [InnovAnon-Inc@protonmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 src/librw2chipcstd.pc
])

PKG_PROG_PKG_CONFIG

AC_ARG_ENABLE([use-submodules],
    AS_HELP_STRING([--enable-use-submodules], [Enable use submodules]))
AM_CONDITIONAL([USE_SUBMODULES], [test x"$enable_use_submodules" = "xyes"])

AC_CONFIG_MACRO_DIR([m4])

AC_CHECK_HEADERS([stdlib.h unistd.h sys/types.h])
#AC_CHECK_HEADERS([glitter.h ezfork.h restart.h sfork.h rw2chipc.h])

#AC_CHECK_LIB([stdlib],[fork],[ezfork],[restart],[sfork],[rw2chipc])
AC_CHECK_LIB([stdlib],[fork])

PKG_CHECK_MODULES([GLITTER],[glitter],,)
PKG_CHECK_MODULES([RESTART],[librestart],,)
PKG_CHECK_MODULES([RW2CHIPC],[librw2chipc],,)

INNOVANON_WARNINGS([])

AC_OUTPUT

