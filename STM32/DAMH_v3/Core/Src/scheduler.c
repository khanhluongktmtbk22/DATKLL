/*
 * scheduler.c
 *
 *  Created on: Dec 18, 2024
 *      Author: Acer
 */

#include "scheduler.h"

#include "main.h"

//#include "global.h ở .h", tạo SCH_task_G ở global
SCH_ListTasks ListTasks;

void SCH_Init ( void ) {
	while(ListTasks.head != NULL){
		SCH_Delete_Task(0);
	}
	// Reset the global error variable
	// − SCH_Delete_Task () w ill generate an error code ,
	// ( because the task array i s empty)
	//Error_code_G = 0;
	//Timer_int () ;
	ListTasks.numTasks = 0;
	//Watchdog_init () ;
}

void SCH_Update( void ) {
//	if(ListTasks.head!=NULL){
//		if(ListTasks.head->Delay == 0){
//			ListTasks.head->RunMe = 1;
////			if(ListTasks.head->Period){
////				ListTasks.head->Delay = ListTasks.head->Period;
////			}
//		}
//		else{
//			ListTasks.head->Delay --;
//		}
//	}
	if(ListTasks.head!=NULL){
		if(ListTasks.head->Delay>0){
			ListTasks.head->Delay --;
		}
		if(ListTasks.head->Delay == 0){
			ListTasks.head->RunMe = 1;
//			if(ListTasks.head->Period){
//				ListTasks.head->Delay = ListTasks.head->Period;
//			}
		}
	}
}

unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD) {
    // Kiểm tra danh sách đầy
    if (ListTasks.numTasks >= SCH_MAX_TASKS) {
        // Task list is full
        return SCH_MAX_TASKS;
    }

    // Tạo task mới
    sTask* newTask = (sTask*)malloc(sizeof(sTask));
    if (newTask == NULL) {
        // Trường hợp malloc thất bại
        return SCH_MAX_TASKS; // Hoặc mã lỗi khác
    }

    // Khởi tạo các thuộc tính của task
    newTask->pTask = pFunction;
    newTask->Period = PERIOD;
    newTask->RunMe = 0;
    newTask->Delay = DELAY;
    newTask->next = NULL;
    newTask->pre = NULL;

    // Nếu danh sách rỗng, thêm task vào đầu
    if (ListTasks.numTasks == 0) {
        ListTasks.head = newTask;
        ListTasks.tail = newTask;
    } else {
        sTask* tmp = ListTasks.head;

        // Kiểm tra nếu task mới có Delay nhỏ hơn head
        if (newTask->Delay < tmp->Delay) {
            tmp->Delay -= newTask->Delay; // Giảm delay của head
            newTask->next = tmp;
            tmp->pre = newTask;
            ListTasks.head = newTask; // Cập nhật head
        } else {
            // Tìm vị trí phù hợp trong danh sách
            newTask->Delay -= tmp->Delay; // Delay tương đối
            while (tmp->next != NULL && newTask->Delay >= tmp->next->Delay) {
                newTask->Delay -= tmp->next->Delay;
                tmp = tmp->next;
            }

            // Chèn task mới vào danh sách
            newTask->next = tmp->next;
            newTask->pre = tmp;

            if (tmp->next != NULL) {
                tmp->next->pre = newTask;
                tmp->next->Delay -= newTask->Delay; // Điều chỉnh delay của task tiếp theo
            } else {
                // Nếu chèn vào cuối danh sách
                ListTasks.tail = newTask;
            }

            tmp->next = newTask;
        }
    }

    // Cập nhật số lượng task
    ListTasks.numTasks++;

    return (unsigned char)ListTasks.numTasks;
}


void SCH_Dispatch_Tasks( void ){

	// Dispatches ( runs ) the next task ( i f one i s ready )
	if(ListTasks.head->RunMe == 1) {
		(* ListTasks.head->pTask) () ; // Run the task
		ListTasks.head->RunMe = 0; // Reset / reduce RunMe fl a g
		// Periodic tasks w ill automatically run again
		// − i f thi s i s a ’one shot ’ task , remove i t from the array
		if ( ListTasks.head->Period != 0){
			SCH_Add_Task(ListTasks.head->pTask, ListTasks.head->Period, ListTasks.head->Period);
		}
		SCH_Delete_Task(0) ;

	}
	// Report system status
	//SCH_Report_Status () ;
	// The scheduler enters idle mode at thi s point
	//SCH_Go_To_Sleep() ;
}

unsigned char SCH_Delete_Task( const tByte TASK_INDEX) {
	unsigned char Return_code = 0;
	if (ListTasks.numTasks <= TASK_INDEX) {
		// No task at thi s location . . .
		//
		// Set the global error variable
		//Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
				// . . . also return an error code
				//Return_code = RETURN_ERROR;
	} else {
		//Return_code = RETURN_NORMAL;
	}
	unsigned char i ;
	sTask* tmp = ListTasks.head;
	for ( i = 0; i < TASK_INDEX; i ++) {
		tmp = tmp->next;
	}
	if(tmp == ListTasks.head && tmp == ListTasks.tail){
		ListTasks.head = NULL;
		ListTasks.tail = NULL;
	}
	else if(tmp == ListTasks.head){
		ListTasks.head = tmp->next;
		ListTasks.head->pre = NULL;
	}
	else if(tmp == ListTasks.tail){
		ListTasks.tail = tmp->pre;
		ListTasks.tail->next = NULL;
	}
	else {
		(tmp->pre)->next = tmp->next;
		(tmp->next)->pre = tmp->pre;
	}
	free(tmp);
	ListTasks.numTasks --;
	return Return_code ; // return status
}


