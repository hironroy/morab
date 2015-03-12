# include "MIns.h"

void MIns::begin(Metronome _metronome, int _led_pin, int _hit_length, int _loop_duration){
  metronome = _metronome;
  led = LED();
  led.begin(_led_pin, _hit_length, _loop_duration);
}

void MIns::loop(){
  if(metronome.isBeatInterval()){
     led.trigger(); 
  }  
  led.loop();
}


