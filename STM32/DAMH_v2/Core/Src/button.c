///*
// * button.c
// *
// *  Created on: Oct 26, 2024
// *      Author: Acer
// */
//
//#include "button.h"
//
//int button_flag[no_button] = {0};
//
//int KeyReg0[no_button] = {NORMAL_STATE};
//int KeyReg1[no_button] = {NORMAL_STATE};
//int KeyReg2[no_button] = {NORMAL_STATE};
//
//int KeyReg3[no_button] = {NORMAL_STATE};
//
//GPIO_PinState readButton(int index){
//	switch (index){
//	case BUTTON0:
//		return HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);
//	case BUTTON1:
//		return HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
//	case BUTTON2:
//		return HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
//	default:
//		return SET;
//		break;
//	}
//}
//
//int isButtonPressed(int index){
//	if(button_flag[index] == 1){
//		button_flag[index] = 0;
//		return 1;
//	}
//	return 0;
//}
//
//void getKeyInput(int index){
//	KeyReg0[index] = KeyReg1[index];
//	KeyReg1[index] = KeyReg2[index];
//	KeyReg2[index] = readButton(index);
//	if(KeyReg0[index] == KeyReg1[index] && KeyReg1[index] == KeyReg2[index]){
//		if(KeyReg2[index] != KeyReg3[index]){
//			KeyReg3[index] = KeyReg2[index];
//			if(KeyReg2[index] == PRESSED_STATE){
//				button_flag[index] = 1;
//				setTimer(index, TimerForKeyPress);
//			}
//		}
//		else{
//			runTimer(index);
//			if(timer_flag[index] == 1){
//				if(KeyReg2[index] == PRESSED_STATE){
//					KeyReg3[index] = NORMAL_STATE;
//				}
//			}
//		}
//	}
//}
//
