# Implementation Plan: Practical C++ Projects Curriculum

**Branch**: `001-practical-projects` | **Date**: 2025-10-29 | **Spec**: [spec.md](spec.md)
**Input**: Feature specification from `/specs/001-practical-projects/spec.md`

**Note**: This plan outlines the development of 30 practical C++ learning projects with comprehensive test suites, build systems, and assignment materials following constitutional principles.

## Summary

Develop a complete curriculum of 30 practical C++ projects organized into 4 difficulty tiers (Beginner, Intermediate, Advanced, Expert). Each project teaches software engineering principles (SOLID, Clean Code, DRY) and design patterns through building genuinely useful applications (productivity tools, audio processors, system utilities). Every project includes pre-written comprehensive test suites using Google Test, CMake build configuration, boilerplate code structure, and curated reference materials—all while maintaining zero solution disclosure per constitutional requirements.

**Technical Approach**: Create standardized directory structure for all 30 projects under `assignments/` directory. Each project follows consistent pattern: assignment specification (README.md), pre-written test suite (tests/), CMake build system, header/source boilerplate with TODO markers, and reference materials. Projects progress from basic C++ (syntax, STL) through OOP, templates, concurrency, to expert-level systems programming.

## Technical Context

**Language/Version**: C++17 (primary), with C++20 features in advanced projects (coroutines, concepts, ranges)

**Primary Dependencies**: 
- Google Test 1.14.0+ (testing framework)
- CMake 3.20+ (build system)
- Standard C++ library (no external dependencies for most projects to focus on fundamentals)
- Platform-specific: PortAudio or RtAudio for audio projects (Tier 2-3)
- Optional: ASIO for networking projects, nlohmann/json for JSON parsing examples

**Storage**: 
- File-based persistence for most projects (JSON, CSV, binary files)
- No external databases (teaches file I/O and serialization fundamentals)
- Advanced projects may implement simple in-memory "database" structures

**Testing**: 
- Google Test (primary framework for all 30 projects)
- CTest integration for test discovery and execution
- Valgrind/AddressSanitizer for memory leak detection
- Test categories: basic functionality, edge cases, error handling, design pattern verification, performance tests

**Target Platform**: 
- Cross-platform (Windows, Linux, macOS)
- C++17 standard compliance for broad compiler support
- Command-line applications (no GUI frameworks to minimize dependencies)
- Audio projects require platform audio APIs (WASAPI/CoreAudio/ALSA or PortAudio abstraction)

**Project Type**: 
- Educational curriculum structure (not single application)
- 30 independent learning modules under `assignments/` directory
- Each module is self-contained with standardized structure
- Progressive dependency chain (later projects assume earlier concepts mastered)

**Performance Goals**: 
- Test execution: All tests for a single project complete within 10 seconds
- Compilation: Single project builds within 30 seconds on modern hardware
- Audio projects: Real-time processing with <10ms latency where applicable
- Focus on algorithmic efficiency teaching (O(n) vs O(n²) understanding)

**Constraints**: 
- Zero solution disclosure (constitutional requirement)
- All tests pre-written before assignment delivery
- Minimal external dependencies (focus on C++ fundamentals)
- Cross-platform compatibility required
- Projects must compile with `-Wall -Wextra -Wpedantic` without warnings
- Memory-safe: No leaks detectable by Valgrind

**Scale/Scope**: 
- 30 total projects across 4 difficulty tiers
- Estimated 6-12 months for complete curriculum completion
- Each project: 50-500 lines of solution code (varies by complexity)
- Test suites: 10-30 tests per project
- Total curriculum: ~5,000-10,000 lines of student-written code

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

**Teaching-First Philosophy**: 
- [x] Assignment specification focuses on learning objectives, NOT solution hints
  - ✅ All 30 projects have explicit learning objectives defined
  - ✅ Focus on WHAT to build and WHY, not HOW
  - ✅ Reference materials guide discovery without revealing implementation
  
- [x] Reference materials guide discovery without revealing solutions
  - ✅ cppreference.com links for C++ features
  - ✅ Design pattern documentation (conceptual, not code)
  - ✅ SOLID principle resources
  - ✅ Debugging strategies and tool recommendations
  
- [x] Clarification pathways defined for conceptual questions only
  - ✅ "Getting Help" section clearly delineates permitted vs prohibited questions
  - ✅ Emphasis on conceptual understanding, not implementation assistance

