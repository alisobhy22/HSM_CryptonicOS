#include "../../Headers/APIs_Headers/OSExecutionControl.h"


AppModeType GetActiveApplicationMode(void)
{
  return ActiveAppMode;
}

void StartOS (AppModeType Mode)
{
  // Disable Interaputs
  // Check for Auto Starts and appmode
  
  for(;;)
  {
    
  }
}



void ShutDownOS (StatusType Error)
{
  //hooks
  for(;;)
  {
    
  }
}
