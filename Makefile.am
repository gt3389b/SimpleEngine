ACLOCAL_AMFLAGS=-I m4
openssl_engine_LTLIBRARIES=libsimple.la

# Removed "openssl/engines" for OSX
openssl_enginedir=@libdir@/engines

libsimple_la_SOURCES= simpleengine.c

EXTRA_DIST = $(TESTSUITE) 
   TESTSUITE = run_tests.sh
     
check-local: $(TESTSUITE)
	bash '$(TESTSUITE)' $(TESTSUITEFLAGS)
