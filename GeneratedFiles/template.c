#include <stdio.h>
#include "OsGenerated.h"
#include "../Headers/APIs_Headers/Globels.h"
void TasksInit(void)
{
    {% for task in tasks %}
    struct Task {{task.name}} = {0,0,{{loop.index-1}},SUSPENDED,{{task.Priority}},{{task.Priority}},{{task.Premtive}},0,0,{{task.Request}},0,{{task.Extended}},NULL};
    {% endfor %}

    struct Task IDLE = {0,0,IDLE_TASK,SUSPENDED,0,0,TASK_FULL,0,0,200,0,0,NULL};
    
    {% for task in tasks %}
    OsTasksPCB[{{loop.index-1}}] = &{{task.name}};
    {% endfor %}
    OsTasksPCB[IDLE_TASK] = &IDLE;

    RunningTaskID = INVALID_TASK;
}