#include <stdio.h>
#include "Tasks.h"

int main() {
    struct Task T1 =
    { 0,RUNNING,5,5,TASK_NON,1,1 };
    struct Task T2 =
    { 1,SUSPENDED,4,4,TASK_NON,1,1 };

    RunningTaskID = 0;

    OsTasksPCB[0] = &T1;
    OsTasksPCB[1] = &T2;

    


    StatusType st = ChainTask(1);

    printf("error_msg %d \n", st);
    printf("RunningTaskID %d \n", RunningTaskID);
    printf("state %d \n", T2.State);
    printf("pointer state %d \n", OsTasksPCB[1]->State);
    printf("pointer record %d \n", OsTasksPCB[1]->Activation_Record);

    if(st != E_OK)
    {
		printf("Error Occured\n\n");
		exit(EXIT_FAILURE);
    }


	return 0;
}