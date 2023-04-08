#include "Libraries.h"

#include "TaskConfig.h"

#ifndef Headers_APIs_Headers_Tasks_H
#define Headers_APIs_Headers_Tasks_H

#define INVALID_TASK 255

#define RUNNING 1
#define READY 2
#define WAITING 3
#define SUSPENDED 4

#define TASK_NON 0
#define TASK_FULL 1


typedef uint8_t StatusType;
#define E_OK 0
#define E_OS_ACCESS 1
#define E_OS_CALLEVEL 2
#define E_OS_ID 3
#define E_OS_LIMIT 4
#define E_OS_NOFUNC 5
#define E_OS_RESOURCE 6
#define E_OS_STATE 7
#define E_OS_VALUE 8



typedef uint8_t TaskType;
typedef uint8_t* TaskRefType;
typedef uint8_t TaskStateType;
typedef uint8_t* TaskStateRefType;

struct Task
{
	TaskType ID;
	TaskStateType State;
	const uint8_t CONFIG_PRIORITY;
	uint8_t Priority;
	const uint8_t F_PREEM; // flag of preemetivety 0 or 1
	uint8_t Activation_Record;
	uint8_t Reasourses_Occupied; //reimplement later using array
};

extern struct Task *OsTasksPCB[MAX_TASKS]; // array of tasks
extern TaskType RunningTaskID;
extern struct Task* Ready_Queue[MAX_TASKS];

StatusType ActivateTask(TaskType TaskID); // 1
StatusType TerminateTask(void); //2 
StatusType ChainTask(TaskType TaskID);
StatusType Schedule(void);
StatusType GetTaskID(TaskRefType TaskID); // 1
StatusType GetTaskState(TaskType TaskID, TaskStateRefType State); //2
void OS_ActivateTask(TaskType TaskID); // 1
void OS_TerminateTask(void); //2 
void OS_Heapify(uint8_t i);
void OS_Insert(struct Task newTask);
void OS_Delete(uint8_t id);

#endif