**Test-Driven Learning**:
- [x] Comprehensive test suite pre-written using C++ testing framework (Google Test, Catch2, etc.)
  - ✅ Google Test 1.14.0+ selected as primary framework
  - ✅ Each project requires 10-30 tests covering all categories
  
- [x] Tests cover core functionality, edge cases, and error conditions
  - ✅ Test categories defined: basic functionality, edge cases, error handling, pattern verification, performance
  - ✅ Example test scenarios documented per project
  
- [x] Test execution automated with clear pass/fail reporting
  - ✅ CMake + CTest integration for automated test discovery
  - ✅ Google Test provides clear pass/fail output with diagnostics
  
- [x] 100% test passage required before review eligibility
  - ✅ Explicitly stated in success criteria across all project specifications

**Zero Solution Disclosure**:
- [x] No implementation code provided in assignment materials
  - ✅ Only interface declarations (headers) with function signatures
  - ✅ Source files contain TODO markers, no logic
  
- [x] Boilerplate/setup code clearly separated from solution code
  - ✅ CMakeLists.txt for build configuration (boilerplate)
  - ✅ Header declarations showing interfaces (boilerplate)
  - ✅ Empty/stubbed implementations with TODO comments (student implements)
  - ✅ Complete test suites (pre-written, not student code)
  
- [x] Examples (if any) are conceptual demonstrations, NOT assignment solutions
  - ✅ Test examples show expected behavior, not implementation approach
  - ✅ Conceptual hints reference patterns/principles, not algorithms
  
- [x] Assistant responses verified to avoid revealing algorithms or logic
  - ✅ "Getting Help" guidelines explicitly prohibit implementation assistance
  - ✅ Constitutional mandate enforces zero solution disclosure

**Progressive Mastery Path**:
- [x] Assignment positioned correctly in curriculum difficulty progression
  - ✅ Tier 1 (Projects 1-5): Beginner - Basic C++ syntax and simple patterns
  - ✅ Tier 2 (Projects 6-15): Intermediate - OOP, templates, RAII, complex patterns
  - ✅ Tier 3 (Projects 16-25): Advanced - Advanced C++, performance, system architecture
  - ✅ Tier 4 (Projects 26-30): Expert - System programming, concurrency, advanced patterns
  
- [x] Prerequisites clearly identified and documented
  - ✅ Tier 1 has no prerequisites (foundational)
  - ✅ Each tier builds on previous tier concepts
  - ✅ Individual projects document specific prerequisite skills
  
- [x] Learning objectives explicitly stated
  - ✅ Six overarching curriculum objectives defined
  - ✅ Each project has specific learning goals (patterns, principles, C++ features)
  
- [x] Real-world relevance articulated
  - ✅ Every project builds something genuinely useful
  - ✅ Productivity tools, audio processors, system utilities
  - ✅ Skills directly applicable to professional software development

**Code Review Gate**:
- [x] Review protocol documented: test passage verification → quality review → feedback iteration
  - ✅ Submission checklist requires 100% test passage before review request
  - ✅ Review process: verify tests pass → evaluate quality → provide feedback → iterate
  
- [x] Review criteria defined: code clarity, design patterns, C++ idioms, performance, maintainability
  - ✅ Comprehensive review criteria in spec covering:
    - Design pattern application
    - SOLID principles adherence
    - Clean code practices
    - Modern C++ idioms
    - Performance considerations
    - Documentation and maintainability
  
- [x] No refactored solution code in feedback—only improvement descriptions
  - ✅ Constitutional mandate enforces description-only feedback
  - ✅ Review criteria focus on identifying issues, not providing fixes

**Self-Reliance & Research Skills**:
- [x] Reference materials include cppreference.com, C++ documentation, relevant textbook chapters
  - ✅ Primary resources section comprehensive
  - ✅ cppreference.com, C++ Core Guidelines, ISO C++ standards
  - ✅ Design pattern documentation (Refactoring Guru, GoF)
  - ✅ Book recommendations for deep learning
  
- [x] Debugging strategies suggested in assignment guidance
  - ✅ Tools: GDB, LLDB, Valgrind, AddressSanitizer
  - ✅ Compiler flags for diagnostics
  - ✅ Static analysis tools recommended
  
- [x] Algorithmic thinking prompts included where appropriate
  - ✅ Conceptual hints section guides high-level thinking
  - ✅ Pattern selection guidance (when to use which pattern)
  - ✅ Performance consideration prompts

**Constitution Check Result**: ✅ **ALL GATES PASSED** - Proceed to Phase 0

## Project Structure

### Documentation (this feature)

