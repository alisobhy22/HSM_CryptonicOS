#include "../../GeneratedFiles/OSGenerated.h"
#include "../../GeneratedFiles/OSGenerated.c"
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Headers/APIs_Headers/OsExecutionControl.h"
#include "../../Sources/APIs_Sources/Tasks.c"
#include "../../Sources/APIs_Sources/OSExecutionControl.c"
#include "../../Headers/APIs_Headers/Globels.h"



void Task0();
void Task1();

int main()
{

    TasksInit();
    StartOS(OSDEFAULTAPPMODE);
    ActivateTask(0);
    Task0();
    ActivateTask(1);
    Task1();
    printf("Hello World!\n");
}



void Task0()
{
    printf("Task0\n");
    TerminateTask();
}

void Task1()
{
    printf("Task1\n");
    TerminateTask();
}