
#ifndef GRADIENT_PALETTES_H
#define GRADIENT_PALETTES_H

#include <FastLED.h>

// From ColorWavesWithPalettes by Mark Kriegsman: https://gist.github.com/kriegsman/8281905786e8b2632aeb

// Gradient Color Palette definitions for 33 different cpt-city color palettes.
//    956 bytes of PROGMEM for all of the palettes together,
//   +618 bytes of PROGMEM for gradient palette code (AVR).
//  1,494 bytes total for all 34 color palettes and associated code.

// Gradient palette "ib_jul01_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ing/xmas/tn/ib_jul01.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(ib_jul01_gp) {
	0, 194, 1, 1,
		94, 1, 29, 18,
		132, 57, 131, 28,
		255, 113, 1, 1
};

// Gradient palette "es_vintage_57_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/vintage/tn/es_vintage_57.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

//DEFINE_GRADIENT_PALETTE( es_vintage_57_gp ) {
//    0,   2,  1,  1,
//   53,  18,  1,  0,
//  104,  69, 29,  1,
//  153, 167,135, 10,
//  255,  46, 56,  4};

// Gradient palette "es_vintage_01_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/vintage/tn/es_vintage_01.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

//DEFINE_GRADIENT_PALETTE( es_vintage_01_gp ) {
//    0,   4,  1,  1,
//   51,  16,  0,  1,
//   76,  97,104,  3,
//  101, 255,131, 19,
//  127,  67,  9,  4,
//  153,  16,  0,  1,
//  229,   4,  1,  1,
//  255,   4,  1,  1};

// Gradient palette "es_rivendell_15_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/rivendell/tn/es_rivendell_15.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

//DEFINE_GRADIENT_PALETTE( es_rivendell_15_gp ) {
//    0,   1, 14,  5,
//  101,  16, 36, 14,
//  165,  56, 68, 30,
//  242, 150,156, 99,
//  255, 150,156, 99};

// Gradient palette "rgi_15_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/rgi/tn/rgi_15.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE(rgi_15_gp) {
	0, 4, 1, 31,
		31, 55, 1, 16,
		63, 197, 3, 7,
		95, 59, 2, 17,
		127, 6, 2, 34,
		159, 39, 6, 33,
		191, 112, 13, 32,
		223, 56, 9, 35,
		255, 22, 6, 38
};

// Gradient palette "retro2_16_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ma/retro2/tn/retro2_16.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space.

//DEFINE_GRADIENT_PALETTE( retro2_16_gp ) {
//    0, 188,135,  1,
//  255,  46,  7,  1};

// Gradient palette "Analogous_1_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/red/tn/Analogous_1.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(Analogous_1_gp) {
	0, 3, 0, 255,
		63, 23, 0, 255,
		127, 67, 0, 255,
		191, 142, 0, 45,
		255, 255, 0, 0
};

// Gradient palette "es_pinksplash_08_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/pink_splash/tn/es_pinksplash_08.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_pinksplash_08_gp) {
	0, 126, 11, 255,
		127, 197, 1, 22,
		175, 210, 157, 172,
		221, 157, 3, 112,
		255, 157, 3, 112
};

// Gradient palette "es_pinksplash_07_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/pink_splash/tn/es_pinksplash_07.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_pinksplash_07_gp) {
	0, 229, 1, 1,
		61, 242, 4, 63,
		101, 255, 12, 255,
		127, 249, 81, 252,
		153, 255, 11, 235,
		193, 244, 5, 68,
		255, 232, 1, 5
};

// Gradient palette "Coral_reef_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/other/tn/Coral_reef.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE(Coral_reef_gp) {
	0, 40, 199, 197,
		50, 10, 152, 155,
		96, 1, 111, 120,
		96, 43, 127, 162,
		139, 10, 73, 111,
		255, 1, 34, 71
};

// Gradient palette "es_ocean_breeze_068_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/ocean_breeze/tn/es_ocean_breeze_068.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_ocean_breeze_068_gp) {
	0, 100, 156, 153,
		51, 1, 99, 137,
		101, 1, 68, 84,
		104, 35, 142, 168,
		178, 0, 63, 117,
		255, 1, 10, 10
};

// Gradient palette "es_ocean_breeze_036_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/ocean_breeze/tn/es_ocean_breeze_036.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_ocean_breeze_036_gp) {
	0, 1, 6, 7,
		89, 1, 99, 111,
		153, 144, 209, 255,
		255, 0, 73, 82
};

// Gradient palette "departure_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/mjf/tn/departure.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 88 bytes of program space.

//DEFINE_GRADIENT_PALETTE( departure_gp ) {
//    0,   8,  3,  0,
//   42,  23,  7,  0,
//   63,  75, 38,  6,
//   84, 169, 99, 38,
//  106, 213,169,119,
//  116, 255,255,255,
//  138, 135,255,138,
//  148,  22,255, 24,
//  170,   0,255,  0,
//  191,   0,136,  0,
//  212,   0, 55,  0,
//  255,   0, 55,  0};

// Gradient palette "es_landscape_64_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/landscape/tn/es_landscape_64.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_landscape_64_gp) {
	0, 0, 0, 0,
		37, 2, 25, 1,
		76, 15, 115, 5,
		127, 79, 213, 1,
		128, 126, 211, 47,
		130, 188, 209, 247,
		153, 144, 182, 205,
		204, 59, 117, 250,
		255, 1, 37, 192
};

// Gradient palette "es_landscape_33_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/landscape/tn/es_landscape_33.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_landscape_33_gp) {
	0, 1, 5, 0,
		19, 32, 23, 1,
		38, 161, 55, 1,
		63, 229, 144, 1,
		66, 39, 142, 74,
		255, 1, 4, 1
};

// Gradient palette "rainbowsherbet_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ma/icecream/tn/rainbowsherbet.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(rainbowsherbet_gp) {
	0, 255, 33, 4,
		43, 255, 68, 25,
		86, 255, 7, 25,
		127, 255, 82, 103,
		170, 255, 255, 242,
		209, 42, 255, 22,
		255, 87, 255, 65
};

// Gradient palette "gr65_hult_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/hult/tn/gr65_hult.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE(gr65_hult_gp) {
	0, 247, 176, 247,
		48, 255, 136, 255,
		89, 220, 29, 226,
		160, 7, 82, 178,
		216, 1, 124, 109,
		255, 1, 124, 109
};

// Gradient palette "gr64_hult_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/hult/tn/gr64_hult.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE(gr64_hult_gp) {
	0, 1, 124, 109,
		66, 1, 93, 79,
		104, 52, 65, 1,
		130, 115, 127, 1,
		150, 52, 65, 1,
		201, 1, 86, 72,
		239, 0, 55, 45,
		255, 0, 55, 45
};

// Gradient palette "GMT_drywet_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/gmt/tn/GMT_drywet.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(GMT_drywet_gp) {
	0, 47, 30, 2,
		42, 213, 147, 24,
		84, 103, 219, 52,
		127, 3, 219, 207,
		170, 1, 48, 214,
		212, 1, 1, 111,
		255, 1, 7, 33
};

// Gradient palette "ib15_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ing/general/tn/ib15.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE(ib15_gp) {
	0, 113, 91, 147,
		72, 157, 88, 78,
		89, 208, 85, 33,
		107, 255, 29, 11,
		141, 137, 31, 39,
		255, 59, 33, 89
};

// Gradient palette "Fuschia_7_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/fuschia/tn/Fuschia-7.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(Fuschia_7_gp) {
	0, 43, 3, 153,
		63, 100, 4, 103,
		127, 188, 5, 66,
		191, 161, 11, 115,
		255, 135, 20, 182
};

// Gradient palette "es_emerald_dragon_08_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/emerald_dragon/tn/es_emerald_dragon_08.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_emerald_dragon_08_gp) {
	0, 97, 255, 1,
		101, 47, 133, 1,
		178, 13, 43, 1,
		255, 2, 10, 1
};

// Gradient palette "lava_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/elem/tn/lava.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE(lava_gp) {
	0, 0, 0, 0,
		46, 18, 0, 0,
		96, 113, 0, 0,
		108, 142, 3, 1,
		119, 175, 17, 1,
		146, 213, 44, 2,
		174, 255, 82, 4,
		188, 255, 115, 4,
		202, 255, 156, 4,
		218, 255, 203, 4,
		234, 255, 255, 4,
		244, 255, 255, 71,
		255, 255, 255, 255
};

// Gradient palette "fire_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/elem/tn/fire.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(fire_gp) {
	0, 1, 1, 0,
		76, 32, 5, 0,
		146, 192, 24, 0,
		197, 220, 105, 5,
		240, 252, 255, 31,
		250, 252, 255, 111,
		255, 255, 255, 255
};

// Gradient palette "Colorfull_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Colorfull.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE(Colorfull_gp) {
	0, 10, 85, 5,
		25, 29, 109, 18,
		60, 59, 138, 42,
		93, 83, 99, 52,
		106, 110, 66, 64,
		109, 123, 49, 65,
		113, 139, 35, 66,
		116, 192, 117, 98,
		124, 255, 255, 137,
		168, 100, 180, 155,
		255, 22, 121, 174
};

