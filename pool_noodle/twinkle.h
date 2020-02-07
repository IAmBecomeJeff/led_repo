#ifndef TWINKLE_H
#define TWINKLE_H

void twinkle_init(LEDStruct& leds, bool ufr = random8(2), uint8_t ts = random8(3,6), uint8_t td = random8(3,7), bool cli = random8(2), bool asbg = random8(2)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= TWINKLE;
	leds.use_palette		= 1;
	leds.delay_time			= 15;

	leds.use_full_range		= ufr;
	if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
	else					 { leds.strip_range = ONE_SIDE; }

	leds.twinkle_speed			= ts;
	leds.twinkle_density		= td;
	leds.cool_like_incandescent = cli;
	leds.auto_select_bg_color	= asbg;
	
}


void twinkle_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 0:
			leds.use_full_range = (bool)update_arg; //a
			if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
			else					 { leds.strip_range = ONE_SIDE; }
			break;
		case 1: leds.twinkle_speed			= (uint8_t)update_arg;	break;	//b
		case 2: leds.twinkle_density		= (uint8_t)update_arg;	break;	//c
		case 3:	leds.cool_like_incandescent = (bool)update_arg;		break;	//d
		case 4: leds.auto_select_bg_color	= (bool)update_arg;		break;	//e

	}
	LEDDebug(leds);
}


uint8_t attackDecayWave8(uint8_t i)
{
	if (i < 86) {
		return i * 3;
	}
	else {
		i -= 86;
		return 255 - (i + (i / 2));
	}
}

void coolLikeIncandescent(CRGB& c, uint8_t phase)
{
	if (phase < 128) return;

	uint8_t cooling = (phase - 128) >> 4;
	c.g = qsub8(c.g, cooling);
	c.b = qsub8(c.b, cooling * 2);
}

CRGB computeOneTwinkle(LEDStruct& leds, uint32_t ms, uint8_t salt)
{
	uint16_t ticks = ms >> (8 - leds.twinkle_speed);
	uint8_t fastcycle8 = ticks;
	uint16_t slowcycle16 = (ticks >> 8) + salt;
	slowcycle16 += sin8(slowcycle16);
	slowcycle16 = (slowcycle16 * 2053) + 1384;
	uint8_t slowcycle8 = (slowcycle16 & 0xFF) + (slowcycle16 >> 8);

	uint8_t bright = 0;
	if (((slowcycle8 & 0x0E) / 2) < leds.twinkle_density) {
		bright = attackDecayWave8(fastcycle8);
	}

	uint8_t hue = slowcycle8 - salt;
	CRGB c;
	if (bright > 0) {
		c = ColorFromPalette(leds.current_palette, hue, bright, NOBLEND);
		if (leds.cool_like_incandescent == 1) {
			coolLikeIncandescent(c, fastcycle8);
		}
	}
	else {
		c = CRGB::Black;
	}
	return c;
}



void twinkle(LEDStruct& leds) {
	if (!leds.mode_initialized) { twinkle_init(leds); }
	if (keyboard_update) { twinkle_update(leds); }

	uint16_t PRNG16 = 11338;

	uint32_t clock32 = millis();

	CRGB bg;

	if ((leds.auto_select_bg_color == 1) && (leds.current_palette[0] == leds.current_palette[1])) {
		bg = leds.current_palette[0];
		uint8_t bglight = bg.getAverageLight();
		if (bglight > 64) {
			bg.nscale8_video(16);
		}
		else if (bglight > 16) {
			bg.nscale8_video(64);
		}
		else {
			bg.nscale8_video(86);
		}
	}
	else {
		bg = CRGB::Black;
	}
	uint8_t bg_bri = bg.getAverageLight();

	for (uint16_t i = 0; i < leds.strip_range; i++) {
		PRNG16 = (uint16_t)(PRNG16 * 2053) + 1384;
		uint16_t myclockoffset16 = PRNG16;
		PRNG16 = (uint16_t)(PRNG16 * 2053) + 1384;
		uint8_t myspeedmultiplierQ5_3 = ((((PRNG16 & 0xFF) >> 4) + (PRNG16 & 0x0F)) & 0x0F) + 0x08;
		uint32_t myclock30 = (uint32_t)((clock32 * myspeedmultiplierQ5_3) >> 3) + myclockoffset16;
		uint8_t myunique8 = PRNG16 >> 8;

		CRGB c = computeOneTwinkle(leds, myclock30, myunique8);

		uint8_t cbright = c.getAverageLight();
		int16_t deltabright = cbright - bg_bri;
		if (deltabright >= 32 || (!bg)) {
			leds.led_data[i] = c;
		}
		else if (deltabright > 0) {
			leds.led_data[i] = blend(bg, c, deltabright * 8);
		}
		else {
			leds.led_data[i] = bg;
		}
	}

	if (!leds.use_full_range) { strip_sync(leds); }
}



#endif