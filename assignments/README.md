# C++ Mastery: Practical Projects Curriculum

Welcome to the C++ Mastery practical projects curriculum! This directory contains 30 hands-on C++ learning projects organized into 4 difficulty tiers.

## 🎯 Curriculum Overview

This curriculum teaches C++ software engineering through building **genuinely useful applications**. Each project:
- Teaches design patterns in practical contexts
- Implements SOLID principles
- Emphasizes clean code and DRY principles
- Includes comprehensive pre-written test suites
- Builds something actually useful for productivity or development

## 📚 Learning Philosophy

**Test-Driven Learning**: All tests are written first. You implement code to make tests pass.

**Zero Solution Disclosure**: You receive specifications, tests, and boilerplate—never implementations. Learning happens through research, experimentation, and problem-solving.

**Progressive Mastery**: Each tier builds on previous knowledge. Complete projects in order within each tier.

## 🗂️ Curriculum Structure

### Tier 1: Foundations (Beginner) - Projects 1-5

**Focus**: Basic C++ syntax, standard library, simple design patterns

1. **001-task-manager** - Command-Line Task Manager (Strategy Pattern)
   - Skills: File I/O, vectors, class design, Strategy pattern
   - SOLID: Single Responsibility, Open/Closed
   - Time: 2-3 days

2. **002-text-processor** - Text File Processor (Factory Pattern)
   - Skills: File I/O, string manipulation, polymorphism
   - SOLID: Open/Closed Principle
   - Time: 2-3 days

3. **003-config-parser** - Configuration File Parser (Builder Pattern)
   - Skills: Parsing, data structures, error handling
   - SOLID: Single Responsibility
   - Time: 3-4 days

4. **004-file-organizer** - Simple File Organizer (Command Pattern)
   - Skills: Filesystem operations, undo/redo, command queue
   - SOLID: Single Responsibility, Open/Closed
   - Time: 3-4 days

5. **005-csv-analyzer** - CSV Data Analyzer (Template Method Pattern)
   - Skills: File parsing, data analysis, algorithm design
   - SOLID: Open/Closed, Single Responsibility
   - Time: 3-4 days

**Estimated Time**: 2-4 weeks

### Tier 2: Intermediate Engineering (Intermediate) - Projects 6-15

**Focus**: OOP, templates, RAII, complex patterns, concurrency basics

6. **006-wav-file-io** - WAV Audio File Reader/Writer (Adapter Pattern)
7. **007-audio-effects** - Audio Effects Processor (Decorator Pattern)
8. **008-event-logger** - Event-Driven Logger System (Observer + Singleton)
9. **009-custom-string** - Custom String Class with Iterators (Iterator Pattern)
10. **010-task-queue** - Thread-Safe Task Queue (Producer-Consumer Pattern)
11. **011-file-watcher** - File System Watcher (Observer Pattern)
12. **012-http-server** - Simple HTTP Server (Chain of Responsibility)
13. **013-serialization** - Serialization Framework (Visitor Pattern)
14. **014-plugin-system** - Plugin System with Dynamic Loading (Abstract Factory)
15. **015-memory-pool** - Memory Pool Allocator (Object Pool Pattern)

**Estimated Time**: 3-5 months

### Tier 3: Advanced Architecture (Advanced) - Projects 16-25

**Focus**: Advanced C++, performance optimization, complex system architecture

16. **016-synthesizer** - Audio Synthesizer Engine (State + Composite)
17. **017-build-system** - Build System Generator (Interpreter)
18. **018-query-engine** - Database Query Engine (Interpreter + Composite)
19. **019-audio-stream** - Real-Time Audio Stream Processor (Bridge)
20. **020-web-scraper** - Concurrent Web Scraper (Flyweight)
21. **021-smart-pointers** - Smart Pointer Library (Proxy)
22. **022-math-library** - Expression Template Math Library (Template Metaprogramming)
23. **023-code-formatter** - Code Formatter/Linter (Visitor)
24. **024-process-monitor** - Process Monitor & Resource Tracker (Mediator)
25. **025-lockfree-ds** - Lock-Free Data Structures

