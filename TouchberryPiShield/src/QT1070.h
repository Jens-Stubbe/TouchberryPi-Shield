#pragma once
#include "I2C.h"
#include <iostream>

namespace qt1070{
  class QT1070{

    public:
      QT1070();
      void reset();
      void calibrate();
      std::string read_key_register();
      int read_vendor_id();
      int get_address();

    private:
      i2c::I2C i2c;
      char buffer[2];
      const int slave_address = 0x1B;
  };
}
