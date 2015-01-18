SimpleEngine
============

Simple test engine for OpenSSL.


# Building, installing and using
```bash

# create the autotools stuff
./bootstrap.sh

# configure pointing to the openssl installation
./configure --with-openssl=/usr/local/opt/openssl

# build the libraries
make

# at this poing we can test the library without installing
LD_LIBRARY_PATH=.libs/ openssl rsa -engine simple

# install the engine in the default list of engines (usually requires root)
make install

# Install the engine on the openssl commandline; (only lasts for that session)
openssl engine -t dynamic -pre SO_PATH:.libs/libsimple.dylib -pre ID:simple -pre LIST_ADD:1 -pre LOAD 
```
