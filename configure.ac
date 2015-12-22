#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([lntconfig], [1.0], [fremaks@163.com])
AM_INIT_AUTOMAKE([lntconfig], [1.0])
AC_CONFIG_SRCDIR([src/lntconfig.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL
# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([strdup])

AC_CONFIG_SUBDIRS([src/submodules/libconfig-1.5])
AC_OUTPUT(Makefile src/Makefile src/submodules/Makefile tests/Makefile)
