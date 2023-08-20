#ifndef Generated
#define Generated


#include <stdio.h>
#include "../Headers/APIs_Headers/Defines.h"
#include "../Configurations/TaskConfig.h"
#include "../Configurations/ResourceConfig.h"
#include "../Configurations/OSExecutionControlConfig.h"


TaskType RunningTaskID=INVALID_TASK;
uint8_t Queue_Size;
struct Ready_List Ready_Queue;
struct Ready_Entry Ready_Entries[MAX_TASKS];
AppModeType ActiveAppMode;



#define Event1 1

#define Event2 2

#define Event3 4






#define R1 0
struct Resource resource0={
    .Res_ID = 0,
    .Ceiling_Priority = 7,
    .Linked_Resource = 0,
    .Resource_Property = 0,
    .Resource_Owner = INVALID_TASK,
    .Prev_Resource = INVALID_RESOURCE
};

#define R2 1
struct Resource resource1={
    .Res_ID = 1,
    .Ceiling_Priority = 5,
    .Linked_Resource = 0,
    .Resource_Property = 0,
    .Resource_Owner = INVALID_TASK,
    .Prev_Resource = INVALID_RESOURCE
};



struct Resource *OsResourcesPCB[MAX_RESOURCES]={
    
    &resource0,
    
    &resource1,
    
};


#define Task1 0
struct Task task0 = {
    .address = 0,
    .current_pc = 0,
    .ID = 0,
    .State = SUSPENDED,
    .CONFIG_PRIORITY = 1,
    .Priority = 1,
    .F_PREEM = TASK_FULL,
    .Preeimpted = 0,
    .Activation_Record = 0,
    .Activation_Request = 1,
    .Reasourses_Occupied = 0,
    .Extended = 1,
    .EventMask = { 3,0 , 0},
    .Needed_Resources = { &resource0,&resource1 }
};

#define Task2 1
struct Task task1 = {
    .address = 0,
    .current_pc = 0,
    .ID = 1,
    .State = SUSPENDED,
    .CONFIG_PRIORITY = 4,
    .Priority = 4,
    .F_PREEM = TASK_NON,
    .Preeimpted = 0,
    .Activation_Record = 0,
    .Activation_Request = 1,
    .Reasourses_Occupied = 0,
    .Extended = 0,
    .EventMask = { 7,0 , 0},
    .Needed_Resources = { &resource0,&resource1 }
};

#define Task3 2
struct Task task2 = {
    .address = 0,
    .current_pc = 0,
    .ID = 2,
    .State = SUSPENDED,
    .CONFIG_PRIORITY = 1,
    .Priority = 1,
    .F_PREEM = TASK_FULL,
    .Preeimpted = 0,
    .Activation_Record = 0,
    .Activation_Request = 1,
    .Reasourses_Occupied = 0,
    .Extended = 1,
    .EventMask = { 6,0 , 0},
    .Needed_Resources = { &resource0,&resource1 }
};



struct Task idle = {
    .address = 0,
    .current_pc = 0,
    .ID = IDLE_TASK,
    .State = SUSPENDED,
    .CONFIG_PRIORITY = 0,
    .Priority = 0,
    .F_PREEM = TASK_FULL,
    .Preeimpted = 0,
    .Activation_Record = 0,
    .Activation_Request = 200,
    .Reasourses_Occupied = 0,
    .Extended = 0,
    .EventMask = {0,0 , 0},
    .Needed_Resources = INVALID_RESOURCE
};

struct Task* OsTasksPCB[MAX_TASKS]={
    
    &task0,
    
    &task1,
    
    &task2,
    
    [MAX_TASKS-1]=&idle
};


#endif