**Estimated Time**: 4-6 months

### Tier 4: Expert Systems (Expert) - Projects 26-30

**Focus**: System programming, advanced concurrency, architectural integration

26. **026-custom-allocator** - Custom Memory Allocator with Debugging (Strategy + Decorator)
27. **027-async-io** - Coroutine-Based Async I/O Framework (C++20 Coroutines)
28. **028-game-engine** - Mini Game Engine (Multiple Patterns Integration)
29. **029-distributed-tasks** - Distributed Task Processing System (Master-Worker)
30. **030-jit-compiler** - JIT Compiler for Simple Language (Interpreter + multiple patterns)

**Estimated Time**: 2-3 months

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler**: GCC 7+, Clang 5+, or MSVC 2019+
- **CMake**: 3.20 or later
- **Git**: For version control (recommended)
- **Text Editor/IDE**: VS Code, CLion, Visual Studio, or your choice

### Setup Instructions

1. **Verify your compiler**:
   ```bash
   g++ --version    # GCC
   clang++ --version  # Clang
   cl.exe           # MSVC
   ```

2. **Verify CMake**:
   ```bash
   cmake --version  # Should be 3.20+
   ```

3. **Start with Project 1**:
   ```bash
   cd assignments/001-task-manager
   ```

4. **Read the full Quick Start Guide**:
   See `specs/001-practical-projects/quickstart.md` for detailed walkthrough

## 📖 How to Use Each Project

Every project follows the same structure:

```
NNN-project-name/
├── README.md              # Assignment specification (READ THIS FIRST)
├── CMakeLists.txt         # Build configuration
├── include/               # Header files (interfaces provided)
├── src/                   # Source files (you implement these)
├── tests/                 # Pre-written comprehensive test suite
│   ├── CMakeLists.txt
│   └── test_*.cpp
└── references/            # Learning resources
    └── resources.md
```

### Workflow for Each Project

1. **Read README.md**: Understand requirements, learning objectives, and success criteria
2. **Review tests**: Study `tests/test_*.cpp` to see what behavior is expected
3. **Study boilerplate**: Examine header files and TODO markers in source files
4. **Research concepts**: Use `references/resources.md` for learning materials
5. **Implement code**: Write code to pass all tests
6. **Build and test**:
   ```bash
   cmake -B build
   cmake --build build
   cd build && ctest --output-on-failure
   ```
7. **Refactor**: Once tests pass, improve code quality
8. **Self-review**: Use submission checklist in README.md

## 🧪 The Test-Driven Learning Cycle

```
READ → RED → GREEN → REFACTOR → REVIEW
  ↑                                  ↓
  └──────────────────────────────────┘
```

1. **READ**: Understand requirements and study tests
2. **RED**: Verify tests fail (they define what you must build)
3. **GREEN**: Implement code to pass all tests
4. **REFACTOR**: Improve code quality while keeping tests green
5. **REVIEW**: Self-review using checklist, then move to next project

## 📏 Code Quality Standards

Every project requires:

- ✅ **100% test passage** (all tests must pass)
- ✅ **No compiler warnings** (`-Wall -Wextra -Wpedantic`)
- ✅ **No memory leaks** (verified with Valgrind or AddressSanitizer)
- ✅ **Design pattern correctly applied**
- ✅ **SOLID principles followed**
- ✅ **Clean code practices** (meaningful names, small functions, DRY)
- ✅ **Modern C++ idioms** (RAII, smart pointers, const correctness)

## 🎓 Learning Resources

### General Resources

