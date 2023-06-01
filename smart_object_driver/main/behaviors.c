#include "behaviors.h"


void display_color_behavior(int8_t color, int8_t half) {
    display_none();
    int limit = 24;
    if(half == 1) {
        limit = 12;
    }
    for (int j=color; j < limit; j = j + 3) {
        LP5024_setColor(j, 140);
    }

}

void display_none() {
    for (int j=0; j < 24; j++) {
        LP5024_setColor(j, 0);
    }
}