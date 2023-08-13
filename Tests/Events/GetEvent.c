#include "../../Headers/APIs_Headers/Events.h"
#include "../../Sources/APIs_Sources/Events.c"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Testing GetEvent\n\n");
    struct Event EventMask = {0b11111,0b01010,0b01010};
    EventMaskType Event;
    struct Task T0 =  {0,0,0,READY,5,5,TASK_NON,0,0,1,0,1,EventMask}; //normal extended task
    struct Task T1 = {0,0,MAX_TASKS,SUSPENDED,5,5,TASK_NON,0,0,0,0,0,EventMask}; //invalid task
    struct Task T2 =  {0,0,2,READY,5,5,TASK_NON,0,0,1,0,0,EventMask};  //not extended task
    struct Task T3 =  {0,0,3,SUSPENDED,5,5,TASK_NON,0,0,1,0,1,EventMask}; //suspended task



    OsTasksPCB[0] = &T0;
    OsTasksPCB[1] = &T1;
    OsTasksPCB[2] = &T2;
    OsTasksPCB[3] = &T3;

    printf("Before GetEvent\n\n");
    StatusType st = GetEvent(T0.ID,&Event);
    printf("After GetEvent\n\n");
    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if(Event != 0b01010)
    {
        printf("Error Occured in Event EX1\n\n");
        exit(1);
    }
    printf("Test 1 Passed\n\n");

    st = GetEvent(T1.ID,&Event);
    if(st != E_OS_ID)
    {
        printf("Error Occured in E_OS_ID EX1\n\n");
        exit(1);
    }
    printf("Test 2 Passed\n\n");
st = GetEvent(T2.ID,&Event);
    if(st != E_OS_ACCESS)
    {
        printf("Error Occured in E_OS_ACCESS EX1\n\n");
        exit(1);
    }
    printf("Test 3 Passed\n\n");

    st = GetEvent(T3.ID,&Event);
    if(st != E_OS_STATE)
    {
        printf("Error Occured in E_OS_STATE EX1\n\n");
        exit(1);
    }
    printf("Test 4 Passed\n\n");

    printf("All Tests Passed\n\n");


}