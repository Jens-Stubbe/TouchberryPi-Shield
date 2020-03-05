#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <linux/uinput.h>
#include "Touchberry.h"

using namespace touchberry;

int main(void) {
    int intensity = 30;
    int R = 10;
    int G = 200;
    int B = 10;
    Touchberry touchberry;

    for(int i = 0;i<5;i++){
    	touchberry.set_led_color(R,G,B);
         }
	touchberry.set_led_intensity(intensity);
        while(true){
        	std::cout<<touchberry.read_buttons()<<std::endl;
		usleep(200000);
	}
  return 0;
}
