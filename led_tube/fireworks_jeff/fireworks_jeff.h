//
#ifndef FIREWORKS_JEFF_H
#define FIREWORKS_JEFF_H
#include "FastLED.h"
#define MAX_NUMBER_OF_SPARKS 60
#define MIN_NUMBER_OF_SPARKS 20
#define SPARK_FADE_TIME 5000
#define NUM_FIREWORKS 4
// Fixed definitions cannot change on the fly.
#define LED_DT 7                                                                // Serial data pin for all strands
#define LED_CK 14                                                               // Serial clock pin for WS2801 or APA102
#define COLOR_ORDER BGR                                                         // It's GRB for WS2812
#define LED_TYPE APA102                                                         // Alternatively WS2801, or WS2812
#define NUM_LEDS 300                                                            // Maximum number of LED's defined (at compile time).

uint8_t max_bright = 255;                                                       // Overall brightness definition. It can be changed on the fly.

struct CRGB leds[NUM_LEDS];                                                     // Initialize our LED array. We'll be using less in operation.
extern CRGBPalette16 spark_palette;
int this_delay = 20;


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


DEFINE_GRADIENT_PALETTE(Blues_09_gp) {
  0, 234, 246, 255,
    28, 234, 246, 255,
    28, 177, 213, 235,
    56, 177, 213, 235,
    56, 132, 182, 216,
    84, 132, 182, 216,
    84, 73, 152, 186,
    113, 73, 152, 186,
    113, 26, 109, 164,
    141, 26, 109, 164,
    141, 7, 74, 135,
    170, 7, 74, 135,
    170, 1, 42, 108,
    198, 1, 42, 108,
    198, 1, 20, 74,
    226, 1, 20, 74,
    226, 1, 6, 29,
    255, 1, 6, 29
};

// Gradient palette "BuGn_09_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cb/seq/tn/BuGn_09.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 72 bytes of program space.

DEFINE_GRADIENT_PALETTE(BuGn_09_gp) {
  0, 234, 248, 250,
    28, 234, 248, 250,
    28, 192, 233, 240,
    56, 192, 233, 240,
    56, 142, 215, 197,
    84, 142, 215, 197,
    84, 67, 176, 140,
    113, 67, 176, 140,
    113, 23, 139, 84,
    141, 23, 139, 84,
    141, 7, 109, 37,
    170, 7, 109, 37,
    170, 1, 67, 9,
    198, 1, 67, 9,
    198, 0, 39, 3,
    226, 0, 39, 3,
    226, 0, 13, 1,
    255, 0, 13, 1
};

// Gradient palette "GnBu_09_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cb/seq/tn/GnBu_09.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 72 bytes of program space.

DEFINE_GRADIENT_PALETTE(GnBu_09_gp) {
  0, 234, 248, 219,
    28, 234, 248, 219,
    28, 182, 229, 174,
    56, 182, 229, 174,
    56, 142, 213, 133,
    84, 142, 213, 133,
    84, 86, 186, 108,
    113, 86, 186, 108,
    113, 38, 156, 132,
    141, 38, 156, 132,
    141, 11, 117, 158,
    170, 11, 117, 158,
    170, 2, 68, 122,
    198, 2, 68, 122,
    198, 1, 35, 95,
    226, 1, 35, 95,
    226, 1, 12, 46,
    255, 1, 12, 46
};

// Gradient palette "Oranges_09_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cb/seq/tn/Oranges_09.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 72 bytes of program space.

DEFINE_GRADIENT_PALETTE(Oranges_09_gp) {
  0, 255, 233, 207,
    28, 255, 233, 207,
    28, 252, 203, 149,
    56, 252, 203, 149,
    56, 249, 162, 82,
    84, 249, 162, 82,
    84, 249, 109, 29,
    113, 249, 109, 29,
    113, 249, 69, 6,
    141, 249, 69, 6,
    141, 220, 36, 1,
    170, 220, 36, 1,
    170, 167, 15, 1,
    198, 167, 15, 1,
    198, 83, 8, 1,
    226, 83, 8, 1,
    226, 41, 4, 1,
    255, 41, 4, 1
};

// Gradient palette "PuBu_09_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cb/seq/tn/PuBu_09.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 72 bytes of program space.

DEFINE_GRADIENT_PALETTE(PuBu_09_gp) {
  0, 255, 237, 245,
    28, 255, 237, 245,
    28, 208, 205, 223,
    56, 208, 205, 223,
    56, 150, 164, 197,
    84, 150, 164, 197,
    84, 83, 131, 174,
    113, 83, 131, 174,
    113, 32, 103, 151,
    141, 32, 103, 151,
    141, 4, 72, 125,
    170, 4, 72, 125,
    170, 1, 41, 100,
    198, 1, 41, 100,
    198, 1, 25, 57,
    226, 1, 25, 57,
    226, 1, 9, 17,
    255, 1, 9, 17
};

