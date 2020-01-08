#include "FastLED.h"
#include "palettes.h"
#include "variables.h"
#include "juggle.h"
#include "colorwave.h"
#include "confetti.h"
#include "fire.h"
#include "pride.h"
#include "rainbow_march.h"
#include "sinelon.h"
#include "full_shelves.h"


#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif


typedef void (*SimpleModeList[])();
SimpleModeList modes = { full_shelves, full_shelves_fading, rainbow_split, fire_mirror_pal, confetti, colorwave, sinelon, fire_mirror, juggle_pal, juggle_pal_onedir, pride, fire, rainbow_march, sinelon_squiggle };

uint8_t current_mode_number = 0;

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))


void setup() {
  delay(2000); // 2 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip) // cpt-city palettes have different color balance
    .setDither(BRIGHTNESS < 255);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  shelf_array_setup();

  set_max_power_in_volts_and_milliamps(5, 3000);

  random16_set_seed(4832);
  random16_add_entropy(analogRead(2));

  //led_mode = EEPROM.read(STARTMODE);

  current_palette = CRGBPalette16(CRGB::Black);
  target_palette = g_gradient_palettes[random8(g_gradient_palette_count + 1)];
  current_blending = LINEARBLEND;
}




void loop()
{
  // Blend Palettes
  EVERY_N_MILLISECONDS(50) {
    nblendPaletteTowardPalette( current_palette, target_palette, 24);
  }

  // Change current palette
  EVERY_N_SECONDS(25) {
	  if (use_palette) {
		  updatePaletteIndex(target_palette);
		  palette_index = random8(g_gradient_palette_count);
		  target_palette = g_gradient_palettes[palette_index];
	  }
  }

  // Change mode 
  EVERY_N_SECONDS(20) {
	  mode_change = 1;
	  //current_mode_number = random8(ARRAY_SIZE(modes));
	  current_mode_number = (current_mode_number + 1) % ARRAY_SIZE(modes);
  }

  // Send values to LEDs
  EVERY_N_MILLIS_I(this_timer, this_delay) {
	  this_timer.setPeriod(this_delay);
	  modes[current_mode_number]();
  }

  // Show LEDs
  FastLED.show();
}
