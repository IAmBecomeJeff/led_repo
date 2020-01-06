#ifndef FIREWORKS_H
#define FIREWORKS_H




void fireworks_start(bool old) {
	if (old) {
		old_gravs[0].dist_old = 0;
		old_gravs[0].distance = 0;
		old_gravs[0].vel_old = streamer_velocity;
		old_gravs[0].velocity = streamer_velocity;
		old_gravs[0].fireworks_hue = random8();
		old_gravs[0].fireworks_sat = 50;
		old_gravs[0].fireworks_bri = 128;
		old_fireworks_state = 1;
	}
	else {
		my_gravs[0].dist_old = 0;
		my_gravs[0].distance = 0;
		my_gravs[0].vel_old = streamer_velocity;
		my_gravs[0].velocity = streamer_velocity;
		my_gravs[0].fireworks_hue = random8();
		my_gravs[0].fireworks_sat = 50;
		my_gravs[0].fireworks_bri = 128;
		fireworks_state = 1;
	}
}

void fireworks_up(bool old) {
	if (old) {
		old_gravs[0].velocity = old_gravs[0].vel_old + gravity * time_inc;
		old_gravs[0].distance = old_gravs[0].dist_old + old_gravs[0].velocity * time_inc;

		int i = map(old_gravs[0].distance, 0, 32767, 0, STRIP_LENGTH);

		old_gravs[0].vel_old = old_gravs[0].velocity;
		old_gravs[0].dist_old = old_gravs[0].distance;

		if (i < STRIP_LENGTH) ringCHSV(1, i, old_gravs[0].fireworks_hue, old_gravs[0].fireworks_sat, old_gravs[0].fireworks_bri);
		if (old_gravs[0].vel_old <= 0) old_fireworks_state = 2;

		for (int j = 0; j < STRIP_LENGTH; j++) old_leds[j].fadeToBlackBy(old_this_fade);

		if (i > 3) {
			if (random8() > 220) {
				ringCHSV(1, i - 3, old_gravs[0].fireworks_hue, random8(100, 200), old_gravs[0].fireworks_bri);
			}
		}
	}
	else {
		my_gravs[0].velocity = my_gravs[0].vel_old + gravity * time_inc;
		my_gravs[0].distance = my_gravs[0].dist_old + my_gravs[0].velocity * time_inc;

		int i = map(my_gravs[0].distance, 0, 32767, 0, STRIP_LENGTH);

		my_gravs[0].vel_old = my_gravs[0].velocity;
		my_gravs[0].dist_old = my_gravs[0].distance;

		if (i < STRIP_LENGTH) ringCHSV(0, i, my_gravs[0].fireworks_hue, my_gravs[0].fireworks_sat, my_gravs[0].fireworks_bri);
		if (my_gravs[0].vel_old <= 0) fireworks_state = 2;

		for (int j = 0; j < STRIP_LENGTH; j++) cur_leds[j].fadeToBlackBy(this_fade);

		if (i > 3) {
			if (random8() > 220) {
				ringCHSV(0, i - 3, my_gravs[0].fireworks_hue, random8(100, 200), my_gravs[0].fireworks_bri);
			}
		}
	}
}

void fireworks_explode_init(bool old) {
	if (old) {
		for (int k = 1; k < num_gravs; k++) {
			old_gravs[k].dist_old = old_gravs[0].distance;
			old_gravs[k].distance = old_gravs[0].distance;
			old_gravs[k].vel_old = random16(-50, explosion_velocity);
			old_gravs[k].velocity = old_gravs[k].vel_old;
			old_gravs[k].fireworks_hue = random8();
			old_gravs[k].fireworks_sat = 255;
			old_gravs[k].fireworks_bri = 255;
		}
		old_my_count = 0;
		old_fireworks_state = 3;
	}
	else {
		for (int k = 1; k < num_gravs; k++) {
			my_gravs[k].dist_old = my_gravs[0].distance;
			my_gravs[k].distance = my_gravs[0].distance;
			my_gravs[k].vel_old = random16(-50, explosion_velocity);
			my_gravs[k].velocity = my_gravs[k].vel_old;
			my_gravs[k].fireworks_hue = random8();
			my_gravs[k].fireworks_sat = 255;
			my_gravs[k].fireworks_bri = 255;
		}
		my_count = 0;
		fireworks_state = 3;
	}
}


void fireworks_explode(bool old) {
	if (old) {
		if (old_my_count++ >= max_count) old_fireworks_state = 0;

		for (int k = 1; k < num_gravs; k++) {
			old_gravs[k].velocity = old_gravs[k].vel_old + gravity * time_inc;
			old_gravs[k].distance = old_gravs[k].dist_old + old_gravs[k].velocity * time_inc;

			int i = map(old_gravs[k].distance, 0, 32767, 0, STRIP_LENGTH);
			old_gravs[k].vel_old = old_gravs[k].velocity;
			old_gravs[k].dist_old = old_gravs[k].distance;

			if (old_gravs[k].distance < 0) { old_gravs[k].fireworks_bri = 0; }
			if (i < STRIP_LENGTH && i >= 0) ringCHSVAdd(1, i, old_gravs[k].fireworks_hue, 255, 255);
		}
		for (int j = 0; j < NUM_LEDS; j++) old_leds[j].fadeToBlackBy(old_this_fade);
	}
	else {
		if (my_count++ >= max_count) fireworks_state = 0;

		for (int k = 1; k < num_gravs; k++) {
			my_gravs[k].velocity = my_gravs[k].vel_old + gravity * time_inc;
			my_gravs[k].distance = my_gravs[k].dist_old + my_gravs[k].velocity * time_inc;

			int i = map(my_gravs[k].distance, 0, 32767, 0, STRIP_LENGTH);
			my_gravs[k].vel_old = my_gravs[k].velocity;
			my_gravs[k].dist_old = my_gravs[k].distance;

			if (my_gravs[k].distance < 0) { my_gravs[k].fireworks_bri = 0; }
			if (i < STRIP_LENGTH && i >= 0) ringCHSVAdd(0, i, my_gravs[k].fireworks_hue, 255, 255);
		}
		for (int j = 0; j < NUM_LEDS; j++) cur_leds[j].fadeToBlackBy(this_fade);
	}
}

void fireworks(bool old) {
  mode_number = 65;
  switch (fireworks_state) {
  case 0: fireworks_start(old); break;
  case 1: fireworks_up(old); break;
  case 2: fireworks_explode_init(old); break;
  case 3: fireworks_explode(old); break;
  default: break;
  }
}

#endif