```text
specs/001-practical-projects/
├── plan.md                     # This file (/speckit.plan command output)
├── spec.md                     # Feature specification
├── research.md                 # Phase 0 output (design decisions, best practices)
├── data-model.md              # Phase 1 output (project structure schema)
├── quickstart.md              # Phase 1 output (getting started guide)
├── contracts/                 # Phase 1 output (project templates)
│   ├── assignment-template.md # Template for assignment README
│   ├── cmake-template.txt     # Template for CMakeLists.txt
│   └── test-template.cpp      # Template for test files
└── checklists/
    └── requirements.md        # Validation checklist (complete)
```

### Source Code (repository root)

**Structure Decision**: Educational curriculum with 30 independent learning modules. Each module under `assignments/` follows standardized structure for consistency and ease of navigation.

```text
cpp_mastery/
├── assignments/                              # All 30 learning projects
│   ├── 001-task-manager/                    # Project 1: CLI Task Manager (Strategy)
│   │   ├── README.md                         # Assignment specification
│   │   ├── CMakeLists.txt                    # Build configuration
│   │   ├── .gitignore                        # Ignore build artifacts
│   │   ├── include/                          # Header files
│   │   │   ├── task.h                        # Task entity interface
│   │   │   ├── task_manager.h                # Manager interface
│   │   │   └── filter_strategy.h             # Strategy pattern interfaces
│   │   ├── src/                              # Source files (student implements)
│   │   │   ├── main.cpp                      # Entry point with TODO markers
│   │   │   ├── task.cpp                      # Task implementation stub
│   │   │   ├── task_manager.cpp              # Manager implementation stub
│   │   │   └── filter_strategy.cpp           # Strategy implementations stub
│   │   ├── tests/                            # Pre-written test suite
│   │   │   ├── CMakeLists.txt                # Test build configuration
│   │   │   └── test_task_manager.cpp         # Comprehensive tests
│   │   └── references/                       # Learning resources
│   │       └── resources.md                  # Links to documentation
│   │
│   ├── 002-text-processor/                  # Project 2: Text File Processor (Factory)
│   │   ├── README.md
│   │   ├── CMakeLists.txt
│   │   ├── include/
│   │   │   ├── processor.h
│   │   │   └── processor_factory.h
│   │   ├── src/
│   │   │   └── ... (similar structure)
│   │   ├── tests/
│   │   │   └── test_processor.cpp
│   │   └── references/
│   │
│   ├── 003-config-parser/                   # Project 3: Config File Parser (Builder)
│   ├── 004-file-organizer/                  # Project 4: File Organizer (Command)
│   ├── 005-csv-analyzer/                    # Project 5: CSV Data Analyzer (Template Method)
│   │
│   ├── 006-wav-file-io/                     # Project 6: WAV Reader/Writer (Adapter)
│   ├── 007-audio-effects/                   # Project 7: Audio Effects Processor (Decorator)
│   ├── 008-event-logger/                    # Project 8: Event-Driven Logger (Observer + Singleton)
│   ├── 009-custom-string/                   # Project 9: Custom String Class (Iterator)
│   ├── 010-task-queue/                      # Project 10: Thread-Safe Task Queue (Producer-Consumer)
│   ├── 011-file-watcher/                    # Project 11: File System Watcher (Observer)
│   ├── 012-http-server/                     # Project 12: Simple HTTP Server (Chain of Responsibility)
│   ├── 013-serialization/                   # Project 13: Serialization Framework (Visitor)
│   ├── 014-plugin-system/                   # Project 14: Plugin System (Abstract Factory)
│   ├── 015-memory-pool/                     # Project 15: Memory Pool Allocator (Object Pool)
│   │
│   ├── 016-synthesizer/                     # Project 16: Audio Synthesizer (State + Composite)
│   ├── 017-build-system/                    # Project 17: Build System Generator (Interpreter)
│   ├── 018-query-engine/                    # Project 18: Database Query Engine (Interpreter + Composite)
│   ├── 019-audio-stream/                    # Project 19: Real-Time Audio Processor (Bridge)
│   ├── 020-web-scraper/                     # Project 20: Concurrent Web Scraper (Flyweight)
│   ├── 021-smart-pointers/                  # Project 21: Smart Pointer Library (Proxy)
│   ├── 022-math-library/                    # Project 22: Expression Template Math (Template Metaprogramming)
│   ├── 023-code-formatter/                  # Project 23: Code Formatter/Linter (Visitor)
│   ├── 024-process-monitor/                 # Project 24: Process Monitor (Mediator)
│   ├── 025-lockfree-ds/                     # Project 25: Lock-Free Data Structures
│   │
│   ├── 026-custom-allocator/                # Project 26: Custom Memory Allocator (Strategy + Decorator)
│   ├── 027-async-io/                        # Project 27: Coroutine-Based Async I/O (C++20 Coroutines)
│   ├── 028-game-engine/                     # Project 28: Mini Game Engine (Multiple Patterns)
│   ├── 029-distributed-tasks/               # Project 29: Distributed Task System (Master-Worker)
│   └── 030-jit-compiler/                    # Project 30: JIT Compiler (Interpreter + Visitor + Builder)
│
├── docs/                                     # General documentation
│   └── creating-assignments.md              # Guide for creating new assignments
│
├── .specify/                                # SpecKit configuration
│   ├── memory/
│   │   └── constitution.md                   # Governing principles
│   └── templates/                           # Document templates
│
└── README.md                                # Repository overview
```

