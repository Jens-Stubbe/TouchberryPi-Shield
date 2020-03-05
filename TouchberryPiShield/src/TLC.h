#pragma once
#include "I2C.h"

namespace tlc{
  class TLC{

    public:
      TLC();
      void set_group_duty_cycle(int dimming);
      void set_color_leds(int value);
      void reset();
      void set_LED_Driver_Output_States();
      void enable_oscillator();
      int get_address();

    private:
      int incrementer();

      i2c::I2C i2c;
      char buffer[2];
      const int slave_address = 0x60;
      int count = 0;
  };
}
