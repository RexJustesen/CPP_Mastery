# Learning Resources for Task Manager Project

This document provides curated learning resources to help you complete this assignment. Use these as **research starting points**, not as direct solution sources.

---

## Table of Contents

1. [C++ Language Fundamentals](#c-language-fundamentals)
2. [Design Pattern: Strategy](#design-pattern-strategy)
3. [SOLID Principles](#solid-principles)
4. [Testing with Google Test](#testing-with-google-test)
5. [Build Tools and CMake](#build-tools-and-cmake)
6. [Debugging and Tools](#debugging-and-tools)
7. [Clean Code Practices](#clean-code-practices)
8. [Additional References](#additional-references)

---

## C++ Language Fundamentals

### Core Language Features

- **cppreference.com** - Comprehensive C++ reference
  - [https://en.cppreference.com/](https://en.cppreference.com/)
  - Focus areas for this project:
    - [Classes](https://en.cppreference.com/w/cpp/language/classes)
    - [Constructors and Destructors](https://en.cppreference.com/w/cpp/language/constructor)
    - [Member Functions](https://en.cppreference.com/w/cpp/language/member_functions)
    - [Const Correctness](https://en.cppreference.com/w/cpp/language/cv)
    - [Exceptions](https://en.cppreference.com/w/cpp/error/exception)
    - [std::vector](https://en.cppreference.com/w/cpp/container/vector)
    - [std::string](https://en.cppreference.com/w/cpp/string/basic_string)
    - [File I/O](https://en.cppreference.com/w/cpp/io)

### C++ Core Guidelines

- **C++ Core Guidelines** - Best practices for modern C++
  - [https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
  - Relevant sections:
    - [C.2: Use class if the class has an invariant](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-struct)
    - [C.45: Don't define a default constructor that only initializes data members](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-default)
    - [E: Error handling](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-errors)
    - [F: Functions](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-functions)

### Books

- *A Tour of C++* by Bjarne Stroustrup (Chapters 3-5: Abstraction Mechanisms, Classes, Templates)
- *Effective Modern C++* by Scott Meyers (Item 7: Distinguish between () and {} when creating objects)
- *C++ Primer* by Lippman, Lajoie, Moo (Chapters 7: Classes, 12: Dynamic Memory, 13: Copy Control)

---

## Design Pattern: Strategy

### Pattern Overview

**What is the Strategy pattern?**

The Strategy pattern defines a family of algorithms, encapsulates each one in a separate class, and makes them interchangeable. Strategy lets the algorithm vary independently from clients that use it.

**When should you use it?**
- You need different variants of an algorithm
- You want to avoid conditional statements (if/else chains) for selecting behavior
- Algorithms should be swappable at runtime
- Related classes differ only in their behavior

**What problem does it solve?**

It solves the problem of having multiple conditional branches that select different behaviors. Instead of hardcoding algorithm selection with if/else or switch statements, Strategy pattern lets you encapsulate each algorithm in its own class and select it dynamically.

### Pattern Resources

- **Refactoring Guru - Strategy Pattern**
  - [https://refactoring.guru/design-patterns/strategy/cpp](https://refactoring.guru/design-patterns/strategy/cpp)
  - Excellent visual diagrams showing pattern structure
  - Real-world analogies (route planning strategies)
  - Pros/cons of the pattern

- **SourceMaking - Strategy Pattern**
  - [https://sourcemaking.com/design_patterns/strategy](https://sourcemaking.com/design_patterns/strategy)
  - Implementation details and code structure
  - When to use and when not to use

- **Design Patterns (Gang of Four Book)**
  - Chapter 5: Behavioral Patterns - Strategy (page 315)
  - Focus on: Intent, Applicability, Structure, Participants, Collaborations

### Pattern Implementation Guidance

**Key components of the Strategy pattern:**
1. **Strategy Interface** - Declares common interface for all supported algorithms (e.g., `IFilterStrategy`)
2. **Concrete Strategies** - Implement specific algorithms adhering to the strategy interface (e.g., `HighPriorityFilter`, `StatusFilter`)
3. **Context** - Maintains a reference to a strategy object and delegates work to it (e.g., `TaskManager`)

**Questions to guide your implementation:**
- How do the components interact? (Context calls strategy's method)
- What responsibilities does each component have? (Context: manage data; Strategy: algorithm logic)
- How does the pattern achieve flexibility? (Strategies are interchangeable at runtime)
- What are the trade-offs? (More classes vs. simpler client code)

---

## SOLID Principles

This project focuses on: **Single Responsibility Principle (SRP)** and **Open/Closed Principle (OCP)**

### Single Responsibility Principle (SRP)

- **Definition**: A class should have one, and only one, reason to change.

- **Resources**:
  - [C++ Core Guidelines C.2](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-struct)
  - [Uncle Bob's SRP article](http://blog.cleancoder.com/uncle-bob/2014/05/08/SingleReponsibilityPrinciple.html)

- **Application in this project**:
  - **Task class**: Responsible only for representing a single task's data
  - **TaskManager class**: Responsible only for managing the collection of tasks
  - **IFilterStrategy and concrete strategies**: Each strategy responsible for one filtering algorithm
  - **Potential separation**: File persistence could be its own class (advanced extension)

**How to verify SRP**: Ask "What is the one reason this class would change?" For Task: changes to task data structure. For TaskManager: changes to collection operations. For filters: changes to filtering logic.

### Open/Closed Principle (OCP)

- **Definition**: Software entities should be open for extension, but closed for modification.

- **Resources**:
  - [OCP article by Robert Martin (PDF)](https://web.archive.org/web/20150906155800/http://www.objectmentor.com/resources/articles/ocp.pdf)
  - [Martin Fowler on OCP](https://martinfowler.com/bliki/OpenClosedPrinciple.html)

- **Application in this project**:
  - **TaskManager is OPEN for extension**: You can add new filter strategies without changing TaskManager code
  - **TaskManager is CLOSED for modification**: Adding `DateRangeFilter` or `DescriptionSearchFilter` doesn't require editing TaskManager.cpp

**How to verify OCP**: Can you add a new filter strategy without modifying TaskManager? If yes, you've achieved OCP through the Strategy pattern.

### Other SOLID Principles (Not Primary Focus)

- **LSP (Liskov Substitution)**: Applies if you use inheritance. Any derived filter should work wherever base IFilterStrategy is expected.
- **ISP (Interface Segregation)**: Keep interfaces focused. IFilterStrategy should only have methods related to filtering.
- **DIP (Dependency Inversion)**: TaskManager depends on IFilterStrategy abstraction, not concrete filters.

---

## Testing with Google Test

### Google Test Documentation

- **Official Google Test Primer**
  - [https://google.github.io/googletest/primer.html](https://google.github.io/googletest/primer.html)
  - Basic assertions: `EXPECT_EQ`, `ASSERT_EQ`, `EXPECT_TRUE`, `EXPECT_FALSE`
  - Test fixtures: `SetUp()` and `TearDown()` for common initialization
  - Death tests for exception verification

- **Google Test Assertions Reference**
  - [https://google.github.io/googletest/reference/assertions.html](https://google.github.io/googletest/reference/assertions.html)
  - `EXPECT_THROW(statement, exception_type)` - Verify exceptions
  - `EXPECT_NO_THROW(statement)` - Verify no exceptions
  - `EXPECT_EQ(val1, val2)` - Verify equality
  - `EXPECT_NE(val1, val2)` - Verify inequality

### Test-Driven Development (TDD)

**TDD Cycle**: Red → Green → Refactor

1. **Red**: Run tests, see them fail (because code not implemented yet)
2. **Green**: Write minimal code to make tests pass
3. **Refactor**: Improve code quality while keeping tests green

**Resources**:
- *Test Driven Development: By Example* by Kent Beck
- [Martin Fowler on TDD](https://martinfowler.com/bliki/TestDrivenDevelopment.html)

### Writing Good Tests

- **Arrange-Act-Assert Pattern**: 
  - Arrange: Set up test data and objects
  - Act: Perform the operation being tested
  - Assert: Verify expected outcome
- **Test Independence**: Each test should run independently (no shared state between tests)
- **Descriptive Test Names**: `AddTaskSuccessfully` is better than `Test1`

---

## Build Tools and CMake

### CMake Basics

- **CMake Tutorial**
  - [https://cmake.org/cmake/help/latest/guide/tutorial/index.html](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
  - Steps 1-4 cover everything needed for this project

- **Key CMake Commands**:
  - `cmake_minimum_required(VERSION 3.20)` - Specify minimum CMake version
  - `project(TaskManager)` - Define project name
  - `add_library(task_manager_lib ...)` - Create a library from source files
  - `add_executable(task_manager_main ...)` - Create executable
  - `target_link_libraries(...)` - Link libraries together
  - `enable_testing()` and `add_subdirectory(tests)` - Enable test discovery

### Building and Running Tests

```bash
# Standard CMake workflow
cmake -B build           # Configure
cmake --build build      # Compile
cd build && ctest --output-on-failure  # Run tests
```

---

## Debugging and Tools

### Debugging Techniques

**Print Debugging**:
```cpp
std::cout << "Task ID: " << task.getId() << std::endl;
std::cerr << "Error: " << error_message << std::endl;
```

**Debugger Usage**:
- **GDB** (Linux/macOS): 
  - [GDB Quick Reference](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf)
  - Run: `gdb ./task_manager_main`
  - Set breakpoint: `break TaskManager::addTask`
  - Run: `run`, Step: `step`, Continue: `continue`
  
- **LLDB** (macOS):
  - [LLDB Tutorial](https://lldb.llvm.org/use/tutorial.html)
  - Similar commands to GDB
  
- **Visual Studio Debugger** (Windows):
  - [VS Debugger Docs](https://docs.microsoft.com/en-us/visualstudio/debugger/)
  - F9: Set breakpoint, F5: Start debugging, F10: Step over, F11: Step into

### Memory Safety Tools

**Valgrind** (Linux/macOS):
```bash
valgrind --leak-check=full ./task_manager_main
```
- Detects memory leaks, invalid memory access, uninitialized values
- [Valgrind Quick Start](https://valgrind.org/docs/manual/quick-start.html)

**AddressSanitizer** (All platforms with GCC/Clang):
```bash
# Compile with sanitizer
g++ -fsanitize=address -g -o task_manager_main ...
# Run normally - errors reported automatically
./task_manager_main
```

### Static Analysis

**clang-tidy**:
```bash
clang-tidy src/*.cpp -- -std=c++17
```
- Finds bugs, style violations, potential improvements
- [clang-tidy documentation](https://clang.llvm.org/extra/clang-tidy/)

**cppcheck**:
```bash
cppcheck --enable=all src/
```
- Lightweight static analyzer
- [cppcheck manual](http://cppcheck.sourceforge.net/manual.pdf)

---

## Clean Code Practices

### Naming Conventions

**Classes**: `PascalCase`
```cpp
class TaskManager { };
class HighPriorityFilter { };
```

**Functions/Variables**: `snake_case`
```cpp
void add_task(const Task& task);
int task_count = 0;
```

**Constants**: `kPascalCase` or `ALL_CAPS`
```cpp
const int kMaxTasks = 1000;
const Priority PRIORITY_HIGH = Priority::HIGH;
```

### Function Design

- **Keep functions small**: Aim for <20 lines per function
- **Single purpose**: Each function does one thing well
- **Descriptive names**: `addTask()` is better than `add()`
- **Limit parameters**: 3-4 max; consider a parameter object if more

### Comments

**Good comments (explain WHY)**:
```cpp
// Use vector instead of map for better cache locality when iterating
std::vector<Task> tasks_;

// Filter must be applied after adding to maintain invariant
addTask(task);
applyCurrentFilter();
```

**Bad comments (state the obvious)**:
```cpp
// Increment counter
counter++;

// Return task count
return tasks_.size();
```

### DRY (Don't Repeat Yourself)

**Problem**: Duplicate code
```cpp
// BAD: Repeated logic
void saveToFile() {
    std::ofstream file("tasks.txt");
    for (const auto& task : tasks_) {
        file << task.getId() << "," << task.getDescription() << "\n";
    }
}

void backupToFile() {
    std::ofstream file("backup.txt");
    for (const auto& task : tasks_) {
        file << task.getId() << "," << task.getDescription() << "\n";
    }
}
```

**Solution**: Extract common code
```cpp
// GOOD: Reusable function
void writeTasksToFile(const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& task : tasks_) {
        file << task.getId() << "," << task.getDescription() << "\n";
    }
}
```

---

## Additional References

### Online Communities

- **Stack Overflow** - [https://stackoverflow.com/questions/tagged/c++](https://stackoverflow.com/questions/tagged/c++)
  - Search before asking
  - Provide [minimal reproducible example](https://stackoverflow.com/help/minimal-reproducible-example)

- **C++ Subreddit** - [https://www.reddit.com/r/cpp/](https://www.reddit.com/r/cpp/)
  - Weekly Q&A threads for beginners

- **cpplang Slack** - [https://cpplang.slack.com/](https://cpplang.slack.com/)
  - Active C++ community

### Blogs and Articles

- **Fluent C++** - [https://www.fluentcpp.com/](https://www.fluentcpp.com/)
  - Expressive C++ code techniques

- **Modernes C++** - [https://www.modernescpp.com/](https://www.modernescpp.com/)
  - Modern C++ features and practices

### File I/O Resources

- [C++ File I/O Tutorial](https://www.cplusplus.com/doc/tutorial/files/)
- [std::ofstream reference](https://en.cppreference.com/w/cpp/io/basic_ofstream)
- [std::ifstream reference](https://en.cppreference.com/w/cpp/io/basic_ifstream)

---

## How to Use These Resources

### Research Workflow

1. **Understand the Requirement**: Read REQ-XXX carefully in README.md
2. **Identify Knowledge Gaps**: What concepts are unfamiliar?
3. **Targeted Research**: Use resources above to learn those specific concepts
4. **Read the Tests**: Understand what behavior is expected
5. **Plan Your Implementation**: Sketch approach on paper
6. **Write Code Incrementally**: Small steps, run tests frequently
7. **Refactor**: Once tests pass, clean up your code

### Permitted Research Questions

You can research:
- "How does the Strategy pattern work?"
- "What is const correctness in C++?"
- "How do I use EXPECT_THROW in Google Test?"
- "What does std::vector::erase do?"
- "How do I read/write files in C++?"
- "What is the Single Responsibility Principle?"

### Prohibited Questions

Do NOT search for:
- "Task manager C++ implementation"
- "Complete Strategy pattern code example in C++"
- "How to implement task filtering in C++"
- Direct copy-paste solutions

**Remember**: The goal is to **learn**, not just to complete. Struggle is part of the learning process. Use these resources to build understanding, not to find shortcuts.

---

*Last Updated: 2025-10-29*  
*Constitutional Compliance: Verified under Principle 1 (Teaching-First), Principle 3 (Zero Solution Disclosure)*
