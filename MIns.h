#ifndef __Morab__MIns__
#define __Morab__MIns__

#include "Metronome.h"
#include "LED.h"

class MIns {
public:
    void begin(Metronome _metronome, int _led_pin, int _hit_length, int _loop_duration);
    void loop();
private:
    Metronome metronome;
    LED led;   
};

#endif /* defined(__Morab__MIns__) */
