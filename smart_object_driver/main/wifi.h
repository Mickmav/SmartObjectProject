#pragma once

#include "lib_includes.h"

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

// #include "esp_mac.h" //added by me

#include "lwip/err.h"
#include "lwip/sys.h"


//#define EXAMPLE_ESP_WIFI_SSID      "Proximus-Home-412118"
//#define EXAMPLE_ESP_WIFI_PASS      "hrd4c3hubp939s3y"
//#define EXAMPLE_ESP_WIFI_SSID      "YourWifiName"
//#define EXAMPLE_ESP_WIFI_PASS      "YourWifiPass"
#define EXAMPLE_ESP_WIFI_SSID      "marconi"
#define EXAMPLE_ESP_WIFI_PASS      "iridi4-net"
#define MAX_LINE_LENGTH            100
#define EXAMPLE_ESP_WIFI_CHANNEL   1
#define EXAMPLE_MAX_STA_CONN       4
#define EXAMPLE_ESP_MAXIMUM_RETRY  100

int getCon();
// create wifi
void wifi_init_softap(void);
// connect to wifi
void wifi_init_sta(void);