- [C++ Reference](https://en.cppreference.com/) - Comprehensive C++ documentation
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) - Best practices
- [Refactoring Guru](https://refactoring.guru/design-patterns) - Design pattern explanations

### Project-Specific Resources

Each project includes curated resources in `references/resources.md`:
- Relevant C++ features
- Design pattern documentation
- SOLID principles guidance
- Debugging strategies
- Tool recommendations

## 🆘 Getting Help

### Permitted Questions

You can ask for:
- Clarification on requirements
- Explanation of C++ features
- Conceptual understanding of patterns
- Debugging strategies
- Tool usage guidance

### Prohibited Questions

Do NOT ask for:
- Implementation code
- Algorithm solutions
- "How do I implement X?"
- Code examples that reveal the solution

**Remember**: The AI assistant is a mentor, not a solution provider. Learning happens through struggle and discovery.

## 📊 Tracking Your Progress

Create a personal learning log to track:
- Project completion dates
- Time spent per project
- Key learnings and insights
- Challenges overcome
- Patterns mastered

## 🎉 Milestones

Celebrate your achievements:

- **Tier 1 Complete**: Foundation established! 🎉
- **Tier 2 Complete**: Intermediate skills unlocked! 🚀
- **Tier 3 Complete**: Advanced C++ mastery! 💪
- **Tier 4 Complete**: Expert level achieved! 🏆

## 📜 Constitutional Principles

This curriculum follows six governing principles:

1. **Teaching-First Philosophy**: Focus on deep learning, not just completion
2. **Test-Driven Learning**: Tests define success; 100% passage required
3. **Zero Solution Disclosure**: You must write all implementation code
4. **Progressive Mastery**: Each project builds on previous knowledge
5. **Code Review Gate**: Quality matters as much as correctness
6. **Self-Reliance**: Research and problem-solving are part of learning

See `.specify/memory/constitution.md` for full details.

## 🛠️ Tools and Environment

### Required Tools

- C++ Compiler (GCC/Clang/MSVC)
- CMake 3.20+
- Git (recommended)

### Recommended Tools

- **Debugger**: GDB, LLDB, or Visual Studio Debugger
- **Memory Analysis**: Valgrind or AddressSanitizer
- **Static Analysis**: clang-tidy, cppcheck
- **Formatter**: clang-format (optional)

### IDE Recommendations

- **VS Code**: Install C/C++ and CMake Tools extensions
- **CLion**: Native CMake support
- **Visual Studio**: Full C++ environment
- **Command Line**: Works perfectly fine!

## 📞 Support

If you encounter issues:

1. **Read the error message carefully** - Most errors are self-explanatory
2. **Check the project README** - Often the answer is there
3. **Consult resources.md** - Curated learning materials
4. **Research the concept** - Use cppreference.com, Stack Overflow
5. **Ask conceptual questions** - Focus on understanding, not implementation

## 🚦 Project Status Legend

Projects you'll see in this directory:

- ✅ **Complete**: Specification, tests, and boilerplate ready
- 🚧 **In Progress**: Currently being developed
- ⏳ **Planned**: Not yet started

## 📅 Estimated Timeline

**Full Curriculum Completion**: 6-12 months at comfortable pace

- **Fast Track** (full-time study): 4-6 months
- **Regular Pace** (part-time study): 6-12 months
- **Relaxed Pace** (casual learning): 12-18 months

**Take your time. Mastery cannot be rushed.**

## 🎯 What You'll Build

By completing this curriculum, you will have built:

- Task managers and productivity tools
- Audio processing systems and synthesizers
- Build systems and development tools
- Network servers and web scrapers
- Custom memory allocators and smart pointers
- Concurrency primitives and lock-free structures
- Game engines and distributed systems
- A JIT compiler for a custom language

**These aren't toy examples—they're real, useful applications that demonstrate professional software engineering.**

---

## Ready to Begin?

Start with **Project 001: Command-Line Task Manager**

```bash
cd 001-task-manager
cat README.md  # Read the assignment
```

**Welcome to your C++ mastery journey!** 🚀

*Last Updated: 2025-10-29*
