#include "OsTasks.h"

extern struct Task* OsTasksPCB[MAX_TASKS+2];
extern TaskType RunningTaskID ;
extern uint8_t Queue_Size ;
extern struct Task* Ready_Queue[MAX_TASKS+2];

void OS_ActivateTask(TaskType TaskID)
{
	OsTasksPCB[TaskID]->State = READY;
	OsTasksPCB[TaskID]->Activation_Record--;
	//OS_Insert(*OsTasksPCB[TaskID]);
	return;
}

void OS_TerminateTask(void)
{

	//Context_Switch();
	OsTasksPCB[RunningTaskID]->State = SUSPENDED;
	RunningTaskID = INVALID_TASK;
	//OS_Delete(RunningTaskID);

	// return calllevel error msg when called from ISR...
	return;
}




void OS_Insert(struct Task newTask)
{
	if (Queue_Size == 0)
	{
		Ready_Queue[0] = &newTask;
		Queue_Size++;
	}
	else
	{
		Ready_Queue[Queue_Size] = &newTask;
		Queue_Size++;
		for (int i = Queue_Size / 2 - 1; i >= 0; i--)
		{
			OS_Heapify(i);
		}
	}
}

void OS_Delete(uint8_t id)
{
	uint8_t j;
	for (j = 0; j < Queue_Size; j++)
		if (id == Ready_Queue[j]->ID)
			break;
	if (j == Queue_Size) // Added this case for if an element is not found
		return;
	struct Task* temp;
	for (int i = j; i < Queue_Size - 1; i++) // Used this method instead of replacing elements, I shifted them up. It is better to preserve order of elements.
	{
		Ready_Queue[i] = Ready_Queue[i + 1];
	}
	Queue_Size--;
	temp = NULL;
	for (int i = Queue_Size / 2 - 1; i >= 0; i--)
	{
		OS_Heapify(i);
	}
}
