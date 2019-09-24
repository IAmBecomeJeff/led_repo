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

// Toggles
bool palette_switch = 1;
bool use_palette = 1;
bool use_palette_beat = 0;
bool show_active_pixels = 1;

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

#endif