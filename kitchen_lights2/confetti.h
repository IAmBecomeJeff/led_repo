#ifndef CONFETTI_H
#define CONFETTI_H

void confetti_init(LEDStruct& leds, uint8_t cf = random8(6,21)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= CONFETTI;
	leds.use_palette		= 1;
	leds.delay_time			= 15;
	leds.confetti_fade		= cf;
}

void confetti_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 1:	leds.confetti_fade = (uint8_t)update_arg;	break; //b
		default: break;
	}
	LEDDebug(leds);
}

void confetti(LEDStruct& leds)
{
	if (!leds.mode_initialized) { confetti_init(leds); }
	if (keyboard_update) { confetti_update(leds); }

	fadeToBlackBy(leds.led_data, NUM_LEDS, leds.confetti_fade);
	int pos = random16(NUM_LEDS);
	leds.led_data[pos] += ColorFromPalette(leds.current_palette, random8());
}

#endif