#include "task_manager.h"
#include "filter_strategy.h"

#include <iostream>
#include <memory>
#include <string>

using namespace task_manager;

/**
 * @brief Display the main menu
 */
void displayMenu() {
    std::cout << "\n=== Task Manager ===\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. Update Task\n";
    std::cout << "4. Mark Task Complete\n";
    std::cout << "5. Mark Task Incomplete\n";
    std::cout << "6. List All Tasks\n";
    std::cout << "7. Filter Tasks by Priority\n";
    std::cout << "8. Filter Tasks by Status\n";
    std::cout << "9. Save Tasks to File\n";
    std::cout << "10. Load Tasks from File\n";
    std::cout << "11. Show Statistics\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

/**
 * @brief Display a task
 */
void displayTask(const Task& task) {
    (void)task;  // Suppress unused parameter warning
    // TODO: Implement task display according to REQ-014
    //
    // What you need to do:
    // 1. Print task information in a formatted way
    // 2. Include: ID, Description, Priority, Status, Creation Date
    //
    // Example format:
    // [1] Write documentation (HIGH) [INCOMPLETE] Created: 2024-01-15
    //
    throw std::runtime_error("Not implemented: displayTask");
}

/**
 * @brief Handle adding a new task
 */
void handleAddTask(TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement add task UI according to REQ-002, REQ-014
    //
    // What you need to do:
    // 1. Prompt user for task description
    // 2. Prompt user for priority (LOW, MEDIUM, HIGH)
    // 3. Call manager.addTask()
    // 4. Display confirmation with assigned task ID
    // 5. Handle any exceptions (e.g., empty description)
    //
    throw std::runtime_error("Not implemented: handleAddTask");
}

/**
 * @brief Handle removing a task
 */
void handleRemoveTask(TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement remove task UI according to REQ-002, REQ-014
    //
    // What you need to do:
    // 1. Prompt user for task ID
    // 2. Call manager.removeTask()
    // 3. Display success or "Task not found" message
    //
    throw std::runtime_error("Not implemented: handleRemoveTask");
}

/**
 * @brief Handle updating a task
 */
void handleUpdateTask(TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement update task UI according to REQ-002, REQ-014
    //
    // What you need to do:
    // 1. Prompt user for task ID
    // 2. Display current task details
    // 3. Prompt for new description, priority, status
    // 4. Call manager.updateTask()
    // 5. Handle "Task not found" case
    //
    throw std::runtime_error("Not implemented: handleUpdateTask");
}

/**
 * @brief Handle marking a task complete
 */
void handleMarkComplete(TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement mark complete UI according to REQ-006, REQ-014
    //
    throw std::runtime_error("Not implemented: handleMarkComplete");
}

/**
 * @brief Handle marking a task incomplete
 */
void handleMarkIncomplete(TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement mark incomplete UI according to REQ-006, REQ-014
    //
    throw std::runtime_error("Not implemented: handleMarkIncomplete");
}

/**
 * @brief List all tasks
 */
void handleListAllTasks(const TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement list tasks UI according to REQ-002, REQ-014
    //
    // What you need to do:
    // 1. Get all tasks from manager
    // 2. Display each task using displayTask()
    // 3. Handle empty task list case
    //
    throw std::runtime_error("Not implemented: handleListAllTasks");
}

/**
 * @brief Handle filtering tasks by priority
 */
void handleFilterByPriority(const TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement priority filter UI according to REQ-003, REQ-014
    //
    // What you need to do:
    // 1. Prompt user for priority (LOW, MEDIUM, HIGH)
    // 2. Create PriorityFilter with selected priority
    // 3. Call manager.filterTasks()
    // 4. Display filtered tasks
    //
    // This demonstrates the Strategy pattern in action!
    //
    throw std::runtime_error("Not implemented: handleFilterByPriority");
}

/**
 * @brief Handle filtering tasks by status
 */
void handleFilterByStatus(const TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement status filter UI according to REQ-003, REQ-014
    //
    // What you need to do:
    // 1. Prompt user for status (INCOMPLETE, COMPLETE)
    // 2. Create StatusFilter with selected status
    // 3. Call manager.filterTasks()
    // 4. Display filtered tasks
    //
    throw std::runtime_error("Not implemented: handleFilterByStatus");
}

/**
 * @brief Handle saving tasks to file
 */
void handleSaveToFile(const TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement save UI according to REQ-009, REQ-014
    //
    // What you need to do:
    // 1. Prompt user for filename
    // 2. Call manager.saveToFile()
    // 3. Display success message
    // 4. Handle any exceptions
    //
    throw std::runtime_error("Not implemented: handleSaveToFile");
}

/**
 * @brief Handle loading tasks from file
 */
void handleLoadFromFile(TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement load UI according to REQ-009, REQ-014
    //
    // What you need to do:
    // 1. Prompt user for filename
    // 2. Call manager.loadFromFile()
    // 3. Display success message with number of tasks loaded
    // 4. Handle any exceptions (file not found, invalid format)
    //
    throw std::runtime_error("Not implemented: handleLoadFromFile");
}

/**
 * @brief Show task statistics
 */
void handleShowStatistics(const TaskManager& manager) {
    (void)manager;  // Suppress unused parameter warning
    // TODO: Implement statistics UI according to REQ-002, REQ-014
    //
    // What you need to do:
    // 1. Display total task count
    // 2. Display complete task count
    // 3. Display incomplete task count
    // 4. Optional: Calculate and display completion percentage
    //
    throw std::runtime_error("Not implemented: handleShowStatistics");
}

int main() {
    // TODO: Implement main menu loop according to REQ-014, REQ-015
    //
    // What you need to do:
    // 1. Create TaskManager instance
    // 2. Loop until user chooses to exit:
    //    a. Display menu
    //    b. Get user choice
    //    c. Call appropriate handler function
    // 3. Handle invalid menu choices
    // 4. Catch and display any exceptions
    //
    // Optional enhancement:
    // - Auto-save on exit
    // - Confirm before exit if unsaved changes
    //
    // Remove this stub once you implement the logic:
    throw std::runtime_error("Not implemented: main");
}
