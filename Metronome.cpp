# include "Metronome.h"

void Metronome::begin(int initial_bpm, int _interval_duration){
  setBPM(initial_bpm);
  interval_duration = _interval_duration;
  msSinceLastBeat = 0;
  is_beat_interval = false;
}

int Metronome::getBPM(){
  return bpm;
}

void Metronome::setBPM(int _bpm){
  bpm = _bpm;
}

int Metronome::getCurrentDelay(){
    float float_bpm;
    float_bpm = (float) getBPM();
    
    return floor(60 * (1000 / float_bpm) + 0.5);
}

bool Metronome::isBeatInterval(){
  return is_beat_interval;
}

void Metronome::loop(){
  msSinceLastBeat += interval_duration;
  int currentDelay = getCurrentDelay();
  
  is_beat_interval = false;
  if(msSinceLastBeat > currentDelay){
    resetBeat();
    is_beat_interval= true;
    Serial.println("Metronome Beat Interval");
  }
}

void Metronome::resetBeat(){
  msSinceLastBeat = 0;
}