// Gradient palette "PuRd_09_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cb/seq/tn/PuRd_09.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 72 bytes of program space.

DEFINE_GRADIENT_PALETTE(PuRd_09_gp) {
  0, 234, 231, 240,
    28, 234, 231, 240,
    28, 197, 193, 216,
    56, 197, 193, 216,
    56, 157, 125, 172,
    84, 157, 125, 172,
    84, 137, 77, 137,
    113, 137, 77, 137,
    113, 179, 33, 100,
    141, 179, 33, 100,
    141, 197, 4, 54,
    170, 197, 4, 54,
    170, 146, 1, 16,
    198, 146, 1, 16,
    198, 66, 0, 9,
    226, 66, 0, 9,
    226, 24, 0, 1,
    255, 24, 0, 1
};

// Gradient palette "Emo_Barbie_Playmate_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/colo/rphnick/tn/Emo_Barbie_Playmate.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 40 bytes of program space.

DEFINE_GRADIENT_PALETTE(Emo_Barbie_Playmate_gp) {
  0, 64, 1, 1,
    51, 64, 1, 1,
    51, 152, 6, 4,
    102, 152, 6, 4,
    102, 206, 36, 29,
    153, 206, 36, 29,
    153, 247, 100, 77,
    204, 247, 100, 77,
    204, 234, 176, 123,
    255, 234, 176, 123
};

// Gradient palette "YlOrRd_09_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cb/seq/tn/YlOrRd_09.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 72 bytes of program space.

DEFINE_GRADIENT_PALETTE(YlOrRd_09_gp) {
  0, 255, 255, 145,
    28, 255, 255, 145,
    28, 255, 217, 79,
    56, 255, 217, 79,
    56, 252, 178, 37,
    84, 252, 178, 37,
    84, 252, 115, 12,
    113, 252, 115, 12,
    113, 249, 69, 6,
    141, 249, 69, 6,
    141, 247, 18, 2,
    170, 247, 18, 2,
    170, 188, 1, 1,
    198, 188, 1, 1,
    198, 117, 0, 2,
    226, 117, 0, 2,
    226, 42, 0, 2,
    255, 42, 0, 2
};

CRGBPalette16 spark_palette0 = Blues_09_gp;
CRGBPalette16 spark_palette1 = BuGn_09_gp;
CRGBPalette16 spark_palette2 = GnBu_09_gp;
CRGBPalette16 spark_palette3 = Oranges_09_gp;
CRGBPalette16 spark_palette4 = PuBu_09_gp;
CRGBPalette16 spark_palette5 = PuRd_09_gp;
CRGBPalette16 spark_palette6 = Emo_Barbie_Playmate_gp;
CRGBPalette16 spark_palette7 = YlOrRd_09_gp;

#define NUM_SPARK_PALETTES 8
CRGBPalette16* spark_palette_array[NUM_SPARK_PALETTES] = {
  &spark_palette0,
  &spark_palette1,
  &spark_palette2,
  &spark_palette3,
  &spark_palette4,
  &spark_palette5,
  &spark_palette6,
  &spark_palette7 };


void Firework::initialize() {
  current_stage = WAITING;
  gravity = 0.99;
  get_random_palette = true;
  next_launch_max_wait = 10000;
  next_launch_min_wait = 5000;
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
  flare_velocity = float(random16(50, 100)) / 100;
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
      leds[(int)flare_position] = CHSV(flare_hue, flare_sat, flare_val);
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
    uint16_t pixel = leds[(int)spark_position[x]];
    CRGB pixel_color = ColorFromPalette(*active_spark_palette, spark_gradient_index[x]);
    leds[pixel] += pixel_color;
    if (spark_velocity_direction[x]) {
      spark_position[x] += spark_velocity[x];
    }
    else {
      spark_position[x] -= spark_velocity[x];
    }
    spark_position[x] = constrain(spark_position[x], 0.0, (float)(NUM_LEDS));
    spark_velocity[x] *= 0.98;
  }
  float fastest_spark = 0.0;
  for (uint8_t x = 0; x < number_of_sparks; x++) {
    if (spark_velocity[x] > fastest_spark) {
      fastest_spark = spark_velocity[x];
    }
  }
  if (fastest_spark < 0.5) {
    current_stage = FADING;
    spark_fade_end = millis() + SPARK_FADE_TIME;
  }
}

void Firework::fading() {
  for (uint16_t x = 0; x < NUM_LEDS; x++) {
    leds[x].fadeToBlackBy(8);
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
