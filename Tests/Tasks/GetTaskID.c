#include <stdlib.h>
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"


int main()
{
    struct Task T1 =
    {0,0, 0,RUNNING,5,5,TASK_NON,0,0,0,0 };

    OsTasksPCB[0] = &T1;
   
    RunningTaskID = 0;

    TaskType ref;

    StatusType st = GetTaskID(&ref);

    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if (ref != 0)
    {
        printf("Error Occured in E_OK EX2\n\n");
        exit(1);
    }

    printf("Test 1 Passed\n\n");
    exit(0);

}