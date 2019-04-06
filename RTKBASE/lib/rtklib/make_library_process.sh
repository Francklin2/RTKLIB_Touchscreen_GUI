#!/bin/bash
#############################################
cd ./app/convbin/gcc
make clean
make -j2
sudo make install
cd ../../../
cd lib/iers/gcc
make clean
make -j2
cd ../../../
cd ./app/rnx2rtkp/gcc
make clean
make -j2
sudo make install
cd ../../../




#############################################
