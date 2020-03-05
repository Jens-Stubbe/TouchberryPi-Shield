#include "Touchberry.h"

namespace touchberry{
  Touchberry::Touchberry(){
    TLC.reset();
    QT1070.reset();
    QT1070.calibrate();
    TLC.enable_oscillator();
    TLC.set_LED_Driver_Output_States();
  }
  void Touchberry::set_led_color(int R,int G,int B){
    //Each time this method get's called a different led is programmed, untill all leds are programmed.
    //Then you'll start programming again at the starting RGB led
    TLC.set_color_leds(R);
    TLC.set_color_leds(G);
    TLC.set_color_leds(B);
  }
  char Touchberry::get_vendor_id(){
    char id = QT1070.read_vendor_id();
    return id;
  }
  void Touchberry::set_led_intensity(int dimming_value){
    TLC.set_group_duty_cycle(dimming_value);
  }
  std::string Touchberry::read_buttons(){
    return QT1070.read_key_register();
  }
}
