from jinja2 import Environment, FileSystemLoader
import json
import os

def replace_values(task):
    if task['Extended']:
        task['Extended'] = 1
    else:
        task['Extended'] = 0

    if task['Premtive']:
        task['Premtive'] = "TASK_FULL"
    else:
        task['Premtive'] = "TASK_NON"
    task["Needed_Resources"] = "&(struct Resource[]){"+task["Needed_Resources"]+"}"
    return task



# file = open('F:\AUC\Thesis\HSM\HSM_CryptonicOS\GeneratedFiles\Config.json')
file = open("./GeneratedFiles/Config.json")
data = json.load(file)
tasks = data['tasks']

res = data['resources']

tasks = [replace_values(task) for task in tasks]
##if task has extended to be true replace with 1, and if it has Premtive to be true replace with TASK_FULL, if false it will be TASK_NON
   



# Create an env object for OsConfig.c
env = Environment(loader=FileSystemLoader("."))

# Load the template file
template = env.get_template("./GeneratedFiles/template.c")
# Render the template with the desired value for 'tasks'
rendered_template = template.render(res=res , tasks=tasks)

# rendered_template = template.render()

# Write the rendered template to a new file or do something with it
with open("./GeneratedFiles/OsGenerated.h", "w") as file:
    file.write(rendered_template)





