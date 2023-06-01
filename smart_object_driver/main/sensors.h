#pragma once

#include "lib_includes.h"
#include "i2c_com.h"



bool write_to(const char* TAG, i2c_port_t i2c_num, uint8_t SLAVE_ADDR, uint8_t *data_wr, size_t size);
bool read_from(const char* TAG, i2c_port_t i2c_num, uint8_t SLAVE_ADDR, uint8_t *data_rd, size_t size);