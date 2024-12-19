/*
 * global.h
 *
 *  Created on: Dec 18, 2024
 *      Author: Acer
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <led.h>
#include "stdio.h"
#include "string.h"
#include <stdint.h>

#include "software_timer.h"
#include "scheduler.h"
#include "i2c-lcd.h"
#include "i2c-dht20.h"
#include "uart-esp32.h"

#include "fsm_main.h"

#define NUM_LEDS 1
extern uint16_t pwm_data[NUM_LEDS * 24 + 50];

typedef enum {
	INIT,
    READING,
    UPDATING_DISPLAY,
    ERROR_DISPLAY
} State;

extern State current_state;

extern int status;

extern DHT20_Data sensor_data;

extern char buffer1[16];
extern char buffer2[16];
extern char sendBuffer[40];

extern float last_temperature; // Giá trị mặc định ngoài phạm vi đo
extern float last_humidity;

#endif /* INC_GLOBAL_H_ */
