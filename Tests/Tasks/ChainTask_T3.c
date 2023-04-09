#include <stdio.h>
#include <stdlib.h>
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"
int main() {
    struct Task T1 =
    { 0,RUNNING,5,5,TASK_NON,1,1 };
    struct Task T2 =
    { 1,SUSPENDED,4,4,TASK_NON,1,1 };

    RunningTaskID = 0;

    OsTasksPCB[0] = &T1;
    OsTasksPCB[1] = &T2;

    


    StatusType st = ChainTask(256);

    printf("error_msg %d \n", st);
    printf("RunningTaskID %d \n", RunningTaskID);
    printf("state %d \n", T2.State);
    printf("pointer state %d \n", OsTasksPCB[1]->State);
    printf("pointer record %d \n", OsTasksPCB[1]->Activation_Record);

    if(st != E_OS_LIMIT)
    {
		printf("Error Occured\n\n");
		exit(1);
    }


	return 0;
}