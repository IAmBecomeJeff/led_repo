#include <FastLED.h>

#include "variables.h"
#include "gradient_palettes.h"

//#include "bouncing_balls.h"
#include "colorwave.h"
#include "confetti.h"
//#include "cylon.h"
#include "fire.h"
#include "fireworks.h"
#include "juggle.h"
#include "one_sin.h"
#include "pride.h"
#include "rainbow_march.h"
#include "ripple.h"
#include "sinelon.h"
//#include "three_sin.h"
//#include "twinkle.h"
#include "two_sin.h"
#include "pacific_waves.h"

typedef void (*SimpleModeList[])();
SimpleModeList modes = {two_sin, 
						one_sin, 
						pacifica_loop, 
						rainbow_split, 
						fire_mirror_pal, 
						fireworks, 
						confetti, 
						colorwave, 
						sinelon, 
						fire_mirror, 
						juggle_pal, 
						juggle_pal_onedir, 
						pride, 
						fire, 
						rainbow_march
						};

uint8_t current_mode_number = 0;

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))


void setup() {
	delay(2000);
	//Serial.begin(57600);

	LEDS.setBrightness(max_bright);

	LEDS.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);

	//LEDS.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
	set_max_power_in_volts_and_milliamps(5, 3000);

	random16_set_seed(4832);
	random16_add_entropy(analogRead(2));

	//led_mode = EEPROM.read(STARTMODE);

	current_palette  = CRGBPalette16(CRGB::Black);
	target_palette   = g_gradient_palettes[random8(g_gradient_palette_count + 1)];
	current_blending = LINEARBLEND;

}


void loop() {
	random16_add_entropy(random());

	EVERY_N_MILLISECONDS(50) {
		nblendPaletteTowardPalette(current_palette, target_palette, 24); // maxChanges = 24
	}

	EVERY_N_SECONDS(25){
		if(use_palette){
			updatePaletteIndex(target_palette);
			palette_index = random8(g_gradient_palette_count);
			target_palette = g_gradient_palettes[palette_index]	;
		}
	}

	EVERY_N_SECONDS(120) {
		mode_change = 1;
		current_mode_number = random8(ARRAY_SIZE(modes));
	  //current_mode_number = (current_mode_number + 1) % ARRAY_SIZE(modes);
	}

	EVERY_N_MILLIS_I(this_timer, this_delay) {
		this_timer.setPeriod(this_delay);
		modes[current_mode_number]();
	}


	FastLED.show();

}
