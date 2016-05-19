# RTKLIB_Touchscreen_GUI
RTKLIB GUI for Raspberry Pi with touchscreen made with Qt by the ENSG students 


To build this project you will need :

- Raspberry pi 2 and a 8gb SD

- 5 inch HDMI touchscreen like this one
https://www.amazon.fr/Waveshare-Raspberry-Resistive-Interface-Rapsberry/dp/B00TIA0PMQ

- Talysman antenna 
http://www.digikey.fr/product-detail/fr/0/1526-1016-ND

- TNC/SMA adapter like this
http://www.ebay.fr/itm/370949049924?_trksid=p2060353.m2749.l2649&ssPageName=STRK%3AMEBIDX%3AIT

- GNSS Ublox M8T, you can found cheap one at csgshop.com
http://www.csgshop.com/product.php?id_product=205

- a standart rectangular on/off power switch
http://www.ebay.fr/itm/5Pcs-2-Pin-Snap-in-On-Off-Position-Snap-Boat-Rocker-Switch-12V-110V-250V-K0TG-/311562995499?hash=item488a9a072b:g:zbAAAOSwxp9W39wh

- Régulator Ubec 5V , you can found them in any RC-model shop
http://www.ebay.fr/itm/5V-3A-Mini-UBEC-BEC-Converter-Step-Down-Module-For-RC-Plane-FPV-DIY-Aircraft-Fly-/131676464873?hash=item1ea88766e9:g:zmQAAOSwvUlWsgG4 

- Battery Adapter Mounting Plate for NP-F970
http://www.ebay.fr/itm/Battery-Adapter-Mounting-Plate-fr-NP-F970-F750-F550-Sony-Battery-970-DSLR-Rig-/172049210887?hash=item280eee9e07

- Battery Sony NP-F970 or a compatible one ( you can find many cheap clones)
http://www.ebay.fr/itm/6600mAh-NP-F960-NP-F970-Batteries-pour-NP-F930-F330-F550-F750-F770-SONY-Appareil-/281720172938?hash=item4197d4b18a:g:GN4AAOSwBahVeQMW

- Charger for battery NP-F Sony 
http://www.ebay.fr/itm/Dual-Channel-Battery-Charger-For-SONY-NP-F970-F750-F960-FM50-FM500H-FM55H-QM91D-/371008913548?hash=item5661dac08c:g:9UUAAOxyLm9TAttp

- mini USB angled for wiring the GNSS
http://www.ebay.fr/itm/Court-20cm-Angle-Droit-USB-A-a-90-degres-Angle-Droit-Mini-B-USB-Data-Cable-Cable-/221683667935?hash=item339d6053df:g:dDoAAOSwPhdU1PcB

 - Dérial RF link, 2 units needed to link a rover too a base like a Xbeepro or a cheaper 3DR télémetry module(Half duplex only !)
 https://www.sparkfun.com/products/10419
and
http://www.ebay.fr/itm/3DRobotics-Radio-3DR-Kit-Telemetry-433Mhz-Module-for-APM-APM2-5-2-6-Pixhawk-PX4-/221852845151?hash=item33a775c45f:g:0YgAAOSwgQ9V0Un~

- Wifi dongle to for internet Ntrip GNSS correction
-http://www.ebay.fr/itm/Wireless-USB-Adapter-LAN-Wifi-Dongle-for-Raspberry-Pi-802-11-b-g-n-150Mbps-PK-/311440828311?hash=item488351e797:g:UJIAAOSwWnFV7mJy

To install system on a raspberry pi 2 with the touchscreen you can download a raspian image with all the touchscreen drivers preinstalled here :
https://drive.google.com/file/d/0B2SuLGFxizpVMzRtODVkN0tZVjA/view?usp=sharing
Copy them on a SD card, you can use Rufus for that :
https://rufus.akeo.ie/
Copy the RTKBASE folder in the /home/pi folder (still have problem with absolute path), lauch the RTKBASE file in the RTKBASE folder to lauch the GUI, the is also a RTKBASE.sh script , you can use it to lauch the GUI at startup in  the autostart file of raspian in the folder /etc/xdg/lxsession/LXDE-pi/ , edit the autostart file and add the path of the RTKBASE.sh :
@/etc/xdg/lxsession/LXDE-pi/RTKBASE.sh
Before switch off the power you still have to close GUI and shutdown the raspberry by the menu , I will  add a button for that in the next version


