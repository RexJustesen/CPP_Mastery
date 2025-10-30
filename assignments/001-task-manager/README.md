# Project 001: Command-Line Task Manager

**Design Pattern**: Strategy Pattern  
**Difficulty**: Beginner (Tier 1)  
**Estimated Time**: 2-3 days  
**Prerequisites**: None (first project)

## Learning Objectives

By completing this project, you will:

1. Master basic C++ class design and object-oriented programming fundamentals
2. Implement and understand the Strategy pattern for algorithm selection
3. Apply Single Responsibility Principle (SRP) and Open/Closed Principle (OCP)
4. Practice file I/O and data persistence in C++
5. Work with STL containers (vector, map) and string manipulation
6. Develop test-driven development workflow habits

**Real-World Relevance**: Task management applications are ubiquitous in software development. Understanding how to design flexible filtering systems (via Strategy pattern) applies to search engines, database queries, log analysis, and any system requiring interchangeable algorithms. The SRP and OCP principles you'll practice are fundamental to maintainable codebases in professional environments.

---

## Problem Statement

Build a command-line task management application that allows users to create, organize, and track tasks. The application must support flexible task filtering using the Strategy pattern, enabling users to view tasks by priority, completion status, or other criteria without modifying the core TaskManager class.

### Context

Developers frequently need lightweight task tracking tools for managing work items, bugs, features, and todos. A well-designed task manager demonstrates clean separation of concerns: Task entities, management operations, and filtering strategies should be independent components. This project teaches you to build extensible systems where new filtering algorithms can be added without changing existing code (Open/Closed Principle).

### Requirements

#### Core Functionality

- **REQ-001**: The system MUST provide a Task class that represents an individual task with properties: unique ID, description, priority level, completion status, and creation date
- **REQ-002**: The system MUST provide a TaskManager class that maintains a collection of tasks and supports adding, removing, and retrieving tasks
- **REQ-003**: The system MUST implement the Strategy pattern for task filtering, with an IFilterStrategy interface and at least three concrete strategy implementations (by priority, by status, by date range)
- **REQ-004**: The TaskManager MUST support filtering tasks using any strategy without modifying the TaskManager class itself (demonstrating Open/Closed Principle)
- **REQ-005**: Tasks MUST have three priority levels: HIGH, MEDIUM, LOW
- **REQ-006**: Tasks MUST have two completion statuses: COMPLETE, INCOMPLETE
- **REQ-007**: Each task MUST have a unique integer ID automatically assigned when created
- **REQ-008**: The TaskManager MUST support updating task properties (description, priority, status)
- **REQ-009**: The TaskManager MUST support marking tasks as complete
- **REQ-010**: The TaskManager MUST persist tasks to a file when requested (save operation)
- **REQ-011**: The TaskManager MUST load tasks from a file on startup (load operation)
- **REQ-012**: The system MUST handle errors gracefully (e.g., attempting to remove non-existent task should throw appropriate exception)
- **REQ-013**: Task descriptions MUST NOT be empty strings
- **REQ-014**: The system MUST provide a count of total tasks and filtered tasks
- **REQ-015**: Multiple filter strategies MUST be combinable (e.g., filter by HIGH priority AND INCOMPLETE status)

#### Input Specifications

- Input format: Task data via class methods (not command-line parsing for this project)
- Task descriptions: non-empty strings (max length: 500 characters)
- Priority: one of {HIGH, MEDIUM, LOW}
- Status: one of {COMPLETE, INCOMPLETE}
- Date: C++ chrono time_point or equivalent

#### Output Specifications

- Output format: Task objects returned from queries, file I/O for persistence
- File format: Plain text or JSON-style (your choice, document in code)
- Error reporting: Exceptions with descriptive messages (std::invalid_argument, std::runtime_error)

---

## Build & Run

### Building the Project

```bash
# From project root directory (assignments/001-task-manager/)
cmake -B build
cmake --build build

# On Windows with MSVC:
cmake -B build
cmake --build build --config Release
```

### Running Tests

```bash
# From project root
cd build
ctest --output-on-failure

# OR run test executable directly
./tests/run_tests

# On Windows:
.\tests\Debug\run_tests.exe
```

