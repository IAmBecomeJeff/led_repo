#ifndef FIREWORKS_H
#define FIREWORKS_H

#define MAX_NUMBER_OF_SPARKS 60
#define MIN_NUMBER_OF_SPARKS 20

enum stage { FADEUP, EXPLOSION, WAITING };
uint8_t firework_position;
uint8_t firework_hue;
uint8_t firework_bri;
stage current_stage;
uint16_t max_wait = 2000;
uint16_t min_wait = 500;
uint32_t next_explosion_time;
bool exploded;
float gravity = 0.97;
uint8_t number_of_sparks;
float spark_pos[MAX_NUMBER_OF_SPARKS];
float spark_vel[MAX_NUMBER_OF_SPARKS];
bool spark_dir[MAX_NUMBER_OF_SPARKS];
float spark_fade[MAX_NUMBER_OF_SPARKS];
uint8_t firework_bg_fade = 128;
float spark_bri[MAX_NUMBER_OF_SPARKS];
uint8_t brightest_spark;

void prepare_for_explosion() {
	random16_add_entropy(analogRead(2));
	firework_position = random8(20,NUM_LEDS - 10);
	current_stage = FADEUP;
	firework_hue = random8();
	firework_bri = 0;
	exploded = false;
	fill_solid(leds, NUM_LEDS, CRGB::Black);
}

void fadeup() {
	if (exploded) {
		current_stage = EXPLOSION;
		number_of_sparks = random8(MIN_NUMBER_OF_SPARKS, MAX_NUMBER_OF_SPARKS + 1);
		for (uint8_t i = 0; i < number_of_sparks; i++) {
			spark_pos[i] = (float)firework_position;
			spark_vel[i] = (float)(random16(10, 125)) / 100;
			spark_dir[i] = random8(0, 2);
			spark_fade[i] = random8(5, 15);
			spark_bri[i] = 255;
		}
		leds[firework_position] = CRGB::White;
	}
	else {
		firework_bri += 5;
		leds[firework_position] = CHSV(firework_hue, 255, firework_bri);
		if (firework_bri >= 255) {
			exploded = true;
		}
	}
}

void explosion() {
	fadeToBlackBy(leds, NUM_LEDS, firework_bg_fade);
	brightest_spark = 0;
	for (uint8_t x = 0; x < number_of_sparks; x++) {
		leds[(int)spark_pos[x]] += CHSV(firework_hue, 255, (uint8_t)spark_bri[x]);
		if (spark_dir[x]) { spark_pos[x] += spark_vel[x]; }
		else { spark_pos[x] -= spark_vel[x]; }
		spark_pos[x] = constrain(spark_pos[x], 0.0, (float)(NUM_LEDS - 1));
		spark_vel[x] *= gravity;
		spark_bri[x] *= (1 - (spark_fade[x] / 256));
		if ((uint8_t)spark_bri[x] > brightest_spark) { brightest_spark = (uint8_t)spark_bri[x]; }
	}
	if (brightest_spark <= 5) {
		fill_solid(leds, NUM_LEDS, CRGB::Black);
		current_stage = WAITING;
		next_explosion_time = millis() + random16(min_wait + max_wait);
	}
}


void render_firework() {
	if (current_stage == WAITING) {
		if (millis() >= next_explosion_time) {
			prepare_for_explosion();
		}
	}
	else if (current_stage == FADEUP) {
		fadeup();
	}
	else if (current_stage == EXPLOSION) {
		explosion();
	}
}

void fireworks() {
	if (mode_change) {
		mode_change = 0;
		use_palette = 0;
		this_delay = 10;
		current_stage = WAITING;
		firework_position = random8(10, NUM_LEDS - 10);
		firework_hue = random8();
	}
	render_firework();
}
















#endif
