#ifndef __Morab__LED__
#define __Morab__LED__

#include "Arduino.h"

class LED {
public:
    void begin(int _led, int _blinkDuration, int _loopDuration);
    void loop();
    void trigger();
private:
    void startBlink();
    void stopBlink();
    void decrementBlink();
    
    boolean isUp;

    int blinkDuration;    
    int currentBlinkRemaining;
    int loopDuration;
    int led;

};

#endif /* defined(__Morab__LED__) */
