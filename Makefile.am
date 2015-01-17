openssl_engine_LTLIBRARIES=libabraxas.la
openssl_enginedir=@libdir@/openssl/engines

libabraxas_la_LIBADD=-L@OPENSSL_LIB_DIR@ -lcrypto -lc
libabraxas_la_LDFLAGS=-module -avoid-version -shared
libabraxas_la_CFLAGS=-I@OPENSSL_INCLUDE_DIR@ -Wall -Werror -c -g -fstack-protector-all -D_FORTIFY_SOURCE=2 -DENGINE_DYNAMIC_SUPPORT -Qunused-arguments
#libabraxas_la_CFLAGS=-I@OPENSSL_INCLUDE_DIR@ -Wall -Werror -Qunused-arguments
libabraxas_la_SOURCES= simpleengine.c
