#ifndef COLORWAVE_H
#define COLORWAVE_H

// This function draws color waves with an ever-changing,
// widely-varying set of parameters, using a color palette.
//
//	colorwave()
//
//	Variables
//		led.target_palette

void colorwave() {
	if (mode_change) {
		use_palette = 1;
		mode_change = 0;
    this_delay = 10;
	}
	//uint8_t sat8 = beatsin88(87, 220, 250);
	brightdepth = beatsin88(341, 96, 224);
	brightnessthetainc16 = beatsin88(203, (25 * 256), (40 * 256));
	msmultiplier = beatsin88(147, 23, 60);

	hue16 = sHue16;//gHue * 256;
	hueinc16 = beatsin88(113, 300, 1500);

	ms = millis();
	deltams = ms - sLastMillis;
	sLastMillis = ms;
	sPseudotime += deltams * msmultiplier;
	sHue16 += deltams * beatsin88(400, 5, 9);
	brightnesstheta16 = sPseudotime;

	for (uint16_t i = 0; i < NUM_LEDS; i++) {
		for (byte c = 0; c < 4; c++) {
			hue16 += hueinc16;
			hue8 = hue16 / 256;
			h16_128 = hue16 >> 7;
			if (h16_128 & 0x100) {
				hue8 = 255 - (h16_128 >> 1);
			}
			else {
				hue8 = h16_128 >> 1;
			}

			brightnesstheta16 += brightnessthetainc16;
			b16 = sin16(brightnesstheta16) + 32768;

			bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
			bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
			bri8 += (255 - brightdepth);

			cwave_index = hue8;
			//index = triwave8( index);
			cwave_index = scale8(cwave_index, 240);

			CRGB newcolor = ColorFromPalette(current_palette, cwave_index, bri8);

			pixelnumber = i;
			pixelnumber = (NUM_LEDS - 1) - pixelnumber;

			nblend(leds[pixelnumber], newcolor, 128);
		}
	}
}

#endif
