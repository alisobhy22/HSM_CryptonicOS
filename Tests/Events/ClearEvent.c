// #include "../../Headers/APIs_Headers/Events.h"
#include "../../Sources/APIs_Sources/Events.c"
#include "../../Sources/APIs_Sources/OsTasks.c"
#include <stdlib.h>
#include <stdio.h>
int main()
{
    struct Event EventMask = {0b11111,0b01010,0b10101};
    uint64_t ClearEventMask = 0b10000;
    struct Task T0 = {0, 0, 0, WAITING, 5, 5, TASK_NON, 0, 0, 1, 0, 1, EventMask}; // normal extended task
    struct Task T1 = {0, 0, 1, WAITING, 5, 5, TASK_NON, 0, 0, 1, 0, 0, EventMask}; // not extended task
    struct Task IDLE = {0, 0, IDLE_TASK, SUSPENDED, 0, 0, TASK_FULL, 0, 0, 200, 0};
    
    OsTasksPCB[IDLE_TASK] = &IDLE;
    OsTasksPCB[0] = &T0;
    OsTasksPCB[1] = &T1;
    OS_ActivateTask(IDLE.ID);



    OS_ActivateTask(T0.ID);
    StatusType st = ClearEvent(ClearEventMask);
    OS_TerminateTask();
    if (st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if(T0.EventMask.Event_State!=0b00101)
    {
         printf("Error Occured in Clearing EX1\n\n");
        exit(1);
    }
      printf("Test 1 Passed\n\n");


    OS_ActivateTask(T1.ID);
    st = ClearEvent(ClearEventMask);
    OS_TerminateTask();
    if(st != E_OS_ACCESS)
    {
         printf("Error Occured in E_OS_ACCESS EX2\n\n");
        exit(1);
    }
    if(T1.EventMask.Event_State != 0b10101 )
    {
         printf("Error Occured in Clearing EX2\n\n");
        exit(1);
    }
    printf("Test 2 Passed\n\n");

  printf("All tests Passed\n\n");

}