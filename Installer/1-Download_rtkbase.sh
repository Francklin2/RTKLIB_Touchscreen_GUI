#!/bin/sh

# Install RTKBASE folder from github
cd /home/pi/
git clone https://github.com/Francklin2/RTKLIB_Touchscreen_GUI.git
cd /home/pi/RTKLIB_Touchscreen_GUI/RTKBASE
# restore rights for build script
chmod +x build_rtkbase_Qt5_ARM.sh
chmod +x build_rtkbase_Qt5_x86.sh
