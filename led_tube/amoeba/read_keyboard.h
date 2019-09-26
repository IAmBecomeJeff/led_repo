#ifndef READ_KEYBOARD_H
#define READ_KEYBOARD_H

/*
 * Takes in keyboard input and executes commands.
 *
 * Serial timeout value here is important.
 * We should make sure it's set high enough
 * to type the entire command within the timeout.
 */

byte in_byte;
int this_arg;

void readkeyboard() {
	while (Serial.available() > 0) {

		in_byte = Serial.read();

		// Don't print carriage return
		if (in_byte != 10) {
			Serial.print("# ");
			Serial.print(char(in_byte));
			Serial.print(" ");
		}

		switch (in_byte) {

				// A - use_palette [0/1]
			case 65:
				this_arg = Serial.parseInt();
				use_palette = constrain(this_arg, 0, 1);
				Serial.print("use_palette: ");
				Serial.println(use_palette);
				break;

				// B - paletteChanges [0-255]
			case 66:
				this_arg = Serial.parseInt();
				paletteChanges = constrain(this_arg, 0, 255);
				Serial.print("paletteChanges: ");
				Serial.println(paletteChanges);
				break;

				// C - palette_number [0-255]
			case 67:
				this_arg = Serial.parseInt();
				palette_number = constrain(this_arg, 0, g_gradient_palette_count);
				Serial.print("palette_number: ");
				Serial.println(palette_number);
				break;

				// D - palette_index_beat (0-255)
			case 68:
				this_arg = Serial.parseInt();
				palette_index_beat = constrain(this_arg, 0, 255);
				Serial.print("palette_index_beat: ");
				Serial.println(palette_index_beat);
				break;

				// E - palette_index_forward_beat (0-255)
			case 69:
				this_arg = Serial.parseInt();
				palette_index_forward_beat = constrain(this_arg, 0, 255);
				Serial.print("palette_index_forward_beat: ");
				Serial.println(palette_index_forward_beat);
				break;

				// F - palette_index_backward_beat (0-255)
			case 70:
				this_arg = Serial.parseInt();
				palette_index_backward_beat = constrain(this_arg, 0, 255);
				Serial.print("palette_index_backward_beat: ");
				Serial.println(palette_index_backward_beat);
				break;

				// G - palette_switch (0/1)
			case 71:
				this_arg = Serial.parseInt();
				palette_switch = constrain(this_arg, 0, 1);
				Serial.print("palette_switch: ");
				Serial.println(palette_switch);
				break;

				// H - fade_val (0-255)
			case 72:
				this_arg = Serial.parseInt();
				fade_val = constrain(this_arg, 0, 255);
				Serial.print("fade_val: ");
				Serial.println(fade_val);
				break;

				// I - max_bright (0-255) 
			case 73:
				this_arg = Serial.parseInt();
				max_bright = constrain(this_arg, 0, 255);
				Serial.print("max_bright: ");
				Serial.println(max_bright);
				break;

				// J - position_beat (0-255)
			case 74:
				this_arg = Serial.parseInt();
				position_beat = constrain(this_arg, 0, 255);
				Serial.print("position_beat: ");
				Serial.println(position_beat);
				break;
				
				// K - forward_range (0-255)
			case 75:
				this_arg = Serial.parseInt();
				forward_range = constrain(this_arg, 0, 255);
				Serial.print("forward_range: ");
				Serial.println(forward_range);
				break;

				// L - forward_beat (0-255)
			case 76:
				this_arg = Serial.parseInt();
				forward_beat = constrain(this_arg, 0, 255);
				Serial.print("forward_beat: ");
				Serial.println(forward_beat);
				break;

			//	// M - Get mode
			//case 77:
			//	print_mode(mode_number);
			//	break;

				// N - backward_range (0-255) 
			case 78:
				this_arg = Serial.parseInt();
				backward_range = constrain(this_arg, 0, 255);
				Serial.print("backward_range: ");
				Serial.println(backward_range);
				break;

				// O - backward_beat (0-255)
			case 79:
				this_arg = Serial.parseInt();
				backward_beat = constrain(this_arg, 0, 255);
				Serial.print("backward_beat: ");
				Serial.println(backward_beat);
				break;

				// P - Get Palette
			case 80:
				print_palette(palette_number);
				break;

				// Q - Show active pixels
			case 81:
				this_arg = Serial.parseInt();
				show_active_pixels = constrain(this_arg, 0, 1);
				Serial.print("show_active_pixels: ");
				Serial.println(show_active_pixels);
				break;

				// R - use_palette_beat [0/1]
			case 82:
				this_arg = Serial.parseInt();
				use_palette_beat = constrain(this_arg, 0, 1);
				Serial.print("use_palette_beat: ");
				Serial.println(use_palette_beat);
				break;

				// S - Display variables in use
			case 83:
				display_variables();
				break;

				// T - jug16_phase
			case 84:
        this_arg = Serial.parseInt();
        additive = constrain(this_arg, 0, 1);
        Serial.print("additive: ");
        Serial.println(additive);
				break;

			//	// U - 
			//case 85:
			//	break;

			//	// V - 
			//case 86:
			//	break;

			//	// W - 
			//case 87:
			//	break;

			//	// X - 
			//case 88:
			//	break;

			//	// Y - 
			//case 89:
			//	break;

			//	// Z - 
			//case 90:
			//	break;

			//	// a 
			//case 97:
			//	break;

			//	// b 
			//case 98:
			//	break;

			//	// c 
			//case 99:
			//	break;

				// d {delay} - set the delay amount to {delay} (0-255)
			case 100:
				this_arg = Serial.parseInt();
				this_delay = constrain(this_arg, 0, 255);
				Serial.print("Delay: ");
				Serial.println(this_delay);
				break;

			//	// f 
			//case 102:
			//	break;

			//	// g 
			//case 103:
			//	break;

			//	// h 
			//case 104:
			//	break;

			//	// i 
			//case 105:
			//	break;

			//	// j 
			//case 106:
			//	break;
   //     
			//	// k 
			//case 107:
			//	break;
   //     
			//	// l 
			//case 108:
			//	break;
   //     
			//	// m
			//case 109:
			//	break;
			//	
			//	// n
			//case 110:
			//	break;

			//	// o 
			//case 111:
			//	break;

			//	// p 
			//case 112:
			//	break;

			//	// q
			//case 113:
			//	break;

			//	// r 
			//case 114:
			//	break;

			//	// s 
			//case 115:
			//	break;

			//	// t 
			//case 116:
			//	break;

			//	// u 
			//case 117:
			//	break;

			//	// v 
			//case 118:
			//	break;

			//	// w 
			//case 119:
			//	break;

			//	// x 
			//case 120:
			//	break;

			//	// y 
			//case 121:
			//	break;

			//	// z 
			//case 122:
			//	break;
                
		}
	}
}

#endif
