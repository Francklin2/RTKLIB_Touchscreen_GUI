#!/bin/bash

# Install RTKBASE 

while true
do

PS3='Please enter your choice:'
options=("Download RTKbase 2.4.2" "Download RTKbase 2.4.3" "Update RTKbase 2.4.2" "Update RTKbase 2.4.3" "Build RTKbase" "Install autostart at boot" "Install 5 inch LCD driver" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Download RTKbase 2.4.2")
            echo "Install RTKBASE 2.4.2 folder from github"
            cd $HOME
            git clone https://github.com/Francklin2/RTKLIB_Touchscreen_GUI.git
            # restore rights for build script
            cd $HOME/RTKLIB_Touchscreen_GUI/RTKBASE
            chmod +x build_rtkbase_Qt5_ARM.sh
	    chmod +x build_rtkbase_Qt5_x86_64.sh
	    chmod +x build_rtkbase_Qt5_x86_32.sh
	    break
            ;;
        "Download RTKbase 2.4.3")
            echo "Install RTKBASE 2.4.3 folder from github"
            cd $HOME
            git clone https://github.com/Francklin2/RTKLIB_Touchscreen_GUI.git --branch RTKbase-2.4.3
            # restore rights for build script
            cd $HOME/RTKLIB_Touchscreen_GUI/RTKBASE
            chmod +x build_rtkbase_Qt5_ARM.sh
	    chmod +x build_rtkbase_Qt5_x86_64.sh
	    chmod +x build_rtkbase_Qt5_x86_32.sh
	    break
            ;;
            "Update RTKbase 2.4.2")
            echo "Update RTKBASE folder from github"
            echo "Backup config and data"
            cd $HOME
            mkdir Installer
            cd Installer
            mkdir Backup
            cd Backup
            mkdir BaseFiles
            mkdir ConfFiles
            mkdir PointsFiles
            mkdir data
            cp $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/BaseFiles/* $HOME/Installer/Backup/BaseFiles
            cp $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/ConfFiles/* $HOME/Installer/Backup/ConfFiles
            cp $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/PointsFiles/* $HOME/Installer/Backup/PointsFiles
            cp $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/data/* $HOME/Installer/Backup/data
            
            echo "Erase old RTKBASE folder"
            cd $HOME
            rm -r -f RTKLIB_Touchscreen_GUI

            echo "Update new RTKBASE folder from github"
            git clone https://github.com/Francklin2/RTKLIB_Touchscreen_GUI.git
            
            echo "Copy backup files to new RTKBASE folder"
            cp $HOME/Installer/Backup/BaseFiles/* $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/BaseFiles
            cp $HOME/Installer/Backup/ConfFiles/* $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/ConfFiles
            cp $HOME/Installer/Backup/PointsFiles/* $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/PointsFiles
            cp $HOME/Installer/Backup/data/* $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/data
            cd $HOME/RTKLIB_Touchscreen_GUI/RTKBASE
            chmod +x build_rtkbase_Qt5_ARM.sh
	    chmod +x build_rtkbase_Qt5_x86_64.sh
	    chmod +x build_rtkbase_Qt5_x86_32.sh
            break
            ;;
            "Update RTKbase 2.4.3")
            echo "Update RTKBASE folder from github"
            echo "Backup config and data"
            cd $HOME
            mkdir Installer
            cd Installer
            mkdir Backup
            cd Backup
            mkdir BaseFiles
            mkdir ConfFiles
            mkdir PointsFiles
            mkdir data
            cp $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/BaseFiles/* $HOME/Installer/Backup/BaseFiles
            cp $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/ConfFiles/* $HOME/Installer/Backup/ConfFiles
            cp $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/PointsFiles/* $HOME/Installer/Backup/PointsFiles
            cp $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/data/* $HOME/Installer/Backup/data
            
            echo "Erase old RTKBASE folder"
            cd $HOME
            rm -r -f RTKLIB_Touchscreen_GUI

            echo "Update new RTKBASE folder from github"
            git clone https://github.com/Francklin2/RTKLIB_Touchscreen_GUI.git --branch RTKbase-2.4.3
            
            echo "Copy backup files to new RTKBASE folder"
            cp $HOME/Installer/Backup/BaseFiles/* $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/BaseFiles
            cp $HOME/Installer/Backup/ConfFiles/* $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/ConfFiles
            cp $HOME/Installer/Backup/PointsFiles/* $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/PointsFiles
            cp $HOME/Installer/Backup/data/* $HOME/RTKLIB_Touchscreen_GUI/RTKBASE/data
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
			break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
done
