#ifndef __Morab__Instrument__
#define __Morab__Instrument__

#include "Arduino.h"
#include "Button.h"
#include "LED.h"

class Instrument {
public:
    void begin(int _button_pin, int _debounce_interval, int _led_pin, int _hit_length, int _loop_duration);
    void loop();
private:
    Button button;
    LED led;
    int loop_duration;
    
    void updateLEDState();

};

#endif /* defined(__Morab__Instrument__) */
