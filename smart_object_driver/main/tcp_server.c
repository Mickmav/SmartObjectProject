
#include "tcp_server.h"




int tcp_respond(const int socket, const char* message, const int size){
	int written = send(socket, message, size, 0);
	if (written < 0) {
           ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
    }
	return written;
}


int tcp_socket_listening(const int listen_sock){
	char addr_str[128];
	ESP_LOGI(TAG, "Socket listening");

    struct sockaddr_in6 source_addr; // Large enough for both IPv4 or IPv6
    uint addr_len = sizeof(source_addr);
    int sock = accept(listen_sock, (struct sockaddr *)&source_addr, &addr_len);
    if (sock < 0) {
        ESP_LOGE(TAG, "Unable to accept connection: errno %d", errno);
		return 1;
    }

    // Convert ip address to string
    if (source_addr.sin6_family == PF_INET) {
        inet_ntoa_r(((struct sockaddr_in *)&source_addr)->sin_addr.s_addr, addr_str, sizeof(addr_str) - 1);
        printf("IP ADDRESS v4 \n");
    } else if (source_addr.sin6_family == PF_INET6) {
        printf("ip address v6 \n");
        inet6_ntoa_r(source_addr.sin6_addr, addr_str, sizeof(addr_str) - 1);
    }
    ESP_LOGI(TAG, "Socket accepted ip address: %s", addr_str);
	return sock;
}


unsigned long long int get_config(const int sock){
    char rx_buffer[14];
    char config[13];
    unsigned long long int config_num = 0;
    memset(config, '\0',sizeof(config));
    memset(rx_buffer, '\0',sizeof(rx_buffer));
    int len = 0;
    while(len < sizeof(config)){
        int curr_len = recv(sock, rx_buffer, sizeof(rx_buffer) - 1, 0);
        len += curr_len;   
        if (curr_len < 0) {
            ESP_LOGE(TAG, "Error occurred during receiving: errno %d", errno);
        } else if (curr_len == 0) {
            ESP_LOGW(TAG, "Connection closed");
            break;
        } else {
            rx_buffer[curr_len] = '\0'; // Null-terminate whatever is received and treat it like a string
            //ESP_LOGI(TAG, "Received %d bytes: %s", curr_len, rx_buffer);
        }
        strcat(config, rx_buffer);
    }
    //sscanf(config, "%ld", &config_num);
    config_num = strtoull(config, NULL, 10);
    return config_num;
}

int get_action(const int sock){
    char init_buffer[1];
    recv(sock, init_buffer, sizeof(init_buffer), 0);
    int num = init_buffer[0] - '0';
    if(num != 0){
        return num;
    }
    return 0;
}

int get_id(const int sock){
    char init_buffer[1];
    recv(sock, init_buffer, sizeof(init_buffer), 0);
    int id = init_buffer[0] - '0';

    return id;
}

/*char* getFile(const int sock) { 
    char* file = "A";


    return file;
}*/


void print_message(const int sock){
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



int tcp_server_init(void *pvParameters){
    int addr_family = (int)pvParameters;
    int ip_protocol = 0;
    struct sockaddr_in6 dest_addr;

    if (addr_family == AF_INET) {
        struct sockaddr_in *dest_addr_ip4 = (struct sockaddr_in *)&dest_addr;
        dest_addr_ip4->sin_addr.s_addr = htonl(INADDR_ANY);
        //dest_addr_ip4->sin_addr.s_addr = inet_addr("192.168.4.1");
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
        return 1;
    }

#if defined(CONFIG_EXAMPLE_IPV4) && defined(CONFIG_EXAMPLE_IPV6)
    // Note that by default IPV6 binds to both protocols, it is must be disabled
    // if both protocols used at the same time (used in CI)
    int opt = 1;
    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    setsockopt(listen_sock, IPPROTO_IPV6, IPV6_V6ONLY, &opt, sizeof(opt));
#endif

    ESP_LOGI(TAG, "Socket created");

    int err = bind(listen_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (err != 0) {
        ESP_LOGE(TAG, "Socket unable to bind: errno %d", errno);
        ESP_LOGE(TAG, "IPPROTO: %d", addr_family);
        return 1;
    }
    ESP_LOGI(TAG, "Socket bound, port %d", PORT);

    err = listen(listen_sock, 1);
    if (err != 0) {
        ESP_LOGE(TAG, "Error occurred during listen: errno %d", errno);
	close(listen_sock);
	return 1;
    	//vTaskDelete(NULL);
    }

    ESP_LOGI(TAG, "Successful creation of the socket!");
    return listen_sock;

}
