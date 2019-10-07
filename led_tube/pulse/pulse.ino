

#include "FastLED.h"
#define LED_TYPE APA102
#define DATA_PIN 7
#define CLOCK_PIN 14
#define COLOR_ORDER BGR
#define NUM_LEDS 300
CRGB leds[NUM_LEDS];

int pulse_width = 7;
int pulse_start = -pulse_width;
int pos = pulse_start;
uint8_t fade_val = 180;
uint8_t this_hue = 0;
uint8_t this_sat = 255;
int this_index;
uint8_t this_delay = 30;
uint8_t this_val;
int min_range;
int max_range;
int restart_index = 400;
bool switch_pulse = 1;
uint8_t beat = 5;
uint8_t pulse_min = 3;
uint8_t pulse_max = 21;
bool varying = 0;
uint8_t max_bright = 150;

uint8_t gaussian_table[256] = { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4,
								5, 5, 6, 6, 7, 8, 8, 9, 10, 10, 11, 12, 13,
								14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 25,
								26, 28, 29, 31, 33, 34, 36, 38, 40, 42, 44,
								46, 48, 50, 52, 54, 57, 59, 62, 64, 67, 70,
								72, 75, 78, 81, 84, 87, 90, 93, 96, 99, 103,
								106, 109, 113, 116, 120, 123, 127, 130, 134,
								138, 141, 145, 149, 152, 156, 160, 163, 167,
								171, 174, 178, 181, 185, 188, 192, 195, 199,
								202, 205, 208, 211, 214, 217, 220, 223, 226,
								228, 231, 233, 235, 237, 240, 241, 243, 245,
								247, 248, 249, 251, 252, 252, 253, 254, 254,
								255, 255, 255, 255, 255, 254, 254, 253, 252,
								252, 251, 249, 248, 247, 245, 243, 241, 240,
								237, 235, 233, 231, 228, 226, 223, 220, 217,
								214, 211, 208, 205, 202, 199, 195, 192, 188,
								185, 181, 178, 174, 171, 167, 163, 160, 156,
								152, 149, 145, 141, 138, 134, 130, 127, 123,
								120, 116, 113, 109, 106, 103, 99, 96, 93, 90,
								87, 84, 81, 78, 75, 72, 70, 67, 64, 62, 59, 57,
								54, 52, 50, 48, 46, 44, 42, 40, 38, 36, 34, 33,
								31, 29, 28, 26, 25, 24, 22, 21, 20, 19, 18, 17,
								16, 15, 14, 13, 12, 11, 10, 10, 9, 8, 8, 7, 6,
								6, 5, 5, 4, 4, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 0, 0 };


void pulse() {
	if (varying) { pulse_width = beatsin8(beat, pulse_min, pulse_max); }
	min_range = pos - pulse_width / 2;
	max_range = pos + pulse_width / 2;

	if (min_range > 0)   { leds[min_range - 1] = CRGB::Black; }
	if (max_range < 255) { leds[max_range + 1] = CRGB::Black; }

	if (pulse_width % 2 == 1) {
		for (uint8_t i = 0; i < pulse_width; i++) {
			this_index = i * 256 / (pulse_width + 1);
			this_val = gaussian_table[this_index];
			if (min_range + i >= 0 && min_range + i <= NUM_LEDS) { leds[min_range + i] = CHSV(this_hue, this_sat, this_val); }
		}
	}
	else {
		for (uint8_t i = 0; i < pulse_width / 2; i++) {
			this_index = i * 256 / pulse_width;
			this_val = gaussian_table[this_index];
			if (min_range + i >= 0) { leds[min_range + i] = CHSV(this_hue, this_sat, this_val); }
			if (max_range - i <= NUM_LEDS) { leds[max_range - i] = CHSV(this_hue, this_sat, this_val); }
		}
	}
	//this_hue++;
	pos++;
	if (pos > restart_index) { Serial.println("outside index"); pos = pulse_start; }
  Serial.println(pos);
}

void dark_pulse() {
	if (varying) { pulse_width = beatsin8(beat, pulse_min, pulse_max); }
	fill_rainbow(leds, NUM_LEDS, this_hue++);
	
	min_range = pos - pulse_width / 2;
	max_range = pos + pulse_width / 2;

	if (pulse_width % 2 == 1) {
		for (uint8_t i = 0; i < pulse_width; i++) {
			this_index = i * 256 / (pulse_width + 1);
			this_val = gaussian_table[this_index];
			if (min_range + i >= 0 && min_range + i <= NUM_LEDS) { leds[min_range + i].nscale8(this_val); }
		}
	}
	else {
		for (uint8_t i = 0; i < pulse_width / 2; i++) {
			this_index = i * 256 / pulse_width;
			this_val = gaussian_table[this_index];
			if (min_range + i >= 0) { leds[min_range + i].nscale8(this_val); }
			if (max_range - i <= NUM_LEDS) { leds[max_range - i].nscale8(this_val); }
		}
	}

	pos++;
	if (pos > restart_index) { pos = 0 - pulse_width / 2; }
}



void setup() {
	delay(1000);  
  Serial.begin(115200);
	FastLED.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.setBrightness(max_bright);
	set_max_power_in_volts_and_milliamps(5, 2000);
}

void loop() {

	EVERY_N_SECONDS(30) {
		switch_pulse = !switch_pulse;
    Serial.println(switch_pulse);
		fill_solid(leds, NUM_LEDS, CRGB::Black);
	}

	EVERY_N_MILLIS_I(this_timer, this_delay) {
		this_timer.setPeriod(this_delay);
		if (switch_pulse)	{ pulse();		}
		else				{ dark_pulse(); }
	}

	FastLED.show();

}
