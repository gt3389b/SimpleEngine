SimpleEngine
============

Simple test engine for OpenSSL.


```bash

./bootstrap.sh

./configure --with-openss=/usr/local/opt/openssl

make

# install the engine in the default list of engines
make install

openssl engine -t dynamic -pre SO_PATH:.libs/libsimple.dylib -pre ID:simple -pre LIST_ADD:1 -pre LOAD 

```
