/*
 * uart-esp32.c
 *
 *  Created on: Dec 18, 2024
 *      Author: Acer
 */

#include "uart-esp32.h"

extern UART_HandleTypeDef huart1;

HAL_StatusTypeDef UART_SendString(const char *data) {
    return HAL_UART_Transmit(&huart1, (uint8_t *)data, strlen(data), 1000);
}
