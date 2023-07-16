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
    uint8_t  test;

    TasksInit();
    StartOS(OSDEFAULTAPPMODE);

    GetTaskID(&test);
    printf("%d",test);
    
    ActivateTask(0);

    GetTaskID(&test);
    printf("%d",test);

    ActivateTask(1);

    GetTaskID(&test);
    printf("%d",test);
}