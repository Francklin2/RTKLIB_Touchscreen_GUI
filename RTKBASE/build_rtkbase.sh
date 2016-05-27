#!/bin/bash
# Script to build RTKBASE in one command
cd ./lib/rtklib
chmod +x make_library.sh
sh make_library.sh
cd ../../
make clean
qmake
make
