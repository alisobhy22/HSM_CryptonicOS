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