#ifndef STARBURST_H
#define STARBURST_H

#define STARBURST_MAX_FRAG 12

//each needs 64 byte
typedef struct particle {
    CRGB     color;
    uint32_t birth = 0;
    uint32_t last = 0;
    float    vel = 0;
    uint16_t pos = -1;
    float    fragment[STARBURST_MAX_FRAG];
} star;

void starburst_init(LEDStruct& leds) {

}

void starburst_update(LEDStruct& leds) {

}

// leds.star_speed

void mode_starburst(LEDStruct& leds) {
    if (!leds.mode_initialized) { starburst_init(leds); }
    if (keyboard_update) { starburst_update(leds); }

    uint8_t numStars = 1 + (leds.strip_range >> 3);
    if (numStars > 15) numStars = 15;
    uint16_t dataSize = sizeof(star) * numStars;

    uint32_t it = millis();

    star* stars = reinterpret_cast<star*>(SEGENV.data);

    float          maxSpeed = 375.0f;  // Max velocity
    float          particleIgnition = 250.0f;  // How long to "flash"
    float          particleFadeTime = 1500.0f; // Fade out time

    for (int j = 0; j < numStars; j++)
    {
        // speed to adjust chance of a burst, max is nearly always.
        if (random8((144 - (leds.star_speed >> 1))) == 0 && stars[j].birth == 0)
        {
            // Pick a random color and location.  
            uint16_t startPos = random16(leds.strip_range - 1);
            float multiplier = (float)(random8()) / 255.0 * 1.0;

            stars[j].color = col_to_crgb(color_wheel(random8()));
            stars[j].pos = startPos;
            stars[j].vel = maxSpeed * (float)(random8()) / 255.0 * multiplier;
            stars[j].birth = it;
            stars[j].last = it;
            // more fragments means larger burst effect
            int num = random8(3, 6 + (SEGMENT.intensity >> 5));

            for (int i = 0; i < STARBURST_MAX_FRAG; i++) {
                if (i < num) stars[j].fragment[i] = startPos;
                else stars[j].fragment[i] = -1;
            }
        }
    }

    fill(SEGCOLOR(1));

    for (int j = 0; j < numStars; j++)
    {
        if (stars[j].birth != 0) {
            float dt = (it - stars[j].last) / 1000.0;

            for (int i = 0; i < STARBURST_MAX_FRAG; i++) {
                int var = i >> 1;

                if (stars[j].fragment[i] > 0) {
                    //all fragments travel right, will be mirrored on other side
                    stars[j].fragment[i] += stars[j].vel * dt * (float)var / 3.0;
                }
            }
            stars[j].last = it;
            stars[j].vel -= 3 * stars[j].vel * dt;
        }

        CRGB c = stars[j].color;

        // If the star is brand new, it flashes white briefly.  
        // Otherwise it just fades over time.
        float fade = 0.0f;
        float age = it - stars[j].birth;

        if (age < particleIgnition) {
            c = col_to_crgb(color_blend(WHITE, crgb_to_col(c), 254.5f * ((age / particleIgnition))));
        }
        else {
            // Figure out how much to fade and shrink the star based on 
            // its age relative to its lifetime
            if (age > particleIgnition + particleFadeTime) {
                fade = 1.0f;                  // Black hole, all faded out
                stars[j].birth = 0;
                c = col_to_crgb(SEGCOLOR(1));
            }
            else {
                age -= particleIgnition;
                fade = (age / particleFadeTime);  // Fading star
                byte f = 254.5f * fade;
                c = col_to_crgb(color_blend(crgb_to_col(c), SEGCOLOR(1), f));
            }
        }

        float particleSize = (1.0 - fade) * 2;

        for (uint8_t index = 0; index < STARBURST_MAX_FRAG * 2; index++) {
            bool mirrored = index & 0x1;
            uint8_t i = index >> 1;
            if (stars[j].fragment[i] > 0) {
                float loc = stars[j].fragment[i];
                if (mirrored) loc -= (loc - stars[j].pos) * 2;
                int start = loc - particleSize;
                int end = loc + particleSize;
                if (start < 0) start = 0;
                if (start == end) end++;
                if (end > SEGLEN) end = SEGLEN;
                for (int p = start; p < end; p++) {
                    setPixelColor(p, c.r, c.g, c.b);
                }
            }
        }
    }
    return FRAMETIME;
}

#endif