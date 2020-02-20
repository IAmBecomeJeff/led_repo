#ifndef WAVES_H
#define WAVES_H

void wave_init(LEDStruct& leds, uint8_t wb = random8(10,28), uint8_t ws = random8(0,8)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= WAVES;
	leds.use_palette		= 1;
	leds.delay_time			= 15;

	leds.wave_beat		= wb;
	leds.wave_speed		= ws;
}


void wave_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 0:		leds.wave_beat	= (uint8_t)update_arg;	break; //a
		case 1:		leds.wave_speed = (uint8_t)update_arg;	break; //b
		default: break;
	}
}

void waves(LEDStruct& leds) {

	for (uint8_t i = 0; i < ONE_SIDE; i++) {
		leds.wave_brightness = beatsin8(leds.wave_beat, 0, 255, 0, (i * 255) / (ONE_SIDE - 1));
		leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.wave_index + i, leds.wave_brightness, leds.current_blending);
	}
	leds.wave_index += leds.wave_speed;
	strip_sync(leds);

}



#endif