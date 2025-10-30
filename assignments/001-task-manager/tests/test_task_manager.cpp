#include <gtest/gtest.h>
#include "task.h"
#include "task_manager.h"
#include "filter_strategy.h"
#include <memory>
#include <fstream>
#include <filesystem>

using namespace task_manager;

// ============================================================================
// Test Fixture for Task Tests
// ============================================================================

class TaskTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create sample tasks for testing
        task1 = Task(1, "Write documentation", Priority::HIGH, Status::INCOMPLETE);
        task2 = Task(2, "Fix bug in parser", Priority::MEDIUM, Status::COMPLETE);
        task3 = Task(3, "Review pull request", Priority::LOW, Status::INCOMPLETE);
    }
    
    Task task1;
    Task task2;
    Task task3;
};

// ============================================================================
// SECTION 1: Basic Functionality Tests - Task Class
// ============================================================================

TEST_F(TaskTest, TaskConstructionSetsProperties) {
    // REQ-001: Task class with id, description, priority, status, creation_date
    EXPECT_EQ(task1.getId(), 1);
    EXPECT_EQ(task1.getDescription(), "Write documentation");
    EXPECT_EQ(task1.getPriority(), Priority::HIGH);
    EXPECT_EQ(task1.getStatus(), Status::INCOMPLETE);
    EXPECT_FALSE(task1.getCreationDate().empty());
}

TEST_F(TaskTest, SetDescriptionUpdatesDescription) {
    // REQ-001: Task has setters for mutable properties
    task1.setDescription("Updated description");
    EXPECT_EQ(task1.getDescription(), "Updated description");
}

TEST_F(TaskTest, SetPriorityUpdatesPriority) {
    task1.setPriority(Priority::LOW);
    EXPECT_EQ(task1.getPriority(), Priority::LOW);
}

TEST_F(TaskTest, SetStatusUpdatesStatus) {
    task1.setStatus(Status::COMPLETE);
    EXPECT_EQ(task1.getStatus(), Status::COMPLETE);
}

TEST_F(TaskTest, MarkCompleteChangesStatus) {
    // REQ-006: Task has markComplete() method
    task1.markComplete();
    EXPECT_EQ(task1.getStatus(), Status::COMPLETE);
    EXPECT_TRUE(task1.isComplete());
}

TEST_F(TaskTest, MarkIncompleteChangesStatus) {
    // REQ-006: Task has markIncomplete() method
    task2.markIncomplete();
    EXPECT_EQ(task2.getStatus(), Status::INCOMPLETE);
    EXPECT_FALSE(task2.isComplete());
}

TEST_F(TaskTest, IsCompleteReturnsCorrectValue) {
    EXPECT_FALSE(task1.isComplete());
    EXPECT_TRUE(task2.isComplete());
}

// ============================================================================
// Test Fixture for TaskManager Tests
// ============================================================================

class TaskManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        manager = TaskManager();
    }
    
    TaskManager manager;
};

// ============================================================================
// SECTION 2: Basic Functionality Tests - TaskManager Class
// ============================================================================

TEST_F(TaskManagerTest, NewManagerIsEmpty) {
    // REQ-002: TaskManager manages collection of tasks
    EXPECT_EQ(manager.getTaskCount(), 0);
}

TEST_F(TaskManagerTest, AddTaskIncreasesCount) {
    // REQ-002: TaskManager can add tasks
    int id = manager.addTask("Test task", Priority::MEDIUM);
    EXPECT_EQ(manager.getTaskCount(), 1);
    EXPECT_GT(id, 0);
}

TEST_F(TaskManagerTest, AddTaskReturnsUniqueIds) {
    int id1 = manager.addTask("Task 1", Priority::HIGH);
    int id2 = manager.addTask("Task 2", Priority::LOW);
    EXPECT_NE(id1, id2);
}

TEST_F(TaskManagerTest, GetTaskReturnsCorrectTask) {
    // REQ-002: TaskManager can retrieve tasks
    int id = manager.addTask("Find me", Priority::HIGH);
    auto task_opt = manager.getTask(id);
    
    ASSERT_TRUE(task_opt.has_value());
    EXPECT_EQ(task_opt->getId(), id);
    EXPECT_EQ(task_opt->getDescription(), "Find me");
    EXPECT_EQ(task_opt->getPriority(), Priority::HIGH);
}

TEST_F(TaskManagerTest, GetTaskReturnsNulloptForInvalidId) {
    auto task_opt = manager.getTask(999);
    EXPECT_FALSE(task_opt.has_value());
}

