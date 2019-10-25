#ifndef LED_EFFECT_H
#define LED_EFFECT_H

#include <FastLED.h>
#include "vars.h"

class LedEffect{
    public:
        bool enabled;
        CRGBArray<NUM_LEDS> led_data;
        virtual void render() = 0;
        unsigned long last_update;
        unsigned long interval = 20;

        void enable(){ enabled = true; }
        void disable(){ enabled = false; }
        void toggle(){ enabled = !enabled; }
        void change_speed(unsigned long suppliedValue){interval = suppliedValue;}

        void update(){
            if ((unsigned long)(millis() - last_update) >= interval){
                last_update = millis();
                render();
                //delay(10);
            }
        }
};

#endif
