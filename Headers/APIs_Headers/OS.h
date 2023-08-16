#ifndef OS_H
#define OS_H


#include "Globels.h"


// OS APIs
AppModeType GetActiveApplicationMode(void);
void StartOS (AppModeType Mode); // how to pass a deafult value argument to it? OSDEFAULTAPPMODE
void ShutDownOS (StatusType Error);

// Task APIs
StatusType ActivateTask(TaskType TaskID);
StatusType TerminateTask(void); 
StatusType ChainTask(TaskType TaskID);
StatusType Schedule(void);
StatusType GetTaskID(TaskRefType TaskID);
StatusType GetTaskState(TaskType TaskID, TaskStateRefType State);


// Resource APIs
StatusType GetResource(ResourceType ResID); 
StatusType ReleaseResource(ResourceType ResID); 

// Event APIs
StatusType SetEvent (TaskType TaskID, EventMaskType ActivatedEvents);
StatusType ClearEvent (EventMaskType Mask); //done 
StatusType GetEvent (TaskType TaskID, EventMaskRefType Event); //done
StatusType WaitEvent (EventMaskType EventMask); //done


#endif