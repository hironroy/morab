/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.

  @author Hiron Roy
  @email me@hironroy.com
 */

#include "tBeat.h"
#include "Bounce2.h"

#include "Instrument.h"
#include "Metronome.h"
#include "LED.h"

//Milliseconds that elapsed between system state evaluations via tBeat
int loop_interval = 8;

//Pin Declarations
int btn_debounce_interval = 5;
int ins1_btn_pin = 28;
int ins2_btn_pin = 30;
int ins3_btn_pin = 32;
int ins4_btn_pin = 34;

int led_blink_duration = 500;
int ins1_led_pin = 3;
int ins2_led_pin = 4;
int ins3_led_pin = 5;
int ins4_led_pin = 6;

Instrument ins1;
Instrument ins2;
Instrument ins3;
Instrument ins4;

Metronome metronome;
LED mled;
int metronome_led = 8;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);      // open the serial port at 9600 bps:
  
  metronome.begin(50, loop_interval);
  mled.begin(metronome_led, 200, loop_interval);

//  metronome.begin(8, 500, loopInterval);
//  button1.begin(24, 5);
  ins1.begin(ins1_btn_pin, btn_debounce_interval, ins1_led_pin, led_blink_duration, loop_interval);
  ins2.begin(ins2_btn_pin, btn_debounce_interval, ins2_led_pin, led_blink_duration, loop_interval);
  ins3.begin(ins3_btn_pin, btn_debounce_interval, ins3_led_pin, led_blink_duration, loop_interval);
  ins4.begin(ins4_btn_pin, btn_debounce_interval, ins4_led_pin, led_blink_duration, loop_interval);

  
  tBeat.init();
  //All of the actuators get triggered at the sample interval
  tBeat.newHook(loop_interval, runInterval);

  tBeat.start();
}

// the loop routine runs over and over again forever:
void loop() {  
    tBeat.exec();
}


void runInterval(){
  
  metronome.loop();
  if(metronome.isBeatInterval()){
    Serial.println("Beat");
     mled.trigger(); 
  }
  
  mled.loop();
  
  ins1.loop();
  ins2.loop();
  ins3.loop();
  ins4.loop();

}


