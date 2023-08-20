from jinja2 import Environment, FileSystemLoader
import json

file = open("./GeneratedFiles/Config.json")
data = json.load(file)
events_names = data['Events']

tasks = data['Tasks']

resources = data['Resources']

hooks = data['Hooks']



#takes a task and returns the event mask
def FetchTaskEventMask(task,events):
    taskeventmask = 0
    for event in events:
        if event['name'] in task['OsTaskEventRef']:
            taskeventmask = taskeventmask | event['mask']
    return taskeventmask
   


#handles events
events = []
for index,event in enumerate(events_names):
    mask = 1 << index
    event_dic = {"name":event,"mask":mask}
    events.append(event_dic)

print(events)
#handles tasks
for task in tasks:
    if task['OsTaskSchedule'] == "FULL":
        task['OsTaskSchedule'] = "TASK_FULL"
    else:
        task['OsTaskSchedule'] = "TASK_NON"
    if task['OsTaskType'] == "EXTENDED":
        task['OsTaskType'] = 1
    else:
        task['OsTaskType'] = 0
    task['OsTaskEventRef'] = FetchTaskEventMask(task,events)


        

# Create an env object for OsConfig.c
env = Environment(loader=FileSystemLoader("."))

# Load the template file
template = env.get_template("./GeneratedFiles/template.c")
# Render the template with the desired value for 'tasks'
rendered_template = template.render(events=events , tasks=tasks, resources=resources, hooks=hooks)

# rendered_template = template.render()

# Write the rendered template to a new file or do something with it
with open("./GeneratedFiles/OsGenerated.h", "w") as file:
    file.write(rendered_template)