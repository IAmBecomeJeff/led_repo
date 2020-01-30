// Variables

// Setup variables
#define NUM_LEDS	150
#define ONE_SIDE	75
#define DATA_PIN	14
#define CLOCK_PIN	7
#define COLOR_ORDER BGR
#define LED_TYPE	APA102	

// Master LED Array
struct CRGB master_leds[NUM_LEDS];

// Debug
#define DEBUG 1


// LED Variables
uint8_t max_bright = 255;		// used in initial LEDS.set_brightness


// Array Variables
enum ArrayType { CURRENT, NEXT, OVERLAY };
uint8_t curr_delay;
uint8_t next_delay;


// Mode Variables
uint8_t current_mode_number = 0;
bool	random_mode			= 0;		// Determines if we change randomly or in the order of ModeList
bool	mode_change			= 1;
uint16_t mode_change_time = 20;			// seconds

enum Mode	  	  { JUGGLE, JUGGLE_ONE_DIR, JUGGLE_PHASED, JUGGLE_PHASED_ONE_DIR, JUGGLE_RANDOM, 
					RAINBOW_MARCH, RAINBOW_MARCH_SPLIT, RAINBOW_MARCH_RANDOM,
					FIRE, FIRE_SYNC, FIRE_MIRROR, FIRE_MIRROR_SYNC, FIRE_RANDOM, TORCH, TORCH_SYNC,
					COLORWAVE, PRIDE, PACIFICA,
					CONFETTI,
					ONE_SIN, TWO_SIN,
					FIREWORKS,
					SHOOTING_POLE,
					NOISE,
					BOUNCE, BOUNCING_BALLS
				  };

Mode ModeList[] = { JUGGLE, JUGGLE_ONE_DIR, JUGGLE_PHASED, JUGGLE_PHASED_ONE_DIR, JUGGLE_RANDOM, 
					RAINBOW_MARCH, RAINBOW_MARCH_SPLIT, RAINBOW_MARCH_RANDOM,
					FIRE, FIRE_SYNC, FIRE_MIRROR, FIRE_MIRROR_SYNC, FIRE_RANDOM, TORCH, TORCH_SYNC,
					COLORWAVE, PRIDE, PACIFICA,
					CONFETTI,
					ONE_SIN, TWO_SIN,		
					FIREWORKS,
					SHOOTING_POLE,
					NOISE,
					BOUNCE, BOUNCING_BALLS
				  };

extern Mode start_mode;
uint16_t number_of_mode_changes;
uint16_t number_of_min_on;
uint8_t number_of_sec_on;


// Palette Variables
uint8_t palette_index;
uint8_t palette_count = sizeof(palettes) / sizeof(TProgmemRGBGradientPalettePtr);
bool	random_palette = 1;


// Transition Variables
enum TransitionType { BLENDING, WIPEDOWN, WIPEUP, COLORFADE};
TransitionType TransitionList[] = { BLENDING, WIPEDOWN, WIPEUP, COLORFADE };
bool in_transition = 0;
TransitionType transition_type;
uint8_t transition_ratio;
uint8_t transition_speed; // seconds
uint8_t wipe_pos;
bool color_up;
CHSV colorfade_hue;
CRGB colorfade_rgb;

// Serial Variables
byte in_byte;
uint8_t update_var;
uint16_t update_arg;
bool keyboard_update;
#define SERIAL_BAUDRATE 57600
#define SERIAL_TIMEOUT 500


// Fireworks Variables
#define MAX_NUMBER_OF_SPARKS 60
#define MIN_NUMBER_OF_SPARKS 20
enum stage { FADEUP, EXPLOSION, WAITING };
uint16_t max_wait = 1000;
uint16_t min_wait = 500;
float gravity = 0.97;
uint8_t firework_bg_fade = 128;

// Bouncing Balls
#define MAX_NUMBER_OF_BALLS 8
#define GRAVITY -1
#define h0 1
float   bouncing_vImpact0 = sqrt(-2 * GRAVITY * h0);