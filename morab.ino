/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.

  @author Hiron Roy
  @email me@hironroy.com
 */

#include "tBeat.h"
#include "LED.h"

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 8;

LED ledEight;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);      // open the serial port at 9600 bps:
  
  ledEight.begin(8, 500, 8);
  
  tBeat.init();
  //All of the actuators get triggered at the sample interval
  tBeat.newHook(1000, blink);
  tBeat.newHook(8, runInterval);

  tBeat.start();
}

// the loop routine runs over and over again forever:
void loop() {  
    tBeat.exec();
}

void blink(){
  ledEight.startBlink();
}

void runInterval(){
   ledEight.loop();
}


