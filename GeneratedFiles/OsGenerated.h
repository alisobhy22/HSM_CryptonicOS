#ifndef Generated
#define Generated

#include <stdio.h>
#include "../Headers/APIs_Headers/Externs.h"

TaskType RunningTaskID=INVALID_TASK;
uint8_t Queue_Size;
struct Ready_List Ready_Queue;
struct Ready_Entry Ready_Entries[MAX_TASKS];

AppModeType ActiveAppMode;

struct Resource *OsResourcesPCB[MAX_RESOURCES]={
    
    { 7,0,0,INVALID_TASK,INVALID_RESOURCE},
    
    { 5,0,0,INVALID_TASK,INVALID_RESOURCE},
    
};
struct Task* OsTasksPCB[MAX_TASKS]={
    
   
        {0, 0, 0, SUSPENDED, 2, 2, TASK_FULL,
         0, 1, 0, 1, {0b010111,0 , 0}, {&OsResourcesPCB[0],&OsResourcesPCB[1]} },
    
   
        {0, 0, 1, SUSPENDED, 4, 4, TASK_FULL,
         0, 2, 0, 1, {0b101000,0 , 0},{&OsResourcesPCB[0],&OsResourcesPCB[1]} },
    
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    NULL,
    
    {0, 0, IDLE_TASK, SUSPENDED, 0, 0, TASK_FULL, 0, 200, 0,0,{0,0,0},INVALID_RESOURCE}
};

#endif