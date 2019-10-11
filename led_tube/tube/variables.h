#ifndef VARIABLES_H
#define VARIABLES_H

#define NUM_LEDS 300 
#define DATA_PIN 7
#define CLOCK_PIN 14
#define CHIPSET APA102
#define COLOR_ORDER BGR

// Array of LEDs
CRGB leds[NUM_LEDS];

// Palette variables
CRGBPalette16 current_palette;
CRGBPalette16 target_palette = LavaColors_p;
uint8_t paletteChanges = 24;
uint8_t palette_number = 0;
uint8_t palette_index = 0;
uint8_t palette_index_backward = 0;
uint8_t palette_index_forward = 0;
uint8_t palette_index_beat = 10;
uint8_t palette_index_forward_beat = 1;
uint8_t palette_index_backward_beat = 3;

uint8_t current_pattern_number = 0;
// Toggles
bool palette_switch = 1;
bool use_palette = 1;
bool use_palette_beat = 0;
bool show_active_pixels = 0;
bool additive = 0;




// Operational Variables
uint8_t fade_val = 180;
uint8_t this_delay = 5;
uint8_t max_bright = 96;
uint8_t hue = 0;

// Positional Variables
int position = 0;
int position_beat = 4;

uint8_t forward_edge;
uint8_t forward_range = 10;
uint8_t forward_beat = 9;

uint8_t backward_edge;
uint8_t backward_range = 14;
uint8_t backward_beat = 21;



// blend_into_rainbow

uint16_t pos, pos2, pos3;
//uint8_t hue = 115;
uint8_t hue2;
uint8_t bpm = 2;
uint8_t bpm2 = 6;
uint8_t bpm3 = 2;

// ripples
#define MAX_RIPPLES 6
//----------------- Ripple structure definition ----------------------------------------------------------------

struct ripple {                                                                 // Reko Meri�'s structures

// Local definitions

// Persistent local variables

// Temporary local variables
	uint8_t brightness;                                   // 0 to 255
	int8_t color;                                         // 0 to 255
	int16_t pos;                                           // -1 to NUM_LEDS  (up to 127 LED's)
	int8_t velocity;                                      // 1 or -1
	uint8_t life;                                         // 0 to 20
	uint8_t maxLife;                                      // 10. If it's too long, it just goes on and on. . .
	uint8_t fade;                                         // 192
	bool exist;                                           // 0 to 1


	void Move() {

		pos += velocity;
		life++;

		if (pos > NUM_LEDS - 1) {                           // Bounce back from far end.
			velocity *= -1;
			pos = NUM_LEDS - 1;
		}

		if (pos < 0) {                                      // Bounce back from 0.
			velocity *= -1;
			pos = 0;
		}

		brightness = scale8(brightness, fade);              // Adjust brightness accordingly to strip length

		if (life > maxLife) exist = false;                  // Kill it once it's expired.

	} // Move()



	void Init(uint8_t Fade, uint8_t MaxLife) {                 // Typically 216, 20

		pos = random8(NUM_LEDS / 8, NUM_LEDS - NUM_LEDS / 8);     // Avoid spawning too close to edge.
		velocity = 1;                                       // -1 or 1
		life = 0;                                           // 0 to Maxlife
		maxLife = MaxLife;                                  // 10 called
		exist = true;                                       // 0, 1
		brightness = 255;                                   // 0 to 255
		color = millis();                                   // hue;
		fade = Fade;                                        // 192 called

	} // Init()

}; // struct ripple

typedef struct ripple Ripple;

Ripple ripples[MAX_RIPPLES];

#endif
