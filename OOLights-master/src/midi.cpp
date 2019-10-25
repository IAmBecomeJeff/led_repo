#ifndef SYMMETRIC_TRAILS_H
#define SYMMETRIC_TRAILS_H

#include <FastLED.h>
#include "vars.h"
#include "ledeffect.cpp"

// We subclass from the LEDEffect abstract class.
class MidiEffect: public LedEffect {

  private:
    // Each LedEffect subclass will have its own private variables



  public:
    // Default constructor
    MidiEffect() {

    }

    // Each LedEffect subclass must implement render(), which renders the next frame to the ledData array
    void render() {

    }
};

#endif
