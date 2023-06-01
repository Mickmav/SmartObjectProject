#include "LP5024.h"



const char *LP5024_TAG = "LP5024 LED DRIVER";


bool LP5024_init() {
    bool success = true;
    if(!LP5024_powerUp()){
        success = false;
    }
    if(!LP5024_configure(0x20 | 0x10 | 0x08 | 0x04)){
        success = false;
    }
    return success;

}

bool LP5024_configure(uint8_t configuration) {
    uint8_t init_reg_addr[2] = {LP5024_DEVICE_CONFIG1, configuration};
    if(!write_to(LP5024_TAG, I2C_MASTER_NUM, LP5024_SLAVE_ADDR, init_reg_addr, 2)){
        return false;
    }
    return true;
}


bool LP5024_powerUp() {
    uint8_t pwr_reg_addr[2] = {LP5024_DEVICE_CONFIG0, 0x40}; // 0x40 = 64 = 0b01000000 6th bit set to 1 (counting from 0 -> 7)
    if(!write_to(LP5024_TAG, I2C_MASTER_NUM, LP5024_SLAVE_ADDR, pwr_reg_addr, 2)){
        return false;
    }
    return true;
}

bool LP5024_powerDown() {
    uint8_t pwr_reg_addr[2] = {LP5024_DEVICE_CONFIG0, 0x00}; // 0x00 = 0 = 0b00000000 6th bit set to 0 (counting from 0 -> 7)
    if(!write_to(LP5024_TAG, I2C_MASTER_NUM, LP5024_SLAVE_ADDR, pwr_reg_addr, 2)){
        return false;
    }
    return true;
}


bool LP5024_reset() {
    uint8_t reset_reg_addr[2] = {LP5024_RESET, 0xFF}; 
    if(!write_to(LP5024_TAG, I2C_MASTER_NUM, LP5024_SLAVE_ADDR, reset_reg_addr, 2)){
        return false;
    }
    return true;
}

bool LP5024_setColor(uint8_t channel, uint8_t color) {
    uint8_t color_reg_addr[2] = {LP5024_OUT0_COLOR + channel, color}; 
        if(!write_to(LP5024_TAG, I2C_MASTER_NUM, LP5024_SLAVE_ADDR, color_reg_addr, 2)){
            return false;
        }
    return true;
}