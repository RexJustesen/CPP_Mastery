# Research: Practical C++ Projects Curriculum

**Phase**: 0 - Outline & Research  
**Date**: 2025-10-29  
**Purpose**: Resolve technical decisions, establish best practices, and document design rationales for curriculum development

---

## Executive Summary

This research document consolidates decisions for creating 30 practical C++ learning projects that teach software engineering principles through hands-on development. All projects use Google Test for testing, CMake for builds, and follow constitutional zero-solution-disclosure principles. The curriculum progresses from beginner (basic C++ syntax) to expert (system programming, concurrency, advanced patterns).

---

## 1. Testing Framework Selection

### Decision: **Google Test 1.14.0+**

### Rationale:
- **Industry Standard**: Most widely used C++ testing framework in production environments
- **Rich Assertions**: Comprehensive assertion macros (EXPECT_*, ASSERT_*, custom matchers)
- **Death Tests**: Can test that code properly crashes/throws exceptions
- **Parameterized Tests**: Easy to test multiple inputs with same logic
- **Test Fixtures**: Clean setup/teardown for complex test scenarios
- **CMake Integration**: Excellent integration via `FetchContent` and `gtest_discover_tests()`
- **Cross-Platform**: Works seamlessly on Windows, Linux, macOS
- **Documentation**: Extensive official documentation and community resources

### Alternatives Considered:
- **Catch2**: Excellent framework but header-only design can slow compilation; less familiar to students who will work in industry where GTest dominates
- **Boost.Test**: Requires Boost dependency which contradicts "minimal dependencies" goal
- **doctest**: Fast compilation but less feature-rich; newer with smaller community
- **CppUnit**: Older, more verbose, less actively maintained

### Implementation Details:
```cmake
# In tests/CMakeLists.txt
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests test_module.cpp)
target_link_libraries(run_tests project_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)
```

---

## 2. Build System Selection

### Decision: **CMake 3.20+**

### Rationale:
- **Industry Standard**: De facto build system for C++ projects
- **Cross-Platform**: Single CMakeLists.txt works on Windows/Linux/macOS
- **Modern Features**: C++17/20 support, target-based dependency management
- **Testing Integration**: Built-in CTest for test discovery and execution
- **IDE Support**: Supported by Visual Studio, CLion, VS Code CMake Tools
- **Learning Value**: Essential skill for professional C++ development
- **FetchContent**: Modern dependency management for Google Test

### Alternatives Considered:
- **Make**: Platform-specific, requires separate Makefiles for each OS
- **Ninja**: Low-level, typically used as CMake backend rather than directly
- **Meson**: Newer, simpler but less industry adoption
- **Bazel**: Over-engineered for educational projects, steep learning curve

### Standard CMakeLists.txt Template:
```cmake
cmake_minimum_required(VERSION 3.20)
project(ProjectName VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
elseif(MSVC)
    add_compile_options(/W4 /WX)
endif()

# Source library
add_library(project_lib
    src/file1.cpp
    src/file2.cpp
)

target_include_directories(project_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Main executable (optional for some projects)
add_executable(project_main src/main.cpp)
target_link_libraries(project_main project_lib)

# Enable testing
enable_testing()
add_subdirectory(tests)
```

---

## 3. C++ Standard Version

### Decision: **C++17 (primary), C++20 (advanced projects)**

### Rationale:
- **C++17 as Baseline**:
  - Widely supported by all major compilers (GCC 7+, Clang 5+, MSVC 2017+)
  - Essential modern features: structured bindings, std::optional, std::variant, if-init statements
  - `<filesystem>` header for file operations (useful for many projects)
  - Fold expressions for template metaprogramming
  - Inline variables
  
- **C++20 for Advanced Projects** (26-30):
  - Concepts for template constraints (Project 22: Expression Templates)
  - Ranges library for functional-style algorithms
  - Coroutines (Project 27: Async I/O Framework)
  - Modules (optional, not required due to compiler support variability)

### Alternatives Considered:
- **C++11/14**: Too limiting; missing many modern features students need
- **C++20 throughout**: Insufficient compiler support; would limit accessibility
- **C++23**: Too new; minimal compiler support as of 2025

---

## 4. Design Pattern Teaching Progression

### Decision: **Incremental complexity with practical application**

### Rationale:
Progressive introduction ensures students understand simpler patterns before tackling complex ones. Each pattern introduced in a practical context where its benefits are obvious.

### Progression Strategy:

