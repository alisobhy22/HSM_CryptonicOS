#include "../../Headers/APIs_Headers/OSExecutionControl.h"
#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Headers/APIs_Headers/Globels.h"
AppModeType GetActiveApplicationMode(void)
{
  return ActiveAppMode;
}

void StartOS (AppModeType Mode)
{
  // Disable Interaputs
  // Check for Auto Starts and appmode

  if(Mode == OSDEFAULTAPPMODE)
  {
    ActivateTask(IDLE_TASK);
  }
}



void ShutDownOS (StatusType Error)
{
  //hooks
  for(;;)
  {
    
  }
}
