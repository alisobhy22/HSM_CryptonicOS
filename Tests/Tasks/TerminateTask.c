#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"
#include <stdlib.h>
int main()
{
    struct Task T1 =
    {0,0, 0,RUNNING,5,5,TASK_NON,0,0,0 };
    

    RunningTaskID = 0;

    OsTasksPCB[0] = &T1;
    //test E_OK

    StatusType st = TerminateTask();

    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if (RunningTaskID != INVALID_TASK)
    {
        printf("Error Occured in E_OK EX2\n\n");
        exit(1);
    }
    if (T1.State != SUSPENDED)
    {
        printf("Error Occured in E_OK EX3\n\n");
        exit(1);
    }
    printf("Test 1 Passed\n\n");
    //test E_OS_RESOURCE
    //E_OS_CALLEVEL
    exit(0);
}