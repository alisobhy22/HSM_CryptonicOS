#include "../../Headers/APIs_Headers/Tasks.h"

struct Task* OsTasksPCB[MAX_TASKS+2];
TaskType RunningTaskID = INVALID_TASK;
uint8_t Queue_Size = 0;
struct Task* Ready_Queue[MAX_TASKS+2];

void OS_Heapify(uint8_t i);


StatusType ActivateTask(TaskType TaskID)
{
	StatusType StatusMsg = E_OK;
	if (TaskID > MAX_TASKS) //max number of active tasks
	{
		if (TaskID == INVALID_TASK)
		{
			// error msg
			StatusMsg = E_OS_ID;
			return StatusMsg;
		}
		StatusMsg = E_OS_LIMIT;
		return StatusMsg;
	}

	if ((OsTasksPCB[TaskID]->State == SUSPENDED) && (OsTasksPCB[TaskID]->Activation_Record != 0)) // if task is suspended and activationrecord not zero
	{
		OS_ActivateTask(TaskID);
		StatusMsg = E_OK;
		return StatusMsg;
	}
	else
	{
		// to be implemented
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
		if (OsTasksPCB[RunningTaskID]->Reasourses_Occupied != 0)
		{
			StatusMsg = E_OS_RESOURCE;
		}
		else
		{
			OS_TerminateTask();
		}
		// return calllevel error msg when called from ISR...

	}
	return StatusMsg;
}

StatusType ChainTask(TaskType TaskID)
{
	StatusType StatusMsg = E_OK;

	//E_OS_CALLEVEL

	if (RunningTaskID == INVALID_TASK) //  implement RunningTaskID later
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

	if (TaskID > MAX_TASKS) //max number of active tasks
	{
		if (TaskID == INVALID_TASK)
		{
			// error msg
			StatusMsg = E_OS_ID;
			return StatusMsg;
		}
		StatusMsg = E_OS_LIMIT;
		return StatusMsg;
	}
	if (OsTasksPCB[TaskID]->State == SUSPENDED) // if task is suspended
	{
		OS_ActivateTask(TaskID);
		StatusMsg = E_OK;
		return StatusMsg;
	}
	return StatusMsg;
}

StatusType Schedule(void)
{
	printf("Schedule\n");
	StatusType StatusMsg = E_OK;
	//check if running task exists
	//check if running task is preimpteable
	//check if readyqueue has priority higher than running task

	if(RunningTaskID == INVALID_TASK)
	{
		printf("1\n");
		//feth highest priority task from ready queue
		RunningTaskID = Ready_Queue[0]->ID;
		printf("1\n");
		Ready_Queue[0]->State = RUNNING;
		printf("1\n");
		// context switch?????
		StatusMsg = E_OK;
		printf("1\n");
		printf("1 DONE\n");
	}
	else
	{
		if(OsTasksPCB[RunningTaskID]->F_PREEM == TASK_FULL)
		{
			if(Ready_Queue[0]->Priority > OsTasksPCB[RunningTaskID]->Priority)
			{
				printf("2\n");
				OsTasksPCB[RunningTaskID]->State = READY;
				RunningTaskID = Ready_Queue[0]->ID;
				Ready_Queue[0]->State = RUNNING;
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
	printf("Schedule end\n");
	return StatusMsg;
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
		*TaskID = OsTasksPCB[RunningTaskID]->ID;
	}
	return StatusMsg;
	
}

StatusType GetTaskState(TaskType TaskID, TaskStateRefType State) 
{
	StatusType StatusMsg = E_OK;

	if (TaskID > MAX_TASKS)
	{
		StatusMsg = E_OS_STATE;
	}
	else
	{
		*State = OsTasksPCB[TaskID]->State; // Note: implement PCB later
	}
	return StatusMsg;
}

void OS_Heapify(uint8_t i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	uint8_t largest = i;
	if (l < Queue_Size && Ready_Queue[l]->Priority > Ready_Queue[largest]->Priority) //Removed & because we want values not addreses
		largest = l;
	if (r < Queue_Size && Ready_Queue[r]->Priority > Ready_Queue[largest]->Priority) //Removed & because we want values not addreses
		largest = r;

	if (largest != i)
	{
		struct Task* temp = Ready_Queue[largest];
		for (int st = largest; st > i; st--)
		{
			Ready_Queue[st] = Ready_Queue[st - 1];
		}
		Ready_Queue[i] = temp;
	/*	struct Task* temp = Ready_Queue[i];
		Ready_Queue[i] = Ready_Queue[largest];
		Ready_Queue[largest] = temp;
		OS_Heapify(largest);
		temp = NULL;
*/  }

}
