#include "mission2.h"
#include "behaviors.h"



int display_color_mission2;

void mission2_init(int color_to_display) {
    display_color_mission2 = color_to_display;
}

//color_floor: 1-->white, 0-->black, 2-->gray 
void mission2_start(void *_color_floor) {
     //   for (int j=0; j < 24; j ++) {
       // LP5024_setColor(j, 100);
    //}
    int size = 5;
    int8_t color_floor = (int8_t) _color_floor;
    int16_t ground_sensor_r[size];
    int16_t ground_sensor_g[size];
    int16_t ground_sensor_b[size];
    float offset = 10.0;
    for (int i=0; i < size; i++) {
        ground_sensor_r[i] = 0;
        ground_sensor_g[i] = 0;
        ground_sensor_b[i] = 0;
    }
    int index = 0;

    float white_r, white_g, white_b;
    float black_r, black_g, black_b;
    TCS34725_get_calibrated_values(0, &white_r, &white_g, &white_b);
    TCS34725_get_calibrated_values(1, &black_r, &black_g, &black_b);
    printf("r black: %f g black: %f b black: %f\n", black_r, black_g, black_b);
    printf("r white: %f g white: %f b white: %f\n", white_r, white_g, white_b);
    m_groundState = UNKNOWN;
    m_previousGroundState = UNKNOWN;
    while (true) {
        float r, g, b;
        float mean_r = 0.0;
        float mean_g = 0.0;
        float mean_b = 0.0;
        TCS34725_get_rgb(&r, &g, &b);
        printf("r : %f g : %f b : %f\n", r, g, b);
        ground_sensor_r[index] = r;
        ground_sensor_g[index] = g;
        ground_sensor_b[index] = b;
        index++;
        if (index == size) {
            for (int j=0; j<size; j++) {
                mean_r += ground_sensor_r[j];
                mean_g += ground_sensor_g[j];
                mean_b += ground_sensor_b[j];
            }
            mean_r = mean_r/size;
            mean_g = mean_g/size;
            mean_b = mean_b/size;
            if ((white_r < mean_r + offset && white_r > mean_r - offset) && (white_g < mean_g + offset && white_g > mean_g - offset)
                 && (white_b < mean_b + offset && white_b > mean_b - offset)) {
                        printf("GROUND COLOR: WHITE\n");
                        m_groundState = WHITE;
            } else if ((black_r < mean_r + offset && black_r > mean_r - offset) && (black_g < mean_g + offset && black_g > mean_g - offset)
                 && (black_b < mean_b + offset && black_b > mean_b - offset)){
                        printf("GROUND COLOR: BLACK \n");
                        m_groundState = BLACK;
            } else {
                     printf("GROUND COLOR: GRAY \n");
                     m_groundState = GRAY;

            }

            index = 0;
            for (int i=0; i < size; i++) {
                ground_sensor_r[i] = 0;
                ground_sensor_g[i] = 0;
                ground_sensor_b[i] = 0;
            }
            if (m_previousGroundState != m_groundState) {
                m_previousGroundState = m_groundState;
                printf("CHANGE COLOR \n");
                if((m_groundState == WHITE && color_floor == 1) 
                     || (m_groundState == BLACK && color_floor == 0)
                     || (m_groundState == GRAY && color_floor == 2)) {
                        display_color_behavior(2, 0); 
                } else {
                        display_color_behavior(0, 0);
                }
               
               /* switch (m_groundState) {
                    case WHITE:
                        display_color_behavior(1, 0);
                        break;
                    case BLACK:
                        display_color_behavior(0, 0);
                        break;
                    case GRAY:
                        break;    
                    default:
                        break;
                }*/

            }
        }


        vTaskDelay(100/ portTICK_RATE_MS);
    }
}


void mission2_stop() {
    display_none();
    printf("MISSION STOPPED \n");
}