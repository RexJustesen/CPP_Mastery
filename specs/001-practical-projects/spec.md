````markdown
# Assignment Specification: Practical C++ Projects Curriculum

**Assignment Module**: `001-practical-projects`  
**Created**: 2025-10-29  
**Difficulty**: Progressive (Beginner → Expert)  
**Prerequisites**: None (starts from fundamentals)  
**Estimated Time**: 6-12 months for complete curriculum

## Learning Objectives *(mandatory)*

By completing this curriculum of practical projects, you will:

1. **Master Core C++ Language Features**: Syntax, memory management, OOP, templates, modern C++ (C++11/14/17/20/23)
2. **Apply Software Design Patterns**: Understand and implement creational, structural, and behavioral patterns in real contexts
3. **Implement SOLID Principles**: Write maintainable, extensible code following Single Responsibility, Open/Closed, Liskov Substitution, Interface Segregation, and Dependency Inversion principles
4. **Practice Clean Code & DRY**: Develop readable, maintainable software that minimizes duplication and maximizes clarity
5. **Build Production-Ready Software**: Create useful, practical applications with proper error handling, testing, and documentation
6. **Develop Software Engineering Discipline**: Test-driven development, debugging, performance optimization, and code review practices

**Real-World Relevance**: This curriculum bridges academic C++ knowledge and professional software engineering. Every project builds something useful—productivity tools, audio processors, system utilities—teaching not just language syntax but the craftsmanship required to build reliable, maintainable software that others (including your future self) can understand and extend.

---

## Problem Statement *(mandatory)*

Design and implement a comprehensive curriculum of practical C++ projects that teach software engineering principles through building real, useful applications. Each project must have pre-written tests that define success, and learners must pass all tests before receiving code review feedback.

### Context

Traditional C++ education often focuses on isolated syntax exercises disconnected from real software development. This curriculum takes a different approach: every project builds something genuinely useful while teaching fundamental software engineering principles. Projects range from command-line productivity tools to audio processing systems, ensuring learners see immediate practical value while developing deep technical expertise.

The curriculum follows strict constitutional principles:
- **Test-Driven Learning**: All tests written first; 100% passage required
- **Zero Solution Disclosure**: Learners receive guidance and references, never implementations
- **Teaching-First Philosophy**: AI assistant acts as mentor, not solution provider
- **Progressive Mastery**: Each project builds on previous knowledge with clear prerequisites

### Requirements

This specification defines the curriculum structure, project categories, and learning progression.

#### Core Functionality

- **REQ-001**: Curriculum MUST include 20-30 practical projects organized into clear difficulty tiers (Beginner, Intermediate, Advanced, Expert)

- **REQ-002**: Each project MUST teach at least one software design pattern (Factory, Strategy, Observer, Command, Template Method, etc.) in a practical context

- **REQ-003**: Projects MUST be genuinely useful applications that could boost productivity or accomplish meaningful tasks (task managers, text processors, audio tools, system utilities, etc.)

- **REQ-004**: Every project MUST include comprehensive pre-written test suites covering:
  - Core functionality verification
  - Edge cases and boundary conditions
  - Error handling and invalid input
  - Performance requirements (where applicable)

