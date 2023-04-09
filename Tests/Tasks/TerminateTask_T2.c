#include <stdio.h>
#include "Tasks.h"

int main() {

    struct Task T1 =
    { 0,RUNNING,5,5,TASK_NON,0,2 };
    

    RunningTaskID = 0;

    OsTasksPCB[0] = &T1;

    StatusType st = TerminateTask();

    printf("error_msg %d \n", st);
    printf("RunningTaskID %d \n", RunningTaskID);
    printf("state %d \n", T1.State);
    printf("pointer state %d \n", OsTasksPCB[0]->State);

    if(st != E_OS_RESOURCE)
    {
		printf("Error Occured\n\n");
		exit(EXIT_FAILURE);
    }


    
    return 0;
}