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
  this_index = 0;                                           // Reset the hue values.
  fadeToBlackBy(leds, NUM_LEDS, this_fade);
  for( int i = 0; i < num_dots; i++) {
	//leds[beatsin16(thisbeat+i+numdots,0,NUM_LEDS)] += ColorFromPalette(currentPalette, thisindex , thisbright, currentBlending);    // Munge the values and pick a colour from the palette
	LtoR_PaletteAdd(beatsin16(this_beat + i + num_dots, 0, 67), currentPalette, this_index);
	this_index += this_diff;
  }
} // juggle_pal()


void juggle2_pal() {                                            // Several colored dots, weaving in and out of sync with each other
  //this_index = 0;                                           // Reset the hue values.
  fadeToBlackBy(leds, NUM_LEDS, this_fade);
  for( int i = 0; i < num_dots; i++) {
	leds[beatsin16(this_beat+i+num_dots,0,NUM_LEDS)] += ColorFromPalette(currentPalette, this_index , this_bright, currentBlending);    // Munge the values and pick a colour from the palette
	//LtoR_PaletteAdd(beatsin16(this_beat + i + num_dots, 0, 67), currentPalette, this_index);
  this_index += this_diff;
  }
} // juggle_pal()

void juggle_from_center_pal(){
  //this_index = 0;
  fadeToBlackBy(leds, NUM_LEDS, this_fade);

  leds[leftArray[beatsin16_halfup(this_beat, 18,34)]] += ColorFromPalette(currentPalette, this_index, this_bright, currentBlending);
  leds[leftArray[beatsin16_halfdown(this_beat,0,17)]] += ColorFromPalette(currentPalette, this_index, this_bright, currentBlending);

  leds[rightArray[beatsin16_halfup(this_beat, 18,34)]] += ColorFromPalette(currentPalette, this_index, this_bright, currentBlending);
  leds[rightArray[beatsin16_halfdown(this_beat,0,17)]] += ColorFromPalette(currentPalette, this_index, this_bright, currentBlending);

  leds[frontArray[beatsin16_halfup(this_beat, 33,65)]] += ColorFromPalette(currentPalette, this_index, this_bright, currentBlending);
  leds[frontArray[beatsin16_halfdown(this_beat,0,32)]] += ColorFromPalette(currentPalette, this_index, this_bright, currentBlending);

  this_index += this_diff;
  
}

void center_juggle_pal() {
  //this_index = 0;
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	leds[rightFromCenter[beatsin16_halfup(this_beat, 0, 97)]] = ColorFromPalette(currentPalette, this_index, this_bright, currentBlending);
	leds[leftFromCenter[beatsin16_halfup(this_beat, 0, 97)]] = ColorFromPalette(currentPalette, this_index, this_bright, currentBlending);
	this_index += this_diff;
}


void sinelon() {
	fadeToBlackBy( leds, MAX_LEDS, this_fade);
	int pos = beatsin16(13,0,MAX_LEDS);
	static int prevpos = 0;
	if( pos < prevpos ){
		fill_solid( leds+pos, (prevpos-pos)+1, CHSV(gHue,220,255));
	}else{
		fill_solid( leds+prevpos, (pos-prevpos)+1, CHSV( gHue,220,255));
		gHue++;
	}
	prevpos=pos;
}


#endif
