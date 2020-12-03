
void fire() {
	random16_add_entropy(random8());

	static byte heat[MAX_LEDS];

	for(int i = 0; i < MAX_LEDS; i++) {
		heat[i] = qsub8(heat[i], random8(0, ((COOLING * 10) / MAX_LEDS) + 2));
	}

	for (int k = MAX_LEDS - 1; k >= 2; k--) {
		heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
	}

	if (random8() < SPARKING) {
		int y = random8(7);
		heat[y] = qadd8(heat[y], random8(160, 255));
	}

	for (int j = 0; j < MAX_LEDS; j++) {
		byte colorindex = scale8(heat[j], 240);
		CRGB color = ColorFromPalette(fire_palette, colorindex);
		int pixelnumber;
		leds[pixelnumber] = color;
	}
}


void fire_center() {
	random16_add_entropy(random8());

	static byte heat_center[STRAND_LENGTH];

	for (int i = 0; i < STRAND_LENGTH; i++) {
		heat_center[i] = qsub8(heat_center[i], random8(0, ((COOLING * 10) / 98) + 2));
	}

	for (int k = STRAND_LENGTH - 1; k >= 2; k--) {
		heat_center[k] = (heat_center[k - 1] + heat_center[k - 2] + heat_center[k - 2]) / 3;
	}

	if (random8() < SPARKING) {
		int y = random8(7);
		heat_center[y] = qadd8(heat_center[y], random8(160, 255));
	}

	for (int j = 0; j < STRAND_LENGTH; j++) {
		byte firecolorindex = scale8(heat_center[j], 240);
		CRGB firecolor = ColorFromPalette(currentPalette, firecolorindex);
		int pixelnumber = j;
		leds[rightFromCenter[pixelnumber]] = firecolor;
		leds[leftFromCenter[pixelnumber]] = firecolor;
	}
}
