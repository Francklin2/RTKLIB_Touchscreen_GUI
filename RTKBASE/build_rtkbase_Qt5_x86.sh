#!/bin/bash
# Script to build RTKBASE in one command
## build packages
echo 
echo "     Script created by"
echo "     Sylvain POULAIN <sylvain.poulain@giscan.com>"
echo "     released under GPL"
echo "     Attribution"
echo
echo "     if the script doesn't finish properly"
echo "     (i.e. it doesn't print \"script finished\" at the end)"
echo "     please open an issue on github at : "
echo "    https://github.com/Francklin2/RTKLIB_Touchscreen_GUI "
echo
echo
echo "  - script started - `date`"
## dest base path
LOG_PATH="$PWD/logs"
## get sys vars
ARCH=`uname -m`
CORES=`grep -c processor /proc/cpuinfo`
## prevents different (localized) output
#LC_ALL=C #>>>> TEST MODIF pour build pi2
## removing old stuff
rm -Rf "$LOG_PATH"
## create needed directory
mkdir -p "$LOG_PATH"
## output sys info
echo "System info:" > "$LOG_PATH/sysinfo.txt"
uname -a > "$LOG_PATH/sysinfo.txt"
echo
echo "  > Install dependencies : "
echo "  > Script will ask your passwork to install it"
sudo apt-get install --assume-yes proj-bin qtdeclarative5-dev qttools5-dev-tools libgles2-mesa libgles2-mesa-dev build-essential qt5-default > "$LOG_PATH/apt.log" 2>&1
echo "  > building required static lib rtklib"
cd ./lib/rtklib
echo "  > building required static lib rnx2rtkp"
chmod +x make_library.sh > "$LOG_PATH/rtklib_rights.log" 2>&1
./make_library.sh > "$LOG_PATH/rtklib.log" 2>&1
chmod +x make_library_process.sh > "$LOG_PATH/rtklib_rights.log" 2>&1
./make_library_process.sh
cd ../../
echo "  < done - `date`"
echo

cd ../
cd Package
echo "  > copy x86 Package "
cd bin-x86
cp * ../
cd ../
echo "  > Check packages rights : "
chmod +x RTKBASE.sh > "$LOG_PATH/rtklib_rights.log" 2>&1
chmod +x RNX2CRX > "$LOG_PATH/rtklib_rights.log" 2>&1
chmod +x CRX2RNX > "$LOG_PATH/rtklib_rights.log" 2>&1
chmod +x teqc > "$LOG_PATH/rtklib_rights.log" 2>&1
cd ../
cd RTKBASE
chmod +x build_rtkbase.sh > "$LOG_PATH/rtklib_rights.log" 2>&1

echo "  > building RTKBASE"
./build_rtkbase.sh
./build_rtkbase.sh
echo "  < done - `date`"
echo "  - script finished - `date`"
exit
