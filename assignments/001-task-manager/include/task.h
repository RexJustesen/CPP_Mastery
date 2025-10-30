#ifndef TASKMANAGER__TASK_H
#define TASKMANAGER__TASK_H

#include <string>
#include <chrono>

namespace task_manager {

/**
 * @brief Priority levels for tasks
 */
enum class Priority {
    LOW,
    MEDIUM,
    HIGH
};

/**
 * @brief Completion status for tasks
 */
enum class Status {
    INCOMPLETE,
    COMPLETE
};

/**
 * @brief Represents a single task with description, priority, and status
 * 
 * The Task class encapsulates all data associated with a task item.
 * Each task has a unique ID, description, priority level, completion status,
 * and creation timestamp.
 * 
 * @note This class follows the Single Responsibility Principle - it only
 * manages task data, not task collection management.
 */
class Task {
public:
    /**
     * @brief Construct a new Task with given properties
     * 
     * @param id Unique identifier for the task
     * @param description Text description of the task (must not be empty)
     * @param priority Priority level (HIGH, MEDIUM, or LOW)
     * @param status Completion status (COMPLETE or INCOMPLETE)
     * 
     * @throws std::invalid_argument if description is empty
     * 
     * @complexity O(1)
     */
    Task(int id, const std::string& description, Priority priority, Status status);
    
    /**
     * @brief Get the unique identifier of this task
     * 
     * @return int The task's ID
     * 
     * @complexity O(1)
     */
    int getId() const;
    
    /**
     * @brief Get the description of this task
     * 
     * @return std::string Copy of the task's description
     * 
     * @complexity O(1)
     */
    std::string getDescription() const;
    
    /**
     * @brief Get the priority level of this task
     * 
     * @return Priority The task's priority (HIGH, MEDIUM, or LOW)
     * 
     * @complexity O(1)
     */
    Priority getPriority() const;
    
    /**
     * @brief Get the completion status of this task
     * 
     * @return Status The task's status (COMPLETE or INCOMPLETE)
     * 
     * @complexity O(1)
     */
    Status getStatus() const;
    
    /**
     * @brief Get the creation timestamp of this task
     * 
     * @return std::string The time this task was created (formatted as string)
     * 
     * @complexity O(1)
     */
    std::string getCreationDate() const;
    
    /**
     * @brief Set a new description for this task
     * 
     * @param description New description text (must not be empty)
     * 
     * @throws std::invalid_argument if description is empty
     * 
     * @complexity O(1)
     */
    void setDescription(const std::string& description);
    
    /**
     * @brief Set the priority level for this task
     * 
     * @param priority New priority level
     * 
     * @complexity O(1)
     */
    void setPriority(Priority priority);
    
    /**
     * @brief Set the completion status for this task
     * 
     * @param status New completion status
     * 
     * @complexity O(1)
     */
    void setStatus(Status status);
    
    /**
     * @brief Mark this task as complete
     * 
     * Convenience method equivalent to setStatus(Status::COMPLETE)
     * 
     * @complexity O(1)
     */
    void markComplete();
    
    /**
     * @brief Mark this task as incomplete
     * 
     * Convenience method equivalent to setStatus(Status::INCOMPLETE)
     * 
     * @complexity O(1)
     */
    void markIncomplete();
    
    /**
     * @brief Check if this task is complete
     * 
     * @return true if status is COMPLETE, false otherwise
     * 
     * @complexity O(1)
     */
    bool isComplete() const;

private:
    int id_;                                            // Unique task identifier
    std::string description_;                           // Task description text
    Priority priority_;                                 // Task priority level
    Status status_;                                     // Task completion status
    std::chrono::system_clock::time_point creation_date_;  // When task was created
};

/**
 * @brief Convert Priority enum to string representation
 * 
 * @param priority Priority value to convert
 * @return std::string String representation ("HIGH", "MEDIUM", or "LOW")
 */
std::string priorityToString(Priority priority);

/**
 * @brief Convert string to Priority enum
 * 
 * @param str String representation ("HIGH", "MEDIUM", or "LOW")
 * @return Priority Corresponding priority value
 * @throws std::invalid_argument if string is not a valid priority
 */
Priority stringToPriority(const std::string& str);

/**
 * @brief Convert Status enum to string representation
 * 
 * @param status Status value to convert
 * @return std::string String representation ("COMPLETE" or "INCOMPLETE")
 */
std::string statusToString(Status status);

/**
 * @brief Convert string to Status enum
 * 
 * @param str String representation ("COMPLETE" or "INCOMPLETE")
 * @return Status Corresponding status value
 * @throws std::invalid_argument if string is not a valid status
 */
Status stringToStatus(const std::string& str);

}  // namespace task_manager

#endif  // TASKMANAGER__TASK_H
