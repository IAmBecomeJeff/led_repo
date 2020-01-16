// Pool Noodle Totems
//		by JeffKarle

// Includes
#include includes.h

void setup() {
	if (DEBUG) {
		Serial.begin(57600);
		Serial.setTimeout(1500);
	}

	delay(1000);

	if (DEBUG) { Serial.println("DEBUG ON"); }

	FastLED.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);
	FastLED.setBrightness(MAX_BRIGHT);
	FastLed.setCorrection(TypicalLEDStrip);

	FastLED.clear(); FastLED.delay(500);
	if (DEBUG) {
		leds.fill_solid(CRGB::Red); FastLED.delay(500);
		leds.fill_solid(CRGB::Blue); FastLED.delay(500);
		leds.fill_solid(CRGB::Green); FastLED.delay(500);
		FastLED.clear(); FastLED.delay(500);
	}
}

void loop() {

}