### Standardized Project Structure (Applied to All 30 Projects)

Each project directory follows this consistent pattern:

```text
assignments/NNN-project-name/
├── README.md                    # Assignment specification
│   ├── Learning Objectives      # What student will master
│   ├── Problem Statement        # What to build
│   ├── Requirements (REQ-NNN)   # Functional requirements
│   ├── Test Suite Overview      # Test categories and examples
│   ├── Reference Materials      # cppreference links, resources
│   ├── Conceptual Hints         # High-level guidance (no solutions)
│   ├── Code Review Criteria     # Quality evaluation checklist
│   ├── Submission Checklist     # Pre-review verification
│   └── Getting Help             # Permitted vs prohibited questions
│
├── CMakeLists.txt              # Root build configuration
│   ├── Project setup            # C++ standard, compiler flags
│   ├── Source library           # Compile student code
│   ├── Executable (if needed)   # Main program
│   └── Test subdirectory        # Enable testing, add tests/
│
├── .gitignore                  # Ignore build/, *.o, executables
│
├── include/                    # Header files (interfaces only)
│   ├── entity.h                # Data structures/classes (declarations)
│   ├── manager.h               # Core logic classes (interfaces)
│   └── patterns.h              # Design pattern interfaces (abstract bases)
│   # All headers have:
│   # - Doxygen-style documentation
│   # - Function/method declarations
│   # - NO implementations (except inline trivial getters)
│
├── src/                        # Source files (student implements these)
│   ├── main.cpp                # Entry point with TODO markers
│   ├── entity.cpp              # Implementation stubs with TODOs
│   ├── manager.cpp             # Implementation stubs with TODOs
│   └── patterns.cpp            # Pattern implementation stubs with TODOs
│   # All source files have:
│   # - Include guards
│   # - TODO comments indicating what to implement
│   # - Empty function bodies OR stub returns
│   # - NO solution logic
│
├── tests/                      # Pre-written comprehensive test suite
│   ├── CMakeLists.txt          # Test build configuration
│   │   ├── Fetch Google Test   # Using FetchContent
│   │   ├── Test executable     # Link against student library
│   │   └── Test discovery      # gtest_discover_tests()
│   │
│   └── test_project.cpp        # Main test file
│       ├── Basic functionality tests (10-15 tests)
│       ├── Edge case tests (5-10 tests)
│       ├── Error handling tests (5-10 tests)
│       ├── Design pattern tests (3-5 tests)
│       └── Performance tests (0-5 tests, if applicable)
│   # Tests use Google Test framework
│   # Tests MUST fail with boilerplate code (RED state)
│   # Tests MUST pass with correct implementation (GREEN state)
│
└── references/                 # Learning resources
    └── resources.md            # Curated reference materials
        ├── C++ Language Features (cppreference links)
        ├── Design Patterns (Refactoring Guru links)
        ├── SOLID Principles (documentation)
        ├── Debugging Tools (GDB, Valgrind guides)
        └── Conceptual Background (NO solutions)
```

### Key Design Decisions

1. **Standardization**: All 30 projects follow identical structure for predictability
2. **Self-Containment**: Each project is independent with its own build system
3. **Progressive Prerequisites**: Later projects assume mastery of earlier concepts but remain buildable independently
4. **Zero Coupling**: No shared libraries between projects (except standard library) to avoid hidden dependencies
5. **CMake Everywhere**: Consistent build system across all platforms
6. **Google Test Standard**: Single testing framework for consistency
7. **Boilerplate vs Solution**: Clear separation via TODO markers and empty implementations

````
