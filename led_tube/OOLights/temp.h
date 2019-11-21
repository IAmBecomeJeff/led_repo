#ifndef TEMP_H
#define TEMP_H

#include <FastLED.h>
#include "vars.h"
#include "ledeffect.h"

class TestEffect : public LedEffect {

private:
	uint8_t bpm;
	uint8_t bpm2;
	uint16_t index;

public:
	TestEffect(uint8_t providedBpm, uint8_t providedBpm2) {
		bpm = providedBpm;
		bpm2 = providedBpm2;
	}

	void render() {
		index = beatsin16(bpm, 1, 100,0, beatsin16(bpm2));
		Serial.println(index);
	}
};




#endif
