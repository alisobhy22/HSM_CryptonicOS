#include <stdio.h>
#include "OsGenerated.h"
#include "../Headers/APIs_Headers/Globels.h"
void TasksInit(void)
{
    extern struct Task *OsTasksPCB[MAX_TASKS];
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
    Task1->Waiting_Events = NULL;
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
    Task2->Waiting_Events = NULL;
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
    IDLE->Waiting_Events = NULL;
    OsTasksPCB[IDLE_TASK] = IDLE;

    RunningTaskID = INVALID_TASK;
}