#ifndef Headers_APIs_Headers_Defines_H
#define Headers_APIs_Headers_Defines_H


#include "stdint.h"
#include "../../Configurations/TaskConfig.h"
#include "../../Configurations/OSExecutionControlConfig.h"
#include "../../Configurations/ResourceConfig.h"

#define INVALID_TASK MAX_TASKS

#define RUNNING 1
#define READY 2
#define WAITING 3
#define SUSPENDED 4

#define TASK_NON 0
#define TASK_FULL 1

#define E_OK 0
#define E_OS_ACCESS 1
#define E_OS_CALLEVEL 2
#define E_OS_ID 3
#define E_OS_LIMIT 4
#define E_OS_NOFUNC 5
#define E_OS_RESOURCE 6
#define E_OS_STATE 7
#define E_OS_VALUE 8


#define INVALID_RESOURCE MAX_RESOURCES



#define OSDEFAULTAPPMODE 0
#define INVALID_APPMODE 255


typedef uint8_t StatusType;
typedef uint8_t TaskType;
typedef uint8_t *TaskRefType;
typedef uint8_t TaskStateType;
typedef uint8_t *TaskStateRefType;

typedef uint64_t EventMaskType;
typedef uint64_t *EventMaskRefType;

typedef uint8_t ResourceType;

typedef uint8_t AppModeType;

struct Event
{
	uint64_t Configured_Events; // 64 bit configured events
	uint64_t Event_Waiting; // 64 bit event id
	uint64_t Event_State; // 64 bit event state

};
struct Resource
{
	ResourceType Res_ID;
	uint8_t Ceiling_Priority;

	ResourceType *Linked_Resource ;
	ResourceType Resource_Property;

	TaskType Resource_Owner;
	ResourceType Prev_Resource;

};
struct Task
{
	int address; //address of the task in memory
	int current_pc; //might remove later
	TaskType ID; //id of task
	TaskStateType State; //current state of task
	uint8_t CONFIG_PRIORITY; //configured priority of task  CONST
	uint8_t Priority; //current priority of task
	uint8_t F_PREEM; // flag of preemetivety 0 or 1  CONST
	uint8_t Preeimpted; // flag wether it was preimpted or not
	uint8_t Activation_Record; // activation record of task
	uint8_t Activation_Request; // request record of task
	uint8_t Reasourses_Occupied; //reimplement later using array CONST
	// add function pointer refrence to task function

	// for events
	uint8_t Extended;			   // flag wether it is extended or basic
	//EventMaskType *Waiting_Events; // array of events that the task is waiting for
	struct Event EventMask;
	// for resoruces
	ResourceType Last_Running_Resource; // Current/Last assigned reso
	struct Resource *Needed_Resources;		// refrence to Resources needed by Task
	// BAAAD WARNING FROM HERE here 

};
struct Ready_Entry
{ // Is for an array holding all entries of the ready list
	struct Task *task;
	struct Ready_Entry *Prev;
	struct Ready_Entry *Next;
};

struct Ready_List
{ // Is for size and head/tail pointers to navigate the ready entries
	uint8_t Queue_Size;
	struct Ready_Entry *Head;
	struct Ready_Entry *Tail;
};



 #endif