#ifndef COLORWAVE_H
#define COLORWAVE_H

void colorwave_init(LEDStruct& leds, bool ufr = random8(2)) {
	leds.mode_initialized = 1;
	leds.use_palette = 1;
	leds.mode_type = COLORWAVE;

	leds.use_full_range = ufr;
	if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
	else					 { leds.strip_range = ONE_SIDE; }
}


void colorwave(LEDStruct& leds) {
	if (!leds.mode_initialized) { colorwave_init(leds); }

	//uint8_t sat8 = beatsin88(87, 220, 250);
	leds.brightdepth = beatsin88(341, 96, 224);
	leds.brightnessthetainc16 = beatsin88(203, (25 * 256), (40 * 256));
	leds.msmultiplier = beatsin88(147, 23, 60);

	leds.hue16 = leds.sHue16;//gHue * 256;
	leds.hueinc16 = beatsin88(113, 300, 1500);

	leds.ms = millis();
	leds.deltams = leds.ms - leds.sLastMillis;
	leds.sLastMillis = leds.ms;
	leds.sPseudotime += leds.deltams * leds.msmultiplier;
	leds.sHue16 += leds.deltams * beatsin88(400, 5, 9);
	leds.brightnesstheta16 = leds.sPseudotime;

	for (uint16_t i = 0; i < leds.strip_range; i++) {
		for (byte c = 0; c < 4; c++) {
			leds.hue16 += leds.hueinc16;
			leds.hue8 = leds.hue16 / 256;
			leds.h16_128 = leds.hue16 >> 7;
			if (leds.h16_128 & 0x100) {
				leds.hue8 = 255 - (leds.h16_128 >> 1);
			}
			else {
				leds.hue8 = leds.h16_128 >> 1;
			}

			leds.brightnesstheta16 += leds.brightnessthetainc16;
			leds.b16 = sin16(leds.brightnesstheta16) + 32768;

			leds.bri16 = (uint32_t)((uint32_t)leds.b16 * (uint32_t)leds.b16) / 65536;
			leds.bri8 = (uint32_t)(((uint32_t)leds.bri16) * leds.brightdepth) / 65536;
			leds.bri8 += (255 - leds.brightdepth);

			leds.cwave_index = leds.hue8;
			//index = triwave8( index);
			leds.cwave_index = scale8(leds.cwave_index, 240);

			CRGB newcolor = ColorFromPalette(leds.current_palette, leds.cwave_index, leds.bri8);

			leds.pixelnumber = i;
			leds.pixelnumber = (leds.strip_range - 1) - leds.pixelnumber;

			nblend(leds.led_data[leds.pixelnumber], newcolor, 128);
		}
	}
	if (!leds.use_full_range) { strip_sync(leds); }
}

#endif
