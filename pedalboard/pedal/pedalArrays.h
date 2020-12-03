#pragma once


void LtoR_CRGB(uint8_t pos, uint8_t r, uint8_t g, uint8_t b) {
	if (pos == 0) {
		for (int i = 0; i < 35; i++) {
			leds[leftArray[i]] = CRGB(r, g, b);
		}
	}
	else if (pos < 67) {
		leds[frontArray[66 - pos]] = CRGB(r, g, b);
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
	}
	else if (pos == 67) {
		for (int i = 0; i < 35; i++) {
			leds[rightArray[i]] += CHSV(h, s, v);
		}
	}
}

void LtoR_Palette(uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri = 255, TBlendType blending = LINEARBLEND){
	if (pos == 0) {
		for (int i = 0; i < 35; i++) {
			leds[leftArray[i]] = ColorFromPalette(pal, index, bri, blending);
		}
	}
	else if (pos < 67) {
		leds[frontArray[66 - pos]] = ColorFromPalette(pal, index, bri, blending);
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
	}
	else if (pos == 67) {
		for (int i = 0; i < 35; i++) {
			leds[rightArray[i]] += ColorFromPalette(pal, index, bri, blending);
		}
	}
}

void fromCenterPal(uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri=255, TBlendType blending = currentBlending) {
	for (int i = 0; i < 33; i++) {
		leds[frontArray[32 - i]] = ColorFromPalette(pal, index, bri, blending);
		leds[frontArray[33 + i]] = ColorFromPalette(pal, index, bri, blending);
	}
	for (int i = 33; i < 68; i++) {
		leds[leftArray[i-33]] = ColorFromPalette(pal, index, bri, blending);
		leds[rightArray[67-i]] = ColorFromPalette(pal, index, bri, blending);
	}
}

void fromCenterPalAdd(uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri = 255, TBlendType blending = currentBlending) {
	for (int i = 0; i < 33; i++) {
		leds[frontArray[32 - i]] += ColorFromPalette(pal, index, bri, blending);
		leds[frontArray[33 + i]] += ColorFromPalette(pal, index, bri, blending);
	}
	for (int i = 33; i < 68; i++) {
		leds[leftArray[i - 33]] += ColorFromPalette(pal, index, bri, blending);
		leds[rightArray[67 - i]] += ColorFromPalette(pal, index, bri, blending);
	}
}

void fromCenterCRGB(uint8_t pos, uint8_t r, uint8_t g, uint8_t b) {
	for (int i = 0; i < 33; i++) {
		leds[frontArray[32 - i]] = CRGB(r, g, b);
		leds[frontArray[33 + i]] = CRGB(r, g, b);
	}
	for (int i = 33; i < 68; i++) {
		leds[leftArray[i - 33]] = CRGB(r, g, b);
		leds[rightArray[67 - i]] = CRGB(r, g, b);
	}
}

void fromCenterCRGBadd(uint8_t pos, uint8_t r, uint8_t g, uint8_t b) {
	for (int i = 0; i < 33; i++) {
		leds[frontArray[32 - i]] += CRGB(r, g, b);
		leds[frontArray[33 + i]] += CRGB(r, g, b);
	}
	for (int i = 33; i < 68; i++) {
		leds[leftArray[i - 33]] += CRGB(r, g, b);
		leds[rightArray[67 - i]] += CRGB(r, g, b);
	}
}

void fromCenterCHSV(uint8_t pos, uint8_t h, uint8_t s, uint8_t v) {
	for (int i = 0; i < 33; i++) {
		leds[frontArray[32 - i]] = CHSV(h, s, v);
		leds[frontArray[33 + i]] = CHSV(h, s, v);
	}
	for (int i = 33; i < 68; i++) {
		leds[leftArray[i - 33]] = CHSV(h, s, v);
		leds[rightArray[67 - i]] = CHSV(h, s, v);
	}
}

void fromCenterCHSVadd(uint8_t pos, uint8_t h, uint8_t s, uint8_t v) {
	for (int i = 0; i < 33; i++) {
		leds[frontArray[32 - i]] += CHSV(h, s, v);
		leds[frontArray[33 + i]] += CHSV(h, s, v);
	}
	for (int i = 33; i < 68; i++) {
		leds[leftArray[i - 33]] += CHSV(h, s, v);
		leds[rightArray[67 - i]] += CHSV(h, s, v);
	}
}