**Tier 1 (Beginner) - Foundational Patterns**:
1. **Strategy Pattern** (Project 1): Most intuitive pattern—encapsulate algorithms
2. **Factory Pattern** (Project 2): Simple object creation abstraction
3. **Builder Pattern** (Project 3): Step-by-step object construction
4. **Command Pattern** (Project 4): Action encapsulation, enables undo/redo
5. **Template Method** (Project 5): Algorithm skeleton with customizable steps

**Tier 2 (Intermediate) - Structural & Behavioral**:
6. **Adapter** (Project 6): Interface conversion—natural for file I/O
7. **Decorator** (Project 7): Dynamic behavior addition—perfect for audio effects chaining
8. **Observer + Singleton** (Project 8): Event notification pattern
9. **Iterator** (Project 9): Collection traversal abstraction
10. **Producer-Consumer** (Project 10): Concurrent pattern introduction
11. **Chain of Responsibility** (Project 12): Request handling pipeline
12. **Visitor** (Project 13): Operations on object structures
13. **Abstract Factory** (Project 14): Family of related objects
14. **Object Pool** (Project 15): Resource reuse optimization

**Tier 3 (Advanced) - Complex Integration**:
15. **State + Composite** (Project 16): Multiple patterns working together
16. **Interpreter** (Projects 17, 18): Language/DSL implementation
17. **Bridge** (Project 19): Abstraction-implementation separation
18. **Flyweight** (Project 20): Memory optimization through sharing
19. **Proxy** (Project 21): Controlled access and smart pointers
20. **Mediator** (Project 24): Component coordination

**Tier 4 (Expert) - Architectural Patterns**:
21. **Multiple Pattern Integration** (Projects 26-30): Real-world architecture combining patterns

---

## 5. SOLID Principles Integration

### Decision: **Progressive teaching with explicit pattern-principle connections**

### Teaching Strategy:

**Single Responsibility Principle (SRP)** - Introduced in Tier 1:
- Project 1: Separate Task, TaskManager, FilterStrategy classes
- Project 3: Separate Parser, Validator, Builder classes
- Reinforced throughout all projects

**Open/Closed Principle (OCP)** - Introduced in Tier 1:
- Project 1: Strategy pattern enables new filters without modifying TaskManager
- Project 2: Factory pattern allows new processors without changing factory interface
- Explicit focus in projects 6-10

**Liskov Substitution Principle (LSP)** - Introduced in Tier 2:
- Project 7: Derived effect classes must work wherever base Effect is expected
- Project 9: Iterator implementations must honor iterator contract
- Emphasized in inheritance-heavy projects (7-15)

**Interface Segregation Principle (ISP)** - Introduced in Tier 2:
- Project 11: Separate IFileWatcher, IChangeHandler interfaces
- Project 14: Plugin interfaces segregated by capability
- Focus on projects with multiple interfaces (11-15)

**Dependency Inversion Principle (DIP)** - Introduced in Tier 2-3:
- Project 10: TaskQueue depends on abstract Task interface, not concrete tasks
- Project 14: Application depends on plugin interface, not concrete plugins
- Advanced application in Tier 3 projects (16-25)

### Implementation in Code Reviews:
Each project's code review criteria explicitly asks:
- Which SOLID principles does this design apply?
- How does the pattern choice support SOLID principles?
- Where could SOLID principles improve the design?

---

## 6. Clean Code & DRY Enforcement

### Decision: **Explicit code quality gates in test suites and review criteria**

### Strategies:

