#ifndef CYLON_H
#define CYLON_H

/*  int cylon_step
	int cylon_center
	uint8_t cylon_index
	uint8_t cylon_brightness = 255
	*/

void cylon(bool old) {
	mode_number = 57;
	if (old) {
		ringPaletteAdd(1, old_cylon_center, current_palette, old_cylon_index, old_cylon_brightness, current_blending);
		for (uint8_t i = 0; i < 15; i++) {
			if (old_cylon_center - 7 + i >= 0 && old_cylon_center - 7 + i < STRIP_LENGTH) {
				ringPaletteAdd(1, old_cylon_center - 7 + i, current_palette, old_cylon_index, old_cylon_brightness - i * 43, current_blending);
			}
		}

		switch (old_cylon_step) {
		case -1:
			old_cylon_center--;
			if (old_cylon_center < -14) { old_cylon_step = 1; }
			break;

		case 1:
			old_cylon_center++;
			if (old_cylon_center > STRIP_LENGTH + 14) { old_cylon_step = -1; old_cylon_index = random8(); }
			break;
		}
	}
	else {
		for (uint8_t i = 0; i < 15; i++) {
			if (cylon_center - 7 + i >= 0 && cylon_center - 7 + i < STRIP_LENGTH) {
				ringPaletteAdd(0, cylon_center - 7 + i, current_palette, cylon_index, cylon_brightness - i * 43, current_blending);
			}
		}

		switch (cylon_step) {
		case -1:
			cylon_center--;
			if (cylon_center < -14) { cylon_step = 1; }
			break;

		case 1:
			cylon_center++;
			if (cylon_center > STRIP_LENGTH + 14) { cylon_step = -1; cylon_index = random8(); }
			break;
		}
	}
}











#endif
