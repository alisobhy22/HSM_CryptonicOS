#ifndef Headers_APIs_Headers_Events_H
#define Headers_APIs_Headers_Events_H

#include "OS.h"
StatusType SetEvent (TaskType TaskID, EventMaskType ActivatedEvents);
StatusType ClearEvent (EventMaskType Mask); //done 
StatusType GetEvent (TaskType TaskID, EventMaskRefType Event); //done
StatusType WaitEvent (EventMaskType EventMask); //done

//change from array to bits
//store state of task
//clearEvent should clear state of task
//add configured events 



#endif
