// #include "../../Headers/APIs_Headers/Events.h"
#include "../../Headers/APIs_Headers/OS.h"
#include "../../Headers/APIs_Headers/Externs.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    struct Event EventMask = {0b11111,0b01010,0b00000};
    uint64_t ActivatedEvents = 0b00000;
    struct Task T0 =  {0,0,0,WAITING,5,5,TASK_NON,0,0,1,0,1,EventMask}; //normal extended task
    struct Task T1 =  {0,0,1,WAITING,5,5,TASK_NON,0,0,1,0,0,NULL};  //not extended task
    struct Task T2 =  {0,0,2,SUSPENDED,5,5,TASK_NON,0,0,1,0,1,EventMask}; //suspended task
    struct Task T3 = {0,0,MAX_TASKS,SUSPENDED,5,5,TASK_NON,0,0,0,0,0,NULL};
    struct Task T4 =  {0,0,4,WAITING,5,5,TASK_NON,0,0,1,0,1,EventMask};
    OsTasksPCB[0] = &T0;
    OsTasksPCB[1] = &T1;
    OsTasksPCB[2] = &T2;
    OsTasksPCB[3] = &T3;
    OsTasksPCB[4] = &T4;



    //set ActivatedEvents to be {0,1,0,1,0}
    ActivatedEvents = 0b01010;
    StatusType st = SetEvent(T0.ID,ActivatedEvents);
    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if (T0.State != READY)
    {
        printf("Error Occured in E_OK EX2\n\n");
        exit(1);
    }
    if(Ready_Queue.Head->task->ID != 0)
    {
        printf("Error Occured in E_OK EX3\n\n");
        exit(1);
    }
    printf("Test 1 Passed\n\n");

  
    ActivatedEvents = 0b00001;

    st = SetEvent(T4.ID,ActivatedEvents);
    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX4\n\n");
        exit(1);
    }
    if (T4.State != WAITING)
    {
        printf("Error Occured in E_OK EX5\n\n");
        exit(1);
    }

    printf("Test 2 Passed\n\n");

    st = SetEvent(T1.ID,ActivatedEvents);
    if(st != E_OS_ACCESS)
    {
        printf("Error Occured in E_OS_ID EX1\n\n");
        exit(1);
    }
    printf("Test 3 Passed\n\n");

    st = SetEvent(T2.ID,ActivatedEvents);
    if(st != E_OS_STATE)
    {
        printf("Error Occured in E_OS_STATE EX1\n\n");
        exit(1);
    }
    printf("Test 4 Passed\n\n");

    st = SetEvent(T3.ID,ActivatedEvents);
    if(st != E_OS_ID)
    {
        printf("Error Occured in E_OS_ID EX2\n\n");
        exit(1);
    }

    printf("All Tests Passed\n\n");
    





}