
#ifndef __Morab__Button__
#define __Morab__Button__

#include "Arduino.h"
#include "Bounce2.h"

class Button {
public:
    void begin(int _pin, int _debounceInterval);
    void loop();
    boolean isPressed();
    boolean isNewlyTriggered();
private:
    Bounce debouncer;
    boolean pressed;
    boolean triggered;
};

#endif /* defined(__Morab__Button__) */
