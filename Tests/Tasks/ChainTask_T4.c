#include <stdio.h>
#include <stdlib.h>
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"
int main() {
    return 0; //remove this line
    struct Task T1 =
    { 0,RUNNING,5,5,TASK_NON,0,0 };
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
		exit(1);
    }


	return 0;
}
