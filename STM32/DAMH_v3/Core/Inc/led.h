/*
 * fsm_RGB.h
 *
 *  Created on: Dec 18, 2024
 *      Author: Acer
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "stm32f1xx_hal.h"
#include "global.h"

extern TIM_HandleTypeDef htim2;

// Hàm ánh xạ dữ liệu màu sang PWM
void WS2812_SetColor(uint8_t red, uint8_t green, uint8_t blue);

// Hàm gửi dữ liệu PWM
void WS2812_Send(void);

void Led_RGB_temp();

#endif /* INC_LED_H_ */
