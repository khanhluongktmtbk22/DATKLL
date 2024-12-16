/*
 * led7_segment.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Acer
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "main.h"

void display7Seg0(int num);
void display7Seg1(int num);
void display7Seg2(int num);
void display7Seg3(int num);

void setCountDown7Seg0(int num);
void setCountDown7Seg1(int num);
void runCountDown7Seg0();
void runCountDown7Seg1();

#endif /* INC_LED7_SEGMENT_H_ */
