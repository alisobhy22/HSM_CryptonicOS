#include "../../GeneratedFiles/OSGenerated.h"
#include "../../GeneratedFiles/OSGenerated.c"
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Headers/APIs_Headers/OsExecutionControl.h"
#include "../../Sources/APIs_Sources/Tasks.c"
#include "../../Sources/APIs_Sources/OSExecutionControl.c"
#include "../../Headers/APIs_Headers/Globels.h"
#include "../../Headers/APIs_Headers/Resources.h"
#include "../../Sources/APIs_Sources/Resources.c"

void Task0();
void Task1();

int main()
{
    uint8_t test;
    uint8_t st;
    TasksInit();
    StartOS(OSDEFAULTAPPMODE);

    GetTaskID(&test);
    printf("%d", test);

    ActivateTask(0);

    GetTaskID(&test);
    printf("%d", test);

    ActivateTask(1);

    GetTaskID(&test);
    printf("%d", test);

    st = GetResource(0);
    printf("%d", st);

    st = GetResource(1);
    printf("%d", st);
}