AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS  = simple
simple_SOURCES = simple.c
simple_CPPFLAGS = -I$(top_srcdir)/src/submodules/libconfig-1.5/lib \
	          -I$(top_srcdir)/include

simple_LDADD = $(top_srcdir)/src/.libs/liblntconfig.la

