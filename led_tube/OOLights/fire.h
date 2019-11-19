#ifndef FIRE_H
#define FIRE_H

#include <FastLED.h>
#include "vars.h"
#include "ledeffect.cpp"

// We subclass from the LedEffect abstract class
class FireEffect: public LedEffect {
    private:
        byte heat[NUM_LEDS];

    public:
        // Default constructor
        FireEffect(uint8_t providedSparking = 80, uint8_t providedCooling = 90, uint8_t providedSpeedDivisor = 4){
            sparking = providedSparking;
            cooling = providedCooling;
            counter = 0;
            speedDivisor = providedSpeedDivisor;
        }

        void render(){
            counter++;
            if (counter%speedDivisor != 0) {return;}

            // Cool down every cell
            for (int i = 0; i < NUM_LEDS; i++){
                heat[i] = qsub8(heat[i], random8(0, ((cooling*10) / NUM_LEDS) + 2));
            }
            
            // Drift heat along strip
            for (int j = NUM_LEDS - 1; j >= 2; j--){
                heat[j] = (heat[j - 1] + heat[j - 2] + heat[j - 2]) / 3;
            }

            // Randmoly ignite new sparks at the bottom
			if (random8() < sparking) {
				uint8_t y = random8(7);
				heat[y] = qadd8(heat[y], random8(160, 255));
			}

			// Map from heat cells to LEDs
            for (int k = 0; k < NUM_LEDS; k++){
                CRGB hcolor = HeatColor(heat[k]);
                leddata[k] = CRGB(hcolor.r, hcolor.g, hcolor.b);
            }
        }
}


class FireMirrorEffect : public LedEffect {
private:
	byte heat[NUM_LEDS/2];

public:
	// Default constructor
	FireEffect(uint8_t providedSparking = 80, uint8_t providedCooling = 90, uint8_t providedSpeedDivisor = 4) {
		sparking = providedSparking;
		cooling = providedCooling;
		counter = 0;
		speedDivisor = providedSpeedDivisor;
	}

	void render() {
		counter++;
		if (counter % speedDivisor != 0) { return; }

		// Cool down every cell
		for (int i = 0; i < NUM_LEDS/2; i++) {
			heat[i] = qsub8(heat[i], random8(0, ((cooling * 10) / (NUM_LEDS / 2)) + 2));
		}

		// Drift heat along strip
		for (int j = (NUM_LEDS/2) - 1; j >= 2; j--) {
			heat[j] = (heat[j - 1] + heat[j - 2] + heat[j - 2]) / 3;
		}

		// Randmoly ignite new sparks at the bottom
		for (int k = 0; k < NUM_LEDS/2; k++) {
			CRGB hcolor = HeatColor(heat[k]);
			leddata[(NUM_LEDS / 2) + k] = CRGB(hcolor.r, hcolor.g, hcolor.b);
			leddata[(NUM_LEDS / 2) - 1 - k] = CRGB(hcolor.r, hcolor.g, hcolor.b);
		}
	}
}

#endif