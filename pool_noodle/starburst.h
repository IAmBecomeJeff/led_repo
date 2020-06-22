#ifndef STARBURST_H
#define STARBURST_H


void starburst_init(LEDStruct& leds, bool ufr = random8(2), uint8_t ss = random8(200,255)) {
    leds.mode_initialized   = 1;
    leds.mode_type          = STARBURST;
    leds.use_palette        = 0;
    leds.delay_time         = 15;

    leds.use_full_range = ufr;
    if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
    else                     { leds.strip_range = ONE_SIDE; }

    leds.star_speed = ss;
}

void starburst_update(LEDStruct& leds) {
    keyboard_update = 0;
    switch (update_var) {
        case 0:     leds.use_full_range = (bool)update_arg;     break; //a
        case 1:     leds.star_speed     = (uint8_t)update_arg;  break; //b
        default: break;
    }
}


void starburst(LEDStruct& leds) {
    if (!leds.mode_initialized) { starburst_init(leds); }
    if (keyboard_update) { starburst_update(leds); }

    // +(leds.strip_range >> 3); // strip range / 8
    //if (numStars > 15) numStars = 15;
    //uint16_t dataSize = sizeof(star) * numStars;
    //if (!SEGENV.allocateData(dataSize)) return mode_static(); //allocation failed
    uint32_t it = millis();

    //star* stars = reinterpret_cast<star*>(SEGENV.data);

    float          maxSpeed = 375.0f;  // Max velocity
    float          particleIgnition = 250.0f;  // How long to "flash"
    float          particleFadeTime = 1500.0f; // Fade out time

    //fill(SEGCOLOR(1));   FastLED.show() ?

    for (int j = 0; j < NUM_STARS; j++)
    {
        if (leds.stars[j].birth != 0) {
            float dt = (it - leds.stars[j].last) / 1000.0;

            for (int i = 0; i < STARBURST_MAX_FRAG; i++) {
                int var = i >> 1;

                if (leds.stars[j].fragment[i] > 0) {
                    //all fragments travel right, will be mirrored on other side
                    leds.stars[j].fragment[i] += leds.stars[j].vel * dt * (float)var / 3.0;
                }
            }
            leds.stars[j].last = it;
            leds.stars[j].vel -= 3 * leds.stars[j].vel * dt;
        }

        CRGB c = leds.stars[j].color;

        // If the star is brand new, it flashes white briefly.  
        // Otherwise it just fades over time.
        float fade = 0.0f;
        float age = it - leds.stars[j].birth;

        if (age < particleIgnition) {
            c = blend(CRGB::White, c, 254.5f * ((age / particleIgnition)));
        }
        else {
            // Figure out how much to fade and shrink the star based on 
            // its age relative to its lifetime
            if (age > particleIgnition + particleFadeTime) {
                fade = 1.0f;                  // Black hole, all faded out
                leds.stars[j].birth = 0;
                c = CRGB::Black;
            }
            else {
                age -= particleIgnition;
                fade = (age / particleFadeTime);  // Fading star
                byte f = 254.5f * fade;
                c = blend(c, CRGB::Black, f);
            }
        }

        float particleSize = (1.0 - fade) * 2;

        for (uint8_t index = 0; index < STARBURST_MAX_FRAG * 2; index++) {
            bool mirrored = index & 0x1;
            uint8_t i = index >> 1;
            if (leds.stars[j].fragment[i] > 0) {
                float loc = leds.stars[j].fragment[i];
                if (mirrored) loc -= (loc - leds.stars[j].pos) * 2;
                int start = loc - particleSize;
                int end = loc + particleSize;
                if (start < 0) start = 0;
                if (start == end) end++;
                if (end > leds.strip_range) end = leds.strip_range;
                for (int p = start; p < end; p++) {
                    leds.led_data[p] = CRGB(c.r, c.g, c.b);
                }
            }
        }
    }
    //return FRAMETIME;


    // Placing birth section at end
    for (int j = 0; j < NUM_STARS; j++)
    {
        // speed to adjust chance of a burst, max is nearly always.
        if (random8((144 - (leds.star_speed >> 1))) == 0 && leds.stars[j].birth == 0)
        {
            // Pick a random color and location.  
            uint16_t startPos = random16(leds.strip_range - 1);
            float multiplier = (float)(random8()) / 255.0 * 1.0;

            CHSV temp_color = CHSV(random8(), 255, 255);
            hsv2rgb_rainbow(temp_color, leds.stars[j].color);
            //leds.stars[j].color = col_to_crgb(color_wheel(random8()));
            leds.stars[j].pos = startPos;
            leds.stars[j].vel = maxSpeed * (float)(random8()) / 255.0 * multiplier;
            leds.stars[j].birth = it;
            leds.stars[j].last = it;
            // more fragments means larger burst effect
            int num = random8(3, 14);
            //int num = random8(3, 6 + (SEGMENT.intensity >> 5));

            for (int i = 0; i < STARBURST_MAX_FRAG; i++) {
                if (i < num) leds.stars[j].fragment[i] = startPos;
                else leds.stars[j].fragment[i] = -1;
            }
        }
    }
}

#endif