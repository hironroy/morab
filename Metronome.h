#ifndef __Morab__Metronome__
#define __Morab__Metronome__

#include <Arduino.h>

class Metronome {
public:
    void begin(int initial_bpm, int _interval_duration);
    int getBPM();
    void setBPM(int _bpm);
    bool isBeatInterval();
    void loop();
private:
    int bpm;
    int interval_duration;
    int msSinceLastBeat;

    int getCurrentDelay();
    void resetBeat();
    bool is_beat_interval;
};

#endif /* defined(__Morab__Metronome__) */
