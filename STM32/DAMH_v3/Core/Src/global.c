/*
 * global.c
 *
 *  Created on: Dec 18, 2024
 *      Author: Acer
 */

#include "global.h"

State current_state = INIT;

DHT20_Data sensor_data;

uint16_t pwm_data[NUM_LEDS * 24 + 50];

char buffer1[16];
char buffer2[16];
char sendBuffer[40];

float last_temperature = -999.0; // Giá trị mặc định ngoài phạm vi đo
float last_humidity = -999.0;
