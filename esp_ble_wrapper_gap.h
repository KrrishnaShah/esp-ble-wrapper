#ifndef __ESP_BLE_WRAPPER_GAP_H__
#define __ESP_BLE_WRAPPER_GAP_H__

#include "esp_gap_ble_api.h"
#include "esp_bt_defs.h"
#include "esp_ble_wrapper_config.h"

void esp_ble_wrapper_gap_set_passkey(uint32_t passkey);
void esp_ble_wrapper_gap_dissociate_bonded_devices(void);
void esp_ble_wrapper_gap_config_adv_data(void);
void esp_ble_wrapper_gap_config_scan_rsp_data(void);
void esp_ble_wrapper_gap_start_advertising(void);
void esp_ble_wrapper_gap_event_handler(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param);

#endif //  __ESP_BLE_WRAPPER_GAP_H__
