
#ifndef __Morab__Button__
#define __Morab__Button__

#include "Arduino.h"
#include "Bounce2.h"

class Button {
public:
    void begin(int _pin, int _debounceInterval);
    void loop();
private:
    Bounce debouncer;
};

#endif /* defined(__Morab__Button__) */
