/*
 * uart-esp32.h
 *
 *  Created on: Dec 18, 2024
 *      Author: Acer
 */

#ifndef INC_UART_ESP32_H_
#define INC_UART_ESP32_H_

#include "stm32f1xx_hal.h"
#include "string.h"

HAL_StatusTypeDef UART_SendString(const char *data);

#endif /* INC_UART_ESP32_H_ */
