#ifndef PRIDE_H
#define PRIDE_H

void pride_init(LEDStruct& leds, bool ufr = random8(2)) {
	leds.mode_initialized = 1;
	leds.mode_type = PRIDE;
	leds.use_palette = 0;
	leds.use_full_range = ufr;
	if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
	else { leds.strip_range = ONE_SIDE; }
}

// This function draws rainbows with an ever-changing,
// widely-varying set of parameters.
void pride(LEDStruct& leds) {
	if (!leds.mode_initialized) { pride_init(leds); }

	leds.sat8 = beatsin88(87, 220, 250);
	leds.brightdepth = beatsin88(341, 96, 224);
	leds.brightnessthetainc16 = beatsin88(203, (25 * 256), (40 * 256));
	leds.msmultiplier = beatsin88(147, 23, 60);

	leds.hue16 = leds.sHue16;//gHue * 256;
	leds.hueinc16 = beatsin88(113, 1, 3000);

	leds.ms = millis();
	leds.deltams = leds.ms - leds.sLastMillis;
	leds.sLastMillis = leds.ms;
	leds.sPseudotime += leds.deltams * leds.msmultiplier;
	leds.sHue16 += leds.deltams * beatsin88(400, 5, 9);
	leds.brightnesstheta16 = leds.sPseudotime;

	for (uint16_t i = 0; i < leds.strip_range; i++) {
		leds.hue16 += leds.hueinc16;
		leds.hue8 = leds.hue16 / 256;

		leds.brightnesstheta16 += leds.brightnessthetainc16;
		leds.b16 = sin16(leds.brightnesstheta16) + 32768;

		leds.bri16 = (uint32_t)((uint32_t)leds.b16 * (uint32_t)leds.b16) / 65536;
		leds.bri8 = (uint32_t)(((uint32_t)leds.bri16) * leds.brightdepth) / 65536;
		leds.bri8 += (255 - leds.brightdepth);

		CRGB newcolor = CHSV(leds.hue8, leds.sat8, leds.bri8);

		leds.pixelnumber = i;
		leds.pixelnumber = (leds.strip_range - 1) - leds.pixelnumber;
		nblend( leds.led_data[leds.pixelnumber], newcolor, 64);
	}
}
#endif
