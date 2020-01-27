#ifndef CONFETTI_H
#define CONFETTI_H

void confetti_init(LEDStruct& leds, uint8_t cf = random8(10,48)) {
	leds.mode_initialized = 1;
	leds.mode_type = CONFETTI;
	leds.use_palette = 1;

	leds.confetti_fade = cf;
}

void confetti(LEDStruct& leds)
{
	if (!leds.mode_initialized) { confetti_init(leds); }

	fadeToBlackBy(leds.led_data, NUM_LEDS, leds.confetti_fade);
	int pos = random16(NUM_LEDS);
	leds.led_data[pos] += ColorFromPalette(leds.current_palette, random8());
}

#endif