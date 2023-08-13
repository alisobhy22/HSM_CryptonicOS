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

    return task



# file = open('F:\AUC\Thesis\HSM\HSM_CryptonicOS\GeneratedFiles\Config.json')
file = open("./Config.json")
data = json.load(file)
tasks = data['tasks']
tasks = [replace_values(task) for task in tasks]
##if task has extended to be true replace with 1, and if it has Premtive to be true replace with TASK_FULL, if false it will be TASK_NON
   



# Create an env object for OsConfig.c
env = Environment(loader=FileSystemLoader("."))

# Load the template file
template = env.get_template("./template.c")

# Render the template with the desired value for 'tasks'
rendered_template = template.render(tasks=tasks)

# Write the rendered template to a new file or do something with it
with open("./OsGenerated.c", "w") as file:
    file.write(rendered_template)





