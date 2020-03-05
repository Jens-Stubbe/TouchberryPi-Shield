//TLC is the LED driver of the touchberry
#include "TLC.h"

namespace tlc{
  TLC::TLC(){
    i2c.openI2C(slave_address);
  }
  int TLC::get_address(){
    return slave_address;
  }
  void TLC::enable_oscillator(){
    buffer[0] = 0x00;
    buffer[1] = 0x00;
    i2c.compose(buffer,sizeof(buffer));
  }
  int TLC::incrementer(){
    if(count<15){
      count = count + 1;
    }else{
      count = 0;
    }
    return count-1;
  }
  void TLC::set_color_leds(int value){
      int address = 0x02 + incrementer();
      buffer[0] = address;
      buffer[1] = value;
      i2c.compose(buffer,sizeof(buffer));
  }
  void TLC::set_group_duty_cycle(int dimming){
    int address = 0x12;
    buffer[0] = address;
    buffer[1] = dimming;
    i2c.compose(buffer,sizeof(buffer));
  }
  void TLC::reset(){
    char memory_address = 0b1101011;
    buffer[0] = memory_address;
    buffer[1] = 0;
    i2c.compose(buffer,sizeof(buffer));
  }
  void TLC::set_LED_Driver_Output_States(){
    buffer[0] = 0x14;
    buffer[1] = 0xFF;
    i2c.compose(buffer,sizeof(buffer));
    buffer[0] = 0x15;
    buffer[1] = 0xFF;
    i2c.compose(buffer,sizeof(buffer));
    buffer[0] = 0x16;
    buffer[1] = 0xFF;
    i2c.compose(buffer,sizeof(buffer));
    buffer[0] = 0x17;
    buffer[1] = 0xFF;
    i2c.compose(buffer,sizeof(buffer));
  }
}
