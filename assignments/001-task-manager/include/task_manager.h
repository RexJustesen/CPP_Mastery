#ifndef TASKMANAGER__TASK_MANAGER_H
#define TASKMANAGER__TASK_MANAGER_H

#include "task.h"
#include "filter_strategy.h"
#include <vector>
#include <memory>
#include <string>
#include <optional>

namespace task_manager {

/**
 * @brief Manages a collection of tasks and supports filtering operations
 * 
 * TaskManager is the primary interface for task operations. It maintains
 * a collection of tasks and provides methods for adding, removing, updating,
 * and querying tasks. It uses the Strategy pattern for flexible filtering.
 * 
 * @note Follows Single Responsibility Principle - manages task collection only
 * @note Demonstrates Open/Closed Principle - new filters can be added without
 * modifying this class
 * 
 * Example usage:
 * @code
 * TaskManager manager;
 * int id = manager.addTask("Write documentation", Priority::HIGH);
 * manager.markTaskComplete(id);
 * 
 * auto high_priority_filter = std::make_shared<PriorityFilter>(Priority::HIGH);
 * auto high_tasks = manager.filterTasks(high_priority_filter);
 * @endcode
 */
class TaskManager {
public:
    /**
     * @brief Construct a new TaskManager with empty task list
     * 
     * @complexity O(1)
     */
    TaskManager();
    
    /**
     * @brief Add a new task to the manager
     * 
     * @param description Task description (must not be empty)
     * @param priority Task priority level
     * @return int The unique ID assigned to the new task
     * 
     * @throws std::invalid_argument if description is empty
     * 
     * @complexity O(1) amortized
     */
    int addTask(const std::string& description, Priority priority);
    
    /**
     * @brief Remove a task by its ID
     * 
     * @param id The ID of the task to remove
     * @return true if task was found and removed
     * @return false if task with given ID was not found
     * 
     * @complexity O(n) where n is the number of tasks
     */
    bool removeTask(int id);
    
    /**
     * @brief Get a task by its ID
     * 
     * @param id The ID of the task to retrieve
     * @return std::optional<Task> The task if found, std::nullopt otherwise
     * 
     * @complexity O(n) where n is the number of tasks
     */
    std::optional<Task> getTask(int id) const;
    
    /**
     * @brief Update an existing task's properties
     * 
     * @param id The ID of the task to update
     * @param description New description (must not be empty)
     * @param priority New priority level
     * @param status New completion status
     * @return true if task was found and updated
     * @return false if task with given ID was not found
     * 
     * @throws std::invalid_argument if description is empty
     * 
     * @complexity O(n) where n is the number of tasks
     */
    bool updateTask(int id, const std::string& description, 
                   Priority priority, Status status);
    
    /**
     * @brief Mark a task as complete
     * 
     * @param id The ID of the task to mark complete
     * @return true if task was found and marked complete
     * @return false if task with given ID was not found
     * 
     * @complexity O(n) where n is the number of tasks
     */
    bool markTaskComplete(int id);
    
    /**
     * @brief Mark a task as incomplete
     * 
     * @param id The ID of the task to mark incomplete
     * @return true if task was found and marked incomplete
     * @return false if task with given ID was not found
     * 
     * @complexity O(n) where n is the number of tasks
     */
    bool markTaskIncomplete(int id);
    
    /**
     * @brief Get all tasks in the manager
     * 
     * @return std::vector<Task> Copy of all tasks
     * 
     * @complexity O(n) where n is the number of tasks
     */
    std::vector<Task> getAllTasks() const;
    
    /**
     * @brief Filter tasks using a given strategy
     * 
     * This method demonstrates the Strategy pattern - the filtering algorithm
     * can be changed at runtime without modifying this class.
     * 
     * @param filter Shared pointer to a filter strategy
     * @return std::vector<Task> Tasks matching the filter criteria
     * 
     * @complexity O(n * f) where n is number of tasks and f is filter complexity
     * 
     * @code
     * auto filter = std::make_shared<PriorityFilter>(Priority::HIGH);
     * auto high_priority_tasks = manager.filterTasks(filter);
     * @endcode
     */
    std::vector<Task> filterTasks(std::shared_ptr<IFilterStrategy> filter) const;
    
    /**
     * @brief Get the total number of tasks
     * 
     * @return size_t The number of tasks in the manager
     * 
     * @complexity O(1)
     */
    size_t getTaskCount() const;
    
    /**
     * @brief Get the number of complete tasks
     * 
     * @return size_t The number of tasks with COMPLETE status
     * 
     * @complexity O(n) where n is the number of tasks
     */
    size_t getCompleteTaskCount() const;
    
    /**
     * @brief Get the number of incomplete tasks
     * 
     * @return size_t The number of tasks with INCOMPLETE status
     * 
     * @complexity O(n) where n is the number of tasks
     */
    size_t getIncompleteTaskCount() const;
    
    /**
     * @brief Save all tasks to a file
     * 
     * Persists the current task list to a file in a format that can be
     * loaded with loadFromFile().
     * 
     * @param filename Path to the file to write
     * 
     * @throws std::runtime_error if file cannot be opened or written
     * 
     * @complexity O(n) where n is the number of tasks
     */
    void saveToFile(const std::string& filename) const;
    
    /**
     * @brief Load tasks from a file
     * 
     * Replaces the current task list with tasks loaded from the file.
     * 
     * @param filename Path to the file to read
     * 
     * @throws std::runtime_error if file cannot be opened or read
     * @throws std::runtime_error if file format is invalid
     * 
     * @complexity O(n) where n is the number of tasks in file
     */
    void loadFromFile(const std::string& filename);
    
    /**
     * @brief Clear all tasks from the manager
     * 
     * @complexity O(n) where n is the number of tasks
     */
    void clear();

private:
    std::vector<Task> tasks_;     // Collection of all tasks
    int next_id_;                 // Counter for generating unique task IDs
    
    /**
     * @brief Find a task by ID
     * 
     * Helper method to locate a task in the collection.
     * 
     * @param id The ID to search for
     * @return Iterator to the task if found, or tasks_.end() if not found
     * 
     * @complexity O(n) where n is the number of tasks
     */
    std::vector<Task>::iterator findTaskById(int id);
    
    /**
     * @brief Find a task by ID (const version)
     * 
     * @param id The ID to search for
     * @return Const iterator to the task if found, or tasks_.end() if not found
     * 
     * @complexity O(n) where n is the number of tasks
     */
    std::vector<Task>::const_iterator findTaskById(int id) const;
};

}  // namespace task_manager

#endif  // TASKMANAGER__TASK_MANAGER_H
