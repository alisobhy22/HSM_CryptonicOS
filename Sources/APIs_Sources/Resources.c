#include "../../Headers/APIs_Headers/Resources.h"

StatusType GetResource(ResourceType ResID)
{
    StatusType StatusMsg = E_OK;

    // validate that the reuqest is from and ISR

    if (ResID >= INVALID_RESOURCE)
    {
        StatusMsg = E_OS_ID;
    }
    else
    {
        if (OsResourcesPCB[ResID]->Resource_Owner != INVALID_TASK ||  
            OsTasksPCB[RunningTaskID]->Priority > OsResourcesPCB[ResID]->Ceiling_Priority)
        {
            StatusMsg = E_OS_ACCESS; // return later
        }
        else
        {

            
            OsTasksPCB[RunningTaskID]->Priority = OsResourcesPCB[ResID]->Ceiling_Priority;
            OsResourcesPCB[ResID]->Resource_Owner = OsTasksPCB[RunningTaskID]->ID;
            OsResourcesPCB[ResID]->Prev_Resource = OsTasksPCB[RunningTaskID]->Last_Running_Resource;
            OsTasksPCB[RunningTaskID]->Last_Running_Resource = ResID;
            OS_Schedule();
            
        }
    }

    return StatusMsg;
}

StatusType ReleaseResource(ResourceType ResID)
{
    StatusType StatusMsg = E_OK;

    // validate that the reuqest is from and ISR

    // return to ERORR E_OS_ACESS LATER
    if (ResID >= INVALID_RESOURCE)
    {
        StatusMsg = E_OS_ID;
    }
    else
    {
        if (OsResourcesPCB[ResID]->Ceiling_Priority < OsTasksPCB[RunningTaskID]->Priority)
        {
            StatusMsg = E_OS_ACCESS;
        }
        else
        {
            if (OsResourcesPCB[ResID]->Resource_Owner == INVALID_TASK || OsTasksPCB[RunningTaskID]->Last_Running_Resource != ResID)
            {
                StatusMsg = E_OS_NOFUNC;
            }
            else
            {

                OsTasksPCB[RunningTaskID]->Last_Running_Resource = OsResourcesPCB[ResID]->Prev_Resource;

                // access the previous resource priority
                if(OsResourcesPCB[ResID]->Prev_Resource != INVALID_RESOURCE)
                {
                    OsTasksPCB[RunningTaskID]->Priority = OsResourcesPCB[OsResourcesPCB[ResID]->Prev_Resource]->Ceiling_Priority;
                }
                else
                {
                    OsTasksPCB[RunningTaskID]->Priority = OsTasksPCB[RunningTaskID]->CONFIG_PRIORITY;
                }
                

                OsResourcesPCB[ResID]->Prev_Resource = INVALID_RESOURCE;

                OsResourcesPCB[ResID]->Resource_Owner = INVALID_TASK;

                OS_Schedule();
            }
        }
    }

    return StatusMsg;
}