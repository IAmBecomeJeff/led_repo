#ifndef CONFETTI_PAL_H
#define CONFETTI_PAL_H

/* This is adapted from the confetti routine created by Mark Kriegsman */

/*  Usage - confetti_pal();
 *   
 *  thisfade
 *  thisdelay
 *  currentPalette and targetPalette
 *  thisdiff
 *  thisindex
 *  thisinc
 *  thisbright
 */


void confetti_pal() {                                                                                               // random colored speckles that blink in and fade smoothly

//  EVERY_N_SECONDS(5) {
//    SetupSimilar4Palette();
//  }

  fadeToBlackBy(leds, MAX_LEDS, this_fade);                                                                      
  int pos = random8(MAX_LEDS);                                                                                      // Pick an LED at random.
  leds[pos] = ColorFromPalette(currentPalette, this_index + random8(this_diff)/4 , this_bright, currentBlending);      // Munge the values and pick a colour from the palette
  this_index += this_inc;                                                                                  // base palette counter increments here.
} // confetti_pal()

#endif