- **REQ-005**: Each project MUST explicitly teach clean code principles:
  - Clear naming conventions
  - Single Responsibility Principle
  - DRY (Don't Repeat Yourself)
  - Appropriate abstraction levels

- **REQ-006**: Projects MUST progressively teach SOLID principles:
  - Early projects: Single Responsibility
  - Mid projects: Open/Closed, Liskov Substitution
  - Advanced projects: Interface Segregation, Dependency Inversion

- **REQ-007**: Curriculum MUST cover modern C++ features:
  - C++11: Smart pointers, move semantics, lambda expressions, range-based for loops
  - C++14: Generic lambdas, return type deduction
  - C++17: Structured bindings, std::optional, std::variant
  - C++20: Concepts, ranges, coroutines (where appropriate)

- **REQ-008**: Each project MUST include curated reference materials:
  - cppreference.com links for relevant features
  - C++ Core Guidelines references
  - Design pattern documentation
  - Debugging strategies

- **REQ-009**: Projects MUST NOT include solution code or implementation hints that reveal the answer

- **REQ-010**: Each project MUST define clear code review criteria focusing on:
  - Correct design pattern application
  - SOLID principle adherence
  - Clean code practices
  - Modern C++ idiom usage
  - Performance considerations

#### Project Categories

Projects organized into these domains (all teaching design patterns and principles):

**Category A: Productivity Tools**
- Command-line task managers
- Text processing utilities
- File organizers and batch processors
- Note-taking systems
- Configuration file parsers

**Category B: Audio Processing**
- WAV file reader/writer
- Audio effects processors (reverb, delay, filtering)
- Simple synthesizers
- Audio format converters
- Real-time audio stream processors

**Category C: System Utilities**
- Log file analyzers
- Process monitors
- File system watchers
- Network utilities (simple servers/clients)
- Resource usage trackers

**Category D: Data Structures & Algorithms**
- Custom container implementations (with iterators)
- Algorithm libraries
- Serialization systems
- Database-like query engines
- Caching systems

**Category E: Development Tools**
- Simple build systems
- Code formatters
- Static analysis tools
- Test harnesses
- Profiling utilities

#### Difficulty Progression

- **REQ-011**: Beginner projects (1-5) MUST focus on:
  - Basic syntax and control flow
  - Functions and classes
  - Standard library containers
  - File I/O
  - Simple design patterns (Strategy, Factory)

- **REQ-012**: Intermediate projects (6-15) MUST introduce:
  - Inheritance and polymorphism
  - Template basics
  - RAII and resource management
  - More complex patterns (Observer, Command, Decorator)
  - Multi-file project structure

- **REQ-013**: Advanced projects (16-25) MUST cover:
  - Advanced templates and metaprogramming
  - Move semantics and perfect forwarding
  - Complex design patterns (Template Method, Visitor, Composite)
  - Performance optimization
  - Concurrency basics

- **REQ-014**: Expert projects (26-30) MUST demonstrate:
  - System-level programming
  - Advanced concurrency patterns
  - Custom memory allocators
  - Compile-time programming
  - Integration of multiple patterns in cohesive architecture

#### Input Specifications

For each project in the curriculum:

- Input format: Project specification document (assignment README.md) describing the problem, requirements, and learning objectives
- Input constraints: Specifications must be clear and testable; no ambiguous requirements
- Invalid input handling: Projects must define expected error handling behavior

#### Output Specifications

For each completed project:

- Output format: Working C++ application passing 100% of pre-written tests
- Output constraints: Code must compile with `-Wall -Wextra -Wpedantic` without warnings
- Error reporting: Applications must handle errors gracefully with clear messages; tests verify error conditions

---

## Curriculum Structure *(mandatory)*

### Project Tier 1: Foundations (Beginner)

**Projects 1-5**: Basic C++ syntax, standard library, simple design patterns

1. **Command-Line Task Manager** (Strategy Pattern)
   - Priority: P1
   - Skills: Basic I/O, vectors, file persistence, class design
   - SOLID: Single Responsibility Principle
   - Utility: Manage daily tasks from terminal

2. **Text File Processor** (Factory Pattern)
   - Priority: P1  
   - Skills: File I/O, string manipulation, polymorphism
   - SOLID: Open/Closed Principle
   - Utility: Batch process text files (uppercase, lowercase, word count, etc.)

3. **Configuration File Parser** (Builder Pattern)
   - Priority: P1
   - Skills: Parsing, data structures, error handling
   - SOLID: Single Responsibility
   - Utility: Parse INI/JSON-like config files for applications

4. **Simple File Organizer** (Command Pattern)
   - Priority: P1
   - Skills: Filesystem operations, undo/redo, command queue
   - SOLID: Command pattern separation
   - Utility: Organize files by type, date, size with undo capability

5. **CSV Data Analyzer** (Template Method Pattern)
   - Priority: P1
   - Skills: File parsing, data analysis, algorithm design
   - SOLID: Template Method structure
   - Utility: Analyze CSV data with custom analysis strategies

### Project Tier 2: Intermediate Engineering (Intermediate)

**Projects 6-15**: OOP, templates, RAII, complex patterns

6. **WAV Audio File Reader/Writer** (Adapter Pattern)
   - Priority: P2
   - Skills: Binary file I/O, byte manipulation, RAII for file handles
   - SOLID: Interface Segregation
   - Utility: Read/write WAV files for audio processing

7. **Audio Effects Processor** (Decorator Pattern)
   - Priority: P2
   - Skills: Audio algorithms, effect chaining, DSP basics
   - SOLID: Decorator for composable effects
   - Utility: Apply reverb, delay, filters to audio

8. **Event-Driven Logger System** (Observer Pattern + Singleton)
   - Priority: P2
   - Skills: Design patterns, thread safety basics, file I/O
   - SOLID: Observer for multi-subscriber logging
   - Utility: Centralized logging for applications

9. **Custom String Class with Iterators** (Iterator Pattern)
   - Priority: P2
   - Skills: Memory management, operator overloading, iterators
   - SOLID: Iterator abstraction
   - Utility: Alternative string implementation with custom features

10. **Thread-Safe Task Queue** (Producer-Consumer Pattern)
    - Priority: P2
    - Skills: Concurrency, mutexes, condition variables, RAII locks
    - SOLID: Dependency Inversion with abstract queue interface
    - Utility: Background task processing system

11. **File System Watcher** (Observer Pattern)
    - Priority: P2
    - Skills: System APIs, event handling, callbacks
    - SOLID: Observer for file change notifications
    - Utility: Monitor directories for changes, trigger actions

12. **Simple HTTP Server** (Chain of Responsibility)
    - Priority: P2
    - Skills: Networking, request handling, middleware pattern
    - SOLID: Chain of Responsibility for request processing
    - Utility: Serve static files, handle basic HTTP requests

13. **Serialization Framework** (Visitor Pattern)
    - Priority: P2
    - Skills: Template metaprogramming, serialization, visitor pattern
    - SOLID: Visitor for type-specific serialization
    - Utility: Serialize/deserialize objects to JSON/XML/binary

14. **Plugin System with Dynamic Loading** (Abstract Factory)
    - Priority: P2
    - Skills: Dynamic libraries, factory pattern, interfaces
    - SOLID: Dependency Inversion for plugin architecture
    - Utility: Load plugins at runtime, extensible application

15. **Memory Pool Allocator** (Object Pool Pattern)
    - Priority: P2
    - Skills: Custom memory management, allocators, optimization
    - SOLID: Single Responsibility for allocation strategy
    - Utility: Fast allocation for performance-critical code

### Project Tier 3: Advanced Architecture (Advanced)

**Projects 16-25**: Advanced C++, performance, complex systems

16. **Audio Synthesizer Engine** (State Pattern + Composite)
    - Priority: P3
    - Skills: Audio synthesis, oscillators, envelopes, modulation
    - SOLID: Composite for synth architecture, State for envelope stages
    - Utility: Generate musical tones, build simple instruments

17. **Build System Generator** (Interpreter Pattern)
    - Priority: P3
    - Skills: DSL parsing, build graph, dependency resolution
    - SOLID: Interpreter for build script language
    - Utility: Define and execute build tasks

18. **Database Query Engine** (Interpreter + Composite)
    - Priority: P3
    - Skills: Query parsing, expression trees, data filtering
    - SOLID: Composite for query expressions
    - Utility: Query in-memory data structures with SQL-like syntax

19. **Real-Time Audio Stream Processor** (Bridge Pattern)
    - Priority: P3
    - Skills: Real-time processing, callback-based audio, low-latency design
    - SOLID: Bridge separates audio I/O from processing
    - Utility: Process audio in real-time (VST-like plugin host)

20. **Concurrent Web Scraper** (Flyweight Pattern)
    - Priority: P3
    - Skills: HTTP requests, HTML parsing, concurrency, resource sharing
    - SOLID: Flyweight for shared scraping state
    - Utility: Scrape websites concurrently, extract data

21. **Smart Pointer Library** (Proxy Pattern)
    - Priority: P3
    - Skills: Template metaprogramming, RAII, reference counting
    - SOLID: Proxy for pointer indirection
    - Utility: Custom smart pointer implementations (like shared_ptr/unique_ptr)

22. **Expression Template Math Library** (Template Metaprogramming)
    - Priority: P3
    - Skills: Expression templates, compile-time optimization, operator overloading
    - SOLID: Template-based compile-time polymorphism
    - Utility: High-performance linear algebra library

23. **Code Formatter/Linter** (Visitor Pattern)
    - Priority: P3
    - Skills: Parsing, AST traversal, code transformation
    - SOLID: Visitor for AST node operations
    - Utility: Format C++ code, detect style violations

24. **Process Monitor & Resource Tracker** (Mediator Pattern)
    - Priority: P3
    - Skills: System calls, process information, resource monitoring
    - SOLID: Mediator coordinates monitoring components
    - Utility: Track CPU, memory, I/O for processes

25. **Lock-Free Data Structures** (No specific pattern—focus on correctness)
    - Priority: P3
    - Skills: Atomic operations, memory ordering, lock-free algorithms
    - SOLID: Focus on correctness and performance over patterns
    - Utility: High-performance concurrent data structures

### Project Tier 4: Expert Systems (Expert)

**Projects 26-30**: System programming, advanced concurrency, architecture

26. **Custom Memory Allocator with Debugging** (Strategy + Decorator)
    - Priority: P4
    - Skills: Low-level memory management, debugging, allocation strategies
    - SOLID: Strategy for allocation policy, Decorator for debugging features
    - Utility: Replace malloc/new with custom allocator, detect leaks

27. **Coroutine-Based Async I/O Framework** (C++20 Coroutines)
    - Priority: P4
    - Skills: Coroutines, async I/O, event loops, promises
    - SOLID: Separation of coroutine logic from I/O implementation
    - Utility: Build async network/file I/O applications

28. **Mini Game Engine** (Multiple Patterns Integration)
    - Priority: P4
    - Skills: Game loop, entity-component system, rendering pipeline
    - Patterns: ECS (Composite/Strategy), Command (input), State (game states)
    - Utility: 2D game engine for simple games

29. **Distributed Task Processing System** (Master-Worker Pattern)
    - Priority: P4
    - Skills: Networking, distributed systems, work distribution, fault tolerance
    - SOLID: Multiple patterns for distributed coordination
    - Utility: Distribute computational tasks across machines

30. **JIT Compiler for Simple Language** (Interpreter + multiple patterns)
    - Priority: P4
    - Skills: Parsing, bytecode generation, JIT compilation, runtime optimization
    - Patterns: Interpreter, Visitor, Builder for compilation pipeline
    - Utility: Execute custom scripting language with JIT optimization

---

## Test Suite Overview *(mandatory)*

**Testing Framework**: Google Test (recommended for all projects)  
**Test Location**: Each project has dedicated `tests/` directory  
**Test Execution**: Automated via CMake and CTest

### Test Categories Per Project

Every project includes comprehensive pre-written tests:

1. **Basic Functionality Tests**: 10-20 tests verifying core requirements work correctly
2. **Edge Case Tests**: 5-10 tests for boundary conditions (empty inputs, maximum values, edge states)
3. **Error Handling Tests**: 5-10 tests ensuring invalid inputs throw proper exceptions or return error codes
4. **Design Pattern Tests**: 3-5 tests specifically verifying correct pattern application
5. **Performance Tests** (advanced projects): Tests ensuring algorithmic complexity requirements met

### Example Test Scenarios (Project 1: Task Manager)

1. **Test**: `AddTaskSuccessfully`  
   **Purpose**: Verifies tasks can be added to the manager  
   **Example**: Given empty task list, when adding task "Write C++ code", expect task list size is 1

2. **Test**: `RemoveTaskById`  
   **Purpose**: Verifies tasks can be removed by identifier  
   **Example**: Given task list with 3 tasks, when removing task ID 2, expect task list size is 2 and ID 2 not found

3. **Test**: `MarkTaskComplete`  
   **Purpose**: Verifies task completion status can be toggled  
   **Example**: Given incomplete task, when marking complete, expect task status is COMPLETE

4. **Test**: `SaveAndLoadTasks`  
   **Purpose**: Verifies persistence to file works correctly  
   **Example**: Given 5 tasks, when saving to file and reloading, expect 5 tasks with same data

5. **Test**: `FilterTasksByPriority`  
   **Purpose**: Verifies Strategy pattern for filtering works  
   **Example**: Given tasks with various priorities, when filtering HIGH priority, expect only high priority tasks returned

### Running Tests

```bash
# Standard test execution for all projects
cd assignments/[project-name]/build
cmake ..
make
ctest --output-on-failure
# OR
./tests/run_tests
```

**Success Criteria**: ALL tests must pass (100% passage) before code review is available.

---

## Reference Materials *(mandatory)*

**Primary Resources**:

- [cppreference.com](https://en.cppreference.com/) - Comprehensive C++ language and library reference
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) - Best practices for modern C++
- [ISO C++ Standards](https://isocpp.org/) - Official C++ standards and proposals
- [Design Patterns: Elements of Reusable Object-Oriented Software](https://en.wikipedia.org/wiki/Design_Patterns) - Gang of Four patterns
- [Refactoring Guru - Design Patterns](https://refactoring.guru/design-patterns) - Pattern explanations with examples

**Supplementary Resources**:

- [Effective Modern C++](https://www.oreilly.com/library/view/effective-modern-c/9781491908419/) by Scott Meyers - Modern C++ best practices
- [C++ Concurrency in Action](https://www.manning.com/books/c-plus-plus-concurrency-in-action-second-edition) by Anthony Williams - Threading and concurrency
- [Clean Code](https://www.oreilly.com/library/view/clean-code-a/9780136083238/) by Robert C. Martin - Code quality principles
- [The Pragmatic Programmer](https://pragprog.com/titles/tpp20/the-pragmatic-programmer-20th-anniversary-edition/) - Software craftsmanship
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) - Industry coding standards

**Design Pattern Resources by Project**:

- **Strategy Pattern**: [Refactoring Guru - Strategy](https://refactoring.guru/design-patterns/strategy/cpp)
- **Factory Pattern**: [Refactoring Guru - Factory Method](https://refactoring.guru/design-patterns/factory-method/cpp)
- **Observer Pattern**: [Refactoring Guru - Observer](https://refactoring.guru/design-patterns/observer/cpp)
- **Command Pattern**: [Refactoring Guru - Command](https://refactoring.guru/design-patterns/command/cpp)
- **Decorator Pattern**: [Refactoring Guru - Decorator](https://refactoring.guru/design-patterns/decorator/cpp)
- **Visitor Pattern**: [Refactoring Guru - Visitor](https://refactoring.guru/design-patterns/visitor/cpp)
- **Template Method**: [Refactoring Guru - Template Method](https://refactoring.guru/design-patterns/template-method/cpp)

**SOLID Principles Resources**:

- [Single Responsibility Principle](https://en.wikipedia.org/wiki/Single-responsibility_principle)
- [Open/Closed Principle](https://en.wikipedia.org/wiki/Open%E2%80%93closed_principle)
- [Liskov Substitution Principle](https://en.wikipedia.org/wiki/Liskov_substitution_principle)
- [Interface Segregation Principle](https://en.wikipedia.org/wiki/Interface_segregation_principle)
- [Dependency Inversion Principle](https://en.wikipedia.org/wiki/Dependency_inversion_principle)

**Audio Processing Resources** (for audio projects):

- [The Audio Programming Book](http://www.audiosynth.com/) - DSP and audio fundamentals
- [Designing Audio Effect Plugins in C++](https://www.willpirkle.com/about/) by Will Pirkle
- [WAV File Format Specification](http://soundfile.sapp.org/doc/WaveFormat/)

**Debugging & Tools**:

- **Debuggers**: GDB (Linux), LLDB (macOS), Visual Studio Debugger (Windows)
- **Memory Analysis**: Valgrind (Linux/macOS), AddressSanitizer (all platforms)
- **Static Analysis**: clang-tidy, cppcheck, PVS-Studio
- **Build Systems**: CMake documentation, CTest for testing
- **Profilers**: perf (Linux), Instruments (macOS), Visual Studio Profiler (Windows)
- **Compiler Flags**: `-Wall -Wextra -Wpedantic -Werror` for strict compilation

---

## Conceptual Hints *(optional—use sparingly)*

### General Architectural Thinking

- **Consider**: What responsibilities does each class have? Are they clearly separated?
- **Remember**: RAII ensures resources are automatically cleaned up—use it for files, memory, locks
- **Think about**: Can this design accommodate future changes without modifying existing code? (Open/Closed Principle)
- **Ask yourself**: Would another developer understand this code in 6 months? (Clean Code)

### Design Pattern Selection

- **When to use Strategy**: Multiple algorithms/behaviors that can be swapped at runtime
- **When to use Factory**: Creating objects without specifying exact class, centralizing object creation logic
- **When to use Observer**: One-to-many dependency where observers need automatic notification of state changes
- **When to use Command**: Encapsulating actions as objects, supporting undo/redo, queuing operations
- **When to use Decorator**: Adding responsibilities to objects dynamically without modifying their class

### Performance Considerations

- **Profile before optimizing**: Measure where time is actually spent
- **Consider algorithmic complexity**: O(n²) vs O(n log n) matters at scale
- **Use move semantics**: Avoid unnecessary copies for large objects (C++11+)
- **Reserve container capacity**: Pre-allocate vectors/strings when size is known
- **Minimize heap allocations**: Stack allocation is faster; use RAII

### Concurrency Principles

- **Prefer RAII for locks**: `std::lock_guard` and `std::unique_lock` prevent deadlocks
- **Minimize lock scope**: Hold locks only as long as necessary
- **Consider lock-free alternatives**: Atomic operations for simple cases
- **Avoid shared mutable state**: Immutability simplifies concurrent code

**Note**: These hints guide thinking about architecture and trade-offs, NOT specific implementation details.

---

## Code Review Criteria *(mandatory)*

Once all tests pass, request code review. Your code will be evaluated on:

### Correctness (Prerequisite)
- [ ] All tests pass (100% passage required)
- [ ] No memory leaks (verified with valgrind/AddressSanitizer)
- [ ] No undefined behavior or data races
- [ ] Handles all error conditions gracefully

### Design Pattern Application
- [ ] Correct pattern chosen for the problem domain
- [ ] Pattern implemented accurately (not a superficial imitation)
- [ ] Pattern provides clear benefits (flexibility, maintainability, extensibility)
- [ ] Pattern not over-engineered (appropriate complexity for problem)

### SOLID Principles Adherence
- [ ] **Single Responsibility**: Each class has one reason to change
- [ ] **Open/Closed**: Open for extension, closed for modification
- [ ] **Liskov Substitution**: Derived classes substitutable for base classes
- [ ] **Interface Segregation**: Clients not forced to depend on unused interfaces
- [ ] **Dependency Inversion**: Depend on abstractions, not concretions

### Clean Code Practices
- [ ] Clear, descriptive naming (variables, functions, classes convey intent)
- [ ] Functions are small and focused (do one thing well)
- [ ] No code duplication (DRY principle)
- [ ] Comments explain WHY, not WHAT (code is self-documenting)
- [ ] Consistent formatting and style

### Modern C++ Idioms
- [ ] Appropriate use of const correctness
- [ ] Smart pointers for dynamic memory (unique_ptr, shared_ptr)
- [ ] Move semantics for efficiency (C++11+)
- [ ] Range-based for loops where appropriate
- [ ] STL algorithms preferred over hand-written loops
- [ ] Modern C++ features used idiomatically (not just for novelty)

### Code Quality
- [ ] Separation of concerns (interface vs implementation)
- [ ] Proper encapsulation (appropriate access specifiers)
- [ ] Resource management follows RAII
- [ ] Error handling is robust and consistent
- [ ] No raw pointers for ownership (use smart pointers)

### Performance (project-dependent)
- [ ] Algorithmic complexity meets requirements
- [ ] No unnecessary copies or allocations
- [ ] Efficient data structure choices
- [ ] Appropriate use of const references
- [ ] Move semantics applied where beneficial

### Documentation & Maintainability
- [ ] Public interfaces documented (Doxygen-style comments)
- [ ] Complex algorithms explained
- [ ] README explains how to build and use the project
- [ ] Dependencies clearly stated
- [ ] Build system properly configured (CMake)

---

## Submission Checklist

Before requesting code review for ANY project:

- [ ] All tests pass without modification to test code
- [ ] Code compiles without warnings (`-Wall -Wextra -Wpedantic`)
- [ ] No memory leaks detected (valgrind/AddressSanitizer)
- [ ] No undefined behavior or data races
- [ ] Code formatted consistently (consider clang-format)
- [ ] Design pattern correctly identified and implemented
- [ ] SOLID principles applied where relevant
- [ ] Clean code practices followed (DRY, meaningful names, small functions)
- [ ] Modern C++ features used appropriately
- [ ] Public interfaces documented
- [ ] README includes build instructions and usage examples
- [ ] You understand every line of code and can explain design decisions
- [ ] You can articulate which SOLID principles you applied and why
- [ ] You can explain the design pattern choice and its benefits

---

## Getting Help

**Permitted Questions**:

- "Can you clarify what [requirement] means?"
- "What C++ feature should I research to handle [concept]?"
- "Which design pattern would be most appropriate for [scenario]?"
- "Can you explain [C++ language feature or standard library component]?"
- "How does [SOLID principle] apply to this situation?"
- "Where can I find documentation about [topic]?"
- "What's the difference between [pattern A] and [pattern B]?"
- "Why is the test expecting [specific behavior]?"
- "What debugging strategy would you recommend for [issue]?"

**Prohibited Questions**:

- "Can you show me how to implement this?"
- "What algorithm should I use?"
- "Can you give me code for [part of solution]?"
- "Can you show me a similar example?" [if it would reveal the solution]
- "Can you write the [class/function] for me?"
- "What's the answer to this problem?"

**Remember**: The assistant acts as a mentor, not a solution provider. Guidance on concepts, patterns, and principles is provided freely. Implementation code is never provided. Struggle builds expertise—embrace the challenge of discovering solutions independently. This is how you become a master craftsperson, not just a code copier.

````
