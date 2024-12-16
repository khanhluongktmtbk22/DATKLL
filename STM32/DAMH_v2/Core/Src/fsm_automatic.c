///*
// * fsm_automatic.c
// *
// *  Created on: Oct 26, 2024
// *      Author: Acer
// */
//
//#include "fsm_automatic.h"
//
//void fsm_automatic_run1(){
//	switch(statusLed1){
//		case INIT:
//			setRed1(OFF);
//			setYellow1(OFF);
//			setGreen1(OFF);
//
//			statusLed1 = AUTO_RED;
//			setTimer(timerForTrafficLight1, timeRedOn);
//
//			setCountDown7Seg0(timeRedOn/100);
//			break;
//		case AUTO_RED:
//			setRed1(ON);
//			setYellow1(OFF);
//			setGreen1(OFF);
//
//			runCountDown7Seg0();
//
//			if(timer_flag[timerForTrafficLight1] == 1){
//				statusLed1 = AUTO_GREEN;
//				setTimer(timerForTrafficLight1, timeGreenOn);
//
//				setCountDown7Seg0(timeGreenOn/100);
//			}
//			break;
//		case AUTO_YELLOW:
//			setRed1(OFF);
//			setYellow1(ON);
//			setGreen1(OFF);
//
//			runCountDown7Seg0();
//
//			if(timer_flag[timerForTrafficLight1] == 1){
//				statusLed1 = AUTO_RED;
//				setTimer(timerForTrafficLight1, timeRedOn);
//
//				setCountDown7Seg0(timeRedOn/100);
//			}
//			break;
//		case AUTO_GREEN:
//			setRed1(OFF);
//			setYellow1(OFF);
//			setGreen1(ON);
//
//			runCountDown7Seg0();
//
//			if(timer_flag[timerForTrafficLight1] == 1){
//				statusLed1 = AUTO_YELLOW;
//				setTimer(timerForTrafficLight1, timeYellowOn);
//
//				setCountDown7Seg0(timeYellowOn/100);
//			}
//			break;
//		default:
//			statusLed1 = INIT;
//			break;
//	}
//}
//
//void fsm_automatic_run2(){
//	switch(statusLed2){
//		case INIT:
//			setRed2(OFF);
//			setYellow2(OFF);
//			setGreen2(OFF);
//
//			statusLed2 = AUTO_GREEN;
//			setTimer(timerForTrafficLight2, timeGreenOn);
//
//			setCountDown7Seg1(timeGreenOn/100);
//			break;
//		case AUTO_RED:
//			setRed2(ON);
//			setYellow2(OFF);
//			setGreen2(OFF);
//
//			runCountDown7Seg1();
//
//			if(timer_flag[timerForTrafficLight2] == 1){
//				statusLed2 = AUTO_GREEN;
//				setTimer(timerForTrafficLight2, timeGreenOn);
//
//				setCountDown7Seg1(timeGreenOn/100);
//			}
//			break;
//		case AUTO_YELLOW:
//			setRed2(OFF);
//			setYellow2(ON);
//			setGreen2(OFF);
//
//			runCountDown7Seg1();
//
//			if(timer_flag[timerForTrafficLight2] == 1){
//				statusLed2 = AUTO_RED;
//				setTimer(timerForTrafficLight2, timeRedOn);
//
//				setCountDown7Seg1(timeRedOn/100);
//			}
//			break;
//		case AUTO_GREEN:
//			setRed2(OFF);
//			setYellow2(OFF);
//			setGreen2(ON);
//
//			runCountDown7Seg1();
//
//			if(timer_flag[timerForTrafficLight2] == 1){
//				statusLed2 = AUTO_YELLOW;
//				setTimer(timerForTrafficLight2, timeYellowOn);
//
//				setCountDown7Seg1(timeYellowOn/100);
//			}
//			break;
//		default:
//			statusLed2 = INIT;
//			break;
//	}
//}
