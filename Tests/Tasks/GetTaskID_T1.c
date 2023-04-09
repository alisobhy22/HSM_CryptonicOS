#include <stdio.h>
#include "Tasks.h"

int main() {

    struct Task T1 =
    { 0,RUNNING,5,5,TASK_NON,0,0 };

    OsTasksPCB[0] = &T1;
   
    RunningTaskID = 255;

    TaskType ref;

    StatusType st = GetTaskID(&ref);
    printf("error_msg %d \n", st);
    printf("ref ID %d \n", ref);

    if(st != E_OS_ID)
    {
		printf("Error Occured\n\n");
		exit(EXIT_FAILURE);
    }


	return 0;
}