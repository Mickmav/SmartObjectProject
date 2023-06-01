#include "mission3.h"
#include "behaviors.h"



void mission3_start() {
    bool start = false;
    while (true) {
        if (!start) {
            display_color_behavior(2, 0);
            start = true;
        };
        vTaskDelay(100/ portTICK_RATE_MS);
    }
}


void mission3_stop() {
    display_none();
    printf("MISSION STOPPED \n");
}