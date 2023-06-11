#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"
#include <stdlib.h>
int main()
{
    struct Task T1 =
    {0,0,0,SUSPENDED,5,5,TASK_NON,0,0,1,0 };//normal task
     struct Task T2 =
    {0,0,1,SUSPENDED,5,5,TASK_NON,0,0,5,0 }; //max activations
     struct Task T3 =
    {0,0,255,SUSPENDED,5,5,TASK_NON,0,0,0,0 }; //invalid task



    OsTasksPCB[0] = &T1;
    OsTasksPCB[1] = &T2;
    OsTasksPCB[2] = &T3;

    //test E_OK normal activate
    StatusType st = ActivateTask(T1.ID);
    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if (T1.State != READY)
    {
        printf("Error Occured in E_OK EX2\n\n");
        exit(1);
    }
    printf("Test 1 Passed\n\n");
    //test E_OS_LIMIT (TO many activations of <TaskID>)
     st = ActivateTask(T2.ID);
    if (st != E_OS_LIMIT)
    {
        printf("Error Occured in E_OS_LIMIT EX1\n\n");
        exit(1);
    }
    if (T2.State != SUSPENDED)
    {
        printf("Error Occured in E_OS_LIMIT EX2\n\n");
        exit(1);
    }
    printf("Test 2 Passed\n\n");
    //test E_OS_ID (Invalid Task ID)
     st = ActivateTask(T3.ID);
    if (st != E_OS_ID)
    {
        printf("Error Occured in E_OS_ID EX1\n\n");
        exit(1);
    }
    if (T3.State != SUSPENDED)
    {
        printf("Error Occured in E_OS_ID EX2\n\n");
        exit(1);
    }
    printf("Test 3 Passed\n\n");
    exit(0);
}
