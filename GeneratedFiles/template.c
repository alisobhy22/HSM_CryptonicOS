#ifndef Generated
#define Generated


#include <stdio.h>
#include "../Headers/APIs_Headers/Defines.h"
#include "../Configurations/TaskConfig.h"
#include "../Configurations/ResourceConfig.h"
#include "../Configurations/OSExecutionControlConfig.h"


TaskType RunningTaskID=INVALID_TASK;
uint8_t Queue_Size;
struct Ready_List Ready_Queue;
struct Ready_Entry Ready_Entries[MAX_TASKS];
AppModeType ActiveAppMode;


{% for e in events %}
#define {{e.name}} {{e.mask}}
{% endfor %}




{% for r in resources %}
#define {{r.OSResourceName}} {{loop.index-1}}
struct Resource resource{{loop.index-1}}={
    .Res_ID = {{loop.index-1}},
    .Ceiling_Priority = {{r.OSResourceCeilingPriority}},
    .Linked_Resource = 0,
    .Resource_Property = {{r.OSResourceProperty}},
    .Resource_Owner = INVALID_TASK,
    .Prev_Resource = INVALID_RESOURCE
};
{% endfor %}


struct Resource *OsResourcesPCB[MAX_RESOURCES]={
    {% for r in resources %}
    &resource{{loop.index-1}},
    {% endfor %}
};

{% for task in tasks %}
#define {{task.OSTaskName}} {{loop.index-1}}
struct Task task{{loop.index-1}} = {
    .address = 0,
    .current_pc = 0,
    .ID = {{loop.index-1}},
    .State = SUSPENDED,
    .CONFIG_PRIORITY = {{task.OsTaskPriority}},
    .Priority = {{task.OsTaskPriority}},
    .F_PREEM = {{task.OsTaskSchedule}},
    .Preeimpted = 0,
    .Activation_Record = 0,
    .Activation_Request = {{task.OsTaskActivation}},
    .Reasourses_Occupied = 0,
    .Extended = {{task.OsTaskType}},
    .EventMask = { {{task.OsTaskEventRef}},0 , 0},
    .Needed_Resources = { {% for r in task.OsTaskResourceRef %}&resource{{loop.index-1}}{% if not loop.last %},{% endif %}{% endfor %} }
};
{% endfor %}


struct Task idle = {
    .address = 0,
    .current_pc = 0,
    .ID = IDLE_TASK,
    .State = SUSPENDED,
    .CONFIG_PRIORITY = 0,
    .Priority = 0,
    .F_PREEM = TASK_FULL,
    .Preeimpted = 0,
    .Activation_Record = 0,
    .Activation_Request = 200,
    .Reasourses_Occupied = 0,
    .Extended = 0,
    .EventMask = {0,0 , 0},
    .Needed_Resources = INVALID_RESOURCE
};

struct Task* OsTasksPCB[MAX_TASKS]={
    {% for task in tasks %}
    &task{{loop.index-1}},
    {% endfor %}
    [MAX_TASKS-1]=&idle
};


#endif