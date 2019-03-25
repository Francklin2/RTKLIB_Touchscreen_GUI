#!/bin/sh
cd /home/pi/
mkdir .config/autostart
mv /home/pi/Installer/RTKBASE.desktop ./.config/autostart/
chmod +x ./.config/autostart/RTKBASE.desktop

reboot