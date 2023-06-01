#pragma once

#include "LP5024.h"
#include "ADXL345.h"


typedef struct {
    int8_t color;
    int16_t x;
    int16_t y;
} MeanValues;


void mission1_start(void *args);
void mission1_stop();
int8_t mission1_get_random_color();

enum MovingState {
    STATIONNARY,
    MOVING

};

enum MovingState m_movingState;
