## Hardware
```
You'll need :
a)A RaspberryPi running Raspbian
b)A TouchberryPi shield, more information can be found at :
https://circuitmaker.com/Projects/Details/Sille-Van-Landschoot-2/TouchBerry-Pi
```
------------------------------------------------------------------------------------------------------------------
## Dependencies : 

`sudo apt-get update`

`sudo apt-get install git build-essential autoconf automake libtool libcurl4-gnutls-dev python3 python3-pip`

`sudo pip3 install pynput`
```
You'll also need to enable I2C on the raspberryPi using :
sudo raspi-config
This will present you with a graphical user interface
Select Interfacing Options
Select I2C
Select Yes, when prompted if you want to enable I2C
```
-------------------------------------------------------------------------------------------------------------
## Compiling the program :
The makefile was designed as to have the code natively compiled on the Raspberry Pi itself
```
cd Touchberry
make clean
make
```
------------------------------------------------------------------------------------------------------------------------------
## Executing the application : 

./Touchshield_Wrapper.py
