/*
 * global.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Acer
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "traffic_light.h"
#include "led7_segment.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"

#define INIT 1
#define AUTO_RED 2
#define AUTO_YELLOW 3
#define AUTO_GREEN 4

#define INIT_MODE 10
#define NORMAL_MODE 11
#define MAN_RED 12
#define MAN_YELLOW 13
#define MAN_GREEN 14


#define timerForTrafficLight1 3
#define timerForTrafficLight2 4
#define timer1Sec1 5
#define timer1Sec2 6
#define timer250ms 7
#define timerAnimation1 8
#define timerAnimation2 9
#define ON 1
#define OFF 0

extern int timeRedOn;
extern int timeYellowOn;
extern int timeGreenOn;

extern int setTimeRed;
extern int setTimeYellow;
extern int setTimeGreen;

extern int statusLed1;
extern int statusLed2;
extern int statusMode;
extern int toggle;

extern int countDown1;
extern int countDown2;

extern int EN0, EN1, EN2, EN3;
#endif /* INC_GLOBAL_H_ */
