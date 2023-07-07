#include "../../Headers/APIs_Headers/Resources.h"




StatusType GetResource(ResourceType ResID)
{
    StatusType StatusMsg = E_OK;

    // validate that the reuqest is from and ISR

    if(ResID >= INVALID_RESOURCE)
    {
        StatusMsg = E_OS_ID;
    }
    else
    {
        if(OsResourcePCB[ResID].Resource_Owner != INVALID_TASK)
        {
             StatusMsg = E_OS_ACCESS; // return later
        }
        else
        {
            

            if (OsResourcePCB[ResID].Ceiling_Priority >= OsTasksPCB[RunningTaskID].Priority)
            {
                OsTasksPCB[RunningTaskID].Priority = OsResourcePCB[ResID].Ceiling_Priority;
                OsResourcePCB[ResID].Resource_Owner =  OsTasksPCB[RunningTaskID].TaskID;
                OsResourcePCB[ResID].Prev_Resource =  OsTasksPCB[RunningTaskID].Last_Running_Resource;
                OsTasksPCB[RunningTaskID].Last_Running_Resource = ResID;
                OS_Schedule();
                
            }
            
        }

        
    }


    return StatusMsg;
}

StatusType ReleaseResource(ResourceType ResID)
{
    StatusType StatusMsg = E_OK;

    // validate that the reuqest is from and ISR

    // return to ERORR E_OS_ACESS LATER
    if(ResID >= INVALID_RESOURCE)
    {
        StatusMsg = E_OS_ID;
    }
    else
    {
        if(OsResourcePCB[ResID].Resource_Owner == INVALID_TASK || OsTasksPCB[RunningTaskID].Last_Running_Resource != ResID)
        {
             StatusMsg = E_OS_NOFUNC; 
        }
        else
        {
            
            OsTasksPCB[RunningTaskID].Last_Running_Resource = OsResourcePCB[ResID].Prev_Resource;

            //access the previous resource priority
            OsTasksPCB[RunningTaskID].Priority = OsResourcePCB[OsResourcePCB[ResID].Prev_Resource].Resource_Priority; 
            
            OsResourcePCB[ResID].Prev_Resource = INVALID_RESOURCE;

            OsResourcePCB[ResID].Resource_Owner =  INVALID_TASK;

            OS_Schedule();
        }

    }
    
    return StatusMsg;
}