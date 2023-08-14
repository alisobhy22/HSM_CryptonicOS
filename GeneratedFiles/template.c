#include <stdio.h>
#include "OsGenerated.h"
#include "../Headers/APIs_Headers/Globels.h"
void TasksInit(void)
{
    {% for r in res %}
    struct Resource *{{r.name}} = malloc(sizeof(struct Resource));
    {{r.name}}->Ceiling_Priority = {{r.Ceiling_Priority}};
    {{r.name}}->Linked_Resource = {{r.Linked_Resource}};
    {{r.name}}->Resource_Property = {{r.Resource_Property}};
    {{r.name}}->Resource_Owner = INVALID_TASK;
    {{r.name}}->Prev_Resource = INVALID_RESOURCE;

    OsResourcesPCB[{{loop.index-1}}] = {{r.name}};
    {% endfor %}


    {% for task in tasks %}

    struct Task *{{task.name}} = malloc(sizeof(struct Task));
    {{task.name}}->address = 0;
    {{task.name}}->current_pc = 0;
    {{task.name}}->ID = {{loop.index-1}};
    {{task.name}}->State = SUSPENDED;
    {{task.name}}->CONFIG_PRIORITY = {{task.Priority}};
    {{task.name}}->Priority = {{task.Priority}};
    {{task.name}}->F_PREEM = {{task.Premtive}};
    {{task.name}}->Activation_Record = 0;
    {{task.name}}->Activation_Request = {{task.Request}};
    {{task.name}}->Reasourses_Occupied = 0;
    {{task.name}}->Extended = {{task.Extended}};
    {{task.name}}->EventMask.Configured_Events = 0b{{task.Events}};
    {{task.name}}->EventMask.Event_Waiting = 0;
    {{task.name}}->EventMask.Event_State = 0;
    {{task.name}}->Needed_Resources = {{task.Needed_Resources}};
    OsTasksPCB[{{loop.index-1}}] = {{task.name}};
    {% endfor %}

    // struct Task IDLE = {0,0,IDLE_TASK,SUSPENDED,0,0,TASK_FULL,0,0,200,0,0,NULL};
    // OsTasksPCB[IDLE_TASK] = &IDLE;
    
    struct Task *IDLE = malloc(sizeof(struct Task));
    IDLE->address = 0;
    IDLE->current_pc = 0;
    IDLE->ID = IDLE_TASK;
    IDLE->State = SUSPENDED;
    IDLE->CONFIG_PRIORITY = 0;
    IDLE->Priority = 0;
    IDLE->F_PREEM = TASK_FULL;
    IDLE->Activation_Record = 0;
    IDLE->Activation_Request = 200;
    IDLE->Reasourses_Occupied = 0;
    IDLE->Extended = 0;
    IDLE->EventMask.Configured_Events = 0;
    IDLE->EventMask.Event_Waiting = 0;
    IDLE->EventMask.Event_State = 0;
    IDLE->Needed_Resources = INVALID_RESOURCE;
    OsTasksPCB[IDLE_TASK] = &IDLE;

    RunningTaskID = INVALID_TASK;
}