// Gradient palette "Magenta_Evening_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Magenta_Evening.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(Magenta_Evening_gp) {
	0, 71, 27, 39,
		31, 130, 11, 51,
		63, 213, 2, 64,
		70, 232, 1, 66,
		76, 252, 1, 69,
		108, 123, 2, 51,
		255, 46, 9, 35
};

// Gradient palette "Pink_Purple_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Pink_Purple.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

//DEFINE_GRADIENT_PALETTE( Pink_Purple_gp ) {
//    0,  19,  2, 39,
//   25,  26,  4, 45,
//   51,  33,  6, 52,
//   76,  68, 62,125,
//  102, 118,187,240,
//  109, 163,215,247,
//  114, 217,244,255,
//  122, 159,149,221,
//  149, 113, 78,188,
//  183, 128, 57,155,
//  255, 146, 40,123};

// Gradient palette "Sunset_Real_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Sunset_Real.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(Sunset_Real_gp) {
	0, 120, 0, 0,
		22, 179, 22, 0,
		51, 255, 104, 0,
		85, 167, 22, 18,
		135, 100, 0, 103,
		198, 16, 0, 130,
		255, 0, 0, 160
};

// Gradient palette "es_autumn_19_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/autumn/tn/es_autumn_19.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_autumn_19_gp) {
	0, 26, 1, 1,
		51, 67, 4, 1,
		84, 118, 14, 1,
		104, 137, 152, 52,
		112, 113, 65, 1,
		122, 133, 149, 59,
		124, 137, 152, 52,
		135, 113, 65, 1,
		142, 139, 154, 46,
		163, 113, 13, 1,
		204, 55, 3, 1,
		249, 17, 1, 1,
		255, 17, 1, 1
};

// Gradient palette "BlacK_Blue_Magenta_White_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Blue_Magenta_White.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(BlacK_Blue_Magenta_White_gp) {
	0, 0, 0, 0,
		42, 0, 0, 45,
		84, 0, 0, 255,
		127, 42, 0, 255,
		170, 255, 0, 255,
		212, 255, 55, 255,
		255, 255, 255, 255
};

// Gradient palette "BlacK_Magenta_Red_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Magenta_Red.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(BlacK_Magenta_Red_gp) {
	0, 0, 0, 0,
		63, 42, 0, 45,
		127, 255, 0, 255,
		191, 255, 0, 45,
		255, 255, 0, 0
};

// Gradient palette "BlacK_Red_Magenta_Yellow_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Red_Magenta_Yellow.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(BlacK_Red_Magenta_Yellow_gp) {
	0, 0, 0, 0,
		42, 42, 0, 0,
		84, 255, 0, 0,
		127, 255, 0, 45,
		170, 255, 0, 255,
		212, 255, 55, 45,
		255, 255, 255, 0
};

// Gradient palette "Blue_Cyan_Yellow_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/Blue_Cyan_Yellow.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(Blue_Cyan_Yellow_gp) {
	0, 0, 0, 255,
		63, 0, 55, 255,
		127, 0, 255, 255,
		191, 42, 255, 45,
		255, 255, 255, 0
};



// Gradient palette "bhw1_greeny_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_greeny.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw1_greeny_gp) {
	0, 0, 0, 0,
		39, 7, 55, 8,
		99, 42, 255, 45,
		153, 7, 55, 8,
		255, 0, 0, 0
};

// Gradient palette "bhw1_26_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_26.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw1_26_gp) {
	0, 107, 1, 205,
		35, 255, 255, 255,
		73, 107, 1, 205,
		107, 10, 149, 210,
		130, 255, 255, 255,
		153, 10, 149, 210,
		170, 27, 175, 119,
		198, 53, 203, 56,
		207, 132, 229, 135,
		219, 255, 255, 255,
		231, 132, 229, 135,
		252, 53, 203, 56,
		255, 53, 203, 56
};

// Gradient palette "bhw1_28_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_28.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw1_28_gp) {
	0, 75, 1, 221,
		30, 252, 73, 255,
		48, 169, 0, 242,
		119, 0, 149, 242,
		170, 43, 0, 242,
		206, 252, 73, 255,
		232, 78, 12, 214,
		255, 0, 149, 242
};

// Gradient palette "bhw2_23_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_23.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw2_23_gp) {
	0, 0, 0, 0,
		66, 57, 227, 233,
		96, 255, 255, 8,
		124, 255, 255, 255,
		153, 255, 255, 8,
		188, 57, 227, 233,
		255, 0, 0, 0
};


// Gradient palette "bhw2_22_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_22.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw2_22_gp) {
	0, 0, 0, 0,
		99, 227, 1, 1,
		130, 249, 199, 95,
		155, 227, 1, 1,
		255, 0, 0, 0
};

// Gradient palette "bhw2_49_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_49.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw2_49_gp) {
	0, 9, 15, 15,
		40, 0, 55, 45,
		86, 9, 15, 15,
		130, 29, 41, 62,
		170, 9, 15, 15,
		211, 64, 8, 199,
		255, 6, 1, 22
};

// Gradient palette "bhw2_10_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_10.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw2_10_gp) {
	0, 0, 12, 0,
		61, 153, 239, 112,
		127, 0, 12, 0,
		165, 106, 239, 2,
		196, 167, 229, 71,
		229, 106, 239, 2,
		255, 0, 12, 0
};

// Gradient palette "bhw2_14_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_14.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw2_14_gp) {
	0, 0, 0, 8,
		45, 0, 0, 45,
		79, 7, 12, 255,
		119, 42, 55, 255,
		158, 7, 12, 255,
		209, 0, 0, 45,
		255, 0, 0, 8
};

// Gradient palette "bhw3_21_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw3/tn/bhw3_21.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw3_21_gp) {
	0, 1, 40, 98,
		48, 1, 65, 68,
		76, 2, 161, 96,
		104, 0, 81, 25,
		130, 65, 182, 82,
		153, 0, 86, 170,
		181, 17, 207, 182,
		204, 17, 207, 182,
		255, 1, 23, 46
};

// Gradient palette "bhw3_30_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw3/tn/bhw3_30.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw3_30_gp) {
	0, 1, 4, 1,
		12, 1, 28, 2,
		28, 16, 68, 11,
		58, 18, 11, 28,
		79, 31, 27, 48,
		96, 2, 13, 34,
		117, 30, 86, 123,
		135, 2, 42, 62,
		153, 74, 128, 155,
		181, 60, 31, 41,
		214, 167, 211, 223,
		237, 179, 70, 78,
		255, 57, 2, 7
};

// Gradient palette "vibrant_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pj/4/tn/vibrant.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(vibrant_gp) {
	0, 255, 255, 255,
		30, 1, 144, 29,
		71, 229, 246, 12,
		119, 255, 1, 8,
		165, 184, 1, 203,
		214, 3, 28, 250,
		255, 0, 0, 0
};

// Gradient palette "cw1_029_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/cw/1/tn/cw1-029.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space.

DEFINE_GRADIENT_PALETTE(cw1_029_gp) {
	0, 12, 80, 210,
		127, 255, 235, 19,
		255, 224, 66, 15
};

// Gradient palette "alarm_p4_0_2_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/dca/tn/alarm.p4.0.2.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 84 bytes of program space.

DEFINE_GRADIENT_PALETTE(alarm_p4_0_2_gp) {
	0, 227, 255, 223,
		12, 255, 36, 4,
		25, 255, 2, 1,
		38, 255, 1, 16,
		51, 255, 1, 98,
		63, 255, 1, 230,
		76, 140, 1, 255,
		89, 63, 1, 255,
		102, 24, 1, 255,
		114, 5, 1, 255,
		127, 1, 1, 255,
		140, 1, 4, 255,
		153, 1, 16, 255,
		165, 1, 36, 255,
		178, 1, 62, 255,
		191, 1, 95, 255,
		204, 1, 131, 255,
		216, 1, 173, 255,
		229, 1, 221, 255,
		242, 1, 255, 235,
		255, 1, 255, 186
};

// Gradient palette "Ribbon_Colors_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/icons/tn/Ribbon-Colors.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE(Ribbon_Colors_gp) {
	0, 227, 2, 9,
		31, 194, 51, 9,
		63, 167, 175, 8,
		95, 27, 209, 78,
		127, 1, 248, 247,
		159, 1, 78, 166,
		191, 1, 5, 102,
		223, 42, 79, 18,
		255, 255, 255, 0
};

// Gradient palette "Orange_to_Purple_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/icons/tn/Orange-to-Purple.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space.

DEFINE_GRADIENT_PALETTE(Orange_to_Purple_gp) {
	0, 208, 50, 1,
		127, 146, 27, 45,
		255, 97, 12, 178
};

// Gradient palette "Fire_1_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/icons/tn/Fire-1.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space.

DEFINE_GRADIENT_PALETTE(Fire_1_gp) {
	0, 255, 0, 0,
		127, 255, 55, 0,
		255, 255, 255, 0
};

