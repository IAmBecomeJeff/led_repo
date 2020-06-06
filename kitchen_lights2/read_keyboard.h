#ifndef READ_KEYBOARD_H
#define READ_KEYBOARD_H

void read_keyboard() {
	while (Serial.available() > 0) {
		in_byte = Serial.read();

		if (in_byte != 10) {
			Serial.print("# ");
			Serial.print(char(in_byte));
			Serial.println(" ");
		}

		update_arg = Serial.parseInt();
		keyboard_update = 1;
		switch (in_byte) {

			// B - brigthness
			case 66: 
				max_bright = (uint8_t)update_arg; 
				LEDS.setBrightness(max_bright); 
				keyboard_update = 0;
				update_var = 255;
				break;

			// D - delay
			case 68: curr_leds.delay_time = (uint8_t)update_arg; keyboard_update = 0; update_var = 255; break;

			// E - next_leds delay, beta
			case 69: next_leds.delay_time = (uint8_t)update_arg; keyboard_update = 0; update_var = 255; break;

			// F - current_leds blending
			case 70: 
				if ((bool)update_arg == 0) { curr_leds.current_blending = NOBLEND;	}
				else { curr_leds.current_blending = LINEARBLEND; }
				keyboard_update = 0; 
				update_var = 255; break;

			// M - mode
			case 77: change_mode((uint8_t)update_arg); keyboard_update = 0; update_var = 255; break;

			// N - direction
			case 78: curr_leds.this_dir = (bool)update_arg; keyboard_update = 0; update_var = 255; break;

			// P - palette
			case 80: 
				curr_leds.palette_index = (uint8_t)update_arg; 
				curr_leds.target_palette = palettes[curr_leds.palette_index]; 
				keyboard_update = 0; 
				break;

			// Q - random palette change	(change palettes randomly every 30 seconds)
			case 81: random_palette = (bool)update_arg; keyboard_update = 0; update_var = 255; break;

			// R - random mode		(when changing modes, do so randomly)
			case 82: random_mode = (bool)update_arg; keyboard_update = 0; update_var = 255; break;

			// S - change modes		(change modes every T seconds)
			case 83: mode_change = (bool)update_arg; keyboard_update = 0; update_var = 255; break;

			// T - mode change timer (how often to change modes, if mode_change is set)
			case 84: mode_change_time = update_arg; keyboard_update = 0; update_var = 255; break;

			// a
			case 97: update_var = 0;	break;

			// b
			case 98: update_var = 1;	break;

			// c
			case 99: update_var = 2;	break;

			// d 
			case 100: update_var = 3;	break;

			// e
			case 101: update_var = 4;	break;

			// f 
			case 102: update_var = 5;	break;

			// g
			case 103: update_var = 6;	break;

			// h
			case 104: update_var = 7;	break;

			// i
			case 105: update_var = 8;	break;

			// j
			case 106: update_var = 9;	break;

			// k
			case 107: update_var = 10;	break;

			// l
			case 108: update_var = 11;	break;

			default: break;
		}


	}
}

#endif