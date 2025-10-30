#include "task_manager.h"

#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <sstream>

namespace task_manager {

TaskManager::TaskManager() 
    : tasks_()
    , next_id_(1) {
    
    // TODO: Implement TaskManager constructor according to REQ-002
    //
    // What you need to do:
    // 1. Initialize tasks_ as empty vector (already done in initializer list)
    // 2. Set next_id_ to 1 (already done in initializer list)
    //
    // Note: The initializer list already handles initialization.
    // You may remove this throw if no additional logic is needed.
    //
    throw std::runtime_error("Not implemented: TaskManager constructor");
}

int TaskManager::addTask(const std::string& description, Priority priority) {
    (void)description;  // Suppress unused parameter warning
    (void)priority;
    // TODO: Implement addTask according to REQ-002, REQ-003
    //
    // What you need to do:
    // 1. Validate that description is not empty
    // 2. Create a new Task with next_id_, description, priority, Status::INCOMPLETE
    // 3. Add the task to tasks_ vector
    // 4. Increment next_id_
    // 5. Return the task's id
    //
    // Error handling:
    // - Throw std::invalid_argument if description is empty
    //
    // Design consideration:
    // - Why do we generate IDs here rather than letting the client specify them?
    //
    throw std::runtime_error("Not implemented: addTask");
}

bool TaskManager::removeTask(int id) {
    (void)id;  // Suppress unused parameter warning
    // TODO: Implement removeTask according to REQ-002, REQ-007
    //
    // What you need to do:
    // 1. Find the task with the given id
    // 2. If found, remove it from tasks_ vector
    // 3. Return true if removed, false if not found
    //
    // Research:
    // - How do you remove an element from a std::vector?
    // - Consider using findTaskById() helper method
    // - Look up std::vector::erase() algorithm
    //
    throw std::runtime_error("Not implemented: removeTask");
}

std::optional<Task> TaskManager::getTask(int id) const {
    (void)id;  // Suppress unused parameter warning
    // TODO: Implement getTask according to REQ-002
    //
    // What you need to do:
    // 1. Find the task with the given id
    // 2. If found, return std::optional with the task
    // 3. If not found, return std::nullopt
    //
    // Research:
    // - What is std::optional and how does it work?
    // - Consider using findTaskById() helper method
    //
    throw std::runtime_error("Not implemented: getTask");
}

bool TaskManager::updateTask(int id, const std::string& description, 
                             Priority priority, Status status) {
    (void)id;  // Suppress unused parameter warnings
    (void)description;
    (void)priority;
    (void)status;
    // TODO: Implement updateTask according to REQ-002, REQ-008
    //
    // What you need to do:
    // 1. Find the task with the given id
    // 2. If found, update its description, priority, and status
    // 3. Return true if updated, false if not found
    //
    // Error handling:
    // - Validate that description is not empty
    // - Throw std::invalid_argument if description is empty
    //
    throw std::runtime_error("Not implemented: updateTask");
}

bool TaskManager::markTaskComplete(int id) {
    (void)id;  // Suppress unused parameter warning
    // TODO: Implement markTaskComplete according to REQ-006
    //
    // What you need to do:
    // 1. Find the task with the given id
    // 2. If found, call task.markComplete()
    // 3. Return true if updated, false if not found
    //
    throw std::runtime_error("Not implemented: markTaskComplete");
}

bool TaskManager::markTaskIncomplete(int id) {
    (void)id;  // Suppress unused parameter warning
    // TODO: Implement markTaskIncomplete according to REQ-006
    //
    // What you need to do:
    // 1. Find the task with the given id
    // 2. If found, call task.markIncomplete()
    // 3. Return true if updated, false if not found
    //
    throw std::runtime_error("Not implemented: markTaskIncomplete");
}

std::vector<Task> TaskManager::getAllTasks() const {
    // TODO: Implement getAllTasks according to REQ-002
    //
    // What you need to do:
    // 1. Return a copy of the tasks_ vector
    //
    // Design consideration:
    // - Why return a copy rather than a reference?
    // - What are the trade-offs of copying vs. returning const reference?
    //
    throw std::runtime_error("Not implemented: getAllTasks");
}

std::vector<Task> TaskManager::filterTasks(std::shared_ptr<IFilterStrategy> filter) const {
    (void)filter;  // Suppress unused parameter warning
    // TODO: Implement filterTasks according to REQ-003, REQ-004
    //
    // What you need to do:
    // 1. Create an empty result vector
    // 2. Iterate through all tasks
    // 3. For each task, call filter->matches(task)
    // 4. If matches returns true, add task to result vector
    // 5. Return the result vector
    //
    // Strategy pattern:
    // - This method demonstrates OCP - you don't need to know what type of
    //   filter is being used, you just call its matches() method
    // - New filter types can be added without modifying this code
    //
    // Research:
    // - How do you iterate through a std::vector?
    // - What is std::shared_ptr and why do we use it here?
    //
    throw std::runtime_error("Not implemented: filterTasks");
}

size_t TaskManager::getTaskCount() const {
    // TODO: Implement getTaskCount according to REQ-002
    //
    // Hint: Return the size of tasks_ vector
    //
    throw std::runtime_error("Not implemented: getTaskCount");
}

size_t TaskManager::getCompleteTaskCount() const {
    // TODO: Implement getCompleteTaskCount according to REQ-002, REQ-006
    //
    // What you need to do:
    // 1. Count how many tasks have Status::COMPLETE
    //
    // Research:
    // - Consider using std::count_if() algorithm
    // - Or manually iterate and count
    //
    throw std::runtime_error("Not implemented: getCompleteTaskCount");
}

size_t TaskManager::getIncompleteTaskCount() const {
    // TODO: Implement getIncompleteTaskCount according to REQ-002, REQ-006
    //
    // What you need to do:
    // 1. Count how many tasks have Status::INCOMPLETE
    //
    throw std::runtime_error("Not implemented: getIncompleteTaskCount");
}

void TaskManager::saveToFile(const std::string& filename) const {
    (void)filename;  // Suppress unused parameter warning
    // TODO: Implement saveToFile according to REQ-009, REQ-010
    //
    // What you need to do:
    // 1. Open file for writing (std::ofstream)
    // 2. Check if file opened successfully
    // 3. Write tasks in a format that can be loaded later
    // 4. Consider using a simple format like CSV or custom text format
    //
    // File format suggestion:
    // - Line 1: Number of tasks
    // - For each task: id,description,priority,status,creation_date
    //
    // Error handling:
    // - Throw std::runtime_error if file cannot be opened
    // - Include filename in error message
    //
    // Research:
    // - How do you write to files in C++? (std::ofstream)
    // - How do you handle file errors?
    // - How do you serialize enum values?
    //
    throw std::runtime_error("Not implemented: saveToFile");
}

void TaskManager::loadFromFile(const std::string& filename) {
    (void)filename;  // Suppress unused parameter warning
    // TODO: Implement loadFromFile according to REQ-009, REQ-011
    //
    // What you need to do:
    // 1. Open file for reading (std::ifstream)
    // 2. Check if file opened successfully
    // 3. Read tasks in the format used by saveToFile()
    // 4. Clear existing tasks_ vector
    // 5. Populate tasks_ with loaded tasks
    // 6. Update next_id_ to be one greater than highest loaded id
    //
    // Error handling:
    // - Throw std::runtime_error if file cannot be opened
    // - Throw std::runtime_error if file format is invalid
    // - Include filename in error message
    //
    // Research:
    // - How do you read from files in C++? (std::ifstream)
    // - How do you parse CSV or delimited text?
    // - Use stringToPriority() and stringToStatus() helpers
    //
    throw std::runtime_error("Not implemented: loadFromFile");
}

void TaskManager::clear() {
    // TODO: Implement clear according to REQ-002
    //
    // What you need to do:
    // 1. Clear the tasks_ vector
    // 2. Reset next_id_ to 1
    //
    throw std::runtime_error("Not implemented: clear");
}

// Private helper methods

std::vector<Task>::iterator TaskManager::findTaskById(int id) {
    (void)id;  // Suppress unused parameter warning
    // TODO: Implement findTaskById helper method
    //
    // What you need to do:
    // 1. Search tasks_ vector for task with matching id
    // 2. Return iterator to the task if found
    // 3. Return tasks_.end() if not found
    //
    // Research:
    // - Consider using std::find_if() algorithm
    // - Or manually iterate with a loop
    //
    throw std::runtime_error("Not implemented: findTaskById");
}

std::vector<Task>::const_iterator TaskManager::findTaskById(int id) const {
    (void)id;  // Suppress unused parameter warning
    // TODO: Implement const version of findTaskById helper method
    //
    // Note: This is almost identical to the non-const version,
    // but returns a const_iterator
    //
    throw std::runtime_error("Not implemented: findTaskById const");
}

}  // namespace task_manager
