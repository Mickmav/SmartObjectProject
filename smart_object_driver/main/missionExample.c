#include "missionExample.h"
#include "behaviors.h"

// Example of a potenital mission 
// Attention don't forget to add in Cmake
void missionExample_start() {
    while (true)
    {
        /* code */
        printf("Hello Word");
        vTaskDelay(100/ portTICK_RATE_MS);
    }
    
}


void missionExample_stop() {
    display_none();
    printf("MISSION STOPPED \n");
}