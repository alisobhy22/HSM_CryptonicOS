#ifndef Headers_APIs_Headers_Globels_H
#define Headers_APIs_Headers_Globels_H



#include "..\..\Configurations\TaskConfig.h"
//Tasks Things

#define INVALID_TASK 255

#define RUNNING 1
#define READY 2
#define WAITING 3
#define SUSPENDED 4

#define TASK_NON 0
#define TASK_FULL 1




#define E_OK 0
#define E_OS_ACCESS 1
#define E_OS_CALLEVEL 2
#define E_OS_ID 3
#define E_OS_LIMIT 4
#define E_OS_NOFUNC 5
#define E_OS_RESOURCE 6
#define E_OS_STATE 7
#define E_OS_VALUE 8



typedef uint8_t StatusType;
typedef uint8_t TaskType;
typedef uint8_t* TaskRefType;
typedef uint8_t TaskStateType;
typedef uint8_t* TaskStateRefType;

extern struct Task* OsTasksPCB[MAX_TASKS+2];
extern TaskType RunningTaskID;
extern struct Task* Ready_Queue[MAX_TASKS+2];

extern uint8_t Queue_Size;


struct Task
{
	int address; //address of the task in memory
	int current_pc; //might remove later
	TaskType ID; //id of task
	TaskStateType State; //current state of task
	const uint8_t CONFIG_PRIORITY; //configured priority of task
	uint8_t Priority; //current priority of task
	const uint8_t F_PREEM; // flag of preemetivety 0 or 1
	uint8_t Preeimpted; // flag wether it was preimpted or not
	uint8_t Activation_Record; // activation record of task
	uint8_t Reasourses_Occupied; //reimplement later using array
};

//

#endif