// Gradient palette "standard_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds9/tn/standard.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE(standard_gp) {
	0, 0, 0, 0,
		84, 10, 17, 255,
		84, 0, 17, 0,
		169, 10, 255, 12,
		169, 10, 0, 0,
		255, 255, 17, 12
};

// Gradient palette "a_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds9/tn/a.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(a_gp) {
	0, 0, 0, 0,
		31, 0, 55, 0,
		63, 0, 255, 45,
		127, 255, 0, 255,
		163, 255, 0, 45,
		196, 255, 0, 0,
		255, 255, 255, 0
};

// Gradient palette "b_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds9/tn/b.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(b_gp) {
	0, 0, 0, 0,
		63, 0, 0, 255,
		127, 255, 0, 0,
		191, 255, 255, 0,
		255, 255, 255, 255
};

// Gradient palette "es_emerald_dragon_01_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/emerald_dragon/tn/es_emerald_dragon_01.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_emerald_dragon_01_gp) {
	0, 1, 1, 1,
		79, 1, 19, 7,
		130, 1, 59, 25,
		229, 28, 255, 255,
		255, 28, 255, 255
};

// Gradient palette "es_landscape_59_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/landscape/tn/es_landscape_59.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

//DEFINE_GRADIENT_PALETTE( es_landscape_59_gp ) {
//    0, 215,114,  9,
//   51, 255,182, 34,
//   89, 255,205, 48,
//   94, 213,229,210,
//  153, 106,161,145,
//  204,  20,101,111,
//  255,   1, 48, 75};

// Gradient palette "es_seadreams_09_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/sea_dreams/tn/es_seadreams_09.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

//DEFINE_GRADIENT_PALETTE( es_seadreams_09_gp ) {
//    0, 121,136,125,
//   58,  34, 97,166,
//  101,   2, 66,212,
//  119,   2, 29,182,
//  153,   3,  8,153,
//  255,  82,107,178};

 // Gradient palette "froth316_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/fractint/base/tn/froth316.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 120 bytes of program space.

DEFINE_GRADIENT_PALETTE(froth316_gp) {
	0, 247, 0, 0,
		17, 247, 0, 0,
		17, 157, 0, 0,
		33, 157, 0, 0,
		33, 86, 0, 0,
		51, 86, 0, 0,
		51, 39, 0, 0,
		68, 39, 0, 0,
		68, 12, 0, 0,
		84, 12, 0, 0,
		84, 0, 248, 0,
		102, 0, 248, 0,
		102, 0, 169, 0,
		119, 0, 169, 0,
		119, 0, 101, 0,
		135, 0, 101, 0,
		135, 0, 52, 0,
		153, 0, 52, 0,
		153, 0, 19, 0,
		170, 0, 19, 0,
		170, 0, 0, 247,
		186, 0, 0, 247,
		186, 0, 0, 160,
		204, 0, 0, 160,
		204, 0, 0, 89,
		221, 0, 0, 89,
		221, 0, 0, 42,
		237, 0, 0, 42,
		237, 0, 0, 14,
		255, 0, 0, 14
};

// Gradient palette "Skydye11_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/fractint/midtones/tn/Skydye11.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 2016 bytes of program space.

DEFINE_GRADIENT_PALETTE(Skydye11_gp) {
	0, 8, 0, 4,
		1, 8, 0, 4,
		2, 12, 0, 8,
		3, 16, 0, 12,
		4, 20, 0, 12,
		5, 20, 0, 16,
		6, 24, 0, 16,
		7, 28, 0, 20,
		9, 28, 0, 20,
		10, 32, 0, 24,
		11, 36, 0, 24,
		12, 36, 0, 28,
		13, 40, 0, 28,
		14, 44, 0, 32,
		15, 48, 0, 36,
		16, 52, 0, 36,
		17, 56, 0, 40,
		18, 60, 0, 44,
		20, 60, 0, 44,
		21, 64, 0, 48,
		22, 68, 0, 52,
		23, 72, 0, 52,
		24, 76, 0, 56,
		25, 76, 4, 56,
		26, 80, 4, 60,
		27, 84, 4, 60,
		28, 88, 4, 64,
		29, 92, 4, 68,
		30, 96, 8, 72,
		31, 96, 8, 76,
		32, 92, 8, 80,
		33, 88, 8, 84,
		34, 84, 8, 92,
		35, 84, 8, 96,
		36, 80, 8, 104,
		37, 76, 8, 108,
		38, 72, 8, 112,
		39, 72, 8, 120,
		40, 68, 8, 124,
		41, 64, 8, 132,
		42, 60, 8, 136,
		43, 60, 8, 144,
		44, 56, 8, 148,
		45, 52, 8, 152,
		46, 48, 8, 160,
		47, 48, 4, 164,
		48, 44, 4, 172,
		49, 40, 4, 176,
		50, 36, 4, 180,
		51, 36, 4, 188,
		52, 32, 4, 192,
		53, 28, 4, 200,
		54, 24, 4, 204,
		55, 24, 4, 212,
		56, 20, 4, 216,
		57, 16, 4, 220,
		58, 12, 4, 228,
		59, 12, 4, 232,
		60, 8, 4, 240,
		61, 4, 4, 244,
		62, 0, 0, 252,
		63, 0, 4, 248,
		64, 0, 12, 244,
		65, 0, 20, 240,
		66, 0, 28, 236,
		67, 0, 36, 232,
		68, 0, 44, 228,
		69, 0, 52, 224,
		70, 0, 60, 220,
		71, 0, 68, 216,
		72, 0, 76, 212,
		73, 0, 84, 208,
		74, 0, 92, 204,
		75, 0, 100, 200,
		76, 0, 108, 196,
		77, 0, 116, 192,
		78, 0, 124, 188,
		79, 0, 132, 184,
		80, 0, 140, 180,
		81, 0, 148, 176,
		82, 0, 156, 172,
		83, 0, 164, 168,
		84, 0, 172, 164,
		85, 0, 180, 160,
		86, 0, 188, 156,
		87, 0, 196, 152,
		88, 0, 204, 148,
		89, 0, 212, 144,
		90, 0, 220, 140,
		91, 0, 228, 136,
		92, 0, 236, 132,
		93, 0, 232, 124,
		94, 0, 224, 120,
		95, 0, 220, 112,
		96, 0, 216, 104,
		97, 0, 208, 96,
		98, 0, 200, 92,
		99, 0, 192, 88,
		100, 0, 184, 80,
		101, 0, 172, 76,
		102, 0, 164, 68,
		103, 0, 156, 64,
		104, 0, 148, 56,
		105, 0, 140, 52,
		106, 0, 128, 44,
		107, 0, 120, 40,
		108, 0, 112, 32,
		109, 0, 104, 28,
		110, 0, 92, 20,
		111, 0, 84, 16,
		112, 0, 76, 8,
		113, 0, 64, 0,
		114, 0, 60, 0,
		115, 0, 56, 0,
		116, 0, 52, 0,
		117, 0, 48, 0,
		118, 0, 44, 0,
		119, 0, 40, 0,
		120, 0, 36, 0,
		121, 4, 32, 0,
		122, 4, 28, 0,
		123, 4, 24, 0,
		124, 4, 20, 0,
		125, 4, 16, 0,
		126, 4, 12, 0,
		127, 4, 8, 0,
		128, 4, 4, 0,
		129, 8, 0, 4,
		130, 12, 0, 8,
		131, 16, 0, 12,
		132, 20, 0, 12,
		133, 20, 0, 16,
		134, 24, 0, 16,
		135, 28, 0, 20,
		136, 32, 0, 20,
		137, 32, 0, 24,
		138, 36, 0, 24,
		139, 40, 0, 28,
		140, 44, 0, 32,
		141, 48, 0, 36,
		142, 52, 4, 36,
		143, 56, 4, 40,
		145, 56, 4, 40,
		146, 60, 4, 44,
		147, 64, 4, 48,
		148, 68, 4, 48,
		149, 68, 4, 52,
		150, 72, 4, 52,
		151, 76, 4, 56,
		152, 80, 4, 56,
		153, 80, 4, 60,
		154, 84, 4, 60,
		155, 88, 4, 64,
		156, 92, 4, 68,
		157, 96, 8, 72,
		158, 96, 8, 76,
		159, 104, 8, 72,
		160, 112, 8, 68,
		161, 124, 8, 64,
		162, 132, 8, 60,
		163, 144, 8, 52,
		164, 152, 8, 48,
		165, 164, 8, 44,
		166, 172, 8, 40,
		167, 180, 4, 36,
		168, 192, 4, 32,
		169, 200, 4, 28,
		170, 212, 4, 20,
		171, 220, 4, 16,
		172, 232, 4, 12,
		173, 240, 4, 8,
		174, 252, 0, 0,
		175, 252, 8, 0,
		176, 252, 20, 0,
		177, 252, 28, 0,
		178, 252, 40, 0,
		179, 252, 48, 0,
		180, 252, 60, 0,
		181, 252, 68, 0,
		182, 252, 80, 0,
		183, 252, 88, 0,
		184, 252, 100, 0,
		185, 252, 108, 0,
		186, 252, 120, 0,
		187, 252, 132, 0,
		188, 252, 140, 0,
		189, 252, 152, 0,
		190, 252, 160, 0,
		191, 252, 172, 0,
		192, 252, 180, 0,
		193, 252, 192, 0,
		194, 252, 200, 0,
		195, 252, 212, 0,
		196, 252, 220, 0,
		197, 252, 232, 0,
		198, 252, 240, 0,
		199, 252, 252, 0,
		200, 252, 240, 0,
		201, 252, 232, 0,
		202, 252, 220, 0,
		203, 252, 208, 0,
		204, 252, 196, 0,
		205, 252, 188, 0,
		206, 252, 176, 0,
		207, 252, 164, 0,
		208, 252, 152, 0,
		209, 252, 144, 0,
		210, 252, 132, 0,
		211, 252, 120, 0,
		212, 252, 112, 0,
		213, 252, 100, 0,
		214, 252, 88, 0,
		215, 252, 76, 0,
		216, 252, 68, 0,
		217, 252, 56, 0,
		218, 252, 44, 0,
		219, 252, 32, 0,
		220, 252, 24, 0,
		221, 252, 12, 0,
		222, 252, 0, 0,
		223, 244, 0, 4,
		224, 236, 0, 8,
		225, 224, 0, 12,
		226, 216, 0, 16,
		227, 204, 0, 24,
		228, 196, 0, 28,
		229, 184, 0, 32,
		230, 176, 4, 36,
		231, 168, 4, 40,
		232, 156, 4, 44,
		233, 148, 4, 48,
		234, 136, 4, 56,
		235, 128, 4, 60,
		236, 116, 4, 64,
		237, 108, 4, 68,
		238, 96, 8, 76,
		239, 92, 8, 72,
		240, 84, 8, 68,
		241, 80, 8, 64,
		242, 72, 8, 56,
		243, 68, 4, 52,
		244, 60, 4, 48,
		245, 56, 4, 44,
		246, 48, 4, 40,
		247, 44, 4, 32,
		248, 36, 4, 28,
		249, 32, 4, 24,
		250, 24, 4, 20,
		251, 20, 0, 16,
		252, 12, 0, 8,
		253, 0, 0, 0,
		254, 4, 0, 4,
		255, 4, 0, 4
};

