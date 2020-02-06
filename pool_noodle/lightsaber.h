#ifndef LIGHTSABER_H
#define LIGHTSABER_H

void lightsaber_init(LEDStruct& leds, bool up = random8(2), uint8_t bc = random8(), uint8_t db = random8(4,32), uint16_t ht = random16(2000,8001)) {
	leds.mode_initialized	= 1;
	leds.use_palette		= up;
	leds.mode_type			= LIGHTSABER;
	leds.use_full_range		= 0;
	leds.delay_time			= 10;

	leds.saber_stage		= UP;
	leds.blade_color		= bc;
	leds.delta_bright		= db;
	leds.hold_time			= ht;
	leds.tip_pos			= 0;
	leds.ls_val				= 0;

}


void lightsaber_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 0:		leds.use_palette	= (bool)update_arg;		break; //a
		case 1:		leds.blade_color	= (uint8_t)update_arg;	break; //b
		case 2:		leds.delta_bright	= (uint8_t)update_arg;	break; //c
		case 3:		leds.hold_time		= (uint16_t)update_arg;	break; //d
		default:	break;
	}
}


void lightsaber(LEDStruct& leds) {
	if (!leds.mode_initialized) { lightsaber_init(leds); }
	if (keyboard_update) { lightsaber_update(leds); }

	switch (leds.saber_stage) {
		case UP:
			if (leds.ls_val + leds.delta_bright >= 255 - leds.delta_bright) {
				if (leds.use_palette) { leds.led_data[leds.tip_pos] = ColorFromPalette(leds.current_palette, leds.tip_pos * 255 / ONE_SIDE, 255, leds.current_blending); }
				else { leds.led_data[leds.tip_pos] = CHSV(leds.blade_color, 255, 255); }
				leds.ls_val = 0;
				if (leds.tip_pos < ONE_SIDE - 1) { leds.tip_pos++; }
				else { 
					leds.saber_stage = WAIT; 
					leds.ls_begin = millis();
					leds.ls_end = leds.ls_begin + leds.hold_time;
				}
			}
			else {
				leds.ls_val += leds.delta_bright;
				if (leds.use_palette) { leds.led_data[leds.tip_pos] = ColorFromPalette(leds.current_palette, leds.tip_pos * 255 / ONE_SIDE, leds.ls_val, leds.current_blending); }
				else { leds.led_data[leds.tip_pos] = CHSV(leds.blade_color, 255, leds.ls_val); }
			}
			break;

		case WAIT:
			if (millis() > leds.ls_end&& leds.tip_pos == ONE_SIDE) { leds.saber_stage = DOWN; leds.ls_val = 255; }
			if (millis() > leds.ls_end&& leds.tip_pos == 0) { leds.saber_stage = UP; leds.ls_val = 0; }
			break;

		case DOWN:
			if (leds.ls_val - leds.delta_bright <= leds.delta_bright) {
				if (leds.use_palette) { leds.led_data[leds.tip_pos] = ColorFromPalette(leds.current_palette, leds.tip_pos * 255 / ONE_SIDE, 255, leds.current_blending); }
				else { leds.led_data[leds.tip_pos] = CHSV(leds.blade_color, 255, 0); }
				leds.ls_val = 255;
				if (leds.tip_pos > 0) { leds.tip_pos--; }
				else {
					leds.saber_stage = WAIT;
					leds.ls_begin = millis();
					leds.ls_end = leds.ls_begin + leds.hold_time / 2;
				}
			}
			else {
				leds.ls_val -= leds.delta_bright;
				if (leds.use_palette) { leds.led_data[leds.tip_pos] = ColorFromPalette(leds.current_palette, leds.tip_pos * 255 / ONE_SIDE, leds.ls_val, leds.current_blending); }
				else { leds.led_data[leds.tip_pos] = CHSV(leds.blade_color, 255, leds.ls_val); }
			}
			break;
	}
	strip_sync(leds);
}


#endif