#!/bin/sh

cd /home/pi/

apt-get update -y


# Install LCD Driver
cd /home/pi/
git clone https://github.com/waveshare/LCD-show.git
cd ./LCD-show/
chmod +x LCD5-show
./LCD5-show
