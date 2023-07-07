#include "../../Headers/APIs_Headers/Events.h"
#include "../../Headers/APIs_Headers/OSTasks.h"
//include OSTasks.c
#include "OsTasks.c"
#include "../../Headers/APIs_Headers/Globels.h"


struct Task *OsTasksPCB[MAX_TASKS];
TaskType RunningTaskID;
uint8_t Queue_Size;
struct Ready_List Ready_Queue;
struct Ready_Entry Ready_Entries[MAX_TASKS];


StatusType SetEvent (TaskType TaskID, EventMaskType* ActivatedEvents)
{
    if (TaskID >= MAX_TASKS) // Invalid task ID
    {
        // error msg
        return E_OS_ID;
    }
    if (OsTasksPCB[TaskID]->Extended == 0)
    {
        return E_OS_ACCESS;
    }
    if (OsTasksPCB[TaskID]->State == SUSPENDED)
    {
        return E_OS_STATE;
    }

    //check if ActiavtedEvents activated any of the waiting events , for example (01010) & (00010) = 1
  
    for(int i=0;i<MAX_EVENTS;i++) //check if any of the waiting events is activated
        {
            if(OsTasksPCB[TaskID]->Waiting_Events[i]*ActivatedEvents[i]==1)
            {
                //OsTasksPCB[RunningTaskID]->Waiting_Events[i]=0; //clear the event
                OsTasksPCB[TaskID]->State = READY;
                OS_Insert(OsTasksPCB[TaskID]); //insert to ready queue
                return E_OK;
            }
        }
     
    return E_OK;



}


StatusType WaitEvent(EventMaskType *EventMask)
{
    if (OsTasksPCB[RunningTaskID]->Extended == 0)
    {
        return E_OS_ACCESS;
    }

    if (OsTasksPCB[RunningTaskID]->Reasourses_Occupied > 0)
    {
        return E_OS_RESOURCE;
    }

    // E_OS_CALLEVEL

    OsTasksPCB[RunningTaskID]->State = WAITING; //set to waititng state
    OsTasksPCB[RunningTaskID]->Waiting_Events = EventMask; //set waiting events
    OS_Delete(RunningTaskID); //delete from ready queue
    OS_Schedule(); //schedule next task
    return E_OK;
}

StatusType GetEvent(TaskType TaskID, EventMaskRefType Event)
{
    if (TaskID >= MAX_TASKS) // max number of active tasks
    {

        // error msg
        return E_OS_ID;
    }

     if (OsTasksPCB[TaskID]->Extended == 0)
    {
        return E_OS_ACCESS;
    }
    
       if (OsTasksPCB[TaskID]->State == SUSPENDED)
    {
        return E_OS_STATE;
    }
    memcpy(Event, OsTasksPCB[TaskID]->Waiting_Events, MAX_EVENTS * sizeof(uint8_t));
    return E_OK;
    
}

StatusType ClearEvent (EventMaskRefType Mask)
{
  if (OsTasksPCB[RunningTaskID]->Extended == 0)
    {
        return E_OS_ACCESS;
    }

        // E_OS_CALLEVEL

    for(int i=0;i<MAX_EVENTS;i++)
        Mask[i]=0;
    
    return E_OK;
}