#include "../../Headers/APIs_Headers/OsTasks.h"
extern struct Task* OsTasksPCB[MAX_TASKS+2];
extern TaskType RunningTaskID ;
extern uint8_t Queue_Size ;
extern struct Ready_List Ready_Queue;

extern struct Ready_Entry Ready_Entries[MAX_TASKS+2];

void OS_ActivateTask(TaskType TaskID)
{
	OsTasksPCB[TaskID]->State = READY;
	OsTasksPCB[TaskID]->Activation_Request++;
	OS_Insert(OsTasksPCB[TaskID]);
	return;
}

void OS_TerminateTask(void)
{

	//Context_Switch();
	OsTasksPCB[RunningTaskID]->State = SUSPENDED;
	OsTasksPCB[RunningTaskID]->Activation_Request--;
	OS_Delete(RunningTaskID);
	RunningTaskID = INVALID_TASK;
	

	// return calllevel error msg when called from ISR...
	return;
}




void OS_Insert(struct Task* newTask)
{
	Ready_Entries[newTask->ID] = (struct Ready_Entry){ newTask,NULL,NULL };
	
	if (Ready_Queue.Queue_Size == 0)
	{
		
		Ready_Queue.Head = &Ready_Entries[newTask->ID];
		Ready_Queue.Tail = Ready_Queue.Head;
		
	}
	else
	{
		struct Ready_Entry* Current = Ready_Queue.Head;
		while (Current != NULL)
		{
			if (newTask->Priority > Current->task->Priority)
			{
				if (Ready_Queue.Head == Current)
				{
					Ready_Queue.Head = &Ready_Entries[newTask->ID];
			
				}
				else
				{
					Ready_Entries[newTask->ID].Prev = Current->Prev;
					Current->Prev->Next = &Ready_Entries[newTask->ID];
				}
				Ready_Entries[newTask->ID].Next = Current;
				Current->Prev = &Ready_Entries[newTask->ID];
				break;
			}
			if (Current->Next == NULL)
			{
				Current->Next = &Ready_Entries[newTask->ID];
				Ready_Entries[newTask->ID].Prev = Current;

				Ready_Queue.Tail = &Ready_Entries[newTask->ID];
				break;
			}
			Current = Current->Next;
		}
	}
	Ready_Queue.Queue_Size++;
}


void OS_Delete(TaskType TaskID)
{
	struct Ready_Entry* Current = Ready_Queue.Head;

	while (Current != NULL)
	{
		if (Current->task->ID == TaskID)
		{
			
			if (Ready_Queue.Head == Current)
			{
				Ready_Queue.Head = Current->Next;
				Ready_Queue.Head->Prev = NULL;
			}
			else
			{
				Current->Prev->Next = Current->Next;
			}
			if (Ready_Queue.Tail == Current)
			{
				Ready_Queue.Tail = Current->Prev;
				Ready_Queue.Tail->Next = NULL;
			}
			else
			{
				Current->Next->Prev = Current->Prev;
			}
			Ready_Queue.Queue_Size--;
			break;
		}
		Current = Current->Next;
	}
}
