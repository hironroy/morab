# include "Instrument.h"

void Instrument::begin(int _button_pin, int _debounce_interval, int _led_pin, int _hit_length, int _loop_duration){   
  button = Button();
  button.begin(_button_pin, _debounce_interval);
  
  led = LED();
  led.begin(_led_pin, _hit_length, _loop_duration);
}

void Instrument::loop(){
  button.loop();
  updateLEDState();
  led.loop();
}  

void Instrument::updateLEDState(){
  if(button.isNewlyTriggered()){
    led.trigger(); 
  }
}


