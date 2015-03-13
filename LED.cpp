# include "LED.h"

void LED::begin(int _led, int _blinkDuration, int _loopDuration){
 blinkDuration = _blinkDuration;
 loopDuration = _loopDuration;
 currentBlinkRemaining = 0;
 
 isUp = false;
 led = _led;
 pinMode(led, OUTPUT);     

}

void LED::trigger(){
  Serial.println("LED Trigger");
 startBlink(); 
}

void LED::startBlink(){
    isUp = true;
    currentBlinkRemaining = blinkDuration;
}

void LED:: stopBlink(){
    isUp = false;
    currentBlinkRemaining = 0;
}

void LED::loop(){
  if(currentBlinkRemaining > 1 && isUp){
    currentBlinkRemaining -= loopDuration;
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    if(currentBlinkRemaining < 0){
       stopBlink(); 
    }
  }
  else {
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  }
  
}  