// Gradient palette "Wizzl019_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/fractint/jewelmap/tn/Wizzl019.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 2040 bytes of program space.

DEFINE_GRADIENT_PALETTE(Wizzl019_gp) {
	0, 140, 20, 172,
		1, 140, 20, 172,
		2, 148, 20, 184,
		3, 160, 16, 200,
		4, 156, 16, 196,
		5, 152, 16, 188,
		6, 148, 16, 180,
		7, 140, 12, 172,
		8, 136, 12, 164,
		9, 132, 12, 156,
		10, 128, 12, 148,
		11, 120, 8, 140,
		12, 116, 8, 136,
		13, 112, 8, 128,
		14, 108, 8, 120,
		15, 100, 4, 112,
		16, 96, 4, 104,
		17, 92, 4, 96,
		18, 88, 4, 88,
		19, 80, 0, 80,
		20, 84, 4, 76,
		21, 92, 12, 72,
		22, 100, 20, 68,
		23, 108, 28, 60,
		24, 116, 36, 56,
		25, 124, 44, 52,
		26, 132, 52, 48,
		27, 140, 60, 40,
		28, 144, 64, 36,
		29, 152, 72, 32,
		30, 160, 80, 28,
		31, 168, 88, 20,
		32, 176, 96, 16,
		33, 184, 104, 12,
		34, 192, 112, 8,
		35, 200, 120, 0,
		36, 196, 116, 0,
		37, 188, 112, 0,
		38, 180, 108, 0,
		39, 172, 100, 0,
		40, 164, 96, 0,
		41, 156, 92, 0,
		42, 148, 88, 0,
		43, 140, 80, 0,
		44, 136, 76, 0,
		45, 128, 72, 0,
		46, 120, 68, 0,
		47, 112, 60, 0,
		48, 104, 56, 0,
		49, 96, 52, 0,
		50, 88, 48, 0,
		51, 80, 40, 0,
		52, 76, 48, 4,
		53, 72, 60, 8,
		54, 68, 68, 12,
		55, 60, 80, 20,
		56, 56, 88, 24,
		57, 52, 100, 28,
		58, 48, 108, 32,
		59, 40, 120, 40,
		60, 36, 128, 44,
		61, 32, 140, 48,
		62, 28, 148, 52,
		63, 20, 160, 60,
		64, 16, 168, 64,
		65, 12, 180, 68,
		66, 8, 188, 72,
		67, 0, 200, 80,
		68, 0, 192, 76,
		69, 0, 180, 72,
		70, 0, 172, 68,
		71, 0, 160, 60,
		72, 0, 152, 56,
		73, 0, 140, 52,
		74, 0, 132, 48,
		75, 0, 120, 40,
		76, 0, 112, 36,
		77, 0, 100, 32,
		78, 0, 92, 28,
		79, 0, 80, 20,
		80, 0, 72, 16,
		81, 0, 60, 12,
		82, 0, 52, 8,
		83, 0, 40, 0,
		84, 0, 40, 12,
		85, 4, 36, 28,
		86, 4, 36, 44,
		87, 8, 32, 60,
		88, 12, 28, 72,
		89, 12, 28, 88,
		90, 16, 24, 104,
		91, 20, 20, 120,
		92, 20, 20, 132,
		93, 24, 16, 148,
		94, 24, 16, 164,
		95, 28, 12, 180,
		96, 32, 8, 192,
		97, 32, 8, 208,
		98, 36, 4, 224,
		99, 40, 0, 240,
		100, 40, 0, 232,
		101, 36, 0, 220,
		102, 36, 0, 212,
		103, 32, 0, 200,
		104, 28, 0, 192,
		105, 28, 0, 180,
		106, 24, 0, 172,
		107, 20, 0, 160,
		108, 20, 0, 152,
		109, 16, 0, 140,
		110, 16, 0, 132,
		111, 12, 0, 120,
		112, 8, 0, 112,
		113, 8, 0, 100,
		114, 4, 0, 92,
		115, 0, 0, 80,
		116, 12, 0, 84,
		117, 24, 0, 92,
		118, 36, 0, 100,
		119, 48, 0, 108,
		120, 60, 0, 116,
		121, 72, 0, 124,
		122, 84, 0, 132,
		123, 100, 0, 140,
		124, 112, 0, 144,
		125, 124, 0, 152,
		126, 136, 0, 160,
		127, 148, 0, 168,
		128, 160, 0, 176,
		129, 172, 0, 184,
		130, 184, 0, 192,
		131, 200, 0, 200,
		132, 192, 0, 192,
		133, 180, 0, 180,
		134, 172, 0, 172,
		135, 160, 0, 160,
		136, 152, 0, 152,
		137, 140, 0, 140,
		138, 132, 0, 132,
		139, 120, 0, 120,
		140, 112, 0, 112,
		141, 100, 0, 100,
		142, 92, 0, 92,
		143, 80, 0, 80,
		144, 72, 0, 72,
		145, 60, 0, 60,
		146, 52, 0, 52,
		147, 40, 0, 40,
		148, 52, 0, 40,
		149, 64, 0, 40,
		150, 76, 0, 40,
		151, 88, 0, 40,
		152, 100, 0, 40,
		153, 112, 0, 40,
		154, 124, 0, 40,
		155, 140, 0, 36,
		156, 152, 0, 36,
		157, 164, 0, 36,
		158, 176, 0, 36,
		159, 188, 0, 36,
		160, 200, 0, 36,
		161, 212, 0, 36,
		162, 224, 0, 36,
		163, 240, 0, 32,
		164, 232, 0, 32,
		165, 220, 0, 28,
		166, 212, 0, 28,
		167, 200, 0, 24,
		168, 192, 0, 24,
		169, 180, 0, 20,
		170, 172, 0, 20,
		171, 160, 0, 16,
		172, 152, 0, 16,
		173, 140, 0, 12,
		174, 132, 0, 12,
		175, 120, 0, 8,
		176, 112, 0, 8,
		177, 100, 0, 4,
		178, 92, 0, 4,
		179, 80, 0, 0,
		180, 88, 8, 0,
		181, 96, 16, 0,
		182, 104, 24, 0,
		183, 116, 32, 0,
		184, 124, 40, 0,
		185, 132, 48, 0,
		186, 140, 56, 0,
		187, 152, 64, 0,
		188, 160, 72, 0,
		189, 168, 80, 0,
		190, 176, 88, 0,
		191, 188, 96, 0,
		192, 196, 104, 0,
		193, 204, 112, 0,
		194, 212, 120, 0,
		195, 224, 128, 0,
		196, 216, 124, 0,
		197, 204, 116, 0,
		198, 192, 112, 0,
		199, 180, 104, 0,
		200, 168, 100, 0,
		201, 160, 92, 0,
		202, 148, 88, 0,
		203, 136, 80, 0,
		204, 124, 72, 0,
		205, 112, 68, 0,
		206, 104, 60, 0,
		207, 92, 56, 0,
		208, 80, 48, 0,
		209, 68, 44, 0,
		210, 56, 36, 0,
		211, 64, 36, 8,
		212, 76, 36, 20,
		213, 88, 36, 28,
		214, 100, 32, 40,
		215, 112, 32, 48,
		216, 124, 32, 60,
		217, 136, 32, 68,
		218, 148, 28, 80,
		219, 156, 28, 88,
		220, 168, 28, 100,
		221, 180, 28, 108,
		222, 192, 24, 120,
		223, 204, 24, 128,
		224, 216, 24, 140,
		225, 228, 24, 148,
		226, 240, 20, 160,
		227, 228, 20, 152,
		228, 212, 20, 140,
		229, 196, 24, 132,
		230, 180, 24, 120,
		231, 168, 24, 112,
		232, 152, 28, 100,
		233, 136, 28, 92,
		234, 120, 32, 80,
		235, 108, 32, 72,
		236, 92, 32, 60,
		237, 76, 36, 52,
		238, 60, 36, 40,
		239, 48, 36, 32,
		240, 32, 40, 20,
		241, 16, 40, 12,
		242, 0, 44, 0,
		243, 8, 44, 12,
		244, 20, 44, 24,
		245, 28, 40, 36,
		246, 40, 40, 48,
		247, 48, 36, 60,
		248, 60, 36, 72,
		249, 68, 32, 84,
		250, 80, 32, 100,
		251, 88, 32, 112,
		252, 100, 28, 124,
		253, 108, 28, 136,
		254, 120, 24, 148,
		255, 128, 24, 160
};

