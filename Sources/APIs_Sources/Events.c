#include "../../Headers/APIs_Headers/Events.h"
#include "../../Headers/APIs_Headers/OsTasks.h"
#include "OsTasks.c"
#include "../../Headers/APIs_Headers/Globels.h"
#include "../../Headers/APIs_Headers/Libraries.h"
#include <string.h>

extern struct Task *OsTasksPCB[MAX_TASKS];
extern TaskType RunningTaskID;
extern uint8_t Queue_Size;
extern struct Ready_List Ready_Queue;
extern struct Ready_Entry Ready_Entries[MAX_TASKS];

StatusType SetEvent(TaskType TaskID, EventMaskType ActivatedEvents)
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

    OsTasksPCB[TaskID]->EventMask.Event_State = OsTasksPCB[TaskID]->EventMask.Event_State | ActivatedEvents; // set the activated events
    uint64_t condition = OsTasksPCB[TaskID]->EventMask.Configured_Events & OsTasksPCB[TaskID]->EventMask.Event_State & OsTasksPCB[TaskID]->EventMask.Event_Waiting;
    if (condition != 0) // if there is a match between configured and activated events
    {
        OsTasksPCB[TaskID]->State = READY; // set to ready state
        OS_Insert(OsTasksPCB[TaskID]);                 // insert to ready queue
        OsTasksPCB[TaskID]->EventMask.Event_Waiting = OsTasksPCB[TaskID]->EventMask.Event_Waiting & ~OsTasksPCB[TaskID]->EventMask.Event_State; 
        return E_OK;// clear the activated events
    }
    return E_OK;
}

StatusType WaitEvent(EventMaskType EventMask)
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
    if (OsTasksPCB[RunningTaskID]->EventMask.Configured_Events & EventMask != 0)
    {
        OsTasksPCB[RunningTaskID]->State = WAITING;                                                                                                                                     // set to waititng state
        OsTasksPCB[RunningTaskID]->EventMask.Event_Waiting = (OsTasksPCB[RunningTaskID]->EventMask.Configured_Events & EventMask) | OsTasksPCB[RunningTaskID]->EventMask.Event_Waiting; // set waiting events
    }
    OS_Delete(RunningTaskID); // delete from ready queue
    OS_Schedule();            // schedule next task
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

    *Event = OsTasksPCB[TaskID]->EventMask.Event_State;

    return E_OK;
}

StatusType ClearEvent(EventMaskType Mask)
{
    if (OsTasksPCB[RunningTaskID]->Extended == 0)
    {
        return E_OS_ACCESS;
    } 
    // E_OS_CALLEVEL
    OsTasksPCB[RunningTaskID]->EventMask.Event_State = OsTasksPCB[RunningTaskID]->EventMask.Event_State & ~Mask; // clear the activated events

    return E_OK;
}
