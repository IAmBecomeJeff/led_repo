//***************************************************************
// Messing with blending a moving cycling color into a moving
// background rainbow.
//
// Marc Miller, Sept 2019
//***************************************************************

#include "FastLED.h"
#define DATA_PIN    7
#define CLK_PIN     14
#define LED_TYPE    APA102
#define COLOR_ORDER GRB
#define NUM_LEDS    300
#define BRIGHTNESS  100
CRGB leds[NUM_LEDS];
#define max_blends 6;
uint8_t bg_hue = 0;

struct blend_struct {
	uint8_t brightness;
	uint8_t color;
	int16_t pos;
	int16_t prev_pos;
	int8_t velocity;
	uint8_t size;
	uint8_t fade;
	bool exist;
	uint8_t bpm;
	uint16_t start;
	uint16_t end;
	uint8_t blend_amount;

	void Move() {
		pos += velocity;
		life++;
	}

	void Init(uint8_t Fade, uint8_t Size, int8_t Velocity, uint8_t BPM, uint16_t Start, uint16_t End, uint8_t Blend_Amount) {
		pos = 0;
		prev_pos = 0;
		velocity = Velocity;
		size = Size;
		fade = Fade;
		exist = true;
		brightness = 255;
		color = millis();
		bpm = BPM;
		start = Start;
		end = End;
		blend_amount = Blend_Amount;
		if (size % 2 == 0) { size++ };	// keep the size odd

	}

	void Fill() {

	}

};


typedef struct blend_struct Blender;

Blender blender[max_blends];
//---------------------------------------------------------------
void setup() {
	Serial.begin(115200);  // Allows serial monitor output (check baud rate)
	delay(2500); // startup delay
	//FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA_PIN, CLK_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.setBrightness(BRIGHTNESS);
	set_max_power_in_volts_and_milliamps(5, 2000);
	Serial.println("Setup done. \n");
}


//---------------------------------------------------------------
void loop() {
	EVERY_N_MILLISECONDS(150) {
		bg_hue++;  //used to cycle through the rainbow
	}

	fill_rainbow(leds, NUM_LEDS,bg_hue, 255 / NUM_LEDS / 4);  //draw part of the rainbow into the strip

	//Serial.println(pos);
	blend_this();
	FastLED.show();  //update the display

	//EVERY_N_SECONDS(random8(5,21)) {
	  //delay(3000);  //randomly stop the animation to observe the blending
	//}

}//end_main_loop


void blend_this() {

	for (int i = 0; i < max_blends; i++) {
		if (random8() > 224 && !blender[i].exist) {
			blender[i].Init(192, 7, 1, 5, 0, NUM_LEDS-1, 240);
		}

		if (blender[i].exist) {
			blender[i].prev_pos = blender[i].pos;
			blender[i].pos = beatsin16(blender[i].bpm, blender[i].start, blender[i].end);
			for (int j = 0 < blender[i].size/2; j++) {
				leds[(blender[i].pos + j) % NUM_LEDS] = nblend(leds[(blender[i].pos + j) % NUM_LEDS], CHSV(blender[i].color, ));
				leds[(blender[i].pos+ j + blender[i].size/2)%NUM_LEDS] = nblend(leds[(blender[i].pos+ j + blender[i].size/2)%NUM_LEDS], CHSV(blender[i].color, ))
			}
		}
	}


}