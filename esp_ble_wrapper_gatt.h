#ifndef __ESP_BLE_WRAPPER_GATT_H__
#define __ESP_BLE_WRAPPER_GATT_H__

#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_ble_wrapper_config.h"

uint16_t esp_ble_wrapper_gatt_get_max_data_size(void);
void esp_ble_wrapper_gatts_event_handler(esp_gatts_cb_event_t event, esp_gatt_if_t gatts_if, esp_ble_gatts_cb_param_t *param);
void esp_ble_wrapper_gatts_characteristic_notify(s_gatt_service_t *service, s_gatt_char_t *characteristics, esp_gatt_value_t *value);

#endif // __ESP_BLE_WRAPPER_GATT_H__
