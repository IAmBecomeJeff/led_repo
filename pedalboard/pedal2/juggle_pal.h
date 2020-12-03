#ifndef JUGGLE_PAL_H
#define JUGGLE_PAL_H

/* This is adapted from a routine created by Mark Kriegsman */

/*  Usage - juggle_pal();
 *  
 *  thishue
 *  thisfade
 *  numdots
 *  thisbeat
 *  thisbright
 *  thisdiff
 */


void juggle_pal() {                                            // Several colored dots, weaving in and out of sync with each other
  thisindex = 0;                                           // Reset the hue values.
  fadeToBlackBy(leds, NUM_LEDS, thisfade);
  for( int i = 0; i < numdots; i++) {
    //leds[beatsin16(thisbeat+i+numdots,0,NUM_LEDS)] += ColorFromPalette(currentPalette, thisindex , thisbright, currentBlending);    // Munge the values and pick a colour from the palette
    LtoR_PaletteAdd(beatsin16(thisbeat + i + numdots, 0, 67), currentPalette, thisindex);
	thisindex += thisdiff;
  }
} // juggle_pal()


void juggle_from_center(){
  thisindex = 0;
  fadeToBlackBy(leds, NUM_LEDS, thisfade);

  leds[leftArray[beatsin16_halfup(thisbeat, 18,34)]] += ColorFromPalette(currentPalette, thisindex, thisbright, currentBlending);
  leds[leftArray[beatsin16_halfdown(thisbeat,0,17)]] += ColorFromPalette(currentPalette, thisindex, thisbright, currentBlending);

  leds[rightArray[beatsin16_halfup(thisbeat, 18,34)]] += ColorFromPalette(currentPalette, thisindex, thisbright, currentBlending);
  leds[rightArray[beatsin16_halfdown(thisbeat,0,17)]] += ColorFromPalette(currentPalette, thisindex, thisbright, currentBlending);

  leds[frontArray[beatsin16_halfup(thisbeat, 33,65)]] += ColorFromPalette(currentPalette, thisindex, thisbright, currentBlending);
  leds[frontArray[beatsin16_halfdown(thisbeat,0,32)]] += ColorFromPalette(currentPalette, thisindex, thisbright, currentBlending);

  leds[backArray[beatsin16_halfup(thisbeat, 31,60)]] += ColorFromPalette(currentPalette, thisindex, thisbright, currentBlending);
  leds[backArray[beatsin16_halfdown(thisbeat,0,30)]] += ColorFromPalette(currentPalette, thisindex, thisbright, currentBlending);    

  thisindex += thisdiff;
  
}



#endif
