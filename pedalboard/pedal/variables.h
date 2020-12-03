// Variables

#define LED_DT 14
#define COLOR_ORDER GRB
#define MAX_LEDS 136
#define LED_TYPE WS2812

uint8_t NUM_LEDS;
uint8_t max_bright = 255;
struct CRGB leds[MAX_LEDS];

CRGBPalette16 currentPalette;
CRGBPalette16 targetPalette;
TBlendType currentBlending = LINEARBLEND;
uint8_t palette_index = 1;
#define qsuba(x, b) ((x>b)?x-b:0)    
#define qsubd(x, b) ((x>b)?255:0)


// Variables

int this_delay = 10;
uint16_t ram_counter_10s = 0;

uint8_t start_index = 0;
uint8_t this_beat   = 24;
uint8_t this_bright = 255;
uint8_t this_diff   = 64;
uint8_t this_fade   = 8;
uint8_t this_index  = 0;
uint8_t num_dots    = 2;
uint8_t this_hue;
bool this_dir       = 1;
uint8_t this_inc    = 16;

uint8_t color_index = 0;
uint8_t color_speed = 1;
uint8_t color_inc   = 8;

uint8_t gHue = 0;

uint8_t all_freq = 4;
uint8_t bg_bri = 0;
uint8_t bg_clr = 0;
//uint8_t start_index = 24;
uint8_t this_cutoff = 64;
uint8_t this_phase = 4;
uint8_t this_rot = 16;
uint8_t this_speed = 24;

int leftArray[35];
int rightArray[35];
int frontArray[66];
//int backArray[61];
int LeftToRight[68];
int Center[99];

int rightFromCenter[98] = {128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31};
int leftFromCenter[98] = {129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};

int maxMode = 14;
uint8_t ledMode = 1;
bool newMode = 1;
uint8_t oldMode;

extern const TProgmemRGBGradientPalettePtr gGradientPalettes[];
extern const uint8_t gGradientPaletteCount;
uint8_t gCurrentPaletteNumber = 0;
uint8_t currentPaletteIndex = 0;

CRGBPalette16 fire_palette = HeatColors_p;
CRGBPalette16 fire_palette2 = CRGBPalette16(CRGB::Black, CRGB::Red, CRGB::Yellow, CRGB::White);
CRGBPalette16 fire_palette_blue = CRGBPalette16(CRGB::Black, CRGB::Blue, CRGB::Aqua, CRGB::White);
#define COOLING 55
#define SPARKING 110
#define STRAND_LENGTH 98



LIB8STATIC uint16_t beatsin16_halfdown(accum88 beats_per_minute, uint16_t lowest = 0, uint16_t highest = 65535,
  uint32_t timebase = 0, uint16_t phase_offset = 0)
{
  uint16_t beat = beat16(beats_per_minute, timebase) % 32768 + 16384;     
  uint16_t beatsin = (sin16(beat + phase_offset) + 32768);
  uint16_t rangewidth = highest - lowest;
  uint16_t scaledbeat = scale16(beatsin, rangewidth);
  uint16_t result = lowest + scaledbeat;
  return result;
}

LIB8STATIC uint16_t beatsin16_halfup(accum88 beats_per_minute, uint16_t lowest = 0, uint16_t highest = 65535,
  uint32_t timebase = 0, uint16_t phase_offset = 0)
{
  uint16_t beat = beat16(beats_per_minute, timebase) % 32768 + 49152;     
  uint16_t beatsin = (sin16(beat + phase_offset) + 32768);
  uint16_t rangewidth = highest - lowest;
  uint16_t scaledbeat = scale16(beatsin, rangewidth);
  uint16_t result = lowest + scaledbeat;
  return result;
}
