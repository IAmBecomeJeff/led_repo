// QUICK CHANGE variables
#define NUM_LEDS 300
#define LED_PIN 7
#define CLOCK_PIN 14
#define DEBUG false
#define DEBUG_FRAMERATE false
#define DEBUG_STARTCOLOR true
#define MAX_BRIGHT 255
// QUICK CHANGE VARIABLES


      // Kick         - 36
      // Snare        - 38
      // Snare Rim    - 40
      // Tom 1        - 48
      // Tom 1 Rim    - 50
      // Tom 2        - 45
      // Tom 2 Rim    - 73
      // Tom 3        - 53
      // Tom 3 Rim    - 58
      // Ride         - 51
      // Crash 1      - 49
      // Hi-Hat Open  - 46
      // HH 1/2 Open  - 23
      // HH Closed    - 42
      // HH Pedal     - 44

uint8_t kick_start      = 20;   // 20-29
uint8_t kick_length     = 10;

uint8_t snare_start     = 32;   // 32-41
uint8_t snare_length    = 10;   // 30,31,42,43 will be rim

uint8_t tom1_start      = 46;   // 46-55
uint8_t tom1_length     = 10;   // 44,45,56,57 will be rim

uint8_t tom2_start      = 60;   // 60-69
uint8_t tom2_length     = 10;   // 58,59,70,71 will be rim

uint8_t tom3_start      = 74;   // 74-83
uint8_t tom3_length     = 10;   // 72,73,84,85

uint8_t ride_start      = 86;   // 86-95
uint8_t ride_length     = 10;

uint8_t crash_start     = 96;   // 96-105
uint8_t crash_length    = 10;

uint8_t hihat_start     = 108;  // 108-117
uint8_t hihat_length    = 10;   // pedal will be 106,107,109,110

//struct drum {
//    uint8_t start;
//    uint8_t length = 10;
//    byte midi_key;
//};
//
//drum kick, snare, tom1, tom2, tom3, ride, crash, hihat;
//
//kick.start      = 20;
//snare.start     = 32;
//tom1.start      = 46;
//tom2.start      = 60;
//tom3.start      = 74;
//ride.start      = 86;
//crash.start     = 96;
//hihat_start     = 108;
