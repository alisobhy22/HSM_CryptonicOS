#include "../../GeneratedFiles/OSGenerated.c"
#include "../../Sources/APIs_Sources/OsExecutionControl.c"
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
    printf("%d\n", test);

    ActivateTask(0);

    GetTaskID(&test);
    printf("%d\n", test);

    ActivateTask(1);

    GetTaskID(&test);
    printf("%d\n", test);

    st = GetResource(1);
    printf("%d\n", st);

    st = GetResource(0);
    printf("%d\n", st);
}