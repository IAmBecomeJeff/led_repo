#ifndef SWITCH_MODE_H
#define SWITCH_MODE_H

uint8_t num_modes = 3;

void run_mode(uint8_t m) {
    switch (m) {
    case 0: pride(); break;
    case 1: plasma(); break;
    case 2: fire(); break;
    default: break;
    }
}




#endif