//QT1070 is the Touchpad driver for the touchberry
#include "QT1070.h"

namespace qt1070{
  QT1070::QT1070(){
   i2c.openI2C(slave_address);
  }
  int QT1070::get_address(){
   return slave_address;
  }
  int QT1070::read_vendor_id(){
    char memory_address = {0x00};
    buffer[0] = memory_address;
    i2c.compose(buffer,1);
    i2c.consult(buffer,1);
    return buffer[0];
  }
  std::string QT1070::read_key_register(){
    char memory_address = 0x03;
    buffer[0] = memory_address;
    i2c.compose(buffer,1);
    i2c.consult(buffer,1);
    switch (buffer[0]){
    case 1:
      return "a";
      break;
    case 2:
      return "d";
      break;
    case 4:
      return "w";
      break;
    case 8:
      return "s";
      break;
    case 16:
      return "B";
      break;
    case 32:
      return "A";
      break;
    case 64:
      return "X";
      break;
    default:
      //return "other";
      return "";
      break;
    }
  }
  void QT1070::calibrate(){
    char memory_address = 0x56;
    buffer[0] = memory_address;
    buffer[1] = 0xFF;
    i2c.compose(buffer,sizeof(buffer));
  }
  void QT1070::reset(){
    char memory_address = 0x57;
    buffer[0] = memory_address;
    buffer[1] = 0xFF;
    i2c.compose(buffer,sizeof(buffer));
  }
}

