#include <stdio.h>
#include <stdlib.h>
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"
int main() {

    struct Task T1 =
    { 0,0,0,RUNNING,5,5,TASK_NON,0,2 };
    

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
		exit(1);
    }


    
    return 0;
}
