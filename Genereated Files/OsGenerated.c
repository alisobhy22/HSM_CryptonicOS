#include <stdio.h>
#include "OsGenerated.h"
void TasksInit(void)
{
    
    struct Task Task1 = {0,0,0,SUSPENDED,5,5,TASK_FULL,0,0,1,0,1,NULL};
    
    struct Task Task2 = {0,0,1,SUSPENDED,4,4,TASK_FULL,0,0,2,0,1,NULL};
    

    struct Task IDLE = {0,0,IDLE_TASK,SUSPENDED,0,0,TASK_FULL,0,0,200,0,0,NULL};
    
    
    OsTasksPCB[0] = &Task1;
    
    OsTasksPCB[1] = &Task2;
    
    OsTasksPCB[IDLE_TASK] = &IDLE;
}