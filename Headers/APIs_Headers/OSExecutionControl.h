#ifndef Headers_APIs_Headers_OSExecutionControl_H
#define Headers_APIs_Headers_OSExecutionControl_H


#include "OS.h"


AppModeType GetActiveApplicationMode(void);
void StartOS (AppModeType Mode); // how to pass a deafult value argument to it? OSDEFAULTAPPMODE
void ShutDownOS (StatusType Error);


#endif
