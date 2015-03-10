#ifndef __Morab__LED__
#define __Morab__LED__

#include "Arduino.h"

class LED {
public:
    void begin(int _led, int _blinkDuration, int _loopDuration);
    void startBlink();
    void loop();
private:
    void stopBlink();
    void decrementBlink();
    
    boolean isUp;
    boolean blinkDuration;
    
    int currentBlinkRemaining;
    int loopDuration;
    int led;

};

#endif /* defined(__Morab__LED__) */