TEST_F(TaskManagerTest, RemoveTaskDecreasesCount) {
    // REQ-002, REQ-007: TaskManager can remove tasks
    int id = manager.addTask("Remove me", Priority::LOW);
    EXPECT_EQ(manager.getTaskCount(), 1);
    
    bool removed = manager.removeTask(id);
    EXPECT_TRUE(removed);
    EXPECT_EQ(manager.getTaskCount(), 0);
}

TEST_F(TaskManagerTest, RemoveTaskReturnsFalseForInvalidId) {
    bool removed = manager.removeTask(999);
    EXPECT_FALSE(removed);
}

TEST_F(TaskManagerTest, UpdateTaskModifiesProperties) {
    // REQ-002, REQ-008: TaskManager can update tasks
    int id = manager.addTask("Original", Priority::LOW);
    
    bool updated = manager.updateTask(id, "Modified", Priority::HIGH, Status::COMPLETE);
    EXPECT_TRUE(updated);
    
    auto task_opt = manager.getTask(id);
    ASSERT_TRUE(task_opt.has_value());
    EXPECT_EQ(task_opt->getDescription(), "Modified");
    EXPECT_EQ(task_opt->getPriority(), Priority::HIGH);
    EXPECT_EQ(task_opt->getStatus(), Status::COMPLETE);
}

TEST_F(TaskManagerTest, UpdateTaskReturnsFalseForInvalidId) {
    bool updated = manager.updateTask(999, "Invalid", Priority::LOW, Status::INCOMPLETE);
    EXPECT_FALSE(updated);
}

TEST_F(TaskManagerTest, MarkTaskCompleteWorks) {
    // REQ-006: Mark tasks complete
    int id = manager.addTask("Complete me", Priority::MEDIUM);
    bool marked = manager.markTaskComplete(id);
    
    EXPECT_TRUE(marked);
    auto task_opt = manager.getTask(id);
    ASSERT_TRUE(task_opt.has_value());
    EXPECT_TRUE(task_opt->isComplete());
}

TEST_F(TaskManagerTest, MarkTaskIncompleteWorks) {
    int id = manager.addTask("Incomplete me", Priority::MEDIUM);
    manager.markTaskComplete(id);
    bool marked = manager.markTaskIncomplete(id);
    
    EXPECT_TRUE(marked);
    auto task_opt = manager.getTask(id);
    ASSERT_TRUE(task_opt.has_value());
    EXPECT_FALSE(task_opt->isComplete());
}

TEST_F(TaskManagerTest, GetAllTasksReturnsAllTasks) {
    manager.addTask("Task 1", Priority::HIGH);
    manager.addTask("Task 2", Priority::MEDIUM);
    manager.addTask("Task 3", Priority::LOW);
    
    auto tasks = manager.getAllTasks();
    EXPECT_EQ(tasks.size(), 3);
}

TEST_F(TaskManagerTest, GetCompleteTaskCountIsAccurate) {
    // REQ-002: Count complete tasks
    int id1 = manager.addTask("Task 1", Priority::HIGH);
    int id2 = manager.addTask("Task 2", Priority::MEDIUM);
    manager.addTask("Task 3", Priority::LOW);
    
    manager.markTaskComplete(id1);
    manager.markTaskComplete(id2);
    
    EXPECT_EQ(manager.getCompleteTaskCount(), 2);
    EXPECT_EQ(manager.getIncompleteTaskCount(), 1);
}

TEST_F(TaskManagerTest, ClearRemovesAllTasks) {
    manager.addTask("Task 1", Priority::HIGH);
    manager.addTask("Task 2", Priority::MEDIUM);
    
    manager.clear();
    EXPECT_EQ(manager.getTaskCount(), 0);
}

// ============================================================================
// SECTION 3: Edge Cases Tests
// ============================================================================

TEST_F(TaskTest, EmptyDescriptionThrowsException) {
    // REQ-001: Task description must not be empty
    EXPECT_THROW(
        Task(1, "", Priority::HIGH, Status::INCOMPLETE),
        std::invalid_argument
    );
}

TEST_F(TaskTest, SetEmptyDescriptionThrowsException) {
    EXPECT_THROW(
        task1.setDescription(""),
        std::invalid_argument
    );
}

TEST_F(TaskManagerTest, AddTaskWithEmptyDescriptionThrows) {
    EXPECT_THROW(
        manager.addTask("", Priority::MEDIUM),
        std::invalid_argument
    );
}

TEST_F(TaskManagerTest, UpdateTaskWithEmptyDescriptionThrows) {
    int id = manager.addTask("Valid", Priority::LOW);
    EXPECT_THROW(
        manager.updateTask(id, "", Priority::HIGH, Status::COMPLETE),
        std::invalid_argument
    );
}

TEST_F(TaskManagerTest, RemoveFromEmptyListReturnsFalse) {
    EXPECT_FALSE(manager.removeTask(1));
}

