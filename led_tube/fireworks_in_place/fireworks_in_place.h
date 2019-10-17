#ifndef FIREWORKS_IN_PLACE_H
#define FIREWORKS_IN_PLACE_H

#include "FastLED.h"
#include "fireworks_palettes.h"

#define MAX_NUMBER_OF_SPARKS 40
#define MIN_NUMBER_OF_SPARKS 20
#define SPARK_FADE_TIME 5000
#define NUM_FIREWORKS 1

#define LED_DT 7
#define LED_CK 14
#define COLOR_ORDER GRB
#define LED_TYPE APA102
#define NUM_LEDS 300

uint8_t max_bright = 255;

struct CRGB leds[NUM_LEDS];
extern CRGBPalette16 spark_palette;
uint8_t this_delay = 10;

bool locked[NUM_LEDS];

class Firework {
private:
	enum stage {
		FADEUP,
		EXPLOSION,
		FADING,
		WAITING
	};
	stage current_stage;
	uint32_t next_explosion_time;
	uint16_t explosion_max_wait;
	uint16_t explosion_min_wait;
	bool exploded;
	uint16_t flare_position;
	float gravity;
	uint8_t number_of_sparks;
	float spark_position[MAX_NUMBER_OF_SPARKS];
	float spark_velocity[MAX_NUMBER_OF_SPARKS];
	uint8_t spark_gradient_index[MAX_NUMBER_OF_SPARKS];
	bool spark_velocity_direction[MAX_NUMBER_OF_SPARKS];
	CRGBPalette16* active_spark_palette;
	bool get_random_palette;
	bool use_palette;
	uint8_t flare_hue;
	uint8_t flare_sat;
	uint8_t flare_val;
	uint32_t spark_fade_end;
	CRGB spark_color;
	CHSV spark_hsv;

public:
	void initialize();
	void prepare_for_explosion();
	void fadeup();
	void explosion();
	void fading();
	void updating();
};


void Firework::initialize() {
	current_stage = WAITING;
	gravity = 0.99;
	get_random_palette = true;
	explosion_max_wait = 8000;
	explosion_min_wait = 2000;
	flare_hue = random8();
	flare_sat = 255;
	flare_val = 0;
	spark_hsv = CHSV(flare_hue, flare_sat, 255);
	hsv2rgb_rainbow(spark_hsv, spark_color);
}

void Firework::prepare_for_explosion() {
	Serial.println("Preparing firework!");
	random16_add_entropy(analogRead(2));
	flare_position = random16(10, NUM_LEDS - 10);
	if (!locked[flare_position]) {
		locked[flare_position] = true;
		active_spark_palette = spark_palette_array[random8(0, NUM_SPARK_PALETTES + 1)];
		current_stage = FADEUP;
		uint16_t random_add = random16(explosion_min_wait, explosion_max_wait);
		next_explosion_time = millis() + random_add;
		flare_hue = random8();
		exploded = false;
		use_palette = false;
		Serial.print("Firework being created at location ");
		Serial.print(flare_position);
		Serial.print(" at time: ");
		Serial.println(millis());
	}
}

void Firework::fadeup() {
	if (exploded) {
		current_stage = EXPLOSION;
		number_of_sparks = random8(MIN_NUMBER_OF_SPARKS, MAX_NUMBER_OF_SPARKS + 1);
		for (uint8_t x = 0; x < number_of_sparks; x++) {
			spark_gradient_index[x] = random8();
			spark_position[x] = float(flare_position);
			spark_velocity[x] = float(random16(10, 125)) / 100;
			spark_velocity_direction[x] = random8(0, 2);
		}
	}
	else {
		flare_val++;
		leds[flare_position] += CHSV(flare_hue, flare_sat, flare_val);
		if (flare_val == 255) {
			exploded = true;
			flare_val = 0;
		}
	}
}

void Firework::explosion() {
	for (uint8_t x = 0; x < number_of_sparks; x++) {
		leds[(int)spark_position[x]].fadeToBlackBy(128);
	}
	leds[flare_position] = CRGB::White;
	for (uint8_t x = 0; x < number_of_sparks; x++) {
		uint16_t pixel = (int)spark_position[x];
		CRGB pixel_color;
		if (use_palette) {
			pixel_color = ColorFromPalette(*active_spark_palette, spark_gradient_index[x]);
		}
		else {
			pixel_color = spark_color;
		}
		leds[pixel] += pixel_color;
		if (spark_velocity_direction[x]) {
			spark_position[x] += spark_velocity[x];
		}
		else {
			spark_position[x] -= spark_velocity[x];
		}
		spark_position[x] = constrain(spark_position[x], 0.0, (float)(NUM_LEDS));
		spark_velocity[x] *= 0.97;
	}
	float fastest_spark = 0.0;
	for (uint8_t x = 0; x < number_of_sparks; x++) {
		if (spark_velocity[x] > fastest_spark) {
			fastest_spark = spark_velocity[x];
		}
	}
	if (fastest_spark < 0.1) {
		current_stage = FADING;
		spark_fade_end = millis() + SPARK_FADE_TIME;
	}
}

void Firework::fading() {
	for (uint8_t x = 0; x < number_of_sparks; x++) {
		leds[(int)spark_position[x]].fadeToBlackBy(32);
	}
	for (uint8_t x = 0; x < number_of_sparks; x++) {
		uint16_t pixel = (int)spark_position[x];
		CRGB pixel_color;
		if (use_palette) {
			pixel_color = ColorFromPalette(*active_spark_palette, spark_gradient_index[x]);
		}
		else {
			pixel_color = spark_color--;
		}
		leds[pixel] += pixel_color;
		if (spark_velocity_direction[x]) {
			spark_position[x] += spark_velocity[x];
		}
		else {
			spark_position[x] -= spark_velocity[x];
		}
		spark_position[x] = constrain(spark_position[x], 0.0, (float)(NUM_LEDS));
		spark_velocity[x] *= 0.9;
	}
	leds[flare_position].fadeToBlackBy(32);
	if (millis() > spark_fade_end) {
		current_stage = WAITING;
		locked[flare_position] = false;
		Serial.print("Firework at location ");
		Serial.print(flare_position);
		Serial.print(" has finished at ");
		Serial.println(millis());
	}
}


void Firework::updating() {
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
	else if (current_stage == FADING) {
		fading();
	}
	else {
		Serial.println("How did you get here?");
	}
}

Firework firework0;
//Firework firework1;
//Firework firework2;
//Firework firework3;

Firework* firework_array[NUM_FIREWORKS] = {
	&firework0//,
	//&firework1,
	//&firework2,
	//&firework3
};

void fireworks_init() {
	for (uint8_t i = 0; i < NUM_FIREWORKS; i++) {
		firework_array[i]->initialize();
		firework_array[i]->prepare_for_explosion();
	}
	fill_solid(leds, NUM_LEDS, CRGB::Black);
}

void fireworks_update() {
	for (uint8_t i = 0; i < NUM_FIREWORKS; i++) {
		firework_array[i]->updating();
	}
}





#endif
