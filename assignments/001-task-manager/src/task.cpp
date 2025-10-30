#include "task.h"

#include <stdexcept>
#include <sstream>
#include <chrono>
#include <iomanip>

namespace task_manager {

Task::Task(int id, const std::string& description, Priority priority, Status status)
    : id_(id)
    , description_(description)
    , priority_(priority)
    , status_(status)
    , creation_date_() {
    
    // TODO: Implement Task constructor according to REQ-001
    //
    // What you need to do:
    // 1. Initialize all member variables (id, description, priority, status)
    // 2. Set creation_date_ to current timestamp
    // 3. Validate that description is not empty
    //
    // Research questions:
    // - How do you get the current date/time in C++? (Hint: std::chrono)
    // - What exception should you throw for empty description?
    // - Should you validate the id parameter?
    //
    // References:
    // - See references/resources.md for links to:
    //   * std::chrono and time handling
    //   * std::invalid_argument exception
    //   * Constructor best practices
    //
    // Remove this stub once you implement the logic:
    throw std::runtime_error("Not implemented: Task constructor");
}

int Task::getId() const {
    // TODO: Implement getter for id according to REQ-001
    //
    // Note: This is a simple getter - return the member variable.
    //
    throw std::runtime_error("Not implemented: getId");
}

std::string Task::getDescription() const {
    // TODO: Implement getter for description according to REQ-001
    //
    throw std::runtime_error("Not implemented: getDescription");
}

Priority Task::getPriority() const {
    // TODO: Implement getter for priority according to REQ-001
    //
    throw std::runtime_error("Not implemented: getPriority");
}

Status Task::getStatus() const {
    // TODO: Implement getter for status according to REQ-001
    //
    throw std::runtime_error("Not implemented: getStatus");
}

std::string Task::getCreationDate() const {
    // TODO: Implement getter for creation date according to REQ-001
    //
    // What you need to do:
    // 1. Convert creation_date_ member to a formatted string
    // 2. Use a consistent date format (e.g., "YYYY-MM-DD" or "YYYY-MM-DD HH:MM:SS")
    //
    // Research:
    // - How do you format dates in C++? (Hint: std::put_time or std::format in C++20)
    // - What's a good ISO 8601 date format?
    //
    throw std::runtime_error("Not implemented: getCreationDate");
}

void Task::setDescription(const std::string& description) {
    (void)description;  // Suppress unused parameter warning
    // TODO: Implement setter with validation according to REQ-001
    //
    // What you need to do:
    // 1. Validate that description is not empty
    // 2. Update description_ member variable
    //
    // Error handling:
    // - Throw std::invalid_argument if description is empty
    //
    throw std::runtime_error("Not implemented: setDescription");
}

void Task::setPriority(Priority priority) {
    (void)priority;  // Suppress unused parameter warning
    // TODO: Implement setter for priority according to REQ-001
    //
    // Note: Since Priority is an enum, it's already type-safe.
    // Just update the member variable.
    //
    throw std::runtime_error("Not implemented: setPriority");
}

void Task::setStatus(Status status) {
    (void)status;  // Suppress unused parameter warning
    // TODO: Implement setter for status according to REQ-001
    //
    throw std::runtime_error("Not implemented: setStatus");
}

void Task::markComplete() {
    // TODO: Implement convenience method according to REQ-006
    //
    // Hint: This should set the status to Status::COMPLETE
    // Consider: Should this use setStatus() or modify status_ directly?
    //
    throw std::runtime_error("Not implemented: markComplete");
}

void Task::markIncomplete() {
    // TODO: Implement convenience method according to REQ-006
    //
    // Hint: This should set the status to Status::INCOMPLETE
    //
    throw std::runtime_error("Not implemented: markIncomplete");
}

bool Task::isComplete() const {
    // TODO: Implement convenience method according to REQ-006
    //
    // Hint: Return true if status is Status::COMPLETE, false otherwise
    //
    throw std::runtime_error("Not implemented: isComplete");
}

// Helper functions for enum conversion

std::string priorityToString(Priority priority) {
    (void)priority;  // Suppress unused parameter warning
    // TODO: Implement Priority to string conversion according to REQ-005
    //
    // What you need to do:
    // 1. Return "LOW", "MEDIUM", or "HIGH" based on priority value
    //
    // Research:
    // - Should you use if-else or switch statement?
    // - What happens if an invalid enum value is passed?
    //
    throw std::runtime_error("Not implemented: priorityToString");
}

Priority stringToPriority(const std::string& str) {
    (void)str;  // Suppress unused parameter warning
    // TODO: Implement string to Priority conversion according to REQ-005
    //
    // What you need to do:
    // 1. Convert "LOW", "MEDIUM", "HIGH" strings to Priority enum
    // 2. Handle case-insensitive matching (optional but recommended)
    // 3. Throw exception for invalid strings
    //
    // Error handling:
    // - What should happen if str is not a valid priority?
    // - Should this be case-sensitive?
    //
    throw std::runtime_error("Not implemented: stringToPriority");
}

std::string statusToString(Status status) {
    (void)status;  // Suppress unused parameter warning
    // TODO: Implement Status to string conversion according to REQ-006
    //
    // What you need to do:
    // 1. Return "INCOMPLETE" or "COMPLETE" based on status value
    //
    throw std::runtime_error("Not implemented: statusToString");
}

Status stringToStatus(const std::string& str) {
    (void)str;  // Suppress unused parameter warning
    // TODO: Implement string to Status conversion according to REQ-006
    //
    // What you need to do:
    // 1. Convert "INCOMPLETE", "COMPLETE" strings to Status enum
    // 2. Handle case-insensitive matching (optional but recommended)
    // 3. Throw exception for invalid strings
    //
    throw std::runtime_error("Not implemented: stringToStatus");
}

}  // namespace task_manager
