AM_CPPFLAGS = -D__STDC_INT64__

#if USE_SUBMODULES
#SUBDIRS = ../glitter
#AM_CPPFLAGS += -I $(top_srcdir)/glitter/src
#endif

include Makefile-LIBADD.inc

lib_LTLIBRARIES = librw2chipcstd.la
include_HEADERS = rw2chipcstd.h
librw2chipcstd_la_LIBADD = $(LIBRW2CHIPCSTD_LIBADD)
