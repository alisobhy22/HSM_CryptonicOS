#include <stdio.h>
#include <stdlib.h>
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"


int main()
{

   
    struct Task IDLE = { 0,0,IDLE_TASK,SUSPENDED,0,0,TASK_FULL,0,200,0 };
    struct Task T1 =
    {0,0, 0,SUSPENDED,5,5,TASK_NON,0,1,0 };
    OsTasksPCB[T1.ID] = &T1;
    OsTasksPCB[IDLE_TASK] = &IDLE;
    //startos
    StatusType st = ActivateTask(IDLE.ID);
    if(st != E_OK)
    {
        printf("Error Occured in START OS EX1\n\n");
        exit(1);
    }
    if(RunningTaskID != IDLE_TASK)
    {
        printf("Error Occured in START OS EX2\n\n");
        exit(1);
    }

     TaskStateType ref = NULL;

    st = ActivateTask(T1.ID);

    //test E_OK
    st = GetTaskState(T1.ID,&ref);

    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if (ref != RUNNING)
    {
        printf("%d",ref);
        printf("Error Occured in E_OK EX2\n\n");
        exit(1);
    }
    printf("Test 1 Passed\n\n");
    //test E_OS_ID (Invalid Task ID)
    ref = NULL;
    st = GetTaskState(INVALID_TASK,&ref);
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