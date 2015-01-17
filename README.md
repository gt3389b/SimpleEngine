SimpleEngine
============

Simple test engine for OpenSSL.


```bash

./bootstrap.sh

./configure --with-openss=/usr/local/opt/openssl

make

openssl engine -t dynamic -pre SO_PATH:.libs/libsimple.dylib -pre ID:openhsmd -pre LIST_ADD:1 -pre LOAD 

```
