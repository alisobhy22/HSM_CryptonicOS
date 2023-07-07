#include "../../Headers/APIs_Headers/Events.h"
#include "../../Sources/APIs_Sources/Events.c"
#include <stdlib.h>
int main()
{
    EventMaskType EventMask[MAX_EVENTS] = {0, 1, 0, 1, 0};
    EventMaskType ActivatedEvents[MAX_EVENTS] = {0, 1, 0, 0, 0};
    struct Task T0 = {0, 0, 0, WAITING, 5, 5, TASK_NON, 0, 0, 1, 0, 1, EventMask}; // normal extended task
    struct Task T1 = {0, 0, 1, WAITING, 5, 5, TASK_NON, 0, 0, 1, 0, 0, EventMask}; // not extended task
    struct Task IDLE = {0, 0, IDLE_TASK, SUSPENDED, 0, 0, TASK_FULL, 0, 0, 200, 0};
    
    OsTasksPCB[IDLE_TASK] = &IDLE;
    OsTasksPCB[0] = &T0;
    OsTasksPCB[1] = &T1;
    OS_ActivateTask(IDLE.ID);



    OS_ActivateTask(T0.ID);
    StatusType st = ClearEvent(ActivatedEvents);
    OS_TerminateTask();
    if (st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if(T0.Waiting_Events!=ActivatedEvents)
    {
         printf("Error Occured in Clearing EX1\n\n");
        exit(1);
    }
      printf("Test 1 Passed\n\n");


    OS_ActivateTask(T1.ID);
    st = ClearEvent(ActivatedEvents);
    OS_TerminateTask();
    if(st != E_OS_ACCESS)
    {
         printf("Error Occured in E_OS_ACCESS EX2\n\n");
        exit(1);
    }
    if(T1.Waiting_Events !=EventMask )
    {
         printf("Error Occured in Clearing EX2\n\n");
        exit(1);
    }
    printf("Test 2 Passed\n\n");

  printf("All tests Passed\n\n");

}