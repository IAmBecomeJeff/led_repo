//
#ifndef FIREWORKS_JEFF_H
#define FIREWORKS_JEFF_H
#include "FastLED.h"
#include "fireworks_palettes.h"
#define MAX_NUMBER_OF_SPARKS 60
#define MIN_NUMBER_OF_SPARKS 20
#define SPARK_FADE_TIME 2000
#define NUM_FIREWORKS 4
// Fixed definitions cannot change on the fly.
#define LED_DT 7                                                                // Serial data pin for all strands
#define LED_CK 14                                                               // Serial clock pin for WS2801 or APA102
#define COLOR_ORDER GRB                                                         // It's GRB for WS2812
#define LED_TYPE APA102                                                         // Alternatively WS2801, or WS2812
#define NUM_LEDS 300                                                            // Maximum number of LED's defined (at compile time).

uint8_t max_bright = 255;                                                       // Overall brightness definition. It can be changed on the fly.

struct CRGB leds[NUM_LEDS];                                                     // Initialize our LED array. We'll be using less in operation.
extern CRGBPalette16 spark_palette;
int this_delay = 10;


class Firework {
	private:
		enum stage
		{
			LAUNCH,
			EXPLOSION,
			FADING,
			WAITING
		};
		stage current_stage;
		uint32_t next_launch_time;
		uint16_t next_launch_max_wait;
		uint16_t next_launch_min_wait;
		bool launched;
		float flare_velocity;
		float flare_position;
		float gravity;
		uint8_t number_of_sparks;
		float spark_position[MAX_NUMBER_OF_SPARKS];
		float spark_velocity[MAX_NUMBER_OF_SPARKS];
		uint8_t spark_gradient_index[MAX_NUMBER_OF_SPARKS];
		bool spark_velocity_direction[MAX_NUMBER_OF_SPARKS];
		CRGBPalette16* active_spark_palette;
		bool get_random_palette;
		uint8_t flare_hue;
		uint8_t flare_sat;
		uint8_t flare_val;
		uint8_t flare_tail_length;
		uint32_t spark_fade_end;

	public:
		void initialize();
		void prepare_for_launch();
		void launch();
		void explosion();
		void fading();
		void update_firework();
};




void Firework::initialize() {
  current_stage = WAITING;
  gravity = 0.99;
  get_random_palette = true;
  next_launch_max_wait = 2000;
  next_launch_min_wait = 1000;
  flare_hue = 10;
  flare_sat = 255;
  flare_val = 255;
  flare_tail_length = 100;
}

void Firework::prepare_for_launch() {
  random16_add_entropy(analogRead(2));
  active_spark_palette = spark_palette_array[random8(0, NUM_SPARK_PALETTES + 1)];
  current_stage = LAUNCH;
  flare_position = 0.0;
  uint16_t random_add = random16(next_launch_min_wait, next_launch_max_wait);
  next_launch_time = millis() + random_add;
  flare_hue = random8();
  flare_velocity = float(random16(75, 200)) / 100;
  launched = false;
//  fill_solid(leds, NUM_LEDS, CRGB::Black);
}

void Firework::launch() {
  if (launched & (flare_velocity < 0.1)) {
    current_stage = EXPLOSION;
    number_of_sparks = random8(MIN_NUMBER_OF_SPARKS, MAX_NUMBER_OF_SPARKS);
    for (uint8_t x = 0; x < number_of_sparks; x++) {
      spark_gradient_index[x] = random8();
      spark_position[x] = flare_position;
      spark_velocity[x] = float(random16(10, 125)) / 100;
      spark_velocity_direction[x] = random8(0, 2);
    }
  }
  else {
    if (!launched) {
      leds[(int)flare_position] += CHSV(flare_hue, flare_sat, flare_val);
      launched = true;
    }
    else {
      for (uint16_t i = 0; i < (int)flare_position; i++) {
        leds[i].fadeToBlackBy(flare_tail_length);
      }
      float pixel_spill = ((int)flare_position + 1) - flare_position;
      leds[(int)flare_position + 1] = CHSV(flare_hue, flare_sat, (flare_val * (1 - pixel_spill)));
    }
    flare_position += flare_velocity;
    flare_velocity *= gravity;
  }
}

void Firework::explosion() {
  for (uint16_t x = 0; x < NUM_LEDS; x++) {
    leds[x].fadeToBlackBy(128);
  }
  for (uint8_t x = 0; x < number_of_sparks; x++) {
    uint16_t pixel = (int)spark_position[x];
    CRGB pixel_color = ColorFromPalette(*active_spark_palette, spark_gradient_index[x]);
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
  for (uint16_t x = 0; x < NUM_LEDS; x++) {
    leds[x].fadeToBlackBy(32);
  }
  if (millis() > spark_fade_end) {
    current_stage = WAITING;
  }
}

void Firework::update_firework() {
  if (current_stage == WAITING) {
    if (millis() >= next_launch_time) {
      prepare_for_launch();
    }
  }
  else if (current_stage == LAUNCH) {
    launch();
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
Firework firework1;
Firework firework2;
Firework firework3;


Firework* firework_array[NUM_FIREWORKS] = {
  &firework0,
  &firework1,
  &firework2,
  &firework3
};


void fireworks_init() {
  //interval = 30;
  for (uint8_t i = 0; i < NUM_FIREWORKS; i++) {
	  firework_array[i]->initialize();
      firework_array[i]->prepare_for_launch();
  }
    //update = true;
    fill_solid(leds, NUM_LEDS, CRGB::Black);
}


void fireworks_update() {
  for (uint8_t i = 0; i < NUM_FIREWORKS; i++) {
    firework_array[i]->update_firework();
  }
}

#endif
