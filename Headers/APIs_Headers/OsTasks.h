#ifndef Headers_APIs_Headers_OsTasks_H
#define Headers_APIs_Headers_OsTasks_H
#include "Libraries.h"
#include "Globels.h"






void OS_ActivateTask(TaskType TaskID);
void OS_TerminateTask(void);
void OS_Schedule(void);
void OS_Insert(struct Task *newTask);
void OS_Delete(TaskType TaskID);

#endif
