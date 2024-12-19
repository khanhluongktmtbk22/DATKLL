/*
 * scheduler.h
 *
 *  Created on: Dec 18, 2024
 *      Author: Acer
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

typedef unsigned char tByte;

typedef struct sTask{
// Pointer to the task (must be a ’ void ( void ) ’ function )
void ( * pTask) ( void ) ;
// Delay ( ti ck s ) until the function w ill ( next ) be run
uint32_t Delay ;
// Interval ( ti ck s ) between subsequent runs .
uint32_t Period ;
// Incremented ( by scheduler ) when task i s due to execute
uint8_t RunMe;
// This i s a hint to solve the question below .
uint32_t TaskID ;
// Pointer
 struct sTask *next;
 struct sTask *pre;
} sTask;

// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

typedef struct {
	sTask *head;
	sTask *tail;
	uint8_t numTasks;
} SCH_ListTasks;

void SCH_Init ( void );
void SCH_Update( void );
unsigned char SCH_Add_Task( void (* pFunction) () , unsigned int DELAY,
unsigned int PERIOD);
void SCH_Dispatch_Tasks( void );
unsigned char SCH_Delete_Task( const tByte TASK_INDEX);

#endif /* INC_SCHEDULER_H_ */