// Gradient palette "Tropical_Colors_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ggr/tn/Tropical_Colors.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 116 bytes of program space.

DEFINE_GRADIENT_PALETTE(Tropical_Colors_gp) {
	0, 1, 4, 1,
		14, 1, 10, 1,
		21, 1, 19, 0,
		35, 1, 42, 1,
		49, 3, 75, 1,
		59, 56, 103, 1,
		70, 208, 135, 4,
		84, 217, 54, 2,
		98, 224, 10, 1,
		130, 117, 15, 3,
		141, 48, 20, 6,
		155, 42, 18, 77,
		170, 36, 17, 255,
		197, 55, 97, 242,
		210, 80, 255, 228,
		220, 47, 219, 77,
		225, 24, 187, 10,
		228, 24, 180, 9,
		230, 24, 171, 8,
		232, 23, 161, 6,
		235, 23, 149, 5,
		237, 22, 136, 4,
		240, 22, 124, 2,
		242, 21, 112, 1,
		245, 21, 100, 1,
		247, 20, 88, 1,
		250, 19, 77, 1,
		252, 19, 66, 1,
		255, 18, 55, 0
};

// Gradient palette "GMT_seafloor_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/gmt/tn/GMT_seafloor.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 88 bytes of program space.

DEFINE_GRADIENT_PALETTE(GMT_seafloor_gp) {
	0, 25, 0, 109,
		10, 28, 0, 119,
		21, 32, 0, 127,
		31, 35, 0, 140,
		42, 27, 1, 145,
		53, 20, 1, 151,
		74, 14, 4, 156,
		84, 9, 9, 164,
		95, 5, 15, 170,
		106, 2, 24, 176,
		116, 1, 35, 182,
		138, 1, 49, 188,
		148, 0, 66, 197,
		159, 1, 79, 203,
		170, 3, 93, 210,
		180, 10, 109, 216,
		191, 24, 128, 223,
		212, 43, 149, 230,
		223, 72, 173, 240,
		233, 112, 197, 247,
		244, 163, 225, 255,
		255, 220, 248, 255
};

// Gradient palette "slope_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/grass/tn/slope.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE(slope_gp) {
	0, 255, 255, 255,
		5, 255, 255, 0,
		14, 0, 255, 0,
		28, 0, 255, 255,
		42, 0, 0, 255,
		84, 255, 0, 255,
		141, 255, 0, 0,
		255, 0, 0, 0
};

// Gradient palette "ofaurora_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pj/2/tn/ofaurora.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 124 bytes of program space.

DEFINE_GRADIENT_PALETTE(ofaurora_gp) {
	0, 255, 241, 242,
		10, 237, 1, 9,
		15, 42, 1, 2,
		22, 1, 1, 1,
		35, 237, 1, 9,
		48, 255, 241, 242,
		58, 239, 57, 1,
		66, 1, 1, 1,
		76, 239, 57, 1,
		84, 255, 241, 242,
		94, 242, 217, 1,
		101, 1, 1, 1,
		109, 242, 217, 1,
		119, 255, 241, 242,
		127, 9, 144, 36,
		132, 1, 1, 1,
		140, 9, 144, 36,
		147, 255, 241, 242,
		158, 1, 156, 186,
		168, 1, 1, 1,
		178, 1, 156, 186,
		186, 255, 241, 242,
		198, 16, 13, 255,
		206, 1, 1, 1,
		216, 16, 13, 255,
		224, 255, 241, 242,
		234, 78, 1, 156,
		237, 14, 1, 30,
		239, 1, 1, 1,
		244, 78, 1, 156,
		255, 255, 241, 242
};

// Gradient palette "hallows_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pj/3/tn/hallows.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 88 bytes of program space.

DEFINE_GRADIENT_PALETTE(hallows_gp) {
	0, 1, 1, 1,
		20, 247, 28, 1,
		25, 234, 136, 3,
		35, 1, 1, 1,
		48, 247, 28, 1,
		51, 234, 136, 3,
		61, 1, 1, 1,
		76, 247, 28, 1,
		91, 244, 176, 1,
		107, 234, 136, 3,
		122, 1, 1, 1,
		140, 234, 136, 3,
		153, 244, 176, 1,
		168, 247, 28, 1,
		186, 1, 1, 1,
		196, 247, 28, 1,
		204, 234, 136, 3,
		216, 1, 1, 1,
		229, 234, 136, 3,
		239, 247, 28, 1,
		249, 1, 1, 1,
		255, 1, 1, 1
};

// Gradient palette "sea_treasure_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pj/3/tn/sea-treasure.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 48 bytes of program space.

DEFINE_GRADIENT_PALETTE(sea_treasure_gp) {
	0, 1, 13, 5,
		25, 3, 57, 25,
		45, 18, 191, 172,
		61, 2, 29, 12,
		76, 3, 57, 25,
		101, 18, 191, 172,
		124, 10, 54, 20,
		153, 1, 30, 12,
		178, 10, 14, 22,
		209, 9, 93, 47,
		232, 8, 55, 22,
		255, 1, 13, 5
};


// Gradient palette "Secondary_01a_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/turanj/tn/Secondary_01a.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(Secondary_01a_gp) {
	0, 3, 0, 255,
		63, 67, 7, 45,
		127, 255, 33, 0,
		191, 42, 115, 1,
		255, 0, 255, 1
};

// Gradient palette "Split_03_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/vermillion/tn/Split_03.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(Split_03_gp) {
	0, 0, 18, 123,
		63, 0, 75, 29,
		127, 0, 178, 1,
		191, 27, 48, 1,
		255, 167, 1, 2
};

DEFINE_GRADIENT_PALETTE(rainbow_gp) {
	0, 255, 0, 0, // Red
		32, 171, 85, 0, // Orange
		64, 171, 171, 0, // Yellow
		96, 0, 255, 0, // Green
		128, 0, 171, 85, // Aqua
		160, 0, 0, 255, // Blue
		192, 85, 0, 171, // Purple
		224, 171, 0, 85, // Pink
		255, 255, 0, 0
};// and back to Red

DEFINE_GRADIENT_PALETTE(cloudcolors_gp) {
	0, 0, 0, 255,
		15, 0, 0, 139,
		111, 0, 0, 139,
		127, 0, 0, 255,
		143, 0, 0, 139,
		159, 135, 206, 250,
		175, 135, 206, 250,
		191, 173, 216, 230,
		207, 200, 200, 200,
		223, 173, 216, 230,
		239, 135, 206, 235,
		255, 0, 191, 255
};

// Gradient palette "cequal_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/imagej/tn/cequal.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 1860 bytes of program space.
DEFINE_GRADIENT_PALETTE(cequal_gp) {
	0, 1, 1, 1,
		36, 1, 3, 1,
		76, 1, 41, 123,
		112, 59, 1, 252,
		127, 117, 1, 180,
		172, 239, 81, 1,
		195, 252, 180, 1,
		222, 252, 250, 147,
		255, 252, 252, 252
};

// Gradient palette "purple_flower_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/flor/tn/purple-flower.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(purple_flower_gp) {
	0, 0, 0, 0,
		66, 20, 4, 45,
		132, 121, 20, 255,
		180, 179, 73, 255,
		228, 255, 164, 255,
		241, 255, 207, 255,
		255, 255, 255, 255
};

