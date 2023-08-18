#ifndef Generated
#define Generated

#include <stdio.h>
#include "../Headers/APIs_Headers/Externs.h"

TaskType RunningTaskID=INVALID_TASK;
uint8_t Queue_Size;
struct Ready_List Ready_Queue;
struct Ready_Entry Ready_Entries[MAX_TASKS];

AppModeType ActiveAppMode;

struct Resource *OsResourcesPCB[MAX_RESOURCES]={
    {% for r in res %}
    { {{r.Ceiling_Priority}},{{r.Linked_Resource}},{{r.Resource_Property}},INVALID_TASK,INVALID_RESOURCE},
    {% endfor %}
};
struct Task* OsTasksPCB[MAX_TASKS]={
    {% for task in tasks %}
   
        {0, 0, {{loop.index-1}}, SUSPENDED, {{task.Priority}}, {{task.Priority}}, {{task.Premtive}},
         0, {{task.Request}}, 0, {{task.Extended}}, {0b{{task.Events}},0 , 0}, {{task.Needed_Resources}} },
    {% endfor %}
    {% for n in range((198)-tasks|length)%}
    NULL,
    {%endfor%}
    {0, 0, IDLE_TASK, SUSPENDED, 0, 0, TASK_FULL, 0, 200, 0,0,{0,0,0},INVALID_RESOURCE}
};

#endif