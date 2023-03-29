#include<Libraries.h>

#include "../../Configurations/TaskConfig.h"

#ifndef Headers_APIs_Headers_Tasks_H
#define Headers_APIs_Headers_Tasks_H

#define INVALID_TASK 0

#define RUNNING 1
#define READY 2
#define WAITING 3
#define SUSPENDED 4

typedef uint8_t TaskType;
typedef uint8_t* TaskRefType;
typedef uint8_t TaskStateType;
typedef uint8_t* TaskStateRefType;

struct Task
{
	TaskType ID;
	TaskStateType State;
	uint8_t Priority;
	uint8_t F_Preem; // flag of preemetivety 0 or 1
	uint8_t Activation_Record;
	uint8_t Reasourses_Occupied;
};

extern struct Task OsTasksPCB[MAX_TASKS]; // array of tasks

StatusType ActivateTask(TaskType TaskID); // 1
StatusType TerminateTask(void); //2 
StatusType ChainTask(TaskType TaskID);
StatusType Schedule(void);
StatusType GetTaskID(TaskRefType TaskID); // 1
StatusType GetTaskState(TaskType TaskID, TaskStateRefType State); //2
void DeclareTask(int x);



#endif
