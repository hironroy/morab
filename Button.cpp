# include "Button.h"

void Button::begin(int _pin, int _debounceInterval){  
  pinMode(_pin,INPUT_PULLUP);
  debouncer = Bounce();
  debouncer.attach(_pin);
  debouncer.interval(_debounceInterval);
}

void Button::loop(){
  debouncer.update();
  int value = debouncer.read();
  if ( value == LOW ) {
    Serial.println("Button Pressed");
  } 
  else {
  }
}