TEST_F(TaskManagerTest, GetAllTasksOnEmptyManagerReturnsEmptyVector) {
    auto tasks = manager.getAllTasks();
    EXPECT_TRUE(tasks.empty());
}

TEST_F(TaskManagerTest, VeryLongDescriptionIsHandled) {
    // Edge case: Test with very long description (1000+ characters)
    std::string long_desc(1000, 'x');
    int id = manager.addTask(long_desc, Priority::LOW);
    
    auto task_opt = manager.getTask(id);
    ASSERT_TRUE(task_opt.has_value());
    EXPECT_EQ(task_opt->getDescription(), long_desc);
}

// ============================================================================
// SECTION 4: Strategy Pattern Tests
// ============================================================================

TEST_F(TaskManagerTest, FilterByPriorityReturnsMatchingTasks) {
    // REQ-003, REQ-005: Filter tasks by priority using Strategy pattern
    manager.addTask("High priority 1", Priority::HIGH);
    manager.addTask("Medium priority", Priority::MEDIUM);
    manager.addTask("High priority 2", Priority::HIGH);
    manager.addTask("Low priority", Priority::LOW);
    
    auto filter = std::make_shared<PriorityFilter>(Priority::HIGH);
    auto filtered = manager.filterTasks(filter);
    
    EXPECT_EQ(filtered.size(), 2);
    for (const auto& task : filtered) {
        EXPECT_EQ(task.getPriority(), Priority::HIGH);
    }
}

TEST_F(TaskManagerTest, FilterByStatusReturnsMatchingTasks) {
    // REQ-003, REQ-006: Filter tasks by status
    int id1 = manager.addTask("Task 1", Priority::HIGH);
    manager.addTask("Task 2", Priority::MEDIUM);
    int id3 = manager.addTask("Task 3", Priority::LOW);
    
    manager.markTaskComplete(id1);
    manager.markTaskComplete(id3);
    
    auto filter = std::make_shared<StatusFilter>(Status::COMPLETE);
    auto filtered = manager.filterTasks(filter);
    
    EXPECT_EQ(filtered.size(), 2);
    for (const auto& task : filtered) {
        EXPECT_TRUE(task.isComplete());
    }
}

TEST_F(TaskManagerTest, CompositeFilterCombinesMultipleFilters) {
    // REQ-003, REQ-013: Composite filter with AND logic
    manager.addTask("High incomplete", Priority::HIGH);
    int id2 = manager.addTask("High complete", Priority::HIGH);
    manager.addTask("Medium incomplete", Priority::MEDIUM);
    
    manager.markTaskComplete(id2);
    
    auto composite = std::make_shared<CompositeAndFilter>();
    composite->addFilter(std::make_shared<PriorityFilter>(Priority::HIGH));
    composite->addFilter(std::make_shared<StatusFilter>(Status::COMPLETE));
    
    auto filtered = manager.filterTasks(composite);
    
    EXPECT_EQ(filtered.size(), 1);
    EXPECT_EQ(filtered[0].getDescription(), "High complete");
}

TEST_F(TaskManagerTest, AllTasksFilterReturnsAllTasks) {
    // REQ-003: Null object pattern - AllTasksFilter
    manager.addTask("Task 1", Priority::HIGH);
    manager.addTask("Task 2", Priority::MEDIUM);
    manager.addTask("Task 3", Priority::LOW);
    
    auto filter = std::make_shared<AllTasksFilter>();
    auto filtered = manager.filterTasks(filter);
    
    EXPECT_EQ(filtered.size(), 3);
}

TEST_F(TaskManagerTest, StrategyIsSwappableAtRuntime) {
    // REQ-004: Demonstrate OCP - TaskManager doesn't change when using different filters
    manager.addTask("High task", Priority::HIGH);
    manager.addTask("Low task", Priority::LOW);
    
    // Use priority filter
    auto priority_filter = std::make_shared<PriorityFilter>(Priority::HIGH);
    auto high_tasks = manager.filterTasks(priority_filter);
    EXPECT_EQ(high_tasks.size(), 1);
    
    // Swap to all tasks filter - same manager, different strategy
    auto all_filter = std::make_shared<AllTasksFilter>();
    auto all_tasks = manager.filterTasks(all_filter);
    EXPECT_EQ(all_tasks.size(), 2);
    
    // Manager code never changed - OCP demonstrated!
}

// ============================================================================
// SECTION 5: Persistence Tests
// ============================================================================

class PersistenceTest : public ::testing::Test {
protected:
    void SetUp() override {
        manager = TaskManager();
        test_file = "test_tasks.txt";
    }
    
    void TearDown() override {
        // Clean up test file
        std::filesystem::remove(test_file);
    }
    
    TaskManager manager;
    std::string test_file;
};

