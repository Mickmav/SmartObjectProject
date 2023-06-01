
#pragma once

#include "LP5024.h"
#include "TCS34725.h"




void mission2_init(int color_to_display);
void mission2_start();
void mission2_stop();

enum GroundState {
    WHITE,
    BLACK,
    GRAY,
    UNKNOWN
};

enum GroundState m_groundState, m_previousGroundState;
