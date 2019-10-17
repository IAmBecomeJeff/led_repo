#include "FastLED.h"
#include "fireworks_in_place.h"



void setup() {
	Serial.begin(115200);                                                            // Setup serial baud rate
	delay(1000);                                                                    // Slow startup so we can re-upload in the case of errors.
	Serial.println("Let the fireworks begin!");
	LEDS.setBrightness(max_bright);                                                 // Set the generic maximum brightness value.
	LEDS.addLeds<LED_TYPE, LED_DT, LED_CK, COLOR_ORDER >(leds, NUM_LEDS);           // APA102 or WS2801 definition
	set_max_power_in_volts_and_milliamps(5, 2000);                                  // 5V, 2A
	fireworks_init();
} // setup()

void loop() {

	EVERY_N_MILLIS_I(this_timer, this_delay) {
		this_timer.setPeriod(this_delay);
		fireworks_update();
	}

	FastLED.show();
}
