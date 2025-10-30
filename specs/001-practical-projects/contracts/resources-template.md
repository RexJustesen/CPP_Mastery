# Learning Resources for {PROJECT_NAME}

This document provides curated learning resources to help you complete this assignment. Use these as **research starting points**, not as direct solution sources.

---

## Table of Contents

1. [C++ Language Fundamentals](#c-language-fundamentals)
2. [Design Pattern: {Pattern}](#design-pattern-pattern)
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
    - [Standard Library Containers](https://en.cppreference.com/w/cpp/container)

### C++ Core Guidelines

- **C++ Core Guidelines** - Best practices for modern C++
  - [https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
  - Relevant sections:
    - [C: Classes and class hierarchies](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-class)
    - [E: Error handling](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-errors)
    - [F: Functions](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-functions)
    - [Per: Performance](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-performance)

### Books

- *A Tour of C++* by Bjarne Stroustrup (Chapters relevant to this project: [Specify chapters])
- *Effective Modern C++* by Scott Meyers (Items relevant: [Specify items])
- *C++ Primer* by Lippman, Lajoie, Moo (Chapters on classes, containers, exceptions)

---

## Design Pattern: {Pattern}

### Pattern Overview

**What is the {Pattern} pattern?**
- [Brief conceptual description - 2-3 sentences]
- [When should you use it?]
- [What problem does it solve?]

### Pattern Resources

- **Refactoring Guru - {Pattern} Pattern**
  - [https://refactoring.guru/design-patterns/{pattern-slug}](https://refactoring.guru/design-patterns/{pattern-slug})
  - Visual diagrams and code examples
  - Structure, participants, and collaborations
  - Real-world analogies

- **SourceMaking - {Pattern} Pattern**
  - [https://sourcemaking.com/design_patterns/{pattern-slug}](https://sourcemaking.com/design_patterns/{pattern-slug})
  - Implementation details and variations

- **Design Patterns (Gang of Four Book)**
  - Chapter: [Specify chapter]
  - Focus on: Structure, Participants, Collaborations, Implementation considerations

### Pattern Implementation Guidance

**Key components of the {Pattern} pattern:**
1. [Component 1] - [Brief role description]
2. [Component 2] - [Brief role description]
3. [Component 3] - [Brief role description]

**Questions to guide your implementation:**
- How do the components interact?
- What responsibilities does each component have?
- How does the pattern achieve flexibility?
- What are the trade-offs of this pattern?

---

## SOLID Principles

This project focuses on: **{Primary SOLID Principle(s)}**

### Single Responsibility Principle (SRP)

- **Definition**: A class should have one, and only one, reason to change.
- **Resources**:
  - [C++ Core Guidelines C.2](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-struct)
  - [Uncle Bob's article](http://blog.cleancoder.com/uncle-bob/2014/05/08/SingleReponsibilityPrinciple.html)
- **Application in this project**: [Specific guidance]

### Open/Closed Principle (OCP)

- **Definition**: Software entities should be open for extension, but closed for modification.
- **Resources**:
  - [OCP article by Robert Martin](https://web.archive.org/web/20150906155800/http://www.objectmentor.com/resources/articles/ocp.pdf)
- **Application in this project**: [Specific guidance]

### Liskov Substitution Principle (LSP)

- **Definition**: Derived classes must be substitutable for their base classes.
- **Resources**:
  - [C++ Core Guidelines C.129](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-copy)
- **Application in this project**: [Specific guidance]

### Interface Segregation Principle (ISP)

- **Definition**: Clients should not be forced to depend on interfaces they do not use.
- **Resources**:
  - [ISP article](https://web.archive.org/web/20150905081105/http://www.objectmentor.com/resources/articles/isp.pdf)
- **Application in this project**: [Specific guidance]

### Dependency Inversion Principle (DIP)

- **Definition**: Depend on abstractions, not on concretions.
- **Resources**:
  - [DIP article](https://web.archive.org/web/20150905081103/http://www.objectmentor.com/resources/articles/dip.pdf)
- **Application in this project**: [Specific guidance]

---

## Testing with Google Test

### Google Test Documentation

- **Official Google Test Primer**
  - [https://google.github.io/googletest/primer.html](https://google.github.io/googletest/primer.html)
  - Basic assertions (EXPECT_EQ, ASSERT_EQ, etc.)
  - Test fixtures and SetUp/TearDown
  - Death tests for exceptions

- **Google Test Advanced Topics**
  - [https://google.github.io/googletest/advanced.html](https://google.github.io/googletest/advanced.html)
  - Parameterized tests
  - Type-parameterized tests
  - Custom matchers

### Test-Driven Development (TDD)

- **TDD Cycle**: Red → Green → Refactor
  1. **Red**: Write a failing test
  2. **Green**: Write minimal code to pass the test
  3. **Refactor**: Improve code while keeping tests green

- **Resources**:
  - *Test Driven Development: By Example* by Kent Beck
  - [TDD article by Martin Fowler](https://martinfowler.com/bliki/TestDrivenDevelopment.html)

### Writing Good Tests

- **Arrange-Act-Assert Pattern**: Structure each test clearly
- **Test Independence**: Each test should run independently
- **Descriptive Test Names**: Test name should describe what is being tested
- **One Assertion Per Test** (guideline): Focus each test on one behavior

---

## Build Tools and CMake

### CMake Basics

- **CMake Tutorial**
  - [https://cmake.org/cmake/help/latest/guide/tutorial/index.html](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
  - Chapters 1-4 cover essentials for this project

- **CMake Commands Reference**
  - [cmake_minimum_required](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html)
  - [project](https://cmake.org/cmake/help/latest/command/project.html)
  - [add_library](https://cmake.org/cmake/help/latest/command/add_library.html)
  - [add_executable](https://cmake.org/cmake/help/latest/command/add_executable.html)
  - [target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html)
  - [enable_testing](https://cmake.org/cmake/help/latest/command/enable_testing.html)

### Building and Running Tests

```bash
# Standard CMake workflow
cmake -B build
cmake --build build
cd build && ctest --output-on-failure
```

---

## Debugging and Tools

### Debugging Techniques

- **Print Debugging**: Use `std::cout` or `std::cerr` for quick debugging
- **Debugger Usage**:
  - GDB (Linux/macOS): [GDB Quick Reference](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf)
  - LLDB (macOS): [LLDB Tutorial](https://lldb.llvm.org/use/tutorial.html)
  - Visual Studio Debugger (Windows): [VS Debugger Documentation](https://docs.microsoft.com/en-us/visualstudio/debugger/)

### Memory Safety Tools

- **Valgrind** (Linux/macOS)
  - [https://valgrind.org/docs/manual/quick-start.html](https://valgrind.org/docs/manual/quick-start.html)
  - Detects memory leaks, invalid memory access, uninitialized values
  - Run: `valgrind --leak-check=full ./your_program`

- **AddressSanitizer** (GCC/Clang)
  - Compile with: `-fsanitize=address -g`
  - Detects memory errors at runtime with minimal overhead

### Static Analysis

- **clang-tidy**
  - [https://clang.llvm.org/extra/clang-tidy/](https://clang.llvm.org/extra/clang-tidy/)
  - Linter and static analysis tool for C++
  - Run: `clang-tidy src/*.cpp -- -std=c++17`

- **cppcheck**
  - [http://cppcheck.sourceforge.net/](http://cppcheck.sourceforge.net/)
  - Lightweight static analysis
  - Run: `cppcheck --enable=all src/`

---

## Clean Code Practices

### Code Readability

- **Naming Conventions**:
  - Use descriptive names (no abbreviations unless very common)
  - Classes: `PascalCase` (e.g., `TaskManager`)
  - Functions/variables: `snake_case` (e.g., `add_task`, `task_count`)
  - Constants: `kPascalCase` or `ALL_CAPS`

- **Function Design**:
  - Keep functions small and focused (Single Responsibility)
  - Prefer pure functions when possible (no side effects)
  - Limit parameters (3-4 max)

- **Comments**:
  - Write self-documenting code (clear names, simple logic)
  - Use comments for *why*, not *what*
  - Document public APIs with Doxygen comments

### DRY (Don't Repeat Yourself)

- **Principle**: Avoid code duplication
- **Techniques**:
  - Extract repeated code into functions
  - Use loops instead of copy-paste
  - Parameterize differences

### Resources

- *Clean Code* by Robert C. Martin - Chapters on naming, functions, comments
- *The Pragmatic Programmer* - Tips on code organization and maintainability

---

## Additional References

### Online Communities

- **Stack Overflow** - [https://stackoverflow.com/questions/tagged/c++](https://stackoverflow.com/questions/tagged/c++)
  - Search for existing questions first
  - Ask new questions with minimal reproducible examples

- **C++ Subreddit** - [https://www.reddit.com/r/cpp/](https://www.reddit.com/r/cpp/)
  - Weekly Q&A threads for beginner questions

- **cpplang Slack** - [https://cpplang.slack.com/](https://cpplang.slack.com/)
  - Active community for C++ questions

### Blogs and Articles

- **Fluent C++** - [https://www.fluentcpp.com/](https://www.fluentcpp.com/)
  - Expressive code and modern C++ techniques

- **Modernes C++** - [https://www.modernescpp.com/](https://www.modernescpp.com/)
  - Modern C++ features and best practices

- **Herb Sutter's Blog** - [https://herbsutter.com/](https://herbsutter.com/)
  - Expert-level C++ insights

---

## How to Use These Resources

### Research Workflow

1. **Understand the Requirement**: Read the requirement in README.md carefully
2. **Identify Knowledge Gaps**: What concepts are unfamiliar?
3. **Targeted Research**: Use resources above to learn those specific concepts
4. **Read the Tests**: Understand what behavior is expected
5. **Plan Your Implementation**: Sketch out approach on paper
6. **Write Code Incrementally**: Small steps, run tests frequently
7. **Refactor**: Once tests pass, clean up your code

### Permitted Research Questions

You can research:
- "How does the {Pattern} pattern work?"
- "What is const correctness in C++?"
- "How do I use EXPECT_THROW in Google Test?"
- "What does Big-O notation mean?"
- "How do I validate input parameters?"

### Prohibited Questions

Do NOT search for:
- "Solution to {PROJECT_NAME}"
- "Complete implementation of {Pattern} pattern in C++"
- Direct copy-paste code for this assignment

**Remember**: The goal is to *learn*, not just to complete. Struggle is part of the learning process. Use these resources to build understanding, not to find shortcuts.

---

*Last Updated: [Date]*
*Constitutional Compliance: Verified under Principle 1 (Teaching-First), Principle 3 (Zero Solution Disclosure)*
