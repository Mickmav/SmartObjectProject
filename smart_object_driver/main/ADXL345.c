#include "ADXL345.h"

const char *ADXL345_TAG = "ADXL345 ACCELEROMETER";



bool ADXL345_get_device_id(uint8_t* device_id){

    uint8_t reg_addr = ADXL345_REG_DEVID; 
    uint8_t reg_data = 0x00;
    *device_id = reg_data;

    if(!write_to(ADXL345_TAG, I2C_MASTER_NUM, ADXL345_SLAVE_ADDR, &reg_addr, 1)){
        return false;
    }
    if(!read_from(ADXL345_TAG, I2C_MASTER_NUM, ADXL345_SLAVE_ADDR, device_id, 2)){
        return false;
    }
    return true;

}

bool ADXL345_init(){
    uint8_t pwr_reg_addr[2] = {ADXL345_REG_POWER_CTL, 8}; // ...[0] register address, ...[1] what we want to write into this register 8 = 0b00001000 
    if(!write_to(ADXL345_TAG, I2C_MASTER_NUM, ADXL345_SLAVE_ADDR, pwr_reg_addr, 2)){
        return false;
    }
    return true;
}


// Calibrate by computing the mean values at rest by computing the offset
void ADXL345_calibrateAccelerometer(int16_t *mean_x, int16_t *mean_y) {
    int16_t sample_x[100];
    int16_t sample_y[100];
    int16_t x,y,z;
    int i = 0;
    while(i < 100) {
        ADXL345_get_data(&x, &y, &z);
        sample_x[i] = x;
        sample_y[i] = y;
        printf("sampling \n");
        vTaskDelay(100/ portTICK_RATE_MS);
        i++;
    } 
    for (int j=0; j < 100; j++) {
        *mean_x = *mean_x + sample_x[j];
        *mean_y = *mean_y + sample_y[j];
    }
    *mean_x = *mean_x/100;
    *mean_y = *mean_y/100;
}
/*
void ADXL345_calibrateAccelerometer1(void * args) {
    MeanValues* M1args = (MeanValues*) args;
    int16_t mean_x, mean_y;
    mean_x = (int16_t) M1args->x;
    mean_y = (int16_t) M1args->y;
    int16_t sample_x[100];
    int16_t sample_y[100];
    int16_t x,y,z;
    int i = 0;
    while(i < 100) {
        ADXL345_get_data(&x, &y, &z);
        sample_x[i] = x;
        sample_y[i] = y;
        printf("sampling \n");
        vTaskDelay(100/ portTICK_RATE_MS);
        i++;
    } 
    for (int j=0; j < 100; j++) {
        mean_x = mean_x + sample_x[j];
        mean_y = mean_y + sample_y[j];
    }
    mean_x = mean_x/100;
    mean_y = mean_y/100;

    M1args->x = mean_x;
    M1args->y = mean_;
}*/


bool ADXL345_get_x(int16_t* x_acc){
    uint8_t x_reg = ADXL345_REG_DATAX0;
    uint8_t x_data[2] = {0, 0};

    if(!write_to(ADXL345_TAG, I2C_MASTER_NUM, ADXL345_SLAVE_ADDR, &x_reg, 1)){
        return false;
    }
    if(!read_from(ADXL345_TAG, I2C_MASTER_NUM, ADXL345_SLAVE_ADDR, x_data, 2)){
        return false;
    }

    *x_acc = (int16_t)((((uint16_t) x_data[1]) << 8) | x_data[0]);
    return true;
}
bool ADXL345_get_y(int16_t* y_acc){
    uint8_t y_reg = ADXL345_REG_DATAY0;
    uint8_t y_data[2] = {0, 0};


    if(!write_to(ADXL345_TAG, I2C_MASTER_NUM, ADXL345_SLAVE_ADDR, &y_reg, 1)){
        return false;
    }
    if(!read_from(ADXL345_TAG, I2C_MASTER_NUM, ADXL345_SLAVE_ADDR, y_data, 2)){
        return false;
    }
    *y_acc = (int16_t)((((uint16_t) y_data[1]) << 8) | y_data[0]);

    return true;
}
bool ADXL345_get_z(int16_t* z_acc){
    uint8_t z_reg = ADXL345_REG_DATAZ0;
    uint8_t z_data[2] = {0, 0};

   if(!write_to(ADXL345_TAG, I2C_MASTER_NUM, ADXL345_SLAVE_ADDR, &z_reg, 1)){
        return false;
    }
    if(!read_from(ADXL345_TAG, I2C_MASTER_NUM, ADXL345_SLAVE_ADDR, z_data, 2)){
        return false;
    }
    *z_acc = (int16_t)((((uint16_t) z_data[1]) << 8) | z_data[0]);
    return true;
}

bool ADXL345_get_data(int16_t* x_acc, int16_t* y_acc, int16_t* z_acc){
    if(!ADXL345_get_x(x_acc)){
        return false;
    }
    if(!ADXL345_get_y(y_acc)){
        return false;
    }
    if(!ADXL345_get_z(z_acc)){
        return false;
    }

    return true;
}
