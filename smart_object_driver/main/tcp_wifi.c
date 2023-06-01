
#include "wifi.h"




static void respond(const int sock){
    while(1){
        float red, green, blue;
        TCS34725_get_rgb(&red, &green, &blue);
        char buffer1[50];
        char red_buffer[10];
        char green_buffer[10];
        char blue_buffer[10];
        memset(red_buffer, '\0',sizeof(red_buffer));
        memset(green_buffer, '\0',sizeof(green_buffer));
        memset(blue_buffer, '\0',sizeof(blue_buffer));
        memset(buffer1, '\0',sizeof(buffer1));
        snprintf(red_buffer, sizeof(red_buffer), "%f", red);
        snprintf(green_buffer, sizeof(green_buffer), "%f", green);
        snprintf(blue_buffer, sizeof(blue_buffer), "%f", blue);
        strcpy(buffer1, "red: ");
        strcat(buffer1, red_buffer);
        strcat(buffer1, " green: ");
        strcat(buffer1, green_buffer);
        strcat(buffer1, " blue: ");
        strcat(buffer1, blue_buffer);
        int written = send(sock, buffer1, sizeof(buffer1), 0);
       // ESP_LOGI(TAG, "SENT");
        if (written < 0) {
            ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
	    break;
        }
        vTaskDelay(100/ portTICK_RATE_MS);
    }



}

static void print_message(const int sock){
    char message[10];
    memset(message, '\0',sizeof(message));
    int len = 0;
    char rx_buffer[3];
    while(len < sizeof(message)){
        int curr_len = recv(sock, rx_buffer, sizeof(rx_buffer) - 1, 0);
        len += curr_len;
        ESP_LOGI(TAG, "Received %d bytes", curr_len);
        if (curr_len < 0) {
            ESP_LOGE(TAG, "Error occurred during receiving: errno %d", errno);
        } else if (curr_len == 0) {
            ESP_LOGW(TAG, "Connection closed");
        } else {
            rx_buffer[curr_len] = '\0'; // Null-terminate whatever is received and treat it like a string
            ESP_LOGI(TAG, "Received %d bytes: %s", curr_len, rx_buffer);
        }
        strcat(message, rx_buffer);
    }
    ESP_LOGI(TAG, "Final message: %s", message);
}


static void tcp_server_task(void *pvParameters){
    char addr_str[128];
    char addr_str1[128];
    int addr_family = (int)pvParameters;
    int ip_protocol = 0;
    struct sockaddr_in6 dest_addr;

    if (addr_family == AF_INET) {
        struct sockaddr_in *dest_addr_ip4 = (struct sockaddr_in *)&dest_addr;
        dest_addr_ip4->sin_addr.s_addr = htonl(INADDR_ANY);
       // dest_addr_ip4->sin_addr.s_addr = inet_addr("192.168.1.1");
        dest_addr_ip4->sin_family = AF_INET;
        dest_addr_ip4->sin_port = htons(PORT);
        ip_protocol = IPPROTO_IP;
    } else if (addr_family == AF_INET6) {
        bzero(&dest_addr.sin6_addr.un, sizeof(dest_addr.sin6_addr.un));
        dest_addr.sin6_family = AF_INET6;
        dest_addr.sin6_port = htons(PORT);
        ip_protocol = IPPROTO_IPV6;
    }

    int listen_sock = socket(addr_family, SOCK_STREAM, ip_protocol);
    if (listen_sock < 0) {
        ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
        vTaskDelete(NULL);
        return;
    }
    /*char* ip = inet_ntoa(dest_addr.sin6_addr);
    printf("%s \n", ip);*/

#if defined(CONFIG_EXAMPLE_IPV4) && defined(CONFIG_EXAMPLE_IPV6)
    // Note that by default IPV6 binds to both protocols, it is must be disabled
    // if both protocols used at the same time (used in CI)
    int opt = 1;
    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    setsockopt(listen_sock, IPPROTO_IPV6, IPV6_V6ONLY, &opt, sizeof(opt));
#endif

    ESP_LOGI(TAG, "Socket created");

    if (dest_addr.sin6_family == AF_INET) {
            inet_ntoa_r(((struct sockaddr_in *)&dest_addr)->sin_addr.s_addr, addr_str1, sizeof(addr_str1) - 1);
        } else if (dest_addr.sin6_family == AF_INET6) {
            inet6_ntoa_r(dest_addr.sin6_addr, addr_str1, sizeof(addr_str1) - 1);
        }
         ESP_LOGI(TAG, "Socket accepted ip address: %s", addr_str1);
    int err = bind(listen_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (err != 0) {
        ESP_LOGE(TAG, "Socket unable to bind: errno %d", errno);
        ESP_LOGE(TAG, "IPPROTO: %d", addr_family);
        goto CLEAN_UP;
    }
    ESP_LOGI(TAG, "Socket bound, port %d", PORT);

    err = listen(listen_sock, 1);
    if (err != 0) {
        ESP_LOGE(TAG, "Error occurred during listen: errno %d", errno);
        goto CLEAN_UP;
    }

    while (1) {

        ESP_LOGI(TAG, "Socket listening");

        struct sockaddr_in6 source_addr; // Large enough for both IPv4 or IPv6
        uint addr_len = sizeof(source_addr);
        int sock = accept(listen_sock, (struct sockaddr *)&source_addr, &addr_len);
        if (sock < 0) {
            ESP_LOGE(TAG, "Unable to accept connection: errno %d", errno);
            break;
        }

        // Convert ip address to string
        if (source_addr.sin6_family == PF_INET) {
            inet_ntoa_r(((struct sockaddr_in *)&source_addr)->sin_addr.s_addr, addr_str, sizeof(addr_str) - 1);
        } else if (source_addr.sin6_family == PF_INET6) {
            inet6_ntoa_r(source_addr.sin6_addr, addr_str, sizeof(addr_str) - 1);
        }
        ESP_LOGI(TAG, "Socket accepted ip address: %s", addr_str);

        //do_retransmit(sock);
        print_message(sock);
        respond(sock);
        shutdown(sock, 0);
        close(sock);
    }

CLEAN_UP:
    close(listen_sock);
    vTaskDelete(NULL);
}