// Gradient palette "fierce_ice_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/elem/tn/fierce-ice.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(fierce_ice_gp) {
	0, 0, 0, 0,
		59, 0, 7, 45,
		119, 0, 33, 255,
		149, 3, 82, 255,
		180, 23, 156, 255,
		217, 100, 203, 255,
		255, 255, 255, 255
};

// Gradient palette "blueice_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/elem/tn/blueice.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 220 bytes of program space.

DEFINE_GRADIENT_PALETTE(blueice_gp) {
	0, 0, 0, 0,
		31, 1, 2, 15,
		63, 1, 10, 89,
		66, 1, 12, 93,
		68, 1, 13, 96,
		71, 1, 15, 100,
		73, 1, 16, 105,
		76, 1, 18, 108,
		78, 1, 20, 112,
		81, 1, 22, 115,
		83, 1, 23, 120,
		86, 1, 26, 123,
		88, 1, 29, 128,
		91, 1, 31, 132,
		93, 1, 33, 137,
		96, 1, 36, 140,
		98, 1, 40, 145,
		101, 1, 43, 151,
		103, 1, 46, 155,
		106, 1, 50, 160,
		108, 1, 54, 164,
		111, 1, 56, 166,
		113, 1, 60, 170,
		116, 1, 65, 172,
		118, 1, 69, 174,
		121, 1, 72, 178,
		123, 1, 77, 180,
		126, 1, 81, 182,
		128, 1, 86, 184,
		131, 1, 91, 188,
		134, 1, 96, 190,
		136, 1, 101, 192,
		139, 1, 107, 197,
		141, 1, 112, 199,
		144, 1, 118, 201,
		146, 1, 124, 203,
		149, 1, 130, 207,
		151, 1, 138, 210,
		154, 1, 144, 212,
		156, 1, 151, 214,
		159, 1, 159, 219,
		161, 1, 166, 221,
		164, 1, 173, 223,
		166, 1, 182, 228,
		169, 1, 189, 230,
		171, 1, 199, 233,
		174, 1, 207, 235,
		176, 1, 217, 240,
		179, 1, 225, 242,
		181, 1, 235, 245,
		184, 2, 246, 247,
		186, 2, 252, 247,
		189, 2, 255, 242,
		222, 61, 255, 247,
		255, 255, 255, 255
};

// Gradient palette "twilight_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/liht/tn/twilight.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 412 bytes of program space.

DEFINE_GRADIENT_PALETTE(twilight_gp) {
	0, 0, 0, 0,
		2, 1, 1, 1,
		5, 1, 1, 1,
		7, 1, 1, 1,
		10, 1, 1, 1,
		12, 1, 1, 1,
		15, 1, 1, 1,
		17, 1, 1, 1,
		20, 1, 1, 1,
		22, 1, 1, 1,
		25, 1, 1, 1,
		27, 1, 1, 1,
		30, 1, 1, 1,
		32, 1, 2, 1,
		35, 1, 2, 1,
		37, 1, 2, 1,
		40, 2, 3, 2,
		42, 2, 3, 2,
		45, 2, 3, 2,
		47, 3, 4, 3,
		50, 3, 4, 3,
		53, 4, 5, 4,
		55, 4, 5, 4,
		58, 5, 5, 5,
		60, 6, 6, 6,
		63, 6, 6, 6,
		65, 7, 7, 7,
		68, 8, 7, 8,
		70, 9, 8, 9,
		73, 9, 8, 10,
		75, 10, 8, 11,
		78, 11, 9, 13,
		80, 12, 9, 14,
		83, 13, 9, 15,
		85, 14, 10, 16,
		88, 14, 10, 17,
		133, 17, 14, 51,
		136, 16, 14, 52,
		138, 15, 14, 55,
		141, 14, 14, 57,
		143, 13, 14, 61,
		146, 12, 14, 63,
		149, 12, 14, 66,
		151, 10, 13, 69,
		154, 10, 13, 72,
		156, 9, 13, 75,
		159, 8, 13, 78,
		161, 7, 14, 82,
		164, 7, 16, 84,
		166, 7, 17, 88,
		169, 7, 19, 91,
		171, 7, 21, 95,
		174, 7, 22, 98,
		176, 7, 25, 102,
		179, 6, 27, 105,
		181, 6, 29, 109,
		184, 6, 32, 112,
		186, 7, 37, 117,
		189, 8, 42, 120,
		191, 9, 47, 125,
		194, 10, 54, 128,
		196, 11, 59, 132,
		199, 12, 66, 137,
		201, 14, 73, 140,
		204, 16, 80, 145,
		206, 18, 87, 149,
		208, 20, 95, 153,
		211, 22, 103, 158,
		213, 24, 111, 162,
		216, 27, 119, 168,
		218, 30, 128, 172,
		221, 32, 138, 176,
		223, 35, 147, 182,
		226, 39, 156, 186,
		228, 42, 166, 192,
		231, 46, 176, 197,
		233, 52, 182, 201,
		235, 58, 187, 207,
		238, 65, 193, 212,
		240, 73, 199, 219,
		242, 80, 205, 223,
		245, 90, 213, 230,
		247, 100, 219, 235,
		250, 109, 225, 242,
		252, 120, 231, 247,
		255, 132, 237, 255
};


// Gradient palette "green_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/base/tn/green.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(green_gp) {
	0, 0, 0, 0,
		63, 0, 17, 0,
		126, 0, 82, 0,
		155, 0, 128, 0,
		184, 0, 186, 0,
		219, 42, 219, 45,
		255, 255, 255, 255
};

// Gradient palette "ultraviolet_mold_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/faun/tn/ultraviolet-mold.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 408 bytes of program space.

DEFINE_GRADIENT_PALETTE(ultraviolet_mold_gp) {
	0, 0, 0, 0,
		2, 1, 1, 1,
		5, 1, 1, 1,
		7, 1, 1, 1,
		10, 1, 1, 1,
		12, 1, 1, 1,
		15, 1, 1, 1,
		17, 1, 1, 1,
		20, 1, 1, 1,
		22, 1, 1, 1,
		25, 1, 1, 1,
		27, 1, 1, 1,
		30, 1, 1, 1,
		32, 1, 2, 1,
		35, 1, 2, 1,
		37, 1, 2, 2,
		40, 2, 3, 2,
		42, 2, 3, 2,
		45, 2, 3, 3,
		47, 3, 4, 3,
		50, 3, 4, 4,
		53, 3, 4, 5,
		55, 4, 5, 5,
		58, 4, 5, 6,
		60, 4, 5, 7,
		63, 5, 6, 7,
		65, 5, 6, 8,
		68, 5, 7, 9,
		70, 5, 7, 10,
		73, 6, 8, 11,
		75, 6, 8, 12,
		78, 6, 8, 13,
		80, 6, 9, 14,
		83, 6, 9, 15,
		85, 6, 9, 16,
		131, 7, 52, 48,
		133, 7, 57, 51,
		136, 7, 63, 52,
		138, 7, 67, 52,
		141, 7, 69, 50,
		143, 7, 72, 48,
		146, 7, 74, 46,
		148, 7, 78, 43,
		151, 6, 80, 41,
		154, 6, 84, 37,
		156, 6, 87, 34,
		159, 6, 90, 31,
		161, 6, 93, 28,
		164, 5, 96, 25,
		166, 5, 100, 22,
		169, 5, 103, 18,
		171, 5, 107, 15,
		174, 5, 109, 13,
		176, 5, 114, 10,
		179, 4, 117, 7,
		181, 4, 121, 5,
		184, 5, 124, 5,
		186, 7, 128, 4,
		189, 9, 131, 4,
		191, 12, 136, 4,
		194, 16, 139, 4,
		196, 20, 144, 3,
		199, 25, 147, 3,
		201, 30, 152, 3,
		204, 38, 157, 3,
		207, 46, 161, 2,
		209, 55, 166, 2,
		212, 67, 169, 2,
		214, 80, 175, 2,
		217, 95, 178, 1,
		219, 113, 184, 1,
		222, 133, 187, 1,
		224, 157, 193, 1,
		227, 184, 197, 1,
		229, 194, 184, 1,
		232, 199, 168, 1,
		234, 206, 152, 1,
		237, 210, 135, 1,
		239, 217, 119, 1,
		242, 222, 103, 1,
		244, 229, 88, 1,
		247, 234, 73, 1,
		249, 242, 59, 1,
		252, 247, 47, 1,
		255, 255, 36, 1
};

// Gradient palette "apple_green_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/flor/tn/apple-green.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 408 bytes of program space.

DEFINE_GRADIENT_PALETTE(apple_green_gp) {
	0, 0, 0, 0,
		2, 1, 1, 1,
		4, 1, 1, 1,
		7, 1, 1, 1,
		10, 1, 1, 1,
		12, 1, 1, 1,
		15, 1, 1, 1,
		17, 1, 1, 1,
		20, 1, 1, 1,
		22, 1, 1, 1,
		25, 1, 1, 1,
		27, 1, 1, 1,
		30, 1, 2, 1,
		32, 1, 2, 1,
		35, 1, 3, 1,
		37, 1, 3, 1,
		40, 1, 4, 1,
		42, 1, 5, 1,
		45, 1, 5, 1,
		47, 1, 6, 1,
		50, 1, 7, 1,
		52, 1, 8, 1,
		55, 1, 8, 1,
		57, 1, 9, 2,
		60, 1, 10, 2,
		62, 1, 11, 3,
		65, 1, 12, 4,
		67, 1, 13, 5,
		70, 1, 14, 7,
		72, 1, 16, 7,
		75, 1, 17, 8,
		77, 1, 18, 8,
		80, 1, 19, 8,
		82, 1, 21, 9,
		85, 1, 22, 9,
		87, 1, 24, 9,
		130, 1, 58, 8,
		133, 1, 60, 7,
		135, 1, 63, 7,
		138, 1, 66, 6,
		141, 1, 69, 6,
		143, 1, 71, 5,
		146, 1, 74, 5,
		148, 1, 78, 4,
		151, 1, 80, 4,
		153, 1, 84, 3,
		156, 1, 86, 3,
		158, 1, 90, 2,
		161, 1, 92, 2,
		163, 1, 96, 1,
		166, 1, 99, 1,
		168, 1, 103, 1,
		171, 1, 105, 1,
		173, 2, 109, 1,
		176, 2, 112, 1,
		179, 3, 117, 1,
		181, 3, 119, 1,
		184, 4, 124, 1,
		186, 5, 128, 1,
		189, 5, 131, 1,
		191, 6, 136, 1,
		194, 7, 139, 1,
		196, 9, 144, 1,
		199, 10, 147, 1,
		201, 11, 152, 1,
		204, 13, 156, 1,
		206, 15, 161, 1,
		209, 17, 164, 1,
		211, 19, 169, 1,
		214, 22, 173, 1,
		217, 24, 178, 1,
		219, 27, 184, 1,
		222, 31, 187, 1,
		224, 35, 193, 1,
		227, 39, 197, 1,
		229, 44, 203, 1,
		232, 49, 207, 1,
		234, 54, 213, 1,
		237, 60, 217, 1,
		239, 67, 223, 1,
		242, 74, 227, 1,
		244, 82, 233, 1,
		247, 91, 237, 1,
		249, 100, 244, 1,
		252, 110, 248, 1,
		255, 121, 255, 0
};

// Gradient palette "faint_rainbow_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/othr/tn/faint-rainbow.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 408 bytes of program space.

DEFINE_GRADIENT_PALETTE(faint_rainbow_gp) {
	0, 67, 0, 71,
		2, 69, 1, 65,
		5, 72, 1, 59,
		7, 74, 1, 53,
		10, 77, 1, 48,
		12, 78, 1, 43,
		15, 80, 1, 38,
		17, 83, 1, 34,
		20, 86, 1, 29,
		22, 88, 1, 25,
		25, 91, 1, 22,
		27, 94, 1, 18,
		30, 97, 1, 15,
		32, 98, 1, 12,
		35, 101, 1, 10,
		37, 104, 1, 7,
		40, 107, 1, 5,
		42, 110, 1, 4,
		45, 113, 1, 2,
		47, 117, 1, 1,
		50, 120, 1, 1,
		53, 121, 1, 1,
		55, 125, 1, 1,
		58, 128, 1, 1,
		60, 132, 3, 1,
		63, 135, 5, 1,
		65, 139, 8, 1,
		68, 142, 12, 1,
		70, 144, 14, 1,
		73, 144, 16, 1,
		75, 146, 17, 1,
		78, 148, 19, 1,
		80, 148, 22, 1,
		83, 150, 23, 1,
		85, 152, 26, 1,
		131, 175, 88, 1,
		133, 177, 93, 1,
		136, 179, 99, 1,
		138, 179, 104, 1,
		141, 182, 108, 1,
		143, 184, 114, 1,
		146, 184, 119, 1,
		148, 186, 125, 1,
		151, 188, 131, 1,
		154, 188, 138, 1,
		156, 190, 144, 1,
		159, 192, 151, 1,
		161, 192, 157, 1,
		164, 194, 164, 1,
		166, 197, 171, 1,
		169, 199, 178, 1,
		171, 199, 186, 1,
		174, 201, 193, 1,
		176, 203, 201, 2,
		179, 203, 209, 2,
		181, 201, 213, 2,
		184, 197, 215, 2,
		186, 190, 215, 2,
		189, 184, 217, 2,
		191, 179, 219, 2,
		194, 173, 219, 2,
		196, 167, 221, 2,
		199, 161, 223, 2,
		201, 157, 223, 2,
		204, 152, 225, 2,
		207, 146, 227, 2,
		209, 142, 229, 2,
		212, 137, 229, 2,
		214, 132, 231, 3,
		217, 126, 233, 3,
		219, 121, 233, 3,
		222, 118, 235, 3,
		224, 113, 237, 3,
		227, 109, 237, 3,
		229, 104, 239, 3,
		232, 101, 241, 3,
		234, 97, 241, 3,
		237, 92, 244, 3,
		239, 88, 246, 3,
		242, 84, 248, 4,
		244, 80, 248, 4,
		247, 78, 250, 4,
		249, 74, 252, 4,
		252, 71, 252, 4,
		255, 67, 255, 4
};

// Gradient palette "otis_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/otis.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(otis_gp) {
	0, 26, 1, 89,
		127, 17, 193, 0,
		216, 0, 34, 98,
		255, 0, 34, 98
};

// Gradient palette "parrot_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/parrot.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(parrot_gp) {
	0, 126, 0, 1,
		114, 197, 168, 16,
		140, 197, 168, 16,
		216, 0, 2, 32,
		255, 0, 2, 32
};


// Gradient palette "scoutie_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/scoutie.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(scoutie_gp) {
	0, 255, 156, 0,
		127, 0, 195, 18,
		216, 1, 0, 39,
		255, 1, 0, 39
};

// Gradient palette "sunlitwave_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/sunlitwave.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE(sunlitwave_gp) {
	0, 5, 9, 84,
		45, 37, 24, 111,
		81, 16, 5, 59,
		112, 24, 1, 20,
		150, 34, 1, 2,
		198, 175, 36, 7,
		237, 208, 104, 16,
		255, 239, 211, 158
};

// Gradient palette "GMT_cool_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/gmt/tn/GMT_cool.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space.

DEFINE_GRADIENT_PALETTE(GMT_cool_gp) {
	0, 0, 255, 255,
		255, 255, 0, 255
};

// Gradient palette "bhw1_sunconure_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_sunconure.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw1_sunconure_gp) {
	0, 20, 223, 13,
		160, 232, 65, 1,
		252, 232, 5, 1,
		255, 232, 5, 1
};

// Gradient palette "bhw1_05_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_05.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw1_05_gp) {
	0, 1, 221, 53,
		255, 73, 3, 178
};

// Gradient palette "bhw2_turq_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw2/tn/bhw2_turq.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw2_turq_gp) {
	0, 1, 33, 95,
		38, 1, 107, 37,
		76, 42, 255, 45,
		127, 255, 255, 45,
		178, 42, 255, 45,
		216, 1, 107, 37,
		255, 1, 33, 95
};

// Gradient palette "bhw3_13_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw3/tn/bhw3_13.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw3_13_gp) {
	0, 3, 6, 72,
		38, 12, 50, 188,
		109, 217, 35, 1,
		135, 242, 175, 12,
		178, 161, 32, 87,
		255, 24, 6, 108
};

// Gradient palette "bhw3_61_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw3/tn/bhw3_61.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw3_61_gp) {
	0, 14, 1, 27,
		48, 17, 1, 88,
		104, 1, 88, 156,
		160, 1, 54, 42,
		219, 9, 235, 52,
		255, 139, 235, 233
};

// Gradient palette "bhw3_34_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw3/tn/bhw3_34.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw3_34_gp) {
	0, 29, 112, 205,
		48, 92, 255, 250,
		91, 52, 223, 12,
		124, 4, 13, 21,
		183, 9, 103, 15,
		216, 10, 80, 2,
		255, 38, 255, 52
};


// Gradient palette "bhw4_009_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw4/tn/bhw4_009.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE(bhw4_009_gp) {
	0, 66, 186, 192,
		43, 1, 22, 71,
		79, 2, 104, 142,
		117, 66, 186, 192,
		147, 2, 104, 142,
		186, 1, 22, 71,
		224, 2, 104, 142,
		255, 4, 27, 28
};

// Gradient palette "es_emerald_dragon_09_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/emerald_dragon/tn/es_emerald_dragon_09.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(es_emerald_dragon_09_gp) {
	0, 1, 1, 1,
		76, 1, 2, 1,
		153, 10, 47, 1,
		255, 97, 255, 1
};

// Gradient palette "xanidu_2_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pj/3/tn/xanidu-2.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE(xanidu_2_gp) {
	0, 118, 161, 226,
		53, 79, 1, 162,
		94, 67, 1, 7,
		132, 1, 55, 156,
		173, 1, 127, 61,
		211, 39, 45, 72,
		255, 118, 161, 226
};

