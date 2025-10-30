#ifndef TASKMANAGER__FILTER_STRATEGY_H
#define TASKMANAGER__FILTER_STRATEGY_H

#include "task.h"
#include <vector>
#include <memory>

namespace task_manager {

/**
 * @brief Interface for task filtering strategies (Strategy pattern)
 * 
 * This interface defines the contract that all concrete filtering strategies
 * must implement. It enables the Strategy pattern, allowing different
 * filtering algorithms to be used interchangeably.
 * 
 * @note This demonstrates the Open/Closed Principle - new filters can be
 * added without modifying the TaskManager class.
 */
class IFilterStrategy {
public:
    virtual ~IFilterStrategy() = default;
    
    /**
     * @brief Check if a task matches the filter criteria
     * 
     * @param task The task to evaluate
     * @return true if the task matches this filter's criteria
     * @return false if the task does not match
     * 
     * @complexity Depends on concrete strategy implementation
     */
    virtual bool matches(const Task& task) const = 0;
    
    /**
     * @brief Get a description of this filter for display purposes
     * 
     * @return std::string Human-readable description of the filter
     * 
     * @complexity O(1)
     */
    virtual std::string getDescription() const = 0;
};

/**
 * @brief Filter tasks by priority level
 * 
 * Concrete strategy that matches tasks with a specific priority level.
 * Example: Filter for only HIGH priority tasks.
 */
class PriorityFilter : public IFilterStrategy {
public:
    /**
     * @brief Construct a priority filter
     * 
     * @param priority The priority level to filter by
     */
    explicit PriorityFilter(Priority priority);
    
    bool matches(const Task& task) const override;
    std::string getDescription() const override;

private:
    Priority target_priority_;  // The priority level to match
};

/**
 * @brief Filter tasks by completion status
 * 
 * Concrete strategy that matches tasks with a specific completion status.
 * Example: Filter for only INCOMPLETE tasks.
 */
class StatusFilter : public IFilterStrategy {
public:
    /**
     * @brief Construct a status filter
     * 
     * @param status The completion status to filter by
     */
    explicit StatusFilter(Status status);
    
    bool matches(const Task& task) const override;
    std::string getDescription() const override;

private:
    Status target_status_;  // The status to match
};

/**
 * @brief Filter tasks by creation date range
 * 
 * Concrete strategy that matches tasks created within a specific date range.
 * Example: Filter for tasks created this week.
 */
class DateRangeFilter : public IFilterStrategy {
public:
    /**
     * @brief Construct a date range filter
     * 
     * @param start_date Start of date range (inclusive) as string
     * @param end_date End of date range (inclusive) as string
     * 
     * @throws std::invalid_argument if start_date > end_date
     */
    DateRangeFilter(
        const std::string& start_date = "",
        const std::string& end_date = ""
    );
    
    bool matches(const Task& task) const override;
    std::string getDescription() const override;

private:
    std::string start_date_;  // Range start
    std::string end_date_;    // Range end
};

/**
 * @brief Combine multiple filters with AND logic
 * 
 * Composite strategy that matches tasks satisfying ALL contained filters.
 * This is an advanced filter that demonstrates filter composition.
 * 
 * Example: Filter for tasks that are HIGH priority AND INCOMPLETE.
 */
class CompositeAndFilter : public IFilterStrategy {
public:
    /**
     * @brief Construct an empty composite filter
     * 
     * Use addFilter() to add filters to the composition.
     */
    CompositeAndFilter();
    
    /**
     * @brief Add a filter to the AND composition
     * 
     * @param filter Shared pointer to a filter strategy
     * 
     * @note Uses shared_ptr to allow multiple compositions to share filters
     */
    void addFilter(std::shared_ptr<IFilterStrategy> filter);
    
    bool matches(const Task& task) const override;
    std::string getDescription() const override;

private:
    std::vector<std::shared_ptr<IFilterStrategy>> filters_;  // Filters to combine with AND
};

/**
 * @brief Pass-through filter that matches all tasks
 * 
 * Null object pattern implementation - useful as a default filter
 * when no filtering is desired.
 */
class AllTasksFilter : public IFilterStrategy {
public:
    AllTasksFilter() = default;
    bool matches(const Task& task) const override;
    std::string getDescription() const override;
};

}  // namespace task_manager

#endif  // TASKMANAGER__FILTER_STRATEGY_H
