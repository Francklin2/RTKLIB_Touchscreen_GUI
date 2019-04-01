#!/bin/bash

# Install RTKBASE 

while true
do

PS3='Please enter your choice:'
options=("Download RTKbase" "Build RTKbase" "Install autostart at boot" "Install 5 inch LCD driver" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Download RTKbase")
            echo "Install RTKBASE folder from github"
            cd $HOME
            git clone https://github.com/Francklin2/RTKLIB_Touchscreen_GUI.git
            # restore rights for build script
            cd $HOME/RTKLIB_Touchscreen_GUI/RTKBASE
            chmod +x build_rtkbase_Qt5_ARM.sh
	    chmod +x build_rtkbase_Qt5_x86_64.sh
	    chmod +x build_rtkbase_Qt5_x86_32.sh
	    break
            ;;	
        "Build RTKbase")
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
            break
            ;;
        "Install autostart at boot")
            echo "Installing autostart"
            cd $HOME
            mkdir .config/autostart
            mv $HOME/Installer/RTKBASE.desktop $HOME/.config/autostart/
            chmod +x ./.config/autostart/RTKBASE.desktop
            break
            ;;
	 "Install 5 inch LCD driver")
           echo "Installing LCD driver"
	   cd $HOME
	   git clone https://github.com/waveshare/LCD-show.git
	   cd ./LCD-show/
	   chmod +x LCD5-show
	   ./LCD5-show 
           break
           ;;
        "Quit")
            exit
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
done