TEST_F(PersistenceTest, SaveToFileCreatesFile) {
    // REQ-009, REQ-010: Save tasks to file
    manager.addTask("Task 1", Priority::HIGH);
    manager.addTask("Task 2", Priority::LOW);
    
    EXPECT_NO_THROW(manager.saveToFile(test_file));
    EXPECT_TRUE(std::filesystem::exists(test_file));
}

TEST_F(PersistenceTest, LoadFromFileRestoresTasks) {
    // REQ-009, REQ-011: Load tasks from file
    int id1 = manager.addTask("Task 1", Priority::HIGH);
    int id2 = manager.addTask("Task 2", Priority::MEDIUM);
    manager.markTaskComplete(id1);
    
    manager.saveToFile(test_file);
    
    TaskManager manager2;
    EXPECT_NO_THROW(manager2.loadFromFile(test_file));
    
    EXPECT_EQ(manager2.getTaskCount(), 2);
    auto task1 = manager2.getTask(id1);
    ASSERT_TRUE(task1.has_value());
    EXPECT_EQ(task1->getDescription(), "Task 1");
    EXPECT_EQ(task1->getPriority(), Priority::HIGH);
    EXPECT_TRUE(task1->isComplete());
}

TEST_F(PersistenceTest, RoundTripPreservesData) {
    // REQ-009: Full round-trip test
    manager.addTask("Important task", Priority::HIGH);
    manager.addTask("Normal task", Priority::MEDIUM);
    manager.addTask("Minor task", Priority::LOW);
    
    manager.saveToFile(test_file);
    
    TaskManager loaded_manager;
    loaded_manager.loadFromFile(test_file);
    
    EXPECT_EQ(loaded_manager.getTaskCount(), manager.getTaskCount());
    
    auto original_tasks = manager.getAllTasks();
    auto loaded_tasks = loaded_manager.getAllTasks();
    
    EXPECT_EQ(original_tasks.size(), loaded_tasks.size());
    for (size_t i = 0; i < original_tasks.size(); ++i) {
        EXPECT_EQ(original_tasks[i].getId(), loaded_tasks[i].getId());
        EXPECT_EQ(original_tasks[i].getDescription(), loaded_tasks[i].getDescription());
        EXPECT_EQ(original_tasks[i].getPriority(), loaded_tasks[i].getPriority());
        EXPECT_EQ(original_tasks[i].getStatus(), loaded_tasks[i].getStatus());
    }
}

TEST_F(PersistenceTest, LoadNonExistentFileThrows) {
    // REQ-009: Error handling for missing file
    EXPECT_THROW(
        manager.loadFromFile("nonexistent.txt"),
        std::runtime_error
    );
}

TEST_F(PersistenceTest, SaveToInvalidPathThrows) {
    // REQ-009: Error handling for invalid path
    manager.addTask("Task", Priority::HIGH);
    EXPECT_THROW(
        manager.saveToFile("/invalid/path/file.txt"),
        std::runtime_error
    );
}

// ============================================================================
// SECTION 6: Enum Helper Function Tests
// ============================================================================

TEST(EnumHelperTest, PriorityToStringWorks) {
    // REQ-005: Priority enum conversion
    EXPECT_EQ(priorityToString(Priority::LOW), "LOW");
    EXPECT_EQ(priorityToString(Priority::MEDIUM), "MEDIUM");
    EXPECT_EQ(priorityToString(Priority::HIGH), "HIGH");
}

TEST(EnumHelperTest, StringToPriorityWorks) {
    EXPECT_EQ(stringToPriority("LOW"), Priority::LOW);
    EXPECT_EQ(stringToPriority("MEDIUM"), Priority::MEDIUM);
    EXPECT_EQ(stringToPriority("HIGH"), Priority::HIGH);
}

TEST(EnumHelperTest, StringToPriorityThrowsForInvalidString) {
    EXPECT_THROW(stringToPriority("INVALID"), std::invalid_argument);
}

TEST(EnumHelperTest, StatusToStringWorks) {
    // REQ-006: Status enum conversion
    EXPECT_EQ(statusToString(Status::INCOMPLETE), "INCOMPLETE");
    EXPECT_EQ(statusToString(Status::COMPLETE), "COMPLETE");
}

TEST(EnumHelperTest, StringToStatusWorks) {
    EXPECT_EQ(stringToStatus("INCOMPLETE"), Status::INCOMPLETE);
    EXPECT_EQ(stringToStatus("COMPLETE"), Status::COMPLETE);
}

TEST(EnumHelperTest, StringToStatusThrowsForInvalidString) {
    EXPECT_THROW(stringToStatus("INVALID"), std::invalid_argument);
}

// ============================================================================
// Main function (provided by gtest_main, but shown for completeness)
// ============================================================================
