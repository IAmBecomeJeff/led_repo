#ifndef SUPPORT_FUNCTIONS_H
#define SUPPORT_FUNCTIONS_H

// Fade function
void fadeall() { for (int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(fade_val); } }

/*
void SetupMySimilar4Palette() {                                                   // Create a palette with colours close to each other.

	uint8_t thishue = random8();

	targetPalette = CRGBPalette16(CHSV(thishue + random8(32), 255, random8(128, 255)),
		CHSV(thishue + random8(32), 255, random8(192, 255)),
		CHSV(thishue + random8(32), 192, random8(192, 255)),
		CHSV(thishue + random8(32), 255, random8(128, 255)));

} // SetupMySimilar4Palette()

void nextPattern()
{
	// add one to the current pattern number, and wrap around at the end
	current_pattern_number = (current_pattern_number + 1) % ARRAY_SIZE(Patterns);
}
*/
void randomPattern()
{
	current_pattern_number = random8(ARRAY_SIZE(Patterns));
}

// Palette info
void print_palette(uint8_t pn) {
	Serial.print("(");
	Serial.print(pn);
	Serial.print(") ");
	switch (pn) {
	case 0:
		Serial.println("ib_jul01_gp");
		break;

	case 1:
		Serial.println("es_vintage_57_gp");
		break;

	case 2:
		Serial.println("es_vintage_01_gp");
		break;

	case 3:
		Serial.println("es_rivendell_15_gp");
		break;

	case 4:
		Serial.println("rgi_15_gp");
		break;

	case 5:
		Serial.println("retro2_16_gp");
		break;

	case 6:
		Serial.println("Analogous_1_gp");
		break;

	case 7:
		Serial.println("es_pinksplash_08_gp");
		break;

	case 8:
		Serial.println("es_pinksplash_07_gp");
		break;

	case 9:
		Serial.println("Coral_reef_gp");
		break;

	case 10:
		Serial.println("es_ocean_breeze_068_gp");
		break;

	case 11:
		Serial.println("es_ocean_breeze_036_gp");
		break;

	case 12:
		Serial.println("departure_gp");
		break;

	case 13:
		Serial.println("es_landscape_64_gp");
		break;

	case 14:
		Serial.println("es_landscape_33_gp");
		break;

	case 15:
		Serial.println("rainbowsherbet_gp");
		break;

	case 16:
		Serial.println("gr65_hult_gp");
		break;

	case 17:
		Serial.println("gr64_hult_gp");
		break;

	case 18:
		Serial.println("GMT_drywet_gp");
		break;

	case 19:
		Serial.println("ib15_gp");
		break;

	case 20:
		Serial.println("Fuschia_7_gp");
		break;

	case 21:
		Serial.println("es_emerald_dragon_08_gp");
		break;

	case 22:
		Serial.println("lava_gp");
		break;

	case 23:
		Serial.println("fire_gp");
		break;

	case 24:
		Serial.println("Colorfull_gp");
		break;

	case 25:
		Serial.println("Magenta_Evening_gp");
		break;

	case 26:
		Serial.println("Pink_Purple_gp");
		break;

	case 27:
		Serial.println("Sunset_Real_gp");
		break;

	case 28:
		Serial.println("es_autumn_19_gp");
		break;

	case 29:
		Serial.println("BlacK_Blue_Magenta_White_gp");
		break;

	case 30:
		Serial.println("BlacK_Magenta_Red_gp");
		break;

	case 31:
		Serial.println("BlacK_Red_Magenta_Yellow_gp");
		break;

	case 32:
		Serial.println("Blue_Cyan_Yellow_gp");
		break;

	case 33:
		Serial.println("bhw1_greeny_gp");
		break;

	case 34:
		Serial.println("bhw1_26_gp");
		break;

	case 35:
		Serial.println("bhw1_28_gp");
		break;

	case 36:
		Serial.println("bhw2_23_gp");
		break;

	case 37:
		Serial.println("bhw2_22_gp");
		break;

	case 38:
		Serial.println("bhw2_49_gp");
		break;

	case 39:
		Serial.println("bhw2_10_gp");
		break;

	case 40:
		Serial.println("bhw2_14_gp");
		break;

	case 41:
		Serial.println("bhw3_21_gp");
		break;

	case 42:
		Serial.println("bhw3_30_gp");
		break;

	case 43:
		Serial.println("vibrant_gp");
		break;

	case 44:
		Serial.println("cw1_029_gp");
		break;

	case 45:
		Serial.println("alarm_p4_0_2_gp");
		break;

	case 46:
		Serial.println("Ribbon_Colors_gp");
		break;

	case 47:
		Serial.println("Orange_to_Purple_gp");
		break;

	case 48:
		Serial.println("Fire_1_gp");
		break;

	case 49:
		Serial.println("standard_gp");
		break;

	case 50:
		Serial.println("a_gp");
		break;

	case 51:
		Serial.println("b_gp");
		break;

	case 52:
		Serial.println("es_emerald_dragon_01_gp");
		break;

	case 53:
		Serial.println("es_landscape_59_gp");
		break;

	case 54:
		Serial.println("es_seadreams_09_gp");
		break;

	case 55:
		Serial.println("froth316_gp");
		break;

	case 56:
		Serial.println("Skydye11_gp");
		break;

	case 57:
		Serial.println("Wizzl019_gp");
		break;

	case 58:
		Serial.println("Tropical_Colors_gp");
		break;

	case 59:
		Serial.println("slope_gp");
		break;

	case 60:
		Serial.println("ofaurora_gp");
		break;

	case 61:
		Serial.println("hallows_gp");
		break;

	case 62:
		Serial.println("sea_treasure_gp");
		break;

	case 63:
		Serial.println("Secondary_01a_gp");
		break;

	case 64:
		Serial.println("Split_03_gp");
		break;

	case 65:
		Serial.println("GMT_seafloor_gp");
		break;

	case 66:
		Serial.println("rainbow_gp");
		break;

	case 67:
		Serial.println("cloudcolors_gp");
		break;

	case 68:
		Serial.println("cequal_gp");
		break;

	case 69:
		Serial.println("purple_flower_gp");
		break;

	case 70:
		Serial.println("fierce_ice_gp");
		break;

	case 71:
		Serial.println("blueice_gp");
		break;

	case 72:
		Serial.println("twilight_gp");
		break;

	case 73:
		Serial.println("green_gp");
		break;

	case 74:
		Serial.println("ultraviolet_mold_gp");
		break;

	case 75:
		Serial.println("apple_green_gp");
		break;

	case 76:
		Serial.println("faint_rainbow_gp");
		break;

	case 77:
		Serial.println("otis_gp");
		break;

	case 78:
		Serial.println("parrot_gp");
		break;

	case 79:
		Serial.println("scoutie_gp");
		break;

	case 80:
		Serial.println("sunlitwave_gp");
		break;

	case 81:
		Serial.println("GMT_cool_gp");
		break;

	case 82:
		Serial.println("bhw1_sunconure_gp");
		break;

	case 83:
		Serial.println("bhw1_05_gp");
		break;

	case 84:
		Serial.println("bhw2_turq_gp");
		break;

	case 85:
		Serial.println("bhw3_13_gp");
		break;

	case 86:
		Serial.println("bhw3_61_gp");
		break;

	case 87:
		Serial.println("bhw4_009_gp");
		break;

	case 88:
		Serial.println("bhw3_34_gp");
		break;

	case 89:
		Serial.println("es_emerald_dragon_09_gp");
		break;

	case 90:
		Serial.println("xanidu_2_gp");
		break;

	case 91:
		Serial.println("water1_gp");
		break;

	case 92:
		Serial.println("stratosphere_sunset_gp");
		break;

	case 93:
		Serial.println("RedsandCyans_gp");
		break;

	case 94:
		Serial.println("Cyan_Magenta_Blue_gp");
		break;

	case 95:
		Serial.println("Complementary_01a_gp");
		break;

	case 96:
		Serial.println("cyberpunk_neon_gp");
		break;

	case 97:
		Serial.println("blue_fire_gp");
		break;

	case 98:
		Serial.println("purplefly_gp");
		break;

	case 99:
		Serial.println("rainbow2_gp");
		break;

	default:
		Serial.println("Not a gradient palette");
		break;
	}
}

