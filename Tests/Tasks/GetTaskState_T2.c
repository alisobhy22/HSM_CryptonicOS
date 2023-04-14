#include <stdio.h>
#include <stdlib.h>
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"
int main() {

    struct Task T1 =
    {0,0, 0,RUNNING,5,5,TASK_NON,0,0 };

    OsTasksPCB[0] = &T1;
   
    RunningTaskID = 0;

     TaskStateType ref = NULL;

    StatusType st = GetTaskState(0,&ref);
    printf("error_msg %d \n", st);
    printf("ref Status %d \n", ref);

    if(st != E_OK)
    {
		printf("Error Occured\n\n");
		exit(1);
    }


	return 0;
}
