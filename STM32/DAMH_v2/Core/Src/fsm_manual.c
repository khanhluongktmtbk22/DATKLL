///*
// * fsm_manual.c
// *
// *  Created on: Oct 26, 2024
// *      Author: Acer
// */
//
//#include "fsm_manual.h"
//
//void fsm_manual_run(){
//	switch(statusMode){
//		case INIT_MODE:
//			setTimeRed = timeRedOn;
//			setTimeYellow = timeYellowOn;
//			setTimeGreen = timeGreenOn;
//			statusLed1 = INIT;
//			statusLed2 = INIT;
//			statusMode = NORMAL_MODE;
//		case NORMAL_MODE:
//			display7Seg2(0);
//			display7Seg3(0);
//			fsm_automatic_run1();
//			fsm_automatic_run2();
//			if(isButtonPressed(0) == 1){
//				statusMode = MAN_RED;
//				setTimer(timer250ms, 25);
//			}
//			break;
//		case MAN_RED:
//			display7Seg0(2);
//			display7Seg1(2);
//			display7Seg2((setTimeRed/100)/10);
//			display7Seg3((setTimeRed/100)%10);
//			if(timer_flag[timer250ms] == 1){
//				if(toggle == 0){
//					setRed1(ON);
//					setRed2(ON);
//					setYellow1(OFF);
//					setYellow2(OFF);
//					setGreen1(OFF);
//					setGreen2(OFF);
//					setTimer(timer250ms, 25);
//					toggle = 1 - toggle;
//				}
//				else{
//					setRed1(OFF);
//					setRed2(OFF);
//					setYellow1(OFF);
//					setYellow2(OFF);
//					setGreen1(OFF);
//					setGreen2(OFF);
//					setTimer(timer250ms, 25);
//					toggle = 1 - toggle;
//				}
//			}
//			if(isButtonPressed(1) == 1){
//				setTimeRed += 100;
//				display7Seg2((setTimeRed/100)/10);
//				display7Seg3((setTimeRed/100)%10);
//			}
//			if(isButtonPressed(2) == 1){
//				timeRedOn = setTimeRed;
//			}
//			if(isButtonPressed(0) == 1){
//				setTimeRed = timeRedOn;
//				statusMode = MAN_YELLOW;
//			}
//			break;
//		case MAN_YELLOW:
//			display7Seg0(3);
//			display7Seg1(3);
//			display7Seg2((setTimeYellow/100)/10);
//			display7Seg3((setTimeYellow/100)%10);
//			if(timer_flag[timer250ms] == 1){
//				if(toggle == 0){
//					setRed1(OFF);
//					setRed2(OFF);
//					setYellow1(ON);
//					setYellow2(ON);
//					setGreen1(OFF);
//					setGreen2(OFF);
//					setTimer(timer250ms, 25);
//					toggle = 1 - toggle;
//				}
//				else{
//					setRed1(OFF);
//					setRed2(OFF);
//					setYellow1(OFF);
//					setYellow2(OFF);
//					setGreen1(OFF);
//					setGreen2(OFF);
//					setTimer(timer250ms, 25);
//					toggle = 1 - toggle;
//				}
//			}
//			if(isButtonPressed(1) == 1){
//				setTimeYellow += 100;
//				display7Seg2((setTimeYellow/100)/10);
//				display7Seg3((setTimeYellow/100)%10);
//			}
//			if(isButtonPressed(2) == 1){
//				timeYellowOn = setTimeYellow;
//			}
//			if(isButtonPressed(0) == 1){
//				setTimeYellow = timeYellowOn;
//				statusMode = MAN_GREEN;
//			}
//			break;
//		case MAN_GREEN:
//			display7Seg0(4);
//			display7Seg1(4);
//			display7Seg2((setTimeGreen/100)/10);
//			display7Seg3((setTimeGreen/100)%10);
//			if(timer_flag[timer250ms] == 1){
//				if(toggle == 0){
//					setRed1(OFF);
//					setRed2(OFF);
//					setYellow1(OFF);
//					setYellow2(OFF);
//					setGreen1(ON);
//					setGreen2(ON);
//					setTimer(timer250ms, 25);
//					toggle = 1 - toggle;
//				}
//				else{
//					setRed1(OFF);
//					setRed2(OFF);
//					setYellow1(OFF);
//					setYellow2(OFF);
//					setGreen1(OFF);
//					setGreen2(OFF);
//					setTimer(timer250ms, 25);
//					toggle = 1 - toggle;
//				}
//			}
//			if(isButtonPressed(1) == 1){
//				setTimeGreen += 100;
//				display7Seg2((setTimeGreen/100)/10);
//				display7Seg3((setTimeGreen/100)%10);
//			}
//			if(isButtonPressed(2) == 1){
//				timeGreenOn = setTimeGreen;
//			}
//			if(isButtonPressed(0) == 1){
//				setTimeGreen = timeGreenOn;
//				statusMode = INIT_MODE;
//			}
//			break;
//		default:
//			statusMode = INIT_MODE;
//			break;
//	}
//}