### Running the Application

```bash
# From build directory
./task_manager_main

# On Windows:
.\Debug\task_manager_main.exe
```

**Note**: This project focuses on the library implementation and testing. The main.cpp provides a simple demonstration, but the core learning is in the tested library code.

---

## Test Suite Overview

**Testing Framework**: Google Test  
**Test Location**: `tests/test_task_manager.cpp`  
**Minimum Test Count**: 20 tests

### Test Categories

The pre-written test suite includes:

1. **Basic Functionality Tests** (10 tests): Task creation, adding/removing tasks, updating properties, retrieving tasks, counting
2. **Edge Case Tests** (5 tests): Empty task list, maximum capacity, duplicate operations, boundary dates
3. **Error Handling Tests** (5 tests): Invalid task IDs, empty descriptions, invalid priority/status, file I/O errors
4. **Design Pattern Verification Tests** (5 tests): Strategy swapping, filter correctness, combining multiple filters
5. **Persistence Tests** (5 tests): Save to file, load from file, data integrity after round-trip

### Example Test Scenarios

1. **Test**: `AddTaskSuccessfully`  
   **Purpose**: Verifies tasks can be added to the manager  
   **Example**: Given empty task list, when adding task "Write C++ code" with HIGH priority, expect task list size is 1 and task is retrievable by ID

2. **Test**: `RemoveTaskById`  
   **Purpose**: Verifies tasks can be removed by identifier  
   **Example**: Given task list with 3 tasks, when removing task ID 2, expect task list size is 2 and task ID 2 not found

3. **Test**: `FilterTasksByPriority`  
   **Purpose**: Verifies Strategy pattern filtering works correctly  
   **Example**: Given 5 tasks (2 HIGH, 2 MEDIUM, 1 LOW priority), when filtering with HighPriorityFilter, expect 2 tasks returned

4. **Test**: `MarkTaskComplete`  
   **Purpose**: Verifies task completion status can be toggled  
   **Example**: Given incomplete task, when marking complete, expect task status is COMPLETE and task appears in completed filter

5. **Test**: `SaveAndLoadTasksPreservesData`  
   **Purpose**: Verifies persistence round-trip maintains data integrity  
   **Example**: Given TaskManager with 5 tasks, when saving to file, creating new TaskManager, and loading from file, expect 5 tasks with identical properties

### Success Criteria

**ALL tests must pass (100% passage) before code review is available.**

To verify:
```bash
cd build
ctest
# Output should show: 100% tests passed, 0 tests failed
```

---

## Design Guidance

### Strategy Pattern

**Intent**: Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.

**When to use this pattern**:
- You need different variants of an algorithm (e.g., different filtering criteria)
- You want to avoid conditional statements for selecting algorithms
- Clients should be able to choose algorithms at runtime
- Algorithms should be independent and swappable without modifying client code

**Key Components in This Project**:
1. **Context** (TaskManager): Maintains a collection and uses strategies to filter
2. **Strategy Interface** (IFilterStrategy): Defines common interface for all concrete strategies
3. **Concrete Strategies** (PriorityFilter, StatusFilter, DateFilter): Implement specific filtering algorithms

**Benefits**:
- **Open/Closed Principle**: New filters can be added without modifying TaskManager
- **Single Responsibility**: Each filter has one reason to change
- **Runtime Flexibility**: Filters can be swapped dynamically
- **Testability**: Each filter can be tested independently

**Implementation Hints** (conceptual only):
- Strategy interface should have a method like `matches(const Task& task)` or `filter(const std::vector<Task>&)`
- TaskManager should accept a strategy and apply it to the task collection
- Consider how to combine multiple strategies (e.g., AND logic)

---

## SOLID Principles Focus

This project emphasizes:

### Single Responsibility Principle (SRP)
- **Task class**: Represents a single task with its data
- **TaskManager class**: Manages the collection of tasks
- **IFilterStrategy interface and concrete strategies**: Each strategy has one filtering responsibility
- **File I/O**: Consider separating persistence into a dedicated class (optional advanced extension)

