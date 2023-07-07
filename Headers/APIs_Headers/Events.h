#ifndef Headers_APIs_Headers_Events_H
#define Headers_APIs_Headers_Events_H

#include "Libraries.h"
#include "Globels.h"

StatusType SetEvent (TaskType TaskID, EventMaskType* ActivatedEvents);
StatusType ClearEvent (EventMaskRefType Mask); //done 
StatusType GetEvent (TaskType TaskID, EventMaskRefType Event); //done
StatusType WaitEvent (EventMaskType* EventMask); //done





#endif