**DRY (Don't Repeat Yourself)**:
- Test suites include checks for code duplication
- Review criteria specifically evaluate function/class reuse
- Projects designed to have natural abstraction opportunities
- Example: Project 7 (Audio Effects) - if reverb and delay both have similar DSP setup, factor out common code

**Clean Code Practices**:
1. **Meaningful Names**: Variables/functions named by intention
   - Bad: `int d; // elapsed time in days`
   - Good: `int elapsedTimeInDays;`

2. **Small Functions**: Each function does one thing
   - Target: <20 lines per function
   - Enforced through review, not automated tests

3. **No Magic Numbers**: Named constants instead
   - Bad: `if (status == 3)`
   - Good: `if (status == STATUS_COMPLETE)`

4. **Comments Explain WHY, Not WHAT**:
   - Code should be self-documenting
   - Comments clarify non-obvious decisions

5. **Consistent Formatting**:
   - Recommend clang-format for automation
   - Not enforced (student choice) but encouraged

**Implementation**:
- Submission checklist includes "Code formatted consistently"
- Review criteria section: "Style & Maintainability"
- No automated enforcement (learning trust and discipline)

---

## 7. Memory Safety & Leak Detection

### Decision: **Valgrind (Linux/macOS) + AddressSanitizer (cross-platform)**

### Rationale:

**Valgrind**:
- Gold standard for memory leak detection
- Detects: memory leaks, invalid reads/writes, uninitialized values
- Usage: `valgrind --leak-check=full ./program`
- Linux/macOS only

**AddressSanitizer** (ASan):
- Compiler-integrated (GCC, Clang, MSVC)
- Faster than Valgrind
- Detects: buffer overflows, use-after-free, memory leaks
- Cross-platform including Windows
- Usage: Compile with `-fsanitize=address`

**Strategy**:
- Submission checklist requires: "No memory leaks detected by valgrind or equivalent"
- Students choose tool based on platform
- Advanced projects (smart pointers, allocators) specifically tested for leak-free operation
- RAII principles taught early to prevent leaks by design

---

## 8. Cross-Platform Compatibility

### Decision: **Write-once, compile-anywhere with conditional compilation where necessary**

### Strategy:

**Core Projects (1-25)**: Pure standard library, fully cross-platform

**Audio Projects (6, 7, 16, 19)**: Require platform-specific audio I/O
- **Option 1**: Use PortAudio library (cross-platform abstraction)
- **Option 2**: Provide platform-specific implementations:
  - Windows: WASAPI
  - macOS: CoreAudio
  - Linux: ALSA/PulseAudio
- **Decision**: PortAudio for simplicity; focus on DSP algorithms, not I/O plumbing

**Networking Projects (12, 20, 29)**: Socket programming
- Standard POSIX sockets (Linux/macOS)
- Winsock (Windows)
- CMake conditional compilation:
  ```cmake
  if(WIN32)
      target_link_libraries(project_lib ws2_32)
  endif()
  ```

**Filesystem Projects (4, 11)**:
- C++17 `<filesystem>` standard library (cross-platform)
- No platform-specific code needed

### Compiler Support Matrix:
- **GCC 9+**: Full C++17, most C++20
- **Clang 10+**: Full C++17, most C++20
- **MSVC 2019+**: Full C++17, partial C++20
- Students must have one of these compilers

---

## 9. Dependency Management

### Decision: **Minimal external dependencies; CMake FetchContent for testing**

### Rationale:
- **Learning Focus**: Students should master C++ fundamentals, not navigate dependency managers
- **Portability**: Fewer dependencies = easier cross-platform builds
- **Transparency**: Students see all code, not hidden in libraries

### Dependency Strategy:

**Zero Dependencies** (Projects 1-5, 9-11, 21-25):
- Pure standard library
- Teaches fundamentals without external crutches

**Minimal Dependencies** (Projects 6-8, 15-20):
- PortAudio (audio I/O abstraction) - only for audio projects
- Small, well-documented libraries
- Integrated via CMake FetchContent or provided as single-header includes

**Testing Dependencies** (All Projects):
- Google Test via CMake FetchContent
- Automatically downloaded during build
- No manual installation required

**Networking (Projects 12, 20, 29)**:
- Standard sockets (POSIX/Winsock)
- No external networking libraries (teaching low-level networking)

**JSON Parsing** (Optional examples):
- `nlohmann/json` (single-header) for demonstration purposes only
- Students may implement their own parsers (encouraged)

---

## 10. Performance Testing Strategy

### Decision: **Algorithmic complexity verification, not micro-benchmarking**

### Rationale:
- **Educational Goal**: Teach Big-O analysis, not nanosecond optimization
- **Platform Variability**: Micro-benchmarks vary wildly across hardware
- **Focus**: Correct algorithm choice, not premature optimization

### Performance Test Categories:

**Tier 1-2 Projects**: No performance tests
- Focus on correctness and design

**Tier 3 Projects** (16-25): Algorithmic complexity tests
- Example: Project 18 (Query Engine)
  - Test linear search vs binary search performance
  - Verify O(log n) for indexed lookups
  - Compare O(n) vs O(n²) for different algorithms

**Tier 4 Projects** (26-30): Performance-critical requirements
- Project 19 (Real-Time Audio): <10ms latency requirement
- Project 25 (Lock-Free): Concurrent throughput benchmarks
- Project 27 (Async I/O): Measure concurrent operation handling

### Implementation:
```cpp
// Example algorithmic complexity test
TEST(PerformanceTest, BinarySearchFasterThanLinear) {
    std::vector<int> data = generateSortedData(100000);
    
    auto linear_start = std::chrono::high_resolution_clock::now();
    linearSearch(data, target);
    auto linear_duration = std::chrono::high_resolution_clock::now() - linear_start;
    
    auto binary_start = std::chrono::high_resolution_clock::now();
    binarySearch(data, target);
    auto binary_duration = std::chrono::high_resolution_clock::now() - binary_start;
    
    // Binary should be significantly faster (not just "faster" due to noise)
    EXPECT_LT(binary_duration, linear_duration / 10);
}
```

---

## 11. Documentation Standards

### Decision: **Doxygen-style comments for public interfaces, README for usage**

### Standards:

**Header Files** - Public API Documentation:
```cpp
/**
 * @brief Add a new task to the task manager
 * 
 * @param description Text description of the task
 * @param priority Priority level (HIGH, MEDIUM, LOW)
 * @return TaskId Unique identifier for the created task
 * 
 * @throws std::invalid_argument if description is empty
 * 
 * Example:
 * @code
 * TaskManager manager;
 * auto id = manager.addTask("Write documentation", Priority::HIGH);
 * @endcode
 */
TaskId addTask(const std::string& description, Priority priority);
```

**README.md** - Assignment Documentation:
- Learning Objectives
- Problem Statement
- Requirements (REQ-001, REQ-002, etc.)
- Build Instructions
- Test Execution
- Reference Materials
- Code Review Criteria

**resources.md** - Learning Resources:
- cppreference.com links
- Design pattern documentation
- SOLID principles articles
- Debugging guides

**Source Files** - Implementation Comments:
- Explain WHY, not WHAT (code should be self-documenting)
- Document complex algorithms
- Clarify non-obvious design decisions
- NO comments stating the obvious

---

## 12. Curriculum Pacing & Time Estimates

### Decision: **Flexible self-paced with suggested timeframes**

### Estimated Completion Times:

**Tier 1 (Projects 1-5)**: 2-4 weeks
- Project 1-2: 2-3 days each (learning tooling, basic C++)
- Project 3-5: 3-5 days each (solidifying fundamentals)

**Tier 2 (Projects 6-15)**: 3-5 months
- Projects 6-10: 5-7 days each (OOP, templates, RAII)
- Projects 11-15: 7-10 days each (complex patterns, concurrency)

**Tier 3 (Projects 16-25)**: 4-6 months
- Projects 16-20: 1-2 weeks each (advanced architecture)
- Projects 21-25: 2-3 weeks each (template metaprogramming, performance)

**Tier 4 (Projects 26-30)**: 2-3 months
- Projects 26-30: 2-4 weeks each (expert systems, integration)

**Total Estimated Time**: 6-12 months for full curriculum

**Pacing Recommendations**:
- **Full-Time Study**: 2-3 projects per week (Tier 1-2), 1 per week (Tier 3-4)
- **Part-Time Study**: 1 project per week (Tier 1-2), 1 per 2 weeks (Tier 3-4)
- **Self-Directed**: Complete at own pace; no deadlines

---

## 13. Project Utility Validation

### Decision: **Every project must solve a real problem or demonstrate production use case**

### Utility Assessment:

**Productivity Tools** (1-5, 17, 23):
- ✅ Task managers used daily by developers
- ✅ Text processors automate repetitive file operations
- ✅ Build systems core to software development
- ✅ Code formatters enforce team standards

**Audio Processing** (6-8, 16, 19):
- ✅ WAV I/O foundational for audio software
- ✅ Effects processors used in music production
- ✅ Synthesizers teach DSP and real-time systems
- ✅ Real-time audio central to game audio, VoIP, music apps

**System Utilities** (4, 11, 24):
- ✅ File organizers automate digital housekeeping
- ✅ File watchers power IDEs, build tools, deployment systems
- ✅ Process monitors essential for system administration

**Development Tools** (12, 13, 14, 20, 26, 27):
- ✅ HTTP servers teach networking fundamentals
- ✅ Serialization required for data persistence/transmission
- ✅ Plugin systems enable extensible applications
- ✅ Web scrapers automate data collection
- ✅ Custom allocators optimize performance-critical code
- ✅ Async I/O scales network applications

**Data Structures & Algorithms** (9, 10, 15, 18, 21, 22, 25):
- ✅ Custom containers teach implementation details
- ✅ Task queues power background processing
- ✅ Memory pools optimize allocation-heavy code
- ✅ Query engines teach database internals
- ✅ Smart pointers essential for modern C++
- ✅ Expression templates optimize math libraries
- ✅ Lock-free structures maximize concurrency

**Expert Systems** (28, 29, 30):
- ✅ Game engines teach complex architecture
- ✅ Distributed systems core to scalable applications
- ✅ JIT compilers power scripting languages, VMs

**Validation**: Every project either:
1. Solves a problem students encounter in real development, OR
2. Teaches fundamentals used in production systems

---

## 14. Constitutional Compliance Strategy

### Decision: **Three-layer enforcement: specification review, test validation, assistant guidelines**

### Layer 1: Specification Review
- Every assignment README reviewed for solution disclosure
- Conceptual hints validated: do they guide without revealing?
- Reference materials checked: discovery-enabling, not solution-providing

### Layer 2: Test Validation
- Tests written FIRST, before any student engagement
- Tests MUST fail with boilerplate (RED state verified)
- Reference solution implemented privately to verify tests pass (GREEN state)
- Reference solution NEVER shared with students

### Layer 3: Assistant Guidelines
- "Getting Help" section in every README clarifies permitted/prohibited questions
- AI assistant trained on constitutional principles
- Zero solution disclosure enforced in all interactions
- Focus on teaching concepts, not providing code

### Monitoring:
- Code reviews verify NO implementation hints given
- Student questions logged and reviewed for pattern of solution-seeking
- Assistant responses audited for constitutional compliance

---

## 15. Tooling & Development Environment

### Decision: **Minimal required tooling with optional advanced tools**

### Required Tools (All Students):
1. **C++ Compiler**: GCC 9+, Clang 10+, or MSVC 2019+
2. **CMake**: 3.20 or later
3. **Git**: Version control (assignments in separate branches)
4. **Text Editor/IDE**: Student choice (VS Code, CLion, Visual Studio, Vim, etc.)

### Recommended Tools:
1. **Debugger**: GDB (Linux), LLDB (macOS), Visual Studio Debugger (Windows)
2. **Memory Analysis**: Valgrind (Linux/macOS) or AddressSanitizer (all platforms)
3. **Static Analysis**: clang-tidy, cppcheck
4. **Formatter**: clang-format (optional but encouraged)

### IDE Support:
- **VS Code**: CMake Tools extension for build integration
- **CLion**: Native CMake support
- **Visual Studio**: CMake project support
- **Command Line**: Works perfectly fine; not IDE-dependent

### Platform Support:
- **Windows**: MSVC 2019+ or MinGW-w64 (GCC)
- **Linux**: GCC or Clang via package manager
- **macOS**: Clang via Xcode Command Line Tools

---

## Summary of Key Decisions

| Decision Area | Choice | Rationale |
|---------------|--------|-----------|
| Testing Framework | Google Test 1.14.0+ | Industry standard, rich features, excellent CMake integration |
| Build System | CMake 3.20+ | Cross-platform, industry standard, CTest integration |
| C++ Standard | C++17 (primary), C++20 (advanced) | Wide support, modern features, gradual adoption |
| Design Patterns | 15+ patterns, progressive introduction | Start simple (Strategy), build to complex (multiple pattern integration) |
| SOLID Principles | All 5, taught incrementally across tiers | SRP in Tier 1, full integration by Tier 4 |
| Dependencies | Minimal (STL + Google Test + PortAudio) | Focus on fundamentals, reduce complexity |
| Memory Safety | Valgrind + AddressSanitizer | Detect leaks, enforce RAII principles |
| Platform Support | Cross-platform (Windows/Linux/macOS) | Standard C++17, conditional compilation where needed |
| Performance Testing | Algorithmic complexity, not micro-benchmarks | Teach Big-O, avoid platform variability |
| Documentation | Doxygen comments + README + resources.md | API docs + usage + learning materials |
| Pacing | Self-paced, 6-12 months estimated | Flexible learning, no artificial deadlines |
| Utility | Every project solves real problem | Practical value drives engagement |
| Constitutional Compliance | Three-layer enforcement | Specification, tests, assistant guidelines |

---

## Next Steps (Phase 1)

With research complete, proceed to Phase 1:
1. **data-model.md**: Define project templates (assignment structure, CMake templates, test templates)
2. **contracts/**: Create reusable templates for all 30 projects
3. **quickstart.md**: Write getting-started guide for curriculum
4. **Update agent context**: Integrate C++ learning knowledge into assistant

All technical questions resolved. Ready for design phase.
