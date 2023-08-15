#include "../../Headers/APIs_Headers/Tasks.h"
#include "../../Headers/APIs_Headers/OsTasks.h"

extern struct Task* OsTasksPCB[MAX_TASKS];
extern TaskType RunningTaskID;
struct Ready_List Ready_Queue = {0,NULL,NULL};

extern struct Ready_Entry Ready_Entries[MAX_TASKS];



StatusType ActivateTask(TaskType TaskID)
{
	StatusType StatusMsg = E_OK;
	if (TaskID >= MAX_TASKS) //max number of active tasks
	{
		
			// error msg
			StatusMsg = E_OS_ID;
			return StatusMsg;
	}
	if ((OsTasksPCB[TaskID]->State == SUSPENDED) && (OsTasksPCB[TaskID]->Activation_Request != OsTasksPCB[TaskID]->Activation_Record)) // if task is suspended and activationrecord not max
	{
		OS_ActivateTask(TaskID);
		StatusMsg = E_OK;
		return StatusMsg;
	}
	else
	{
		StatusMsg = E_OS_LIMIT;
	}
	return StatusMsg;	
}

StatusType TerminateTask(void)
{
	// to be continued later, i.e to free reasourses
	StatusType StatusMsg = E_OK;

	
	if (OsTasksPCB[RunningTaskID]->Reasourses_Occupied != 0)
	{
		StatusMsg = E_OS_RESOURCE;
	}
	else
	{
		OS_TerminateTask();
	}
	// return calllevel error msg when called from ISR...

	return StatusMsg;
}

StatusType ChainTask(TaskType TaskID)
{
	StatusType StatusMsg = E_OK;

	//E_OS_CALLEVEL
	if (RunningTaskID >= INVALID_TASK) //  implement RunningTaskID later
	{
		StatusMsg = E_OS_ID;
		return StatusMsg;
	}
	if (OsTasksPCB[RunningTaskID]->Reasourses_Occupied != 0)
	{
		StatusMsg = E_OS_RESOURCE;
		return StatusMsg;
	}
	OS_TerminateTask();

	
	if (TaskID >= INVALID_TASK)
	{
		// error msg
		StatusMsg = E_OS_ID;
		return StatusMsg;
	}
	
	
	if (OsTasksPCB[TaskID]->State == SUSPENDED) // if task is suspended
	{
		if(OsTasksPCB[TaskID]->Activation_Request == OsTasksPCB[TaskID]->Activation_Record)
		{
			StatusMsg = E_OS_LIMIT;
			return StatusMsg;
		}
		OS_ActivateTask(TaskID);
		StatusMsg = E_OK;
		return StatusMsg;
	}
	return StatusMsg;
}

StatusType Schedule(void)
{
	
	StatusType StatusMsg = E_OK;
	//check if running task exists
	//check if running task is preimpteable
	//check if readyqueue has priority higher than running task

	if(RunningTaskID == INVALID_TASK)
	{
		
		//feth highest priority task from ready queue
		RunningTaskID = Ready_Queue.Head->task->ID;
		
		Ready_Queue.Head->task->State = RUNNING;
		
		// context switch?????
		StatusMsg = E_OK;
		
	}
	else
	{
		if(OsTasksPCB[RunningTaskID]->F_PREEM == TASK_FULL)
		{
			if(Ready_Queue.Head->task->Priority > OsTasksPCB[RunningTaskID]->Priority)
			{
				
				OsTasksPCB[RunningTaskID]->State = READY;
				RunningTaskID = Ready_Queue.Head->task->ID;
				Ready_Queue.Head->task->State = RUNNING;
				// context switch
			}
			else // running task still highest prio
			{
				// do nothing
				StatusMsg = E_OK;
			}
		}
		else //non preinmteable running task
		{
			// do nothing
			StatusMsg = E_OK;
		}

	}
	
	return StatusMsg;
}

StatusType GetTaskID(TaskRefType TaskID)
{
	StatusType StatusMsg = E_OK;

	
	if (RunningTaskID == INVALID_TASK) //  implement RunningTaskID later
	{
		*TaskID = INVALID_TASK;
	}
	else
	{
		*TaskID = OsTasksPCB[RunningTaskID]->ID;
	}
	return StatusMsg;
	
}

StatusType GetTaskState(TaskType TaskID, TaskStateRefType State) 
{
	StatusType StatusMsg = E_OK;

	if (TaskID >= MAX_TASKS)
	{
		StatusMsg = E_OS_ID;
	}
	else
	{
		*State = OsTasksPCB[TaskID]->State; // Note: implement PCB later
	}
	return StatusMsg;
}

