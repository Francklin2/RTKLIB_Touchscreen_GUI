#!/bin/bash

# Build RTKBASE 
cd $HOME/RTKLIB_Touchscreen_GUI/RTKBASE
# restore rights for build script
chmod +x build_rtkbase_Qt5_ARM.sh
chmod +x build_rtkbase_Qt5_x86.sh


PS3='Please enter your choice:'
options=("Build on ARM" "Build on x86" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Build on ARM")
            echo "you choose ARM build"
            ./build_rtkbase_Qt5_ARM.sh
            break
            ;;
        "Build on x86")
            echo "you choose x86 build"
            ./build_rtkbase_Qt5_x86.sh
            break
            ;;
        "Quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
