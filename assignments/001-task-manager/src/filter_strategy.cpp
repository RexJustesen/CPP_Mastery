#include "filter_strategy.h"

#include <stdexcept>
#include <algorithm>

namespace task_manager {

// PriorityFilter implementation

PriorityFilter::PriorityFilter(Priority priority) 
    : target_priority_(priority) {
    
    // TODO: Implement PriorityFilter constructor according to REQ-003, REQ-005
    //
    // Note: The initializer list already sets target_priority_.
    // You may remove this throw if no additional logic is needed.
    //
    throw std::runtime_error("Not implemented: PriorityFilter constructor");
}

bool PriorityFilter::matches(const Task& task) const {
    (void)task;  // Suppress unused parameter warning
    // TODO: Implement matches according to REQ-003, REQ-005
    //
    // What you need to do:
    // 1. Compare task's priority with target_priority_
    // 2. Return true if they match, false otherwise
    //
    // Hint: Use task.getPriority()
    //
    throw std::runtime_error("Not implemented: PriorityFilter::matches");
}

std::string PriorityFilter::getDescription() const {
    // TODO: Implement getDescription according to REQ-003
    //
    // What you need to do:
    // 1. Return a human-readable description of this filter
    // 2. Example: "Priority: HIGH"
    //
    // Hint: Use priorityToString() helper function
    //
    throw std::runtime_error("Not implemented: PriorityFilter::getDescription");
}

// StatusFilter implementation

StatusFilter::StatusFilter(Status status) 
    : target_status_(status) {
    
    // TODO: Implement StatusFilter constructor according to REQ-003, REQ-006
    //
    throw std::runtime_error("Not implemented: StatusFilter constructor");
}

bool StatusFilter::matches(const Task& task) const {
    (void)task;  // Suppress unused parameter warning
    // TODO: Implement matches according to REQ-003, REQ-006
    //
    // What you need to do:
    // 1. Compare task's status with target_status_
    // 2. Return true if they match, false otherwise
    //
    throw std::runtime_error("Not implemented: StatusFilter::matches");
}

std::string StatusFilter::getDescription() const {
    // TODO: Implement getDescription according to REQ-003
    //
    // Example: "Status: COMPLETE"
    //
    throw std::runtime_error("Not implemented: StatusFilter::getDescription");
}

// DateRangeFilter implementation

DateRangeFilter::DateRangeFilter(const std::string& start_date, const std::string& end_date)
    : start_date_(start_date)
    , end_date_(end_date) {
    
    // TODO: Implement DateRangeFilter constructor according to REQ-003, REQ-012
    //
    // What you need to do:
    // 1. Store start_date and end_date (already done in initializer list)
    // 2. Optional: Validate that date strings are in correct format
    // 3. Optional: Validate that start_date <= end_date
    //
    throw std::runtime_error("Not implemented: DateRangeFilter constructor");
}

bool DateRangeFilter::matches(const Task& task) const {
    (void)task;  // Suppress unused parameter warning
    // TODO: Implement matches according to REQ-003, REQ-012
    //
    // What you need to do:
    // 1. Get task's creation date as string
    // 2. Compare it with start_date_ and end_date_
    // 3. Return true if creation_date >= start_date AND creation_date <= end_date
    //
    // Research:
    // - How do you compare date strings? (Hint: If using ISO format like
    //   "YYYY-MM-DD", string comparison works correctly)
    // - What if dates are in different formats?
    //
    throw std::runtime_error("Not implemented: DateRangeFilter::matches");
}

std::string DateRangeFilter::getDescription() const {
    // TODO: Implement getDescription according to REQ-003
    //
    // Example: "Date range: 2024-01-01 to 2024-12-31"
    //
    throw std::runtime_error("Not implemented: DateRangeFilter::getDescription");
}

// CompositeAndFilter implementation

CompositeAndFilter::CompositeAndFilter() 
    : filters_() {
    
    // TODO: Implement CompositeAndFilter constructor according to REQ-003, REQ-013
    //
    throw std::runtime_error("Not implemented: CompositeAndFilter constructor");
}

void CompositeAndFilter::addFilter(std::shared_ptr<IFilterStrategy> filter) {
    (void)filter;  // Suppress unused parameter warning
    // TODO: Implement addFilter according to REQ-003, REQ-013
    //
    // What you need to do:
    // 1. Add the filter to filters_ vector
    //
    // Design consideration:
    // - This allows building complex filters dynamically
    // - Example: Filter for HIGH priority AND INCOMPLETE status
    //
    throw std::runtime_error("Not implemented: CompositeAndFilter::addFilter");
}

bool CompositeAndFilter::matches(const Task& task) const {
    (void)task;  // Suppress unused parameter warning
    // TODO: Implement matches according to REQ-003, REQ-013
    //
    // What you need to do:
    // 1. Return true if ALL filters in filters_ match the task
    // 2. Return false if ANY filter does not match
    // 3. Edge case: If no filters added, what should this return?
    //    (Suggestion: return true - empty filter matches everything)
    //
    // Research:
    // - Consider using std::all_of() algorithm
    // - Or manually iterate through filters_
    //
    throw std::runtime_error("Not implemented: CompositeAndFilter::matches");
}

std::string CompositeAndFilter::getDescription() const {
    // TODO: Implement getDescription according to REQ-003
    //
    // What you need to do:
    // 1. Build a description combining all sub-filter descriptions
    // 2. Example: "Priority: HIGH AND Status: INCOMPLETE"
    //
    // Hint: Iterate through filters_ and call getDescription() on each
    //
    throw std::runtime_error("Not implemented: CompositeAndFilter::getDescription");
}

// AllTasksFilter implementation (Null Object pattern)

// AllTasksFilter uses default constructor (nothing to initialize)

bool AllTasksFilter::matches(const Task& task) const {
    (void)task;  // Suppress unused parameter warning
    // TODO: Implement matches according to REQ-003
    //
    // What you need to do:
    // 1. Always return true (this filter matches everything)
    //
    // Design pattern:
    // - This is the Null Object pattern
    // - Provides a "do nothing" implementation
    // - Eliminates need for null pointer checks
    //
    throw std::runtime_error("Not implemented: AllTasksFilter::matches");
}

std::string AllTasksFilter::getDescription() const {
    // TODO: Implement getDescription according to REQ-003
    //
    // Example: "All tasks"
    //
    throw std::runtime_error("Not implemented: AllTasksFilter::getDescription");
}

}  // namespace task_manager
