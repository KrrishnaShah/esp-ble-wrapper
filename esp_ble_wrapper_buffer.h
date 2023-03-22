#ifndef __ESP_BLE_WRAPPER_BUFFER_H__
#define __ESP_BLE_WRAPPER_BUFFER_H__

#include <stdint.h>
#include "esp_gatts_api.h"

typedef struct s_linked_buffer
{
    struct s_linked_buffer *next;
    uint32_t len;
    uint8_t *buffer;
} s_linked_buffer_t;

s_linked_buffer_t *esp_ble_wrapper_buffer_create(esp_ble_gatts_cb_param_t *param);
void esp_ble_wrapper_buffer_add_to_buffer(s_linked_buffer_t *buffer, esp_ble_gatts_cb_param_t *param);
void esp_ble_wrapper_buffer_free_buffer(s_linked_buffer_t *l_buffer);
void esp_ble_wrapper_buffer_accumulate_to_start(s_linked_buffer_t *l_buffer);

#endif //  __ESP_BLE_WRAPPER_BUFFER_H__