**Verification**: Each class should have ONE reason to change. Task changes if task data structure changes. TaskManager changes if collection operations change. Filters change if filtering logic changes.

### Open/Closed Principle (OCP)
- **TaskManager is OPEN for extension** (new filter strategies) but **CLOSED for modification** (adding a new filter doesn't require editing TaskManager code)
- You can add DateRangeFilter, DescriptionSearchFilter, or any other filter without touching existing code

**Verification**: Can you add a new filter without modifying TaskManager.cpp? If yes, you've achieved OCP.

---

## Reference Materials

**C++ Language Features**:
- [cppreference: Classes](https://en.cppreference.com/w/cpp/language/classes)
- [cppreference: std::vector](https://en.cppreference.com/w/cpp/container/vector)
- [cppreference: File I/O](https://en.cppreference.com/w/cpp/io)
- [cppreference: Exceptions](https://en.cppreference.com/w/cpp/error/exception)
- [C++ Core Guidelines: C.2 (Use class if it has an invariant)](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-struct)

**Design Patterns**:
- [Refactoring Guru: Strategy Pattern](https://refactoring.guru/design-patterns/strategy/cpp)
- [SourceMaking: Strategy Pattern](https://sourcemaking.com/design_patterns/strategy)

**SOLID Principles**:
- [Single Responsibility Principle](https://en.wikipedia.org/wiki/Single-responsibility_principle)
- [Open/Closed Principle](https://en.wikipedia.org/wiki/Open%E2%80%93closed_principle)
- [Uncle Bob's SOLID article](http://blog.cleancoder.com/uncle-bob/2014/05/08/SingleReponsibilityPrinciple.html)

**File I/O and Persistence**:
- [C++ File I/O Tutorial](https://www.cplusplus.com/doc/tutorial/files/)
- [cppreference: std::fstream](https://en.cppreference.com/w/cpp/io/basic_fstream)

**Debugging Resources**:
- GDB Tutorial: [https://www.gnu.org/software/gdb/documentation/](https://www.gnu.org/software/gdb/documentation/)
- Valgrind Quick Start: [https://valgrind.org/docs/manual/quick-start.html](https://valgrind.org/docs/manual/quick-start.html)
- AddressSanitizer: Compile with `-fsanitize=address -g`

**See also**: `references/resources.md` for comprehensive learning resources specific to this project.

---

## Conceptual Hints

### High-Level Design Thinking

**Task Representation**:
- What data does a task need? (ID, description, priority, status, date...)
- Should Task be mutable or immutable?
- How do you generate unique IDs? (simple counter? UUID?)

**Task Management**:
- What data structure stores tasks efficiently? (vector? map?)
- How do you search for tasks by ID? (linear search? hash map?)
- How do you handle removal from a vector? (std::remove_if? erase-remove idiom?)

**Filtering Strategy**:
- What should the strategy interface look like? (single method? parameters?)
- How does TaskManager apply a strategy? (iterate through tasks, check predicate?)
- How can you combine multiple strategies? (chain them? AND/OR logic?)

**Persistence**:
- What file format is simplest? (JSON-like text? CSV? binary?)
- How do you serialize a Task? (write each field?)
- How do you deserialize a Task? (parse file line-by-line?)
- What if the file doesn't exist on load? (create empty? throw exception?)

### Algorithmic Considerations

- **Task Addition**: O(1) if using vector (amortized), consider ID generation
- **Task Removal**: O(n) for vector search + removal
- **Filtering**: O(n) to iterate through all tasks
- **File I/O**: O(n) for n tasks

**Note**: For this beginner project, simple algorithms are fine. No need for optimization unless you choose to explore more advanced data structures.

---

## Code Review Criteria

Once all tests pass, your code will be evaluated on:

### Correctness
- [ ] All 20+ tests pass (100% passage required)
- [ ] No memory leaks (run with `valgrind` or AddressSanitizer)
- [ ] No undefined behavior or segmentation faults
- [ ] Handles all error conditions gracefully (exceptions with clear messages)

### Design Pattern Application
- [ ] Strategy pattern correctly implemented with interface and concrete strategies
- [ ] TaskManager uses strategies without knowing their internal implementation
- [ ] New strategies can be added without modifying TaskManager
- [ ] Pattern provides clear benefit (flexibility in filtering algorithms)

### SOLID Principles
- [ ] **Single Responsibility**: Each class has one clear responsibility
- [ ] **Open/Closed**: TaskManager is open for extension (new filters) but closed for modification
- [ ] No God classes or classes that "do everything"

### Clean Code Practices
- [ ] Clear, descriptive naming (classes, methods, variables convey intent)
- [ ] Functions are small and focused (each does one thing well)
- [ ] No code duplication (DRY principle applied)
- [ ] Comments explain WHY, not WHAT (code is self-documenting)
- [ ] Consistent formatting and indentation

### Modern C++ Idioms
- [ ] Appropriate use of `const` (const-correctness)
- [ ] Member initialization in constructor initializer lists
- [ ] Use of STL containers and algorithms where appropriate
- [ ] Smart pointers (if dynamic memory needed) or prefer stack allocation
- [ ] Range-based for loops where applicable
- [ ] Proper exception handling (RAII principles)

### Code Quality
- [ ] Proper encapsulation (private data, public interface)
- [ ] Header guards or `#pragma once` in all header files
- [ ] Separation of interface (headers) and implementation (source files)
- [ ] No warnings when compiled with `-Wall -Wextra -Wpedantic`
- [ ] Resource management follows RAII (file handles closed automatically)

### Documentation
- [ ] Public methods documented with purpose and parameters
- [ ] Complex algorithms explained with comments
- [ ] README usage examples are clear and accurate

---

## Submission Checklist

Before considering this project complete:

- [ ] All tests pass without modification to test code
- [ ] Code compiles without warnings (`-Wall -Wextra -Wpedantic`)
- [ ] No memory leaks detected (Valgrind or AddressSanitizer clean)
- [ ] Strategy pattern correctly identified and implemented
- [ ] Single Responsibility and Open/Closed principles applied
- [ ] Clean code practices followed (DRY, meaningful names, small functions)
- [ ] Modern C++ features used appropriately (const, STL, RAII)
- [ ] Code is formatted consistently
- [ ] You understand every line of code and can explain design decisions
- [ ] You can articulate why you chose this design and what alternatives exist
- [ ] You can explain how the Strategy pattern benefits this design

---

## Getting Help

### Permitted Questions

You can ask for:
- "Can you clarify what REQ-005 means?"
- "What C++ feature should I research for file I/O?"
- "How does the Strategy pattern differ from the Command pattern?"
- "What does std::vector::erase do?"
- "Where can I find documentation about std::chrono?"
- "What's the difference between struct and class in C++?"
- "Why is the test expecting an exception here?"

### Prohibited Questions

Do NOT ask for:
- "Can you show me how to implement Task class?"
- "What algorithm should I use for filtering?"
- "Can you give me code for saving tasks to a file?"
- "Can you show me a similar task manager example?"
- "How do I make this test pass?" (without showing your attempt first)
- "What's the answer to this problem?"

**Remember**: The AI assistant acts as a mentor, not a solution provider. Struggle is part of the learning process. Research, experiment, debug, and discover. That's how you build genuine expertise.

---

## Extensions (Optional)

Once you've completed the core requirements and all tests pass, consider these extensions:

1. **Additional Filters**: Implement DateRangeFilter, DescriptionSearchFilter, TagFilter
2. **Composite Strategy**: Combine multiple filters with AND/OR logic
3. **Undo/Redo**: Add Command pattern for undoable operations
4. **JSON Persistence**: Use a JSON library (or write your own simple parser)
5. **Command-Line Interface**: Full CLI with argument parsing (use existing library or write your own)
6. **Multi-User Support**: Add user authentication and per-user task lists
7. **Task Dependencies**: Allow tasks to depend on other tasks
8. **Recurring Tasks**: Support tasks that repeat on a schedule

**Note**: Extensions are NOT required for project completion. Complete the core requirements first.

---

**Project Status**: 🚧 Ready for Implementation  
**Next Steps**: Review the test suite in `tests/test_task_manager.cpp`, then start implementing the Task class.

Good luck, and remember: **Learning happens through struggle!** 🚀
