#ifndef Headers_APIs_Headers_OsTasks_H
#define Headers_APIs_Headers_OsTasks_H

#include "Libraries.h"
#include "Globels.h"





/**
 * @brief Public system function changes a task from suspended to ready state
 *
 * This public system function takes a task ID and changes a task from suspended to ready state.
 *
 * @param[in] TaskID The ID of the Task
 */
void OS_ActivateTask(TaskType TaskID);

/**
 * @brief Public system function changes a task from running to suspended state
 *
 * This public system function makes the current running task changes from running to suspended state.
 */
void OS_TerminateTask(void);

/**
 * @brief Public system function to insert task into the scheduling data structure
 *
 * @param[in] *newTask a refrence to the new task to be inserted
 */
void OS_Insert(struct Task *newTask);
/**
 * @brief Public system function to remove a task from the scheduling data structure
 *
 * @param[in] id the id of task to be removed
 */
void OS_Delete(uint8_t id);

#endif
