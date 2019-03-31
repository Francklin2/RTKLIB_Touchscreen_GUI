#!/bin/bash

# Build RTKBASE 
cd $HOME/RTKLIB_Touchscreen_GUI/RTKBASE
# restore rights for build script
chmod +x build_rtkbase_Qt5_ARM.sh
chmod +x build_rtkbase_Qt5_x86_64.sh
chmod +x build_rtkbase_Qt5_x86_32.sh

            echo "Starting RTKbase build"
	    cd $HOME/RTKLIB_Touchscreen_GUI/RTKBASE
            # Find current arch
	    UNAME=$(uname -m)
	    if [[ "$UNAME" == *"x86_64"* ]] ; then
	    echo "Build for Linux 64 bits" | ./build_rtkbase_Qt5_${UNAME}.sh
	    elif [[ "$UNAME" == *"arm"* ]] ; then
	    echo "Build for ARM" | ./build_rtkbase_Qt5_ARM.sh
	    elif [[ "$UNAME" == *"i"* ]] ; then
	    echo "Build for Linux 32 bits" | ./build_rtkbase_Qt5_x86_32.sh
	    fi
