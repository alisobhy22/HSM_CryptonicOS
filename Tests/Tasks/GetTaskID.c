#include <stdlib.h>
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"
#include "../../Headers/APIs_Headers/Globels.h"


int main()
{
    RunningTaskID = INVALID_TASK;
    struct Task IDLE = { 0,0,IDLE_TASK,SUSPENDED,0,0,TASK_FULL,0,0,200,0 };
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
   

    TaskType ref;

    st = GetTaskID(&ref);

    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if (ref != IDLE_TASK)
    {
        //print ref
        printf("%d",ref);
        printf("Error Occured in E_OK EX2\n\n");
        exit(1);
    }

    printf("Test 1 Passed\n\n");
    exit(0);

}