#pragma once


void LtoR_CRGB(uint8_t pos, uint8_t r, uint8_t g, uint8_t b) {
	if (pos == 0) {
		for (int i = 0; i < 35; i++) {
			leds[leftArray[i]] = CRGB(r, g, b);
		}
	}
	else if (pos < 67) {
		leds[frontArray[66 - pos]] = CRGB(r, g, b);
		if (pos < 65 && pos > 3) {
			leds[backArray[pos - 4]] = CRGB(r, g, b);
		}
	}
	else if (pos == 67) {
		for (int i = 0; i < 35; i++) {
			leds[rightArray[i]] = CRGB(r, g, b);
		}
	}
}

void LtoR_CRGBadd(uint8_t pos, uint8_t r, uint8_t g, uint8_t b) {
	if (pos == 0) {
		for (int i = 0; i < 35; i++) {
			leds[leftArray[i]] += CRGB(r, g, b);
		}
	}
	else if (pos < 67) {
		leds[frontArray[66 - pos]] += CRGB(r, g, b);
		if (pos < 65 && pos > 3) {
			leds[backArray[pos - 4]] += CRGB(r, g, b);
		}
	}
	else if (pos == 67) {
		for (int i = 0; i < 35; i++) {
			leds[rightArray[i]] += CRGB(r, g, b);
		}
	}
}

void LtoR_CHSV(uint8_t pos, uint8_t h, uint8_t s, uint8_t v) {
	if (pos == 0) {
		for (int i = 0; i < 35; i++) {
			leds[leftArray[i]] = CHSV(h, s, v);
		}
	}
	else if (pos < 67) {
		leds[frontArray[66 - pos]] = CHSV(h, s, v);
		if (pos < 65 && pos > 3) {
			leds[backArray[pos - 4]] = CHSV(h, s, v);
		}
	}
	else if (pos == 67) {
		for (int i = 0; i < 35; i++) {
			leds[rightArray[i]] = CHSV(h, s, v);
		}
	}
}

void LtoR_CHSVadd(uint8_t pos, uint8_t h, uint8_t s, uint8_t v) {
	if (pos == 0) {
		for (int i = 0; i < 35; i++) {
			leds[leftArray[i]] += CHSV(h, s, v);
		}
	}
	else if (pos < 67) {
		leds[frontArray[66 - pos]] += CHSV(h, s, v);
		if (pos < 65 && pos > 3) {
			leds[backArray[pos - 4]] += CHSV(h, s, v);
		}
	}
	else if (pos == 67) {
		for (int i = 0; i < 35; i++) {
			leds[rightArray[i]] += CHSV(h, s, v);
		}
	}
}

void LtoR_Palette(uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri = this_bright, TBlendType blending = current_blending){
	if (pos == 0) {
		for (int i = 0; i < 35; i++) {
			leds[leftArray[i]] = ColorFromPalette(pal, index, bri, blending);
		}
	}
	else if (pos < 67) {
		leds[frontArray[66 - pos]] = ColorFromPalette(pal, index, bri, blending);
		if (pos < 65 && pos > 3) {
			leds[backArray[pos - 4]] = ColorFromPalette(pal, index, bri, blending);
		}
	}
	else if (pos == 67) {
		for (int i = 0; i < 35; i++) {
			leds[rightArray[i]] = ColorFromPalette(pal, index, bri, blending);
		}
	}
}

void LtoR_PaletteAdd(uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri = 255, TBlendType blending = LINEARBLEND) {
	if (pos == 0) {
		for (int i = 0; i < 35; i++) {
			leds[leftArray[i]] += ColorFromPalette(pal, index, bri, blending);
		}
	}
	else if (pos < 67) {
		leds[frontArray[66 - pos]] += ColorFromPalette(pal, index, bri, blending);
		if (pos < 65 && pos > 3) {
			leds[backArray[pos - 4]] += ColorFromPalette(pal, index, bri, blending);
		}
	}
	else if (pos == 67) {
		for (int i = 0; i < 35; i++) {
			leds[rightArray[i]] += ColorFromPalette(pal, index, bri, blending);
		}
	}
}