#include "../../Headers/APIs_Headers/Events.h"
#include "../../Sources/APIs_Sources/Events.c"
#include <stdlib.h>


int main()
{
     EventMaskType EventMask[MAX_EVENTS] = {0, 1, 0, 1, 0};
    struct Task T0 = {0, 0, 0, WAITING, 3, 3, TASK_FULL, 0, 0, 1, 3, 1, NULL}; // normal extended task with reasources
    struct Task T1 = {0, 0, 1, WAITING, 4, 4, TASK_FULL, 0, 0, 1, 0, 0, NULL}; // not extended task
    struct Task T2 = {0, 0, 2, WAITING, 5, 5, TASK_FULL, 0, 0, 1, 0, 1, NULL}; // normal extended task
    struct Task IDLE = {0, 0, IDLE_TASK, SUSPENDED, 0, 0, TASK_FULL, 0, 0, 200, 0};
    
    OsTasksPCB[IDLE_TASK] = &IDLE;
    OsTasksPCB[0] = &T0;
    OsTasksPCB[1] = &T1;
    OsTasksPCB[2] = &T2;
    OS_ActivateTask(IDLE.ID);

    OS_ActivateTask(T0.ID);
    StatusType st =  WaitEvent(EventMask);

    if(st!=E_OS_RESOURCE)
    {
        printf("Error Occured in E_OS_RESOURCE EX1\n\n");
        exit(1);
    }
    if(T0.Waiting_Events!=NULL)
    {
         printf("Error Occured in setting mask EX1\n\n");
        exit(1);
    }
      if(T0.State==WAITING)
    {
         printf("Error Occured in state EX1\n\n");
        exit(1);
    }
    printf("Test 1 Passed\n\n");




    OS_ActivateTask(T1.ID);
     st =  WaitEvent(EventMask);

    if(st!=E_OS_ACCESS)
    {
        printf("Error Occured in E_OS_ACCESS EX2\n\n");
        exit(1);
    }
    if(T1.Waiting_Events!=NULL)
    {
         printf("Error Occured in setting mask EX2\n\n");
        exit(1);
    }
      if(T1.State==WAITING)
    {
         printf("Error Occured in state EX2\n\n");
        exit(1);
    }
    printf("Test 2 Passed\n\n");


     OS_ActivateTask(T2.ID);
     st =  WaitEvent(EventMask);

    if(st!=E_OK)
    {
        printf("Error Occured in E_OK EX3\n\n");
        exit(1);
    }
    if(T2.Waiting_Events!=EventMask)
    {
         printf("Error Occured in setting mask EX3\n\n");
        exit(1);
    }
      if(T2.State!=WAITING)
    {
         printf("Error Occured in state EX3\n\n");
        exit(1);
    }
    printf("Test 3 Passed\n\n");

  printf("All tests Passed\n\n");
}