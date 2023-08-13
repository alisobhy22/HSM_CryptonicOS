#include <stdio.h>
#include "OsGenerated.h"
#include "../Headers/APIs_Headers/Globels.h"
void TasksInit(void)
{
    
    struct Resource *R0 = malloc(sizeof(struct Resource));
    R0->Ceiling_Priority = 7;
    R0->Linked_Resource = 0;
    R0->Resource_Property = 0;
    R0->Resource_Owner = INVALID_TASK;
    R0->Prev_Resource = INVALID_RESOURCE;

    OsResourcesPCB[0] = &R0;
    
    struct Resource *R1 = malloc(sizeof(struct Resource));
    R1->Ceiling_Priority = 5;
    R1->Linked_Resource = 0;
    R1->Resource_Property = 0;
    R1->Resource_Owner = INVALID_TASK;
    R1->Prev_Resource = INVALID_RESOURCE;

    OsResourcesPCB[1] = &R1;
    


    

    struct Task *Task1 = malloc(sizeof(struct Task));
    Task1->address = 0;
    Task1->current_pc = 0;
    Task1->ID = 0;
    Task1->State = SUSPENDED;
    Task1->CONFIG_PRIORITY = 2;
    Task1->Priority = 2;
    Task1->F_PREEM = TASK_FULL;
    Task1->Activation_Record = 0;
    Task1->Activation_Request = 1;
    Task1->Reasourses_Occupied = 0;
    Task1->Extended = 1;
    Task1->EventMask.Configured_Events = 0b010111;
    Task1->EventMask.Event_Waiting = 0;
    Task1->EventMask.Event_State = 0;
    Task1->Needed_Resources = &(struct Resource[]){R0,R1};
    OsTasksPCB[0] = Task1;
    

    struct Task *Task2 = malloc(sizeof(struct Task));
    Task2->address = 0;
    Task2->current_pc = 0;
    Task2->ID = 1;
    Task2->State = SUSPENDED;
    Task2->CONFIG_PRIORITY = 4;
    Task2->Priority = 4;
    Task2->F_PREEM = TASK_FULL;
    Task2->Activation_Record = 0;
    Task2->Activation_Request = 2;
    Task2->Reasourses_Occupied = 0;
    Task2->Extended = 1;
    Task2->EventMask.Configured_Events = 0b101000;
    Task2->EventMask.Event_Waiting = 0;
    Task2->EventMask.Event_State = 0;
    Task2->Needed_Resources = &(struct Resource[]){R0,R1};
    OsTasksPCB[1] = Task2;
    

    // struct Task IDLE = {0,0,IDLE_TASK,SUSPENDED,0,0,TASK_FULL,0,0,200,0,0,NULL};
    // OsTasksPCB[IDLE_TASK] = &IDLE;
    
    struct Task *IDLE = malloc(sizeof(struct Task));
    IDLE->address = 0;
    IDLE->current_pc = 0;
    IDLE->ID = IDLE_TASK;
    IDLE->State = SUSPENDED;
    IDLE->CONFIG_PRIORITY = 0;
    IDLE->Priority = 0;
    IDLE->F_PREEM = TASK_FULL;
    IDLE->Activation_Record = 0;
    IDLE->Activation_Request = 200;
    IDLE->Reasourses_Occupied = 0;
    IDLE->Extended = 0;
    IDLE->EventMask.Configured_Events = 0;
    IDLE->EventMask.Event_Waiting = 0;
    IDLE->EventMask.Event_State = 0;
    IDLE->Needed_Resources = INVALID_RESOURCE;
    OsTasksPCB[IDLE_TASK] = &IDLE;

    RunningTaskID = INVALID_TASK;
}