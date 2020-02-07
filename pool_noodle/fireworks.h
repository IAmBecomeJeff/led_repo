#ifndef FIREWORKS_H
#define FIREWORKS_H

void fireworks_init(LEDStruct& leds, bool uo = random8(2)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= FIREWORKS;
	leds.use_palette		= 0;
	leds.delay_time			= 15;

	leds.current_stage		= WAITING;

	leds.use_overlay		= uo;
	if (leds.use_overlay) { if (!overlay_in_use) { over_leds.current_stage = WAITING; } }
}

void fireworks_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 0:	leds.use_overlay = (bool)update_arg;	break; //a
		default:	break;
	}
	LEDDebug(leds);
}

void prepare_for_explosion(LEDStruct& leds) {
	random16_add_entropy(analogRead(2));
	leds.firework_position = random8(ONE_SIDE / 2 - 10, ONE_SIDE / 2 + 10);
	leds.current_stage = FADEUP;
	leds.firework_hue = random8();
	leds.firework_bri = 0;
	leds.exploded = false;
	fill_solid(leds.led_data, NUM_LEDS, CRGB::Black);
}

void fadeup(LEDStruct& leds) {
	if (leds.exploded) {
		leds.current_stage = EXPLOSION;
		leds.number_of_sparks = random8(MIN_NUMBER_OF_SPARKS, MAX_NUMBER_OF_SPARKS + 1);
		for (uint8_t i = 0; i < leds.number_of_sparks; i++) {
			leds.spark_pos[i] = (float)leds.firework_position;
			leds.spark_vel[i] = (float)(random16(10, 125)) / 100;
			leds.spark_dir[i] = random8(0, 2);
			leds.spark_fade[i] = random8(10, 15);
			leds.spark_bri[i] = 255;
		}
		leds.led_data[leds.firework_position]				 = CRGB::White;
		leds.led_data[NUM_LEDS - 1 - leds.firework_position] = CRGB::White;
	}
	else {
		leds.firework_bri += 5;
		leds.led_data[leds.firework_position]				 = CHSV(leds.firework_hue, 255, leds.firework_bri);
		leds.led_data[NUM_LEDS - 1 - leds.firework_position] = CHSV(leds.firework_hue, 255, leds.firework_bri);
		if (leds.firework_bri >= 255) {
			leds.exploded = true;
		}
	}
}

void explosion(LEDStruct& leds) {
	fadeToBlackBy(leds.led_data, NUM_LEDS, firework_bg_fade);
	leds.brightest_spark = 0;
	for (uint8_t x = 0; x < leds.number_of_sparks; x++) {
		leds.led_data[(int)leds.spark_pos[x]] += CHSV(leds.firework_hue, 255, (uint8_t)leds.spark_bri[x]);

		if (leds.spark_dir[x]) { leds.spark_pos[x] += leds.spark_vel[x]; }
		else { leds.spark_pos[x] -= leds.spark_vel[x]; }

		leds.spark_pos[x] = constrain(leds.spark_pos[x], 0.0, (float)(ONE_SIDE - 1));
		leds.spark_vel[x] *= gravity;
		leds.spark_bri[x] *= (1 - (leds.spark_fade[x] / 256));
		if ((uint8_t)leds.spark_bri[x] > leds.brightest_spark) { leds.brightest_spark = (uint8_t)leds.spark_bri[x]; }
	}
	strip_sync(leds);
	if (leds.brightest_spark == 0 ) {
		fill_solid(leds.led_data, NUM_LEDS, CRGB::Black);
		leds.current_stage = WAITING;
		leds.next_explosion_time = millis() + random16(min_wait + max_wait);
	}
}


void fireworks_render(LEDStruct& leds) {
	switch (leds.current_stage) {
		case WAITING:
			fill_solid(leds.led_data, NUM_LEDS, CRGB::Black);
			if (millis() >= leds.next_explosion_time) {
				prepare_for_explosion(leds);
			}
			break;

		case FADEUP:
			fadeup(leds);
			break;

		case EXPLOSION:
			explosion(leds);
			break;
	}
}

void fireworks(LEDStruct& leds) {
	if (!leds.mode_initialized) { fireworks_init(leds); }
	if (keyboard_update) { fireworks_update(leds); }

	fireworks_render(leds);

	overlay_in_use = 0;
	if (leds.use_overlay) {
		overlay_in_use = 1;
		fireworks_render(over_leds);
		for (uint16_t i = 0; i < NUM_LEDS; i++) {
			leds.led_data[i] += over_leds.led_data[i];
		}
	}

}
#endif
