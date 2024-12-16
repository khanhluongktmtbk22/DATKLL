/*
 * button.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Acer
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "software_timer.h"
#include "main.h"

#define no_button 3
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define TimerForKeyPress 200
#define BUTTON0 0
#define BUTTON1 1
#define BUTTON2 2


GPIO_PinState readButton(int index);
int isButtonPressed(int index);
void getKeyInput(int index);


#endif /* INC_BUTTON_H_ */
