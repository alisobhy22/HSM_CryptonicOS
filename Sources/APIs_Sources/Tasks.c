#include "..\..\Headers\APIs_Headers\Headers.h"

struct Task OsTasksPCB[MAX_TASKS];
TaskType RunningTaskID;

StatusType ActivateTask(TaskType TaskID)
{
	StatusType StatusMsg = E_OK;
	if (TaskID > MAX_TASKS) //max number of active tasks
	{
		StatusMsg = E_OS_LIMIT;
		return StatusMsg;
	}

	uint8_t found = 0;
	for (int i = 0; i < MAX_TASKS;i++) 
	{
		if (OsTasksPCB[i].ID == TaskID)
		{
			found = 1;
			break;
		}
	}
	if(found == 0) // task not found
	{
		StatusMsg = E_OS_ID;
		return StatusMsg;
	}


	
	if (OsTasksPCB[TaskID-1].State == SUSPENDED) // if task is suspended
	{
		//context switch
		OsTasksPCB[TaskID - 1].State = READY;
		OsTasksPCB[TaskID - 1].Activation_Record-- ;
		StatusMsg = E_OK;
		return StatusMsg;
	}
	return StatusMsg;	
}

StatusType TerminateTask(void)
{
	// to be continued later, i.e to free reasourses
	StatusType StatusMsg = E_OK;
	if (RunningTaskID == INVALID_TASK) //  implement RunningTaskID later
	{
		StatusMsg = E_OS_ID;
	}
	else
	{
		if (OsTasksPCB[RunningTaskID - 1].Activation_Record > 0)
		{
			//Context_Switch();
			OsTasksPCB[RunningTaskID - 1].State = READY;
			// error msg?
		}
		else
		if (OsTasksPCB[RunningTaskID - 1].Reasourses_Occupied != 0)
		{
			StatusMsg = E_OS_RESOURCE;
		}
		else
		{
			//Context_Switch();
			OsTasksPCB[RunningTaskID - 1].State = SUSPENDED;
			RunningTaskID = INVALID_TASK;
		}
		// return calllevel error msg when called from ISR...

	}
	return StatusMsg;
}

StatusType ChainTask(TaskType TaskID)
{
	StatusType StatusMsg = TerminateTask();
	if(E_OK == StatusMsg)
	{
		StatusMsg = ActivateTaskID(TaskID);
		if(E_OK == StatusMsg)
		{
			return StatusMsg;
		}
	}
	return StatusMsg;
}

StatusType Schedule(void)
{

}

StatusType GetTaskID(TaskRefType TaskID)
{
	StatusType StatusMsg = E_OK;
	if (RunningTaskID == INVALID_TASK) //  implement RunningTaskID later
	{
		*TaskID = INVALID_TASK;
		StatusMsg = E_OS_ID;
	}
	else
	{
		*TaskID = OsTasksPCB[RunningTaskID - 1].TaskID;
	}
	return StatusMsg;
	
}

StatusType GetTaskState(TaskType TaskID, TaskStateRefType State) 
{
	StatusType StatusMsg = E_OK;

	if (TaskID > MAX_TASKS || TaskID < 1)
	{
		StatusMsg = E_OS_STATE;
	}
	else
	{
		*State = OsTasksPCB[TaskID - 1].State; // Note: implement PCB later
	}
	return StatusMsg;
}

void DeclareTask(int x)
{

}
