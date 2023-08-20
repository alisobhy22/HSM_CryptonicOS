 #include "../../GeneratedFiles/OSGenerated.h"
 #include "../../Sources/APIs_Sources/OsExecutionControl.c"
 #include "../../Sources/APIs_Sources/Resources.c"
  #include "../../Sources/APIs_Sources/Tasks.c"
  #include "../../Sources/APIs_Sources/OsTasks.c"
 //#include "../../Headers/APIs_Headers/OS.h"
//#include "../../Headers/APIs_Headers/OS.h"
int main()
{
    uint8_t test;
    uint8_t st;
    // TasksInit();
    StartOS(OSDEFAULTAPPMODE);

    GetTaskID(&test);
    printf("%d\n", test);

    ActivateTask(Task1);

    GetTaskID(&test);
    printf("%d\n", test);

    ActivateTask(Task2);

    GetTaskID(&test);
    printf("%d\n", test);

    st = GetResource(R1);
    printf("%d\n", st);

    st = GetResource(R2);
    printf("%d\n", st);
}