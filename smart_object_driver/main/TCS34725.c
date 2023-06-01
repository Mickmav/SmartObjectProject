
#include "TCS34725.h"

const char *TCS34725_TAG = "TCS34725 COLOR SENSOR";

bool TCS34725_init(){
    uint8_t reg_addr = 0x92;  //0x12 << 1
    uint8_t reg_data = 0x00;

    uint8_t rgbc_reg[2] = {0x81, 0};
    uint8_t cntr_reg[2] = {0x8F, 0};
    uint8_t enbl_reg[2] = {0x80, 3};


    if(!write_to(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, &reg_addr, 1)){
        return false;
    }
    if(!read_from(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, &reg_data, 1)){
        return false;
    }

    if(!write_to(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, rgbc_reg, 2)){
        return false;
    }
    if(!write_to(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, cntr_reg, 2)){
        return false;
    }
    if(!write_to(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, enbl_reg, 2)){
        return false;
    }
    return true;
}

bool TCS34725_get_raw_data(u_int32_t* r, u_int32_t* g, u_int32_t* b, u_int32_t* c){
    uint8_t red_reg = 0x96;
    uint8_t green_reg = 0x98;
    uint8_t blue_reg = 0x9A;
    uint8_t clear_reg = 0x94;

    uint8_t red_data[2] = {0, 0};
    uint8_t green_data[2] = {0, 0};
    uint8_t blue_data[2] = {0, 0};
    uint8_t clear_data[2] = {0, 0};
    int ret;


    if(!write_to(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, &clear_reg, 1)){
        return false;
    }
    if(!read_from(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, clear_data, 2)){
        return false;
    }

    u_int32_t clear_value = (((u_int32_t) clear_data[1]) << 8) | clear_data[0];



    if(!write_to(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, &red_reg, 1)){
        return false;
    }
    if(!read_from(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, red_data, 2)){
        return false;
    }

    u_int32_t red_value = (((u_int32_t) red_data[1]) << 8) | red_data[0];


    if(!write_to(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, &green_reg, 1)){
        return false;
    }
    if(!read_from(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, green_data, 2)){
        return false;
    }

    u_int32_t green_value = (((u_int32_t) green_data[1]) << 8) | green_data[0];


    if(!write_to(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, &blue_reg, 1)){
        return false;
    }
    if(!read_from(TCS34725_TAG, I2C_MASTER_NUM, TCS34725_SLAVE_ADDR, blue_data, 2)){
        return false;
    }

    u_int32_t blue_value = (((u_int32_t) blue_data[1]) << 8) | blue_data[0];

    *r = red_value;
    *g = green_value;
    *b = blue_value;
    *c = clear_value;

    return true;
}

void TCS34725_get_rgb(float* r, float* g, float* b){
    u_int32_t red_value, green_value, blue_value, clear_value;
    TCS34725_get_raw_data(&red_value, &green_value, &blue_value, &clear_value);
   
    u_int32_t sum = clear_value;
    if(clear_value == 0){
        red_value = 0;
        green_value = 0;
        blue_value = 0;
    }
    *r = (float) red_value/sum * 255.0;
    *g = (float) green_value/sum * 255.0;
    *b = (float) blue_value/sum * 255.0;
}

void TCS34725_get_rgb_string(char* rgb_string){
    float red, green, blue;
    TCS34725_get_rgb(&red, &green, &blue);
    char buffer[50];
    char red_buffer[10];
    char green_buffer[10];
    char blue_buffer[10];
    memset(red_buffer, '\0',sizeof(red_buffer));
    memset(green_buffer, '\0',sizeof(green_buffer));
    memset(blue_buffer, '\0',sizeof(blue_buffer));
    memset(buffer, '\0',sizeof(buffer));
    snprintf(red_buffer, sizeof(red_buffer), "%f", red);
    snprintf(green_buffer, sizeof(green_buffer), "%f", green);
    snprintf(blue_buffer, sizeof(blue_buffer), "%f", blue);
    strcpy(rgb_string, "red: ");
    strcat(rgb_string, red_buffer);
    strcat(rgb_string, " green: ");
    strcat(rgb_string, green_buffer);
    strcat(rgb_string, " blue: ");
    strcat(rgb_string, blue_buffer);
}

void TCS34725_calibrate(void *pvParameters) {
    int ground_color = (int) pvParameters;
    printf("CALIBRATION FOR COLOR: %d \n", ground_color);
    // Initialize NVS
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS partition was truncated and needs to be erased
        // Retry nvs_flash_init
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK( err );
    int index = 0;
    int16_t sampling_size = 10;
    float red, green, blue;
    float buffer_red = 0.0;
    float buffer_green = 0.0;
    float buffer_blue = 0.0;
    while (index < sampling_size) {   
        index++;
        TCS34725_get_rgb(&red, &green, &blue);
        buffer_red += red;
        buffer_green += green;
        buffer_blue += blue;
        printf("r: %f g: %f b: %f\n", red, green, blue);
        vTaskDelay(1000/ portTICK_RATE_MS);
    }

    float mean_red = buffer_red/sampling_size;
    float mean_green = buffer_green/sampling_size;
    float mean_blue = buffer_blue/sampling_size;
    printf("mean r: %f mean g: %f mean b: %f\n", mean_red, mean_green, mean_blue);

    int32_t red_cal = (int32_t) (mean_red*1000);
    int32_t green_cal = (int32_t) (mean_green*1000);
    int32_t blue_cal = (int32_t) (mean_blue*1000);

      // Open
    printf("\n");
    printf("Opening Non-Volatile Storage (NVS) handle... ");
    nvs_handle_t my_handle;
    err = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
        printf("Done\n");
        // Write
        printf("Updating colors in NVS ... \n");
        if (ground_color == 0) {
            err = nvs_set_i32(my_handle, "red_white_cal", red_cal);
            printf((err != ESP_OK) ? "RED WHITE CALIBRATION Failed!\n" : " RED WHITE Done\n");
            err = nvs_set_i32(my_handle, "green_white_cal", green_cal);
            printf((err != ESP_OK) ? "GREEN WHITE CALIBRATION Failed!\n" : " GREEN WHITE Done\n");
            err = nvs_set_i32(my_handle, "blue_white_cal", blue_cal);
            printf((err != ESP_OK) ? "BLUE WHITE CALIBRATION Failed!\n" : " BLUE WHITE Done\n");

        }else {
            err = nvs_set_i32(my_handle, "red_black_cal", red_cal);
            printf((err != ESP_OK) ? "RED BLACK CALIBRATION Failed!\n" : " RED BLACK Done\n");
            err = nvs_set_i32(my_handle, "green_black_cal", green_cal);
            printf((err != ESP_OK) ? "GREEN BLACK CALIBRATION Failed!\n" : " GREEN BLACK Done\n");
            err = nvs_set_i32(my_handle, "blue_black_cal", blue_cal);
            printf((err != ESP_OK) ? "BLUE BLACK CALIBRATION Failed!\n" : " BLUE BLACK Done\n");
        }

        // Commit written value.
        // After setting any values, nvs_commit() must be called to ensure changes are written
        // to flash storage. Implementations may write to storage at other times,
        // but this is not guaranteed.
        printf("Committing updates in NVS ... ");
        err = nvs_commit(my_handle);
        printf((err != ESP_OK) ? "Failed!\n" : "Done\n");

        // Close
        nvs_close(my_handle);
    }
    vTaskDelete(0);
}

void TCS34725_get_calibrated_values(int color, float* r, float* g, float* b) {
    // Initialize NVS
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS partition was truncated and needs to be erased
        // Retry nvs_flash_init
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK( err );

     // Open
    printf("\n");
    printf("Opening Non-Volatile Storage (NVS) handle... ");
    nvs_handle_t my_handle;
    err = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
        printf("Done\n");

        // Read
        int32_t red_cal = 0; // value will default to 0, if not set yet in NVS
   	    int32_t green_cal = 0; // value will default to 0, if not set yet in NVS
   	    int32_t blue_cal = 0; // value will default to 0, if not set yet in NVS
        if (color == 0) {
            err = nvs_get_i32(my_handle, "red_white_cal", &red_cal);
 	        err = nvs_get_i32(my_handle, "green_white_cal", &green_cal);
	        err = nvs_get_i32(my_handle, "blue_white_cal", &blue_cal);
        } else {
            err = nvs_get_i32(my_handle, "red_black_cal", &red_cal);
 	        err = nvs_get_i32(my_handle, "green_black_cal", &green_cal);
	        err = nvs_get_i32(my_handle, "blue_black_cal", &blue_cal);
        }
    
        switch (err) {
            case ESP_OK:
                printf("Done\n");
                *r = ((float) red_cal/1000);
                *g = ((float) green_cal/1000);
                *b = ((float) blue_cal/1000);
                printf("DONE WITH READING \n");
		        //printf("Restart counter2 = %f\n", v);
                break;
            case ESP_ERR_NVS_NOT_FOUND:
                printf("The value is not initialized yet!\n");
                break;
            default :
                printf("Error (%s) reading!\n", esp_err_to_name(err));
        }
        // Close
        nvs_close(my_handle);
    }
}


