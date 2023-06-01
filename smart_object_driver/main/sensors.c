

#include "sensors.h"
#include "i2c_com.h"

bool write_to(const char* TAG, i2c_port_t i2c_num, uint8_t SLAVE_ADDR, uint8_t *data_wr, size_t size) {
    esp_err_t ret = i2c_master_write_slave(i2c_num, SLAVE_ADDR, data_wr, size);
    if (ret != ESP_OK){
        ESP_LOGE(TAG, "Error during the writing to the register!: %s", esp_err_to_name(ret));
        return false;
    }
    return true;
}
bool read_from(const char* TAG, i2c_port_t i2c_num, uint8_t SLAVE_ADDR, uint8_t *data_rd, size_t size){
    esp_err_t ret = i2c_master_read_slave(i2c_num, SLAVE_ADDR, data_rd, size);
    if (ret != ESP_OK){
        ESP_LOGE(TAG, "Error during the reading from the register!: %s", esp_err_to_name(ret));
        return false;
    }
    return true;

}