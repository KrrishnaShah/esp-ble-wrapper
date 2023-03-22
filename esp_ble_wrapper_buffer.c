#include "string.h"
#include "esp_ble_wrapper_buffer.h"
#include "esp_gatts_api.h"

s_linked_buffer_t *esp_ble_wrapper_buffer_create(esp_ble_gatts_cb_param_t *param)
{
    s_linked_buffer_t *linked_buffer = malloc(sizeof(s_linked_buffer_t));
    if (linked_buffer)
    {
        memset(linked_buffer, 0, sizeof(s_linked_buffer_t));
        if ((NULL != param->write.value) && (param->write.len > 0))
        {
            linked_buffer->buffer = malloc(param->write.len);
            if (linked_buffer->buffer)
            {
                memcpy(linked_buffer->buffer, param->write.value, param->write.len);
            }
            else
            {
                free(linked_buffer);
                linked_buffer = NULL;
            }
        }
        else
        {
            free(linked_buffer);
            linked_buffer = NULL;
        }
    }

    return linked_buffer;
}

void esp_ble_wrapper_buffer_add_to_buffer(s_linked_buffer_t *buffer, esp_ble_gatts_cb_param_t *param)
{
    while (buffer->next)
    {
        buffer = buffer->next;
    }

    buffer->next = esp_ble_wrapper_buffer_create(param);
}

void esp_ble_wrapper_buffer_free_buffer(s_linked_buffer_t *l_buffer)
{
    if (l_buffer)
    {
        if (l_buffer->buffer)
        {
            free(l_buffer->buffer);
        }
        esp_ble_wrapper_buffer_free_buffer(l_buffer->next);
    }
}

void esp_ble_wrapper_buffer_accumulate_to_start(s_linked_buffer_t *l_buffer)
{
    if (l_buffer)
    {
        uint32_t tot_len = 0;
        while (l_buffer)
        {
            tot_len += l_buffer->len;
            l_buffer = l_buffer->next;
        }

        uint8_t *tot_buffer = malloc(sizeof(s_linked_buffer_t));
        if (tot_buffer)
        {
            uint32_t pos = 0;
            while (l_buffer)
            {
                memcpy(&tot_buffer[pos], l_buffer->buffer, l_buffer->len);
                pos += l_buffer->len;
                l_buffer = l_buffer->next;
            }

            if (l_buffer->buffer)
            {
                free(l_buffer->buffer);
            }

            l_buffer->buffer = tot_buffer;
            l_buffer->len = tot_len;
        }

        esp_ble_wrapper_buffer_free_buffer(l_buffer->next);
    }
}