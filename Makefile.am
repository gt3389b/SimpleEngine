openssl_engine_LTLIBRARIES=libsimple.la
openssl_enginedir=@libdir@/openssl/engines

libsimple_la_LIBADD=-L@OPENSSL_LIB_DIR@
libsimple_la_LDFLAGS=-module -avoid-version -shared
libsimple_la_CFLAGS=-I@OPENSSL_INCLUDE_DIR@ 
libsimple_la_SOURCES= simpleengine.c
