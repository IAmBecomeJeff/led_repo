
#include "FastLED.h"
#include "variables.h"
#include "functions.h"


void setup(){
	LEDS.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setDither(max_bright < 255);
	FastLED.setBrightness(max_bright);
	set_max_power_in_volts_and_milliamps(5, 1000);
}

void loop(){

	EVERY_N_MILLISECONDS(50) {
		uint8_t maxChanges = 24;
		nblendPaletteTowardPalette(current_palette, target_palette, maxChanges);
	}

	EVERY_N_SECONDS(20) {
		mode = (mode + 1) % (max_mode + 1);
	}

	EVERY_N_MILLIS_I(this_timer, ico_delay) {
		this_timer.setPeriod(ico_delay);
		action(mode);
	}
	FastLED.show();
}


void action(uint8_t current_mode, bool isNew) {
	if (isNew) {
		fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
	}

	switch (current_mode) {
	case 0:
		if (isNew) { ico_delay = 15; fade_val = 128; this_index = 0; };
		spin();
		break;

	case 1:
		if (isNew) { ico_delay = 15; delta = 128; increment = 1; };
		ico_fill_rainbow();
		break;

	case 2:
		if (isNew) { ico_delay = 15; target_palette = RainbowStripeColors_p; pal_index = 0; delta = 128; increment = 2 };
		ico_palette();
		break;

	case 3:
		if (isNew) { ico_delay = 20; fade_val = 200; numdots = 1; beat = 10; hue = 0; };
		juggle();
		break;

	case 4:
		if (isNew) { ico_delay = 12; fade_val = 128; numdots = 2; beat = 0; palette_index = 0; };
		juggle_palette();
		break;

	case 5:
		if (isNew) { ico_delay = 15; fade_val = 160; numdots = 1; beat = 5; hue = 0; };
		juggle_up_and_down();
		break;

	case 6:
		if (isNew) { ico_delay = 10; fade_val = 96; hue = 32; };
		confetti();
		break;
	}

}

