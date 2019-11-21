#ifndef CUBICCYLON_H
#define CUBICCYLON_H

#include <FastLED.h>
#include "vars.h"
#include "ledeffect.h"

// We subclass from the LedEffect abstract class
// CubicCylonEffect uses cubicwave8 to achieve SyFy-Approved Realistic Cylon Eyes. Supposedly.
class CubicCylonEffect : public LedEffect {
private:
	uint8_t numDots;
	uint16_t phaseOffset; // How many leds apart each set is
	uint8_t hueOffset; // How offset each dot is in hue from the other
	uint8_t bpm; // How many cycles we complete in a minute
	bool trails; // Whether or not each dot is going to have trails
	bool useORBlendMode;

public:
	// Default constructor
	// Note: many dots with trails make for a cool Aurora-like effect!
	// 48 dots with 15 bpm is pretty.
	CubicCylonEffect(uint8_t howManyDots = 1, uint8_t providedBPM = 13, bool trailsEnabled = false, bool changeBlendMode = true) {
		numDots = howManyDots;
		phaseOffset = 32678 / numDots;
		hueOffset = 255 / numDots;
		bpm = providedBPM;
		trails = trailsEnabled;
		useORBlendMode = changeBlendMode;
	}

	// Each LedEffect subclass must implement render(), which renders the next frame to the ledData array
	// Spread out the dots so they're evenly placed
	void render() {
		if (!trails) { leddata(0, NUM_LEDS - 1) = CRGB::Black; }
		else { leddata.fadeToBlackBy(20); }

		for (uint8_t i = 0; i < numDots; i++) {
			uint16_t index = beatsin16(bpm, 1, NUM_LEDS - 2, 0, phaseOffset * (i * 2));
			if (useORBlendMode) { leddata(index - 1, index + 1) |= CHSV(i * hueOffset, 255, 255); }
			else { leddata(index - 1, index + 1) = CHSV(i * hueOffset, 255, 255); }
		}
	}
};

class CubicCylonAmoebaEffect : public LedEffect {
private:
	uint8_t numDots;
	uint16_t phaseOffset; // How many leds apart each set is
	uint8_t hueOffset; // How offset each dot is in hue from the other
	uint8_t bpm; // How many cycles we complete in a minute
	bool trails; // Whether or not each dot is going to have trails
	bool useORBlendMode;
	uint8_t left_edge_max;
	uint8_t right_edge_max;
	uint8_t left_bpm;
	uint8_t right_bpm;

public:
	// Default constructor
	// Note: many dots with trails make for a cool Aurora-like effect!
	// 48 dots with 15 bpm is pretty.
	CubicCylonAmoebaEffect(uint8_t howManyDots = 1, uint8_t providedBPM = 13, bool trailsEnabled = false, bool changeBlendMode = true, uint8_t providedleft_edge_max = 4, uint8_t providedright_edge_max = 6, uint8_t providedleft_bpm = 3, uint8_t providedright_bpm = 10) {
		numDots = howManyDots;
		phaseOffset = 32678 / numDots;
		hueOffset = 255 / numDots;
		bpm = providedBPM;
		trails = trailsEnabled;
		useORBlendMode = changeBlendMode;
		left_edge_max = providedleft_edge_max;
		right_edge_max = providedright_edge_max;
		left_bpm = providedleft_bpm;
		right_bpm = providedright_bpm;
	}

	// Each LedEffect subclass must implement render(), which renders the next frame to the ledData array
	// Spread out the dots so they're evenly placed
	void render() {
		if (!trails) { leddata(0, NUM_LEDS - 1) = CRGB::Black; }
		else { leddata.fadeToBlackBy(20); }

		for (uint8_t i = 0; i < numDots; i++) {
			uint16_t index = beatsin16(bpm, left_edge_max, NUM_LEDS - right_edge_max, 0, phaseOffset * (i * 2));
			if (useORBlendMode) { leddata(index - beatsin16(4, 1, left_edge_max), index + beatsin16(6,1,right_edge_max)) |= CHSV(i * hueOffset, 255, 255); }
			else { leddata(index - beatsin16(left_bpm, 1, left_edge_max), index + beatsin16(right_bpm, 1, right_edge_max)) = CHSV(i * hueOffset, 255, 255); }
		}
	}
};


#endif
