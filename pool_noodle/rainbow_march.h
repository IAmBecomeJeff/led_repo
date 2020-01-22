#ifndef RAINBOW_MARCH_H
#define RAINBOW_MARCH_H

void rainbow_init(LEDStruct& leds, Mode mn, uint8_t rd = random8(1, 16), uint8_t rr = random8(1,6)) {
    if (DEBUG) { Serial.println("RAINBOW MARCH INIT BEGIN"); }
    leds.mode_initialized = 1;
    leds.mode_name = mn;
    leds.use_palette = 0;

    leds.rainbow_diff = rd;
    leds.rainbow_rot  = rr;

    if (DEBUG) { Serial.println("RAINBOW MARCH INIT COMPLETE"); }
    if (DEBUG) { LEDDebug(leds); }
}


void rainbow_march(LEDStruct& leds) {
    // If not yet iniatilized, call init function with random variables.
    if (!leds.mode_initialized) { rainbow_init(leds, RAINBOW_MARCH); }

    // Increase the start index by the rotation (essentially speed)
	if (leds.this_dir == 0) leds.rainbow_index += leds.rainbow_rot; else leds.rainbow_index -= leds.rainbow_rot;

    // Apply rainbow to LEDs
    if (leds.use_full_range) { fill_rainbow(leds.led_data, NUM_LEDS, leds.rainbow_index, leds.rainbow_diff); }
    else                     { fill_rainbow(leds.led_data, ONE_SIDE, leds.rainbow_index, leds.rainbow_diff); strip_sync(leds); }
}



void rainbow_march_split(LEDStruct& leds){
    // If not yet iniatilized, call init function with random variables.
    if (!leds.mode_initialized) { rainbow_init(leds, RAINBOW_MARCH_SPLIT); }
  
    // Increase the start index by the rotation (essentially speed)
    if (leds.this_dir == 0) leds.rainbow_index += leds.rainbow_rot; else leds.rainbow_index -= leds.rainbow_rot;
    
    // Apply rainbow to half of one side of the LEDs.  No use_full_range for this one
    fill_rainbow(leds.led_data, ONE_SIDE / 2, leds.rainbow_index, leds.rainbow_diff); 
  
    // Copy those to the other half
    for (int i = 0; i < ONE_SIDE / 2; i++) { leds.led_data[ONE_SIDE - 1 - i] = leds.led_data[i]; }

    // Duplicate on the other side of the strip
    strip_sync(leds);
}


#endif
