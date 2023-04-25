#include "Tasks.h"


struct Task T1 = { 10,0,0,SUSPENDED,5,5,TASK_NON,0,1,0 };
struct Task T2 = { 20,0,1,SUSPENDED,5,5,TASK_NON,0,1,0 };
struct Task T3 = { 30,0,2,SUSPENDED,5,5,TASK_NON,0,1,0 };
struct Task T4 = { 40,0,3,SUSPENDED,6,6,TASK_NON,0,1, 0 };
//struct Task T5 = { 50,0,4,SUSPENDED,4,4,TASK_FULL,0,1, 0 };
//struct Task T6 = { 60,0,5,SUSPENDED,5,5,TASK_NON,0,1,  0 };
//struct Task T7 = { 70,0,6,SUSPENDED,1,1,TASK_FULL,0,1, 0 };
//struct Task T8 = { 80,0,7,SUSPENDED,2,2,TASK_NON,0,1,  0 };
//struct Task T9 = { 90,0,8,SUSPENDED,3,3,TASK_FULL,0,1, 0 };
//struct Task T10 = { 100,0,9,SUSPENDED,4,4,TASK_NON,0,1,0 };


void fill_pcbtable();

void print_ready_queue();

void print_PCB_Table();


int main()
{
    //Testing Scheduler with tasks that are non preemptive with same priorities except one to check the ordering in queue is right or not 

    fill_pcbtable();



    print_PCB_Table();


    ActivateTask(0);
    Schedule();
    print_ready_queue();

    ActivateTask(1);
    Schedule();
    print_ready_queue();



    ActivateTask(2);
    Schedule();
    print_ready_queue();


    ActivateTask(3);
    Schedule();
    print_ready_queue();

    print_PCB_Table();

    TerminateTask();
    Schedule();
    print_ready_queue();


    print_PCB_Table();


   


    ///print PCB
    //print Ready queue

    return 0;
}




void fill_pcbtable()
{



    OsTasksPCB[0] = &T1;
    OsTasksPCB[1] = &T2;
    OsTasksPCB[2] = &T3;
    OsTasksPCB[3] = &T4;
    //OsTasksPCB[4] = &T5;
    //OsTasksPCB[5] = &T6;
    //OsTasksPCB[6] = &T7;
    //OsTasksPCB[7] = &T8;
    //OsTasksPCB[8] = &T9;
    //OsTasksPCB[9] = &T10;

}

void print_ready_queue()
{
    printf("Ready Queue: ");
    for (int i = 0; i < Queue_Size; i++)
    {
        printf("%d ", Ready_Queue[i]->ID);
    }
    printf("\n");
}
void print_PCB_Table()
{
    printf("PCB Table: \n");
    for (int i = 0; i < 4; i++)
    {
        printf("id: %d, state: %d \n", OsTasksPCB[i]->ID, OsTasksPCB[i]->State);
    }
}
