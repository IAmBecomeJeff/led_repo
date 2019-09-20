
#include "FastLED.h"
#include "variables.h"
#include "gradient_palettes.h"
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
		mode = random8(max_mode+1);
    isNew = 1;
	}

  EVERY_N_SECONDS(10) {
    target_palette = g_gradient_palettes[random8(g_gradient_palette_count+1)];
  }
	EVERY_N_MILLIS_I(this_timer, ico_delay) {
		this_timer.setPeriod(ico_delay);
		action(mode);
	}
	FastLED.show();
}


void action(uint8_t current_mode) {
	if (isNew) {
		fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
	}

	switch (current_mode) {
	case 0:
		if (isNew) { ico_delay = 30; fade_val = 128; ico_index = 0; isNew = 0; };
		spin();
		break;

	case 1:
		if (isNew) { ico_delay = 15; delta = 128; increment = 1; isNew = 0; };
		ico_fill_rainbow();
		break;

	case 2:
		if (isNew) { ico_delay = 15; target_palette = HeatColors_p; palette_index = 0; delta = 8; increment = 2; isNew = 0; };
		ico_palette();
		break;

	case 3:
		if (isNew) { ico_delay = 10; fade_val = 200; numdots = 2; beat = 16; hue = 0; isNew = 0; };
		juggle();
		break;

	case 4:
		if (isNew) { ico_delay = 12; fade_val = 128; numdots = 2; beat = 20; palette_index = 0; isNew = 0; };
		juggle_palette();
		break;

	case 5:
		if (isNew) { ico_delay = 30; fade_val = 160; numdots = 2; beat = 60; hue = 0; isNew = 0; };
		juggle_up_and_down();
		break;

	case 6:
		if (isNew) { ico_delay = 60; fade_val = 160; isNew = 0; };
		confetti();
		break;

  case 7:
    if(isNew) { ico_delay = 60; fade_val = 180; isNew = 0; };
    confetti_palette();
    break;
	}

}
