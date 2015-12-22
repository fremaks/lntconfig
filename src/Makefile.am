AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4
SUBDIRS = submodules

lib_LTLIBRARIES = liblntconfig.la
liblntconfig_la_LDFLAGS = -avoid-version
liblntconfig_la_SOURCES = lntconfig.c
liblntconfig_la_CPPFLAGS = -I$(top_srcdir)/src/submodules/libconfig-1.5/lib \
			   -I$(top_srcdir)/include

liblntconfig_la_LIBADD = $(top_srcdir)/src/submodules/libconfig-1.5/lib/.libs/libconfig.a

