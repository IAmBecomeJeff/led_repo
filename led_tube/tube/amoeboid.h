#ifndef AMOEBOID_H
#define AMOEBOID_H
void fadeall();
// Amoeba program
void amoeba() {

	// Fade everything
	fadeall();

	// Determine the current LED
	position = beatsin16(position_beat, 0, NUM_LEDS - 1);

	// Set nucleus position
	if (use_palette) {
		if (use_palette_beat) {
			palette_index = beatsin8(palette_index);
		}
		else {
			palette_index++;
		}
   if(additive){
    leds[position] += ColorFromPalette(current_palette, palette_index);
   }
   else{
		leds[position] = ColorFromPalette(current_palette, palette_index);
	  }
	}
	else {
    if(additive){
      leds[position] += CHSV(hue, 255, 255);
    }else{
		  leds[position] = CHSV(hue, 255, 255);
	  }
	}

	// Determine how big the edges are
	forward_edge = beatsin16(forward_beat, 0, forward_range);
	backward_edge = beatsin16(backward_beat, 0, backward_range);

	// Serial display
	if (show_active_pixels) {
		Serial.print("|| ");

		// Set amoeba pixels for range of edges
		for (int j = backward_range; j > backward_edge; j--) { Serial.print("--- "); }
	}

	if (backward_edge > 0) {
		for (int i = backward_edge; i > 0; i--) {
			if (position - i > 0) {
				if (use_palette) {
					if (use_palette_beat) {
						palette_index_backward = beatsin8(palette_index_backward_beat);
					}
					else {
						palette_index_backward = palette_index - i;
					}
          if(additive){
            leds[position - i] += ColorFromPalette(current_palette, palette_index_backward);
          }else{
					  leds[position - i] = ColorFromPalette(current_palette, palette_index_backward);
				}
				}
				else { leds[position - i] = CHSV(hue, 255, 255); }
				if (show_active_pixels) {
					if (position - i < 10) { Serial.print("00"); }
					else if (position - i < 100) { Serial.print("0"); }
					Serial.print(position - i);
					Serial.print(" ");
				}
			}
			else {
				if (show_active_pixels) { Serial.print("___ "); }
			}
		}
	}
	
	if (show_active_pixels) {
		Serial.print("|| ");
		if (position < 10) { Serial.print("00"); }
		else if (position < 100) { Serial.print("0"); }
		Serial.print(position);
		Serial.print(" || ");
	}

	if (forward_edge > 0) {
		for (int i = 0; i < forward_edge; i++) {
			if (position + i < NUM_LEDS - 1) {
				if (use_palette) {
					if (use_palette_beat) {
						palette_index_forward = beatsin8(palette_index_forward_beat);
					}
					else {
						palette_index_forward = palette_index + i;
					}
         if(additive){
           leds[position + i] += ColorFromPalette(current_palette, palette_index_forward);
         }else{
					leds[position + i] = ColorFromPalette(current_palette, palette_index_forward);
				}
				}
				else { leds[position + i] = CHSV(hue, 255, 255); }
				if (show_active_pixels) {
					if (position + i < 10) { Serial.print("00"); }
					else if (position + i < 100) { Serial.print("0"); }
					Serial.print(position + i);
					Serial.print(" ");
				}
			}
			else {
				if (show_active_pixels) { Serial.print("___ "); }
			}
		}
	}

	if (show_active_pixels) {
		for (int j = forward_edge; j < forward_range; j++) { Serial.print("--- "); }
		Serial.println("||");
	}

	if (!use_palette) { hue++; }
}

#endif
