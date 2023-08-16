#ifndef Headers_APIs_Headers_Tasks_H
#define Headers_APIs_Headers_Tasks_H


// #include "OsTasks.h"
// #include "../../Sources/APIs_Sources/OsTasks.c"
#include "OS.h"


StatusType ActivateTask(TaskType TaskID);
StatusType TerminateTask(void); 
StatusType ChainTask(TaskType TaskID);
StatusType Schedule(void);
StatusType GetTaskID(TaskRefType TaskID);
StatusType GetTaskState(TaskType TaskID, TaskStateRefType State);


#endif
