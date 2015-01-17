openssl_engine_LTLIBRARIES=libsimple.la
openssl_enginedir=@libdir@/openssl/engines

libsimple_la_LIBADD=-L@OPENSSL_LIB_DIR@ -lcrypto -lc
libsimple_la_LDFLAGS=-module -avoid-version -shared
libsimple_la_CFLAGS=-I@OPENSSL_INCLUDE_DIR@ -Wall -Werror -c -g -fstack-protector-all -D_FORTIFY_SOURCE=2 -DENGINE_DYNAMIC_SUPPORT -Qunused-arguments
#libsimple_la_CFLAGS=-I@OPENSSL_INCLUDE_DIR@ -Wall -Werror -Qunused-arguments
libsimple_la_SOURCES= simpleengine.c
