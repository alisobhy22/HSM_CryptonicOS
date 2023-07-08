#include "../../Headers/APIs_Headers/Resources.h"
#include "../../Sources/APIs_Sources/Resources.c"
#include <stdlib.h>


int main()
{
    printf("Error Occured in E_OK EX4\n\n");
    // EventMaskType EventMask[MAX_EVENTS] = {0,1,0,1,0};
    // EventMaskType ActivatedEvents[MAX_EVENTS] = {0,0,0,0,0};

    struct Resource R0 = {0, 8, NULL, RESOURCE_STANDARD, INVALID_TASK, INVALID_RESOURCE};
    struct Resource R1 = {1, 8, NULL, RESOURCE_STANDARD, INVALID_TASK, INVALID_RESOURCE};
    struct Resource R2 = {MAX_RESOURCES, 5, NULL, RESOURCE_STANDARD, INVALID_TASK, INVALID_RESOURCE};
    struct Resource R3 = {3, 4, NULL, RESOURCE_STANDARD, INVALID_TASK, INVALID_RESOURCE};
    
    OsResourcesPCB[0] = &R0;
    OsResourcesPCB[1] = &R1;
    OsResourcesPCB[2] = &R2;
    OsResourcesPCB[3] = &R3;

    
    struct Task T0 =  {0,0,0,WAITING,5,5,TASK_NON,0,0,1,2,1,NULL, INVALID_RESOURCE, &(struct Resource[]){R0,R1} }; 
    struct Task T1 =  {0,0,1,WAITING,5,5,TASK_NON,0,0,1,1,0,NULL, INVALID_RESOURCE, &(struct Resource[]){R2} };  
    struct Task T2 =  {0,0,2,SUSPENDED,5,5,TASK_NON,0,0,1,4,1,NULL, INVALID_RESOURCE, &(struct Resource[]){R0,R1,R2,R3} }; 
    struct Task T3 = {0,0,MAX_TASKS,SUSPENDED,5,5,TASK_NON,0,0,0,4,0,NULL, INVALID_RESOURCE, &(struct Resource[]){R0,R1,R2,R3} };
    struct Task T4 =  {0,0,4,WAITING,5,5,TASK_NON,0,0,1,4,1,NULL, INVALID_RESOURCE, &(struct Resource[]){R0,R1,R2,R3}};

    OsTasksPCB[0] = &T0;
    OsTasksPCB[1] = &T1;
    OsTasksPCB[2] = &T2;
    OsTasksPCB[3] = &T3;
    OsTasksPCB[4] = &T4;


    StatusType st;
    st = Activate_Task(T0.ID);
    // st = Activate_Task(T2.ID);
    // st = Activate_Task(T3.ID);
    // st = Activate_Task(T4.ID);

    st = GetResource(R0.Res_ID);
    if(st != E_OK)
    {
        printf("Error Occured in E_OK EX1\n\n");
        exit(1);
    }
    if(T0.Priority != 8)
    {
        printf("Error Occured in E_OK EX2\n\n");
        exit(1);
    }
    if(T0.Last_Running_Resource != R0.Res_ID)
    {
        printf("Error Occured in E_OK EX3\n\n");
        exit(1);
    }
    if(R0.Resource_Owner != T0.ID)
    {
        printf("Error Occured in E_OK EX4\n\n");
        exit(1);
    }
    if(R0.Prev_Resource != INVALID_RESOURCE)
    {
        printf("Error Occured in E_OK EX4\n\n");
        exit(1);
    }
    st = GetResource(R1.Res_ID);
    if(R1.Resource_Owner != T0.ID)
    {
        printf("Error Occured in E_OK EX8\n\n");
        exit(1);
    }
    if(R1.Prev_Resource != R0.Res_ID)
    {
        printf("Error Occured in E_OK EX9\n\n");
        exit(1);
    }
    printf("Test 1 Passed\n\n");
    
    st = Activate_Task(T2.ID);
    st = GetResource(R0.Res_ID);
    if(st != E_OS_ID)
    {
        printf("Error Occured in E_OS_ID EX1\n\n");
        exit(1);
    }



    // printf("All Tests Passed\n\n");
    

}