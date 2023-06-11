#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"
#include <stdlib.h>


int main()
{
    struct Task T1 =
    {0,0, 0,RUNNING,5,5,TASK_NON,0,1,1,0 };
    struct Task T2 =
    {0,0, 1,SUSPENDED,5,5,TASK_NON,0,0,1,0 };
    struct Task T3 =
    {0,0, 2,SUSPENDED,5,5,TASK_NON,0,5,5,0 }; //max activations
    struct Task T4 =
    {0,0, 255,SUSPENDED,5,5,TASK_NON,0,0,1,0 }; //invalid task

    OsTasksPCB[0] = &T1;
    OsTasksPCB[1] = &T2;

    //test E_OK
    RunningTaskID = 0;
    StatusType st = ChainTask(T2.ID);
    printf("st = %d\n",st);
    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if (T1.State != SUSPENDED)
    {
        printf("Error Occured in E_OK EX2\n\n");
        exit(1);
    }
    if (T2.State != READY)
    {
        printf("Error Occured in E_OK EX3\n\n");
        exit(1);
    }
    printf("Test 1 Passed\n\n");
    //test E_OS_LIMIT (TO many activations of <TaskID>)
    RunningTaskID = 1;
    st = ChainTask(T3.ID);
    if (st != E_OS_ID)
    {
        printf("Error Occured in E_OS_ID EX1\n\n");
        exit(1);
    }
    if (T1.State != SUSPENDED)
    {
        printf("Error Occured in E_OS_ID EX2\n\n");
        exit(1);
    }
    if (T2.State != READY)
    {
        printf("Error Occured in E_OS_ID EX3\n\n");
        exit(1);
    }
    printf("Test 2 Passed\n\n");
    //test E_OS_ID (Invalid Task ID)
    RunningTaskID = 2;
    st = ChainTask(T4.ID);
    if (st != E_OS_ID)
    {
        printf("Error Occured in E_OS_ID EX1\n\n");
        exit(1);
    }
    if (T1.State != SUSPENDED)
    {
        printf("Error Occured in E_OS_ID EX2\n\n");
        exit(1);
    }
    if (T2.State != READY)
    {
        printf("Error Occured in E_OS_ID EX3\n\n");
        exit(1);
    }
    printf("Test 3 Passed\n\n");
    //test E_OS_Resource (Task has resources)
    //test E_OS_CALLEVEL (Called from ISR)

    
    exit(0);
}
