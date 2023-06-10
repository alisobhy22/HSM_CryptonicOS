#include <stdio.h>
#include <stdlib.h>
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"


int main()
{
    struct Task T1 =
    {0,0, 0,RUNNING,5,5,TASK_NON,0,0,0,0 };

    OsTasksPCB[0] = &T1;
   
    RunningTaskID = 0;

     TaskStateType ref = NULL;

    //test E_OK
    StatusType st = GetTaskState(0,&ref);

    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if (ref != RUNNING)
    {
        printf("Error Occured in E_OK EX2\n\n");
        exit(1);
    }
    printf("Test 1 Passed\n\n");
    //test E_OS_ID (Invalid Task ID)
    ref = NULL;
    st = GetTaskState(255,&ref);
    if (st != E_OS_ID)
    {
        printf("Error Occured in E_OS_ID EX1\n\n");
        exit(1);
    }
    if (ref != NULL)
    {
        printf("Error Occured in E_OS_ID EX2\n\n");
        exit(1);
    }
    printf("Test 2 Passed\n\n");
    exit(0);
}