#nerfgun

#!!NOTE!!

**Yeah, these instructions are a mess.  I'll clean them up ASAP.**

###**Install**

*Device setup*
Plug in the USB missile launcher.
Run ```lsusb``` and locate the device.
Example: 
```Bus 010 Device 013: ID 0a81:0701 Chesen Electronics Corp. USB Missile Launcher```
means the device is at 010:013
Run
```lsusb -D /dev/bus/usb/010/013 | grep "idVendor"```, which should return a hex number
open file nerfgun/src/ml_lib.cpp, and change the line ```dev->descriptor.idVendor("0x0a81")```
to the correct id.
Run
```
sudo chmod 777 /dev/bus/usb/010/013
```

Plug a game controller into the computer.


###**Build & Run**

**Build**
From your catkin_ws, run ```catkin_make```.

**Run**
```
roslaunch nerfgun teleop_bringup.launch
rosrun nerfgun nerfgun
```

http://libusb.sourceforge.net/api-1.0/group__dev.html#ga32fabedf5f13fdecf1cb33acdb19b57a
