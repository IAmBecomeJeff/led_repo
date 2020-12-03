// Pedalboard //

#include <FastLED.h>
#include <EEPROM.h>

#define LED_DT 7
#define COLOR_ORDER GRB
#define MAX_LEDS 197
#define LED_TYPE WS2812

uint8_t NUM_LEDS;
uint8_t max_bright = 255;
struct CRGB leds[MAX_LEDS];

CRGBPalette16 currentPalette;
CRGBPalette16 targetPalette;
TBlendType currentBlending;


// Variables

int thisdelay = 10;
int maxMode = 10;

int leftArray[35];
int rightArray[35];
int frontArray[66];
int backArray[61];

uint8_t ledMode = 1;
bool newMode = 1;
uint8_t oldMode;

extern const TprogmemRGBGradientPalettePtr gGradientPalettes[];
extern const uint8_t gGradientPaletteCount;
uint8_t gCurrentPaletteNumber = 0;
uint8_t currentPaletteIndex = 0;

#include "make_palettes.h"
#include "gradient_palettes.h"
#include "pedalArrays.h"



void setup(){
	delay(2000);
	
	LEDS.setBrightness(max_bright);
	LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds,MAX_LEDS);
	
	set_max_power_in_volts_and_milliamps(5,500);
	
	NUM_LEDS = MAX_LEDS;
	
	currentPalette  = CRGBPalette16(CRGB::Black);
	targetPalette   = RainbowColors_p;
	currentBlending = LINEARBLEND;
	
	for (uint8_t i = 0; i < 61; i++) {
		backArray[i] = i;
	}
	for (uint8_t i = 0; i < 35; i++) {
		rightArray[i] = i + 61;
		leftArray[i] = i + 162;
	}
	for (uint8_t = 0; i < 66; i++) {
		frontArray[i] = i + 96;
	}
	
	strobe_mode(ledMode, 1);
}
	
void loop(){
	EVERY_N_MILLISECONDS(50){
		uint8_t maxChanges = 24;
		nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);
	}
	
	EVERY_N_SECONDS(30){
		oldMode = ledMode;
		ledMode = rand() % maxMode + 1;
		if(oldMode!=ledMode){newMode=1};
	}
	
	EVERY_N_MILLIS(thistime, thisdelay){
		thistimer.setPeriod(thisdelay);
		if(newMode){
			strobe_mode(ledMode,1);
		}else{
			strobe_mode(ledMode, 0);
		}
	}
	
	FastLED.show();
}
	

void strobe_mode(uint8_t thisMode, bool mc){

	if(mc) {fill_solid(leds,NUM_LEDS,CRGB(0,0,0));}
	
	switch(thisMode){
		
		case  0: if(mc) {fill_solid(leds,NUM_LEDS,CRGB(0,0,0));} break;
		case  1: if(mc) {settings;} juggle_pal(); break;
	}
}
