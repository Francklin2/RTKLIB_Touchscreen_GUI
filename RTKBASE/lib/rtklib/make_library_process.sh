#!/bin/bash
#############################################
cd ./app/convbin/gcc
make clean
make -j2
sudo make install
cd ../../
cd rnx2rtkp/gcc
make clean
make -j2
sudo make install
cd ../../../




#############################################
