#!/bin/sh

# Build RTKBASE 
cd /home/pi/RTKLIB_Touchscreen_GUI/RTKBASE
# restore rights for build script
chmod +x build_rtkbase_Qt5_ARM.sh
chmod +x build_rtkbase_Qt5_x86.sh
./build_rtkbase_Qt5_ARM.sh
