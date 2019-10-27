#ifndef FIREWORK_H
#define FIREWORK_H

#include <FastLED.h>
#include "vars.h"
#include "ledeffect.h"
// Fireworks

// Stages
//  1 - FADEUP
//      - Choose a random position, fade from black to full brightness
//  2 - EXPLOSION
//      - Create sparks and give them velocities and speeds, adding them to the leds
//  3 - FADEOUT
//      - As the sparks fly away, slow them down and begin fading, but fade firework position slowest
//  4 - WAITING
//      - Wait some random amount of time before next firework

#define MAX_NUMBER_OF_SPARKS 60
#define MIN_NUMBER_OF_SPARKS 20

class FireworkEffect: public LedEffect {
    private:
        enum stage {
            FADEUP,
            EXPLOSION,
            FADEOUT,
            WAITING
        };
        uint16_t firework_position;
        uint8_t firework_hue;
        uint16_t firework_bri;
        stage current_stage;
        uint16_t max_wait = 2000;
        uint16_t min_wait = 500;
        uint32_t next_explosion_time;
        bool exploded;
        float gravity = 0.97;
        uint8_t number_of_sparks;
        float spark_position[MAX_NUMBER_OF_SPARKS];
        float spark_velocity[MAX_NUMBER_OF_SPARKS];
        bool spark_direction[MAX_NUMBER_OF_SPARKS];
        float spark_fade[MAX_NUMBER_OF_SPARKS];
        uint8_t bg_fade = 128;
        float spark_bri[MAX_NUMBER_OF_SPARKS];
        uint8_t brightest_spark;

    public:
        // Default constructor, random position
        FireworkEffect(uint16_t startPosition=0, uint8_t startHue=0){
            if(startPosition==0){
                firework_position = random16(10,NUM_LEDS-10);
            }else{
                firework_position = startPosition;
                }
            if(startHue==0){
                firework_hue = random8();
            } else{
                firework_hue = startHue;
                }
            current_stage = WAITING;
            next_explosion_time = random16(0,3000);
        }

        void prepare_for_explosion();
        void fadeup();
        void explosion();
        void render();
        void debug_info();
};


void FireworkEffect::prepare_for_explosion(){
    Serial.println("Prepare for Explosion");
    random16_add_entropy(analogRead(2));
    firework_position = random16(10,NUM_LEDS-10);
    current_stage = FADEUP;
    firework_hue = random8();
    firework_bri = 0;
    exploded = false;
    fill_solid(led_data, NUM_LEDS, CRGB::Black);
}

void FireworkEffect::fadeup(){
  Serial.println("Stage: FADEUP");
    if(exploded){
        current_stage = EXPLOSION;
        number_of_sparks = random8(MIN_NUMBER_OF_SPARKS,MAX_NUMBER_OF_SPARKS+1);
        for (uint8_t i = 0; i < number_of_sparks; i++){
            spark_position[i] = (float)firework_position;
            spark_velocity[i] = (float)(random16(10,125)) / 100;
            spark_direction[i] = random8(0,2);
            spark_fade[i] = random8(5,15);
            spark_bri[i] = 255;
        }
        led_data[firework_position] = CRGB::White;
    }
    else{
        firework_bri += 5;
        led_data[firework_position] = CHSV(firework_hue, 255, firework_bri);
        Serial.print("firework_bri: "); Serial.println(firework_bri);
        if(firework_bri >= 255){
            exploded = true;
        }
    }
}

void FireworkEffect::explosion(){
  Serial.println("EXPLOSION!");
    // Fade all LEDs, we will light up the sparks to their own value.
    led_data.fadeToBlackBy(bg_fade);
    brightest_spark = 0;
    for (uint8_t x = 0; x < number_of_sparks; x++){

        // Update LED data with spark position
        led_data[(int)spark_position[x]] += CHSV(firework_hue,255,(uint8_t)spark_bri[x]);

        // Change position of each spark
        if(spark_direction[x]){ spark_position[x] += spark_velocity[x];}
        else                  { spark_position[x] -= spark_velocity[x];}
        spark_position[x] = constrain(spark_position[x], 0.0, (float)(NUM_LEDS-1));

        // Decrease the spark velocity
        spark_velocity[x] *= gravity;

        // Decrease spark brightness. Fade value of 1 is 1415 frames, 2 is 706 frames, 3 is 470, 10 is 139
        spark_bri[x] *= (1 - (spark_fade[x] / 256));

        // Determine brighest spark to see when they are all at 0 brightness.
        if((uint8_t)spark_bri[x] > brightest_spark){brightest_spark = (uint8_t)spark_bri[x];}
    }
    if (brightest_spark <= 00){
        fill_solid(led_data,NUM_LEDS,CRGB::Black);
        current_stage = WAITING;
        next_explosion_time = millis() + random16(min_wait + max_wait);
    }
}

void FireworkEffect::render(){
    if(current_stage == WAITING){
      Serial.println("WAITING");
        if(millis() >= next_explosion_time){
            prepare_for_explosion();
        }
    }
    else if (current_stage == FADEUP){
        fadeup();
    }
    else if (current_stage == EXPLOSION){
        explosion();
    }
    else {
        Serial.println("How did you get here?");
    }
}


void FireworkEffect::debug_info(){
  Serial.print("| Firework position: "); Serial.print(firework_position); Serial.println("   |");
  Serial.print("| Number of sparks: "); Serial.print(number_of_sparks); Serial.println(" |");
  Serial.println("| Spark | Pos | Vel | Fade | Bri | ");
  for(uint8_t x = 0; x < number_of_sparks; x++){
    Serial.print("| "); Serial.print(x);
    Serial.print("   | "); Serial.print(spark_position[x]);
    Serial.print("   | "); Serial.print(spark_velocity[x]);
    Serial.print("   | "); Serial.print(spark_fade[x]);
    Serial.print("   | "); Serial.print(spark_bri[x]);
    Serial.println(" |");
  }
  Serial.println("---------------");
}




#endif
