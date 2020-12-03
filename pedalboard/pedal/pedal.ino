// Pedalboard //

#include "includes.h"

void setup(){
	delay(2000);
//	Serial.begin(115200);
//	Serial.prinln(F("Pedalboard LEDS"));
//	Serial.println(F(""));
//	Serial.print(F("Initial Free SRAM:  "));
//	Serial.println(freeRam());
//	Serial.println(F(""));
	
	LEDS.setBrightness(max_bright);
	LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds,MAX_LEDS);
	
	set_max_power_in_volts_and_milliamps(5,500);
	
	NUM_LEDS = MAX_LEDS;
	
	currentPalette  = CRGBPalette16(CRGB::Black);
	targetPalette   = RainbowColors_p;
	currentBlending = LINEARBLEND;
	
	//Set up arrays
	for (uint8_t i = 0; i < 61; i++) {
		backArray[i] = i;
	}
	for (uint8_t i = 0; i < 35; i++) {
		rightArray[i] = i + 61;
		leftArray[i] = i + 162;
	}
	for (uint8_t i = 0; i < 66; i++) {
		frontArray[i] = i + 96;
	}

	strobe_mode(ledMode, 1);
	
//	Serial.println(F(""));
//	Serial.println(F("Starting loop."));
//	Serial.print(F("Post-setup Free SRAM:  "));
//	Serial.println(freeRam());
//	Serial.println(F(""));
}

//  // Reset function
//void(* resetFunc) (void) = 0; 

void loop(){
	EVERY_N_MILLISECONDS(50){
		uint8_t maxChanges = 24;
		nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);
	}

//  EVERY_N_MINUTES(10){WRITE_RESTART(0x5FA0004);}
  
	EVERY_N_SECONDS(65){
//		ledMode++; 
//		if(ledMode>maxMode){ledMode=1;}
		oldMode = ledMode;
		ledMode = rand() % maxMode + 1;
		newMode=1;		
		if(oldMode!=ledMode){newMode=1;}
	}

	EVERY_N_SECONDS(15) {
		updatePaletteIndex(targetPalette);
		palette_index = random8(g_gradient_palette_count + 1);
		targetPalette = g_gradient_palettes[palette_index];
	}
	
//	EVERY_N_SECONDS(10) {
//		Serial.print(F("Free SRAM:  "));
//		Serial.println(freeRam());
//		Serial.println(F(""));
//		Serial.println(F("Timer: "));
//		Serial.println(ram_counter_10s);
//		Serial.println(F(""));
//	}
	
	EVERY_N_MILLIS_I(thistimer, this_delay){
		thistimer.setPeriod(this_delay);
		if(newMode){
			strobe_mode(ledMode,1);
			newMode=0;
		}else{
			strobe_mode(ledMode, 0);
		}
   // strobe_mode(ledMode,0);
	}
	
	FastLED.show();
}
	

void strobe_mode(uint8_t thisMode, bool mc){

	if(mc) {fill_solid(leds,NUM_LEDS,CRGB(0,0,0));}
	
	switch(thisMode){
		
		case  1: if (mc) { this_delay = 10; }			
			juggle_pal(); 
			break;
			
		case  2: if (mc) { this_delay = 10; }			
			juggle_from_center_pal(); 
			break;
			
		case  3: if (mc) { this_delay = 10; }			
			palette_motion(); 
			break;
			
		case  4: if (mc) { this_dir = 0;    }			
			palette_motion(); 
			break;
			
		case  5: if (mc) { this_delay = 15; }			
			center_juggle_pal(); 
			break;
			
		case  6: if (mc) { this_delay = 10; }			
			center_matrix_motion();	
			break;
			
		case  7: if (mc) { this_delay = 10; num_dots = rand()%6+1; } 
			juggle2_pal(); 
			break;
			
		case  8: if (mc) { targetPalette = fire_palette2; this_delay = 10; } 
			fire_center(); 
			break;
			
		case  9: if (mc) { targetPalette = fire_palette_blue; this_delay = 10; } 
			fire_center(); 
			break;
			
		case 10: if (mc) { targetPalette = fire_palette; this_delay = 15; } 
			fire_center(); 
			break; 
			
		case 11: if (mc) { this_delay = 10; this_fade = 16; num_dots = 4;}			
			juggle_pal();
			break;
			
		case 12: if (mc) { this_delay = 10; this_fade = 32; this_diff = 16;}			
			juggle_from_center_pal(); 
			break;
			
		case 13: if (mc) { this_delay = 10; this_fade = 24; num_dots = 1;}			
			juggle_pal(); 
			break;
			
		case 14: if (mc) { this_delay = 10; this_fade = 8; this_diff = 32; }			
			juggle_from_center_pal(); 
			break;
	}
}
