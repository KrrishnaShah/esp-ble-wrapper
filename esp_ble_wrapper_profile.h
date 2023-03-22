#ifndef __ESP_BLE_WRAPPER_PROFILE_H__
#define __ESP_BLE_WRAPPER_PROFILE_H__
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_ble_wrapper_config.h"

s_gatt_service_t *esp_ble_wrapper_profile_get_by_app_id(uint16_t app_id);
s_gatt_service_t *esp_ble_wrapper_profile_get_service_by_gatts_if(uint16_t gatts_if);

s_gatt_descr_t *esp_ble_wrapper_profile_get_initiating_descriptor(s_gatt_char_t *characteristic);
// s_gatt_descr_t *esp_ble_wrapper_profile_get_initiating_descriptor(s_gatt_service_t *service);
s_gatt_descr_t *esp_ble_wrapper_profile_get_descriptor_to_init(s_gatt_char_t *characteristic);

// s_gatt_char_t *esp_ble_wrapper_profile_get_characterstics_to_init(void);
s_gatt_char_t *esp_ble_wrapper_profile_get_initiating_characterstics(s_gatt_service_t *service);
s_gatt_char_t *esp_ble_wrapper_profile_get_characterstics_to_init(s_gatt_service_t *service);

s_gatt_service_t *esp_ble_wrapper_gatt_create_service(uint16_t app_id, esp_bt_uuid_t *service_uuid);
s_gatt_descr_t *esp_ble_wrapper_gatt_add_descriptor(s_gatt_char_t *charcteristic, esp_bt_uuid_t *uuid, esp_gatt_perm_t permission,
                                                    f_upcall_t read_func, f_upcall_t write_func, f_upcall_t write_exec_func);
s_gatt_char_t *esp_ble_wrapper_gatt_add_characteristic(s_gatt_service_t *service_obj, esp_bt_uuid_t *uuid, esp_gatt_perm_t permission, esp_gatt_char_prop_t properties,
                                                       f_upcall_t read_func, f_upcall_t write_func, f_upcall_t write_exec_func);
s_gatt_service_t *esp_ble_wrapper_profile_get_head(void);

int esp_ble_wrapper_gatt_number_of_services(void);

void esp_ble_wrapper_gatt_print_descriptor(s_gatt_descr_t *descriptor);
void esp_ble_wrapper_gatt_print_characteristic(s_gatt_char_t *characteristic);
void esp_ble_wrapper_gatt_print_service(s_gatt_service_t *service);
void esp_ble_wrapper_gatt_print_uuid(esp_bt_uuid_t *uuid, char *msg);
void esp_ble_wrapper_profile_print(void);

#endif // __ESP_BLE_WRAPPER_PROFILE_H__
