#pragma once

#include "i2c_com.h"
#include "sensors.h"





#define LP5024_SLAVE_ADDR 0x3C // when AD0 = AD1 = LOW (default) broadcast slave address
extern const char *LP5024_TAG;

#define LP5024_DEVICE_CONFIG0    0x00
#define LP5024_DEVICE_CONFIG1    0x01
#define LP5024_LED_CONFIG0       0x02
#define LP5024_BANK_BRIGHTNESS   0x03
#define LP5024_BANK_A_COLOR      0x04
#define LP5024_BANK_B_COLOR      0x05
#define LP5024_BANK_C_COLOR      0x06
#define LP5024_LED0_BRIGHTNESS   0x07
#define LP5024_LED1_BRIGHTNESS   0x08
#define LP5024_LED2_BRIGHTNESS   0x09
#define LP5024_LED3_BRIGHTNESS   0x0a
#define LP5024_LED4_BRIGHTNESS   0x0b
#define LP5024_LED5_BRIGHTNESS   0x0c
#define LP5024_LED6_BRIGHTNESS   0x0d
#define LP5024_LED7_BRIGHTNESS   0x0e


#define LP5024_OUT0_COLOR   0x0f
#define LP5024_OUT1_COLOR   0x10
#define LP5024_OUT2_COLOR   0x11
#define LP5024_OUT3_COLOR   0x12
#define LP5024_OUT4_COLOR   0x13
#define LP5024_OUT5_COLOR   0x14
#define LP5024_OUT6_COLOR   0x15
#define LP5024_OUT7_COLOR   0x16
#define LP5024_OUT8_COLOR   0x17
#define LP5024_OUT9_COLOR   0x18
#define LP5024_OUT10_COLOR  0x19
#define LP5024_OUT11_COLOR  0x1a
#define LP5024_OUT12_COLOR  0x1b
#define LP5024_OUT13_COLOR  0x1c
#define LP5024_OUT14_COLOR  0x1d
#define LP5024_OUT15_COLOR  0x1e
#define LP5024_OUT16_COLOR  0x1f
#define LP5024_OUT17_COLOR  0x20
#define LP5024_OUT18_COLOR  0x21
#define LP5024_OUT19_COLOR  0x22
#define LP5024_OUT20_COLOR  0x23
#define LP5024_OUT21_COLOR  0x24
#define LP5024_OUT22_COLOR  0x25
#define LP5024_OUT23_COLOR  0x26
#define LP5024_RESET        0x27



bool LP5024_init();
bool LP5024_configure(uint8_t configuration);
bool LP5024_reset();
bool LP5024_powerUp();
bool LP5024_powerDown();
bool LP5024_setColor(uint8_t channel, uint8_t color);
