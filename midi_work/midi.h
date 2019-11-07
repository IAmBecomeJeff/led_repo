#ifndef SYMMETRIC_TRAILS_H
#define SYMMETRIC_TRAILS_H

//#include <FastLED.h>
//#include <MIDI.h>
//#include "vars.h"
//#include "ledeffect.cpp"

// We subclass from the LEDEffect abstract class.
class MidiEffect: public LedEffect {

  private:
    // Each LedEffect subclass will have its own private variables
    uint16_t counter;


  public:
    // Default constructor
    MidiEffect() {
      counter = 0;
    }

    // Each LedEffect subclass must implement render(), which renders the next frame to the ledData array
    void render() {
      leddata.fadeToBlackBy(1);
    }

    void NoteOn(byte channel, byte pitch, byte velocity) {
      //leddata(15) = CRGB::Blue;
    }

    void Note(byte midi_key, byte intensity){
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
      
      switch(midi_key){
        
        // Kick (36)
        case 36:
          leddata(kick_start, kick_start + kick_length) |= CHSV(intensity, 255, 255);
          break;

        // Snare (38)
        case 38:
          leddata(snare_start, snare_start + snare_length) |= CHSV(intensity, 255, 255);    
          break;

        // Snare Rim (40)
        case 40:
          leddata(snare_start-2, snare_start + snare_length + 2) |= CHSV(intensity, 255, 255);     
          break;

        // Tom 1 (48)
        case 48:
          leddata(tom1_start, tom1_start + tom1_length) |= CHSV(intensity, 255, 255);       
          break;

        // Tom 1 Rim (50)
        case 50:
          leddata(tom1_start-2, tom1_start + tom1_length + 2) |= CHSV(intensity, 255, 255);           
          break;

        // Tom 2 (45)
        case 45:
          leddata(tom2_start, tom2_start + tom2_length) |= CHSV(intensity, 255, 255);     
          break;

        // Tom 2 rim (73)
        case 73:
          leddata(tom2_start-2, tom2_start + tom2_length + 2) |= CHSV(intensity, 255, 255);          
          break;

        // Tom 3 (53)
        case 53:
           leddata(tom3_start, tom3_start + tom3_length) |= CHSV(intensity, 255, 255);         
          break;

        // Tom 3 rim (58)
        case 58:
          leddata(tom3_start-2, tom3_start + tom3_length + 2) |= CHSV(intensity, 255, 255);
          break;

        // Ride (51)
        case 51:
           leddata(ride_start, ride_start + ride_length) |= CHSV(intensity, 255, 255);        
          break;

        // Crash 1 (49)
        case 49:
          leddata(crash_start, crash_start + crash_length) |= CHSV(intensity, 255, 255);                
          break;

        // Hi-hat Open (46)
        case 46:
          leddata(hihat_start, hihat_start + hihat_length) |= CHSV(intensity, 255, 255);        
          break;

        // Hi-hat Half-open (23)
        case 23:
          leddata(hihat_start, hihat_start + hihat_length) |= CHSV(intensity, 255, 255);          
          break;

        // Hi-Hat Closed (42)
        case 42:
          leddata(hihat_start, hihat_start + hihat_length) |= CHSV(intensity, 255, 255);          
          break;

        // Hi-Hat Pedal (44)
        case 44:
          leddata(hihat_start, hihat_start + hihat_length) |= CHSV(intensity, 255, 255);          
          break;

        default:
          break;
      }

      // uint8_t starting_led = ((key-40)*2) + 22;
      // leddata(NUM_LEDS - starting_led, NUM_LEDS - starting_led + 1) |= CHSV(intensity, 255, 255);
      // leddata(0, 22).addToRGB(5);
      // leddata(NUM_LEDS-22, NUM_LEDS-1).addToRGB(5);
      //leddata(0, 10).addToRGB(intensity*2);
      //leddata(NUM_LEDS-10, NUM_LEDS-1).addToRGB(intensity*2);
      




    }

    void NoteOff(byte channel, byte pitch, byte velocity) {
      //leddata(0, pitch) = CRGB::Red;
    }
};

#endif