// Display Variables
void display_variables() {
	Serial.println("-------------------------------------------");
	Serial.println("|         Operational Variables           |");
	Serial.println("-------------------------------------------");
	Serial.print("|   fade_val (H) | ");
	Serial.println(fade_val);
	Serial.print("| this_delay (d) | ");
	Serial.println(this_delay);
	Serial.print("| max_bright (I) | ");
	Serial.println(max_bright);
	Serial.println(" ");
	if (use_palette) {
		Serial.println("-------------------------------------------");
		Serial.println("|            Palette Variables            |");
		Serial.println("-------------------------------------------");
		Serial.print("|                 use_palette (A) | ");
		Serial.println(use_palette);
		Serial.print("|              palette_number (C) | ");
		Serial.println(palette_number);
		Serial.print("|                  target_palette | ");
		print_palette(palette_number);
		Serial.print("|          palette_index_beat (D) | ");
		Serial.println(palette_index_beat);
		Serial.print("|  palette_index_forward_beat (E) | ");
		Serial.println(palette_index_forward_beat);
		Serial.print("| palette_index_backward_beat (F) | ");
		Serial.println(palette_index_backward_beat);
		Serial.println(" ");
	}
	Serial.println("-------------------------------------------");
	Serial.println("|          Positional Variables           |");
	Serial.println("-------------------------------------------");
	Serial.print("|      position_beat (J) | ");
	Serial.println(position_beat);
	Serial.print("|      forward_range (K) | ");
	Serial.println(forward_range);
	Serial.print("|       forward_beat (L) | ");
	Serial.println(forward_beat);
	Serial.print("|     backward_range (N) | ");
	Serial.println(backward_range);
	Serial.print("|      backward_beat (O) | ");
	Serial.println(backward_beat);
	Serial.println("-------------------------------------------");
	Serial.println(" ");
  Serial.println("-------------------------------------------");
  Serial.println("|             Toggle  Variables           |");
  Serial.println("-------------------------------------------");
  Serial.print("|     use_palette_beat (R) | ");
  Serial.println(use_palette_beat);
  Serial.print("|   show_active_pixels (Q) | ");
  Serial.println(show_active_pixels);
  Serial.print("|       palette_switch (G) | ");
  Serial.println(palette_switch);
  Serial.print("|       paletteChanges (B) | ");
  Serial.println(paletteChanges);
  Serial.print("|          use_palette (A) | ");
  Serial.println(use_palette);
  Serial.print("|             additive (T) | ");
  Serial.println(additive);
  Serial.println("-------------------------------------------");
  Serial.println(" ");
}

#endif