// Gradient palette "water1_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pj/4/tn/water1.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE(water1_gp) {
	0, 1, 1, 46,
		28, 79, 136, 190,
		53, 16, 81, 184,
		73, 79, 136, 190,
		99, 75, 201, 233,
		124, 6, 12, 103,
		158, 75, 201, 233,
		186, 84, 109, 108,
		198, 16, 81, 184,
		232, 79, 136, 190,
		255, 1, 1, 46
};

// Gradient palette "stratosphere_sunset_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/pd/astro/tn/stratosphere_sunset.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 236 bytes of program space.

DEFINE_GRADIENT_PALETTE(stratosphere_sunset_gp) {
	0, 1, 2, 9,
		4, 1, 2, 9,
		8, 1, 2, 10,
		13, 1, 2, 11,
		17, 1, 2, 11,
		21, 1, 3, 13,
		26, 1, 3, 15,
		30, 1, 3, 16,
		35, 1, 4, 18,
		39, 1, 4, 19,
		43, 1, 4, 21,
		48, 1, 5, 23,
		52, 1, 5, 27,
		57, 1, 6, 32,
		61, 1, 7, 38,
		65, 1, 9, 49,
		70, 1, 11, 61,
		74, 1, 17, 80,
		79, 1, 23, 103,
		83, 1, 31, 135,
		87, 2, 42, 172,
		92, 4, 48, 190,
		96, 9, 54, 210,
		101, 11, 55, 214,
		105, 13, 58, 221,
		109, 16, 60, 219,
		114, 19, 62, 216,
		118, 24, 66, 210,
		123, 30, 69, 201,
		127, 35, 70, 180,
		131, 39, 70, 162,
		136, 64, 84, 144,
		140, 97, 97, 128,
		145, 148, 121, 123,
		149, 210, 146, 119,
		153, 184, 122, 92,
		158, 159, 100, 69,
		162, 133, 68, 33,
		167, 110, 42, 11,
		171, 152, 53, 6,
		175, 203, 65, 3,
		180, 222, 99, 5,
		184, 242, 142, 7,
		189, 222, 122, 5,
		193, 203, 105, 3,
		197, 208, 73, 1,
		202, 210, 48, 1,
		206, 222, 45, 1,
		211, 234, 42, 1,
		215, 150, 23, 1,
		219, 86, 10, 1,
		224, 35, 3, 1,
		228, 9, 1, 1,
		233, 4, 1, 1,
		237, 1, 1, 1,
		241, 1, 1, 1,
		246, 1, 1, 1,
		250, 1, 1, 1,
		255, 1, 1, 1
};

// Gradient palette "RedsandCyans_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/RedsandCyans.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE(RedsandCyans_gp) {
	0, 15, 96, 135,
		78, 40, 87, 74,
		102, 83, 80, 34,
		114, 113, 71, 29,
		127, 150, 63, 25,
		143, 60, 79, 66,
		182, 15, 96, 135,
		223, 15, 96, 135,
		255, 15, 96, 135
};

// Gradient palette "Cyan_Magenta_Blue_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/Cyan_Magenta_Blue.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE(Cyan_Magenta_Blue_gp) {
	0, 0, 255, 255,
		63, 42, 55, 255,
		127, 255, 0, 255,
		191, 42, 0, 255,
		255, 0, 0, 255
};

// Gradient palette "Complementary_01a_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/turanj/tn/Complementary_01a.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 12 bytes of program space.

DEFINE_GRADIENT_PALETTE(Complementary_01a_gp) {
	0, 0, 33, 255,
		127, 42, 33, 45,
		255, 255, 33, 0
};

DEFINE_GRADIENT_PALETTE(cyberpunk_neon_gp) {
	0, 113, 28, 145,
		63, 234, 0, 217,
		127, 10, 189, 198,
		191, 19, 62, 124,
		255, 9, 24, 51
};


DEFINE_GRADIENT_PALETTE(blade_runner_2049_gp) {
	0, 201, 80, 173,
		25, 171, 57, 155,
		50, 104, 35, 115,
		75, 94, 33, 110,
		100, 127, 120, 172,
		125, 77, 141, 169,
		160, 116, 85, 178,
		170, 20, 27, 115,
		200, 75, 21, 73,
		255, 44, 9, 42
};

DEFINE_GRADIENT_PALETTE(blue_fire_gp) {
	0, 0, 0, 0,
		64, 0, 0, 255,
		200, 0, 255, 255,
		255, 255, 255, 255
};

// Gradient palette "purplefly_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/purplefly.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE(purplefly_gp) {
	0, 0, 0, 0,
		63, 239, 0, 122,
		191, 252, 255, 78,
		255, 0, 0, 0
};

// Gradient palette "rainbow_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/rainbow.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 48 bytes of program space.

DEFINE_GRADIENT_PALETTE(rainbow2_gp) {
	0, 126, 1, 142,
		25, 171, 1, 26,
		48, 224, 9, 1,
		71, 237, 138, 1,
		94, 52, 173, 1,
		117, 1, 201, 1,
		140, 1, 211, 54,
		163, 1, 124, 168,
		186, 1, 8, 149,
		209, 12, 1, 151,
		232, 12, 1, 151,
		255, 171, 1, 190
};



// Single array of defined cpt-city color palettes.
// This will let us programmatically choose one based on
// a number, rather than having to activate each explicitly
// by name every time.
// Since it is const, this_ array could also be moved
// into PROGMEM to save SRAM, but for simplicity of illustration
// we'll keep it in a regular SRAM array.
//
// This list of color palettes acts as a "playlist"; you can
// add or delete, or re-arrange as you wish.
TProgmemRGBGradientPalettePtr palettes[] = {
	rainbow2_gp,
  ib_jul01_gp,
  //es_vintage_57_gp,
//  es_vintage_01_gp,
//  es_rivendell_15_gp,
  rgi_15_gp,
  //  retro2_16_gp,
	Analogous_1_gp,
	es_pinksplash_08_gp,
	es_pinksplash_07_gp,
	Coral_reef_gp,
	es_ocean_breeze_068_gp,
	es_ocean_breeze_036_gp,
	//  departure_gp,
	  es_landscape_64_gp,
	  es_landscape_33_gp,
	  rainbowsherbet_gp,
	  gr65_hult_gp,
	  gr64_hult_gp,
	  GMT_drywet_gp,
	  ib15_gp,
	  Fuschia_7_gp,
	  es_emerald_dragon_08_gp,
	  lava_gp,
	  fire_gp,
	  Colorfull_gp,
	  Magenta_Evening_gp,
	  //  Pink_Purple_gp,
		Sunset_Real_gp,
		es_autumn_19_gp,
		BlacK_Blue_Magenta_White_gp,
		BlacK_Magenta_Red_gp,
		BlacK_Red_Magenta_Yellow_gp,
		Blue_Cyan_Yellow_gp,
		bhw1_greeny_gp,
		bhw1_26_gp,
		bhw1_28_gp,
		bhw2_23_gp,
		bhw2_22_gp,
		bhw2_49_gp,
		bhw2_10_gp,
		bhw2_14_gp,
		bhw3_21_gp,
		bhw3_30_gp,
		vibrant_gp,
		cw1_029_gp,
		alarm_p4_0_2_gp,
		Ribbon_Colors_gp,
		Orange_to_Purple_gp,
		Fire_1_gp,
		standard_gp,
		a_gp,
		b_gp,
		es_emerald_dragon_01_gp,
		//  es_landscape_59_gp,
		//  es_seadreams_09_gp,
		  froth316_gp,
		  Skydye11_gp,
		  Wizzl019_gp,
		  Tropical_Colors_gp,
		  slope_gp,
		  ofaurora_gp,
		  hallows_gp,
		  sea_treasure_gp,
		  Secondary_01a_gp,
		  Split_03_gp,
		  GMT_seafloor_gp,
		  rainbow_gp,
		  cloudcolors_gp,
		  cequal_gp,
		  purple_flower_gp,
		  fierce_ice_gp,
		  blueice_gp,
		  twilight_gp,
		  green_gp,
		  ultraviolet_mold_gp,
		  apple_green_gp,
		  faint_rainbow_gp,
		  otis_gp,
		  parrot_gp,
		  scoutie_gp,
		  sunlitwave_gp,
		  GMT_cool_gp,
		  bhw1_sunconure_gp,
		  bhw1_05_gp,
		  bhw2_turq_gp,
		  bhw3_13_gp,
		  bhw3_61_gp,
		  bhw4_009_gp,
		  bhw3_34_gp,
		  es_emerald_dragon_09_gp,
		  xanidu_2_gp,
		  water1_gp,
		  stratosphere_sunset_gp,
		  RedsandCyans_gp,
		  Cyan_Magenta_Blue_gp,
		  Complementary_01a_gp,
		  cyberpunk_neon_gp,
		  blue_fire_gp,
		  purplefly_gp,
		  rainbow2_gp,
		  blade_runner_2049_gp
};

#endif