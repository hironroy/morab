# include "Button.h"

void Button::begin(int _pin, int _debounceInterval){  
  pinMode(_pin,INPUT_PULLUP);
  debouncer = Bounce();
  debouncer.attach(_pin);
  debouncer.interval(_debounceInterval);
}

boolean Button::isPressed(){
  return pressed;
}

boolean Button::isNewlyTriggered(){
 return triggered; 
}

void Button::loop(){
  boolean changed = debouncer.update();
  triggered = false;

  if(changed){
  int value = debouncer.read();
    if ( value == LOW ) {
      triggered = true;
      pressed = true;
    } 
    else {
      pressed = false;
    }
  }
}

