#include <stdio.h>
#include <stdlib.h>
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Sources/APIs_Sources/Tasks.c"

int main(){
    struct Task T1 =
    { 0,INVALID_TASK,5,5,TASK_NON,1,0 };
    OsTasksPCB[0] = &T1;
    StatusType st = ActivateTask(T1.ID);
    printf("error_msg %d \n", st);
    printf("state %d \n", T1.State);
    printf("pointer state %d \n", OsTasksPCB[0]->State);
    printf("pointer record %d \n", OsTasksPCB[0]->Activation_Record);
    if(st != E_OS_ID)
    {
        printf("Error Occured\n\n");
        exit(1);
    }
    return 0;
}