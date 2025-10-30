# Data Model: Practical C++ Projects Curriculum Structure

**Phase**: 1 - Design & Contracts  
**Date**: 2025-10-29  
**Purpose**: Define standardized project templates, directory structures, and reusable components for all 30 learning modules

---

## Overview

This document defines the "data model" for the curriculum—not database schemas, but the standardized structure, templates, and components that all 30 projects will follow. Consistency across projects enables students to focus on learning C++ concepts rather than navigating different project organizations.

---

## 1. Project Entity Model

Each of the 30 projects is an **independent learning module** with the following properties:

### Project Properties

| Property | Type | Description | Example |
|----------|------|-------------|---------|
| `project_id` | Integer (1-30) | Unique sequential identifier | `1` |
| `short_name` | String | Kebab-case descriptive name | `task-manager` |
| `full_name` | String | Human-readable title | `Command-Line Task Manager` |
| `difficulty_tier` | Enum (1-4) | Beginner/Intermediate/Advanced/Expert | `1` (Beginner) |
| `design_pattern` | String | Primary pattern taught | `Strategy Pattern` |
| `learning_objectives` | List[String] | Skills to master | `["File I/O", "Class design", "Strategy pattern"]` |
| `prerequisites` | List[Integer] | Required prior projects | `[]` (Tier 1), `[1,2,3]` (later tiers) |
| `estimated_time` | String | Completion time range | `2-3 days` |
| `utility_category` | Enum | Project type | `ProductivityTool` |
| `external_deps` | List[String] | Non-STL dependencies | `[]` or `["PortAudio"]` |
| `test_count_min` | Integer | Minimum required tests | `15` |
| `solid_principles` | List[String] | Which SOLID principles emphasized | `["SRP", "OCP"]` |

### Project Directory Naming Convention

```
Format: {project_id:03d}-{short_name}
Examples:
  001-task-manager
  015-memory-pool
  030-jit-compiler
```

---

## 2. Directory Structure Schema

### Root Level Structure

```
assignments/
└── {NNN}-{short-name}/           # Project root directory
    ├── README.md                  # Assignment specification
    ├── CMakeLists.txt            # Root build configuration
    ├── .gitignore                # Ignore build artifacts
    ├── include/                  # Public header files (interfaces)
    │   └── *.h
    ├── src/                      # Source files (student implements)
    │   └── *.cpp
    ├── tests/                    # Pre-written test suite
    │   ├── CMakeLists.txt
    │   └── test_*.cpp
    └── references/               # Learning resources
        └── resources.md
```

### File Type Categories

**Specification Files**: (Provided complete)
- `README.md`: Full assignment spec with requirements, objectives, review criteria
- `references/resources.md`: Curated learning materials

**Build System Files**: (Provided complete)
- `CMakeLists.txt` (root): Build configuration for project
- `tests/CMakeLists.txt`: Test build configuration
- `.gitignore`: Standard C++ ignore patterns

**Interface Files**: (Provided complete, NO implementations)
- `include/*.h`: Header files with declarations, documentation, NO definitions

**Implementation Files**: (Provided with TODO stubs)
- `src/*.cpp`: Source files with function stubs and TODO markers
- `src/main.cpp`: Entry point with minimal boilerplate

**Test Files**: (Provided complete)
- `tests/test_*.cpp`: Comprehensive test suites using Google Test

---

## 3. CMakeLists.txt Template Structure

### Root CMakeLists.txt Schema

```cmake
cmake_minimum_required(VERSION 3.20)
project({ProjectName} VERSION 1.0 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD {17|20})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings (strict)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
elseif(MSVC)
    add_compile_options(/W4 /WX)
endif()

# Project library (student code)
add_library({project}_lib
    {list of src/*.cpp files}
)

target_include_directories({project}_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Platform-specific dependencies (if needed)
if(WIN32)
    # Windows-specific linking
elseif(APPLE)
    # macOS-specific linking
else()
    # Linux-specific linking
endif()

# Main executable (if project has CLI entry point)
add_executable({project}_main src/main.cpp)
target_link_libraries({project}_main {project}_lib)

# Enable testing
enable_testing()
add_subdirectory(tests)
```

### Test CMakeLists.txt Schema

```cmake
# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

# For Windows: Prevent overriding parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(run_tests
    test_{project}.cpp
)

target_link_libraries(run_tests
    {project}_lib
    gtest_main
)

# Discover tests
include(GoogleTest)
gtest_discover_tests(run_tests)
```

---

## 4. Header File Template Structure

### Standard Header Pattern

```cpp
#ifndef {PROJECT}__{FILENAME}_H
#define {PROJECT}__{FILENAME}_H

#include <vector>
#include <string>
// ... other includes

namespace {project_namespace} {

/**
 * @brief Brief description of class/function purpose
 * 
 * Detailed description explaining what this entity does,
 * its role in the design pattern, and how it fits the requirements.
 * 
 * @note This implements [Design Pattern] pattern
 * @note Adheres to [SOLID Principle]
 */
class ClassName {
public:
    /**
     * @brief Constructor with clear parameter documentation
     * 
     * @param param1 Description of parameter
     * @throws std::invalid_argument if validation fails
     */
    explicit ClassName(Type param1);
    
    /**
     * @brief Method performing specific operation
     * 
     * @param input Description
     * @return Description of return value
     * 
     * @complexity O(n) where n is...
     * 
     * Example usage:
     * @code
     * ClassName obj(value);
     * auto result = obj.methodName(input);
     * @endcode
     */
    ReturnType methodName(const Type& input);
    
    // More methods...
    
private:
    Type member_variable_;  // Brief description
};

}  // namespace {project_namespace}

#endif  // {PROJECT}__{FILENAME}_H
```

### Key Header Patterns

**Include Guards**: Traditional `#ifndef` pattern (compatible with all compilers)
- Format: `PROJECT__FILENAME_H`
- Example: `TASKMANAGER__TASK_H`

**Documentation**: Doxygen-style comments for all public members
- `@brief`: One-line summary
- `@param`: Parameter descriptions
- `@return`: Return value description
- `@throws`: Exceptions thrown
- `@complexity`: Algorithmic complexity (advanced projects)
- `@code/@endcode`: Usage examples

**Namespaces**: Each project has own namespace
- Format: `project_namespace`
- Example: `task_manager`, `audio_effects`

**Access Specifiers**: Explicit order
1. `public` (interface first)
2. `protected` (if inheritance involved)
3. `private` (implementation details last)

---

## 5. Source File Template Structure

### Standard Implementation Pattern

```cpp
#include "{header_file}.h"

#include <algorithm>
#include <stdexcept>
// ... other includes

namespace {project_namespace} {

ClassName::ClassName(Type param1) 
    : member_variable_(param1) {
    // TODO: Implement constructor
    // Consider: What validation is needed?
    // Consider: What invariants must be established?
    throw std::runtime_error("Not implemented: ClassName constructor");
}

ReturnType ClassName::methodName(const Type& input) {
    // TODO: Implement methodName according to REQ-XXX
    // Research: What algorithm/data structure is appropriate?
    // Hint: Review references/resources.md for guidance
    // 
    // Consider the following:
    // - Edge cases: What if input is empty/invalid?
    // - Error handling: What exceptions should be thrown?
    // - Efficiency: What is the algorithmic complexity?
    // - Design: How does this support the [Pattern] pattern?
    
    throw std::runtime_error("Not implemented: methodName");
}

// ... more implementations with TODO markers

}  // namespace {project_namespace}
```

### Implementation File Patterns

**TODO Markers**: Every function has clear TODO indicating what to implement
- Links to specific requirements (REQ-XXX)
- References to resources.md for learning materials
- Guiding questions (NOT answers)

**Stub Returns**: Functions throw `std::runtime_error("Not implemented")`
- Ensures tests fail initially (RED state)
- Students must remove stub and implement real logic

**No Solution Logic**: Implementation files contain ZERO working code
- Only structure, includes, and TODO markers
- No algorithms, no data structure operations, no business logic

---

## 6. Test File Structure Schema

### Test Organization Pattern

```cpp
#include <gtest/gtest.h>
#include "{project_header}.h"

using namespace {project_namespace};

// ============================================================================
// Basic Functionality Tests
// ============================================================================

TEST(ProjectTest, BasicRequirement_REQ001) {
    // Arrange: Set up test data
    // Act: Perform operation
    // Assert: Verify expected outcome
    
    EXPECT_EQ(expected, actual);
}

TEST(ProjectTest, BasicRequirement_REQ002) {
    // Test another core requirement
}

// ... 10-15 basic functionality tests

// ============================================================================
// Edge Case Tests
// ============================================================================

TEST(ProjectTest, EdgeCase_EmptyInput) {
    // Test behavior with empty input
}

TEST(ProjectTest, EdgeCase_MaximumSize) {
    // Test boundary condition
}

// ... 5-10 edge case tests

// ============================================================================
// Error Handling Tests
// ============================================================================

TEST(ProjectTest, ErrorHandling_InvalidInput) {
    EXPECT_THROW({
        // Code that should throw exception
    }, std::invalid_argument);
}

// ... 5-10 error handling tests

// ============================================================================
// Design Pattern Verification Tests
// ============================================================================

TEST(ProjectTest, PatternVerification_StrategySwappable) {
    // Verify pattern correctly implemented
    // Example: Can strategies be swapped at runtime?
}

// ... 3-5 pattern verification tests

// ============================================================================
// Performance Tests (Advanced Projects Only)
// ============================================================================

TEST(ProjectTest, Performance_AlgorithmicComplexity) {
    // Verify algorithmic efficiency
}

// ... 0-5 performance tests (if applicable)
```

### Test File Patterns

**Test Organization**: Tests grouped by category with clear headers
1. Basic Functionality (10-15 tests)
2. Edge Cases (5-10 tests)
3. Error Handling (5-10 tests)
4. Design Pattern Verification (3-5 tests)
5. Performance (0-5 tests, advanced projects only)

**Test Naming**: `TEST(TestSuiteName, TestName)`
- Suite name: Project or class being tested
- Test name: Descriptive, includes category and requirement ID if applicable
- Example: `TEST(TaskManagerTest, BasicRequirement_REQ001_AddTask)`

**Arrange-Act-Assert**: Standard test structure
- **Arrange**: Set up test data, create objects
- **Act**: Perform the operation being tested
- **Assert**: Verify expected outcome using EXPECT_*/ASSERT_* macros

**Google Test Macros**:
- `EXPECT_EQ(expected, actual)`: Equality check
- `EXPECT_NE(a, b)`: Inequality check
- `EXPECT_TRUE(condition)`: Boolean true
- `EXPECT_FALSE(condition)`: Boolean false
- `EXPECT_THROW(statement, exception)`: Exception verification
- `EXPECT_NO_THROW(statement)`: No exception verification
- `ASSERT_*`: Fatal failure (stops test)
- `EXPECT_*`: Non-fatal failure (continues test)

---

## 7. README.md Assignment Specification Structure

### Standard README Sections

```markdown
# Project {ID}: {Full Name}

**Design Pattern**: {Pattern Name}  
**Difficulty**: {Beginner/Intermediate/Advanced/Expert}  
**Estimated Time**: {Time Range}  
**Prerequisites**: {List or "None"}

## Learning Objectives

By completing this project, you will:

1. [Specific C++ feature to master]
2. [Design pattern to understand and apply]
3. [SOLID principle to implement]
4. [Software engineering practice to develop]

**Real-World Relevance**: [How this applies professionally]

---

## Problem Statement

[Clear description of what to build - WHAT, not HOW]

### Requirements

- **REQ-001**: [Specific functional requirement]
- **REQ-002**: [Another requirement]
- ... (10-15 requirements total)

---

## Build & Run

```bash
mkdir build && cd build
cmake ..
make
./tests/run_tests          # Run tests
./{project}_main            # Run main program (if applicable)
```

---

## Test Suite

**Test Framework**: Google Test  
**Test Count**: {Minimum number} tests

### Test Categories:
1. **Basic Functionality**: {X} tests verifying core requirements
2. **Edge Cases**: {Y} tests for boundary conditions
3. **Error Handling**: {Z} tests for invalid inputs
4. **Pattern Verification**: {N} tests confirming pattern implementation

### Example Test Scenarios:
1. [Representative test with input/output example]
2. [Another test scenario]

**Success Criteria**: ALL tests must pass (100%)

---

## Design Guidance

### {Design Pattern} Pattern

**When to use**: [High-level guidance on pattern applicability]

**Key components**:
- [Component 1]: [Role in pattern]
- [Component 2]: [Role in pattern]

**Benefits**: [Why this pattern helps solve the problem]

---

## SOLID Principles Focus

This project emphasizes:
- **{Principle 1}**: [How it applies]
- **{Principle 2}**: [How it applies]

---

## Reference Materials

**C++ Features**:
- [cppreference.com link]
- [C++ Core Guideline]

**Design Patterns**:
- [Refactoring Guru - Pattern link]

**Debugging Tools**:
- [Tool recommendations]

---

## Code Review Criteria

- [ ] All tests pass (100%)
- [ ] {Pattern} correctly implemented
- [ ] {SOLID principles} applied
- [ ] Clean code practices followed
- [ ] Modern C++ idioms used
- [ ] Memory safe (no leaks)

---

## Getting Help

**Permitted Questions**:
- Clarifications on requirements
- C++ feature explanations
- Pattern concept discussions

**Prohibited Questions**:
- Implementation requests
- Algorithm reveals
- Solution code requests

Remember: Struggle builds mastery!
```

---

## 8. resources.md Learning Materials Structure

### Standard Resources Format

```markdown
# Learning Resources: {Project Name}

## C++ Language Features

### {Feature 1 (e.g., Classes and Objects)}
- [cppreference - Classes](https://en.cppreference.com/w/cpp/language/classes)
- [C++ Core Guidelines - C.1: Organize related data](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-org)

### {Feature 2}
- [Relevant link]

## Design Patterns

### {Pattern Name}
- [Refactoring Guru - {Pattern}](https://refactoring.guru/design-patterns/{pattern}/cpp)
- **Intent**: [One-line pattern purpose]
- **When to use**: [Applicability guidance]
- **Structure**: [High-level component overview—NO code]

## SOLID Principles

### {Principle 1}
- [Wikipedia link]
- **Definition**: [Brief explanation]
- **In this project**: [How it applies—NO implementation hints]

## Debugging Strategies

### Common Issues
- **Compilation errors**: [Where to look, what to check]
- **Segmentation faults**: [How to use debugger]
- **Memory leaks**: [How to run Valgrind/ASan]

### Tools
- **Debugger**: `gdb ./program` - [Link to GDB tutorial]
- **Valgrind**: `valgrind --leak-check=full ./program`
- **Compiler warnings**: Always compile with `-Wall -Wextra -Wpedantic`

## Additional Reading

- [Textbook chapter or article]
- [Video tutorial - conceptual, not solution]

---

**Note**: These resources guide your discovery. Research, experiment, and learn through doing!
```

---

## 9. .gitignore Template

### Standard Ignore Patterns

```gitignore
# Build artifacts
build/
cmake-build-*/
CMakeCache.txt
CMakeFiles/
cmake_install.cmake
Makefile
*.cmake

# Compiled binaries
*.exe
*.out
*.app
*.dll
*.so
*.dylib

# Object files
*.o
*.obj

# Test outputs
Testing/
CTestTestfile.cmake

# IDE files
.vscode/
.idea/
*.swp
*.swo
*~

# Platform-specific
.DS_Store
Thumbs.db
```

---

## 10. Project Metadata Schema

For tooling and automation, maintain project registry:

### projects.json Structure

```json
{
  "projects": [
    {
      "id": 1,
      "short_name": "task-manager",
      "full_name": "Command-Line Task Manager",
      "difficulty_tier": 1,
      "pattern": "Strategy",
      "solid_principles": ["SRP", "OCP"],
      "prerequisites": [],
      "estimated_hours": 16,
      "test_count_min": 15,
      "external_deps": [],
      "utility_category": "ProductivityTool"
    },
    {
      "id": 6,
      "short_name": "wav-file-io",
      "full_name": "WAV Audio File Reader/Writer",
      "difficulty_tier": 2,
      "pattern": "Adapter",
      "solid_principles": ["ISP", "SRP"],
      "prerequisites": [1, 2, 3, 4, 5],
      "estimated_hours": 40,
      "test_count_min": 20,
      "external_deps": ["PortAudio"],
      "utility_category": "AudioProcessing"
    }
    // ... all 30 projects
  ]
}
```

---

## Summary

All 30 projects follow these standardized structures:

1. **Directory Layout**: Consistent across all projects
2. **CMake Build**: Root + Test CMakeLists templates
3. **Headers**: Interface declarations with Doxygen docs
4. **Sources**: TODO stubs with guiding questions
5. **Tests**: Comprehensive suite with 15-30 tests per project
6. **README**: Assignment spec with objectives, requirements, review criteria
7. **Resources**: Curated learning materials

**Benefits of Standardization**:
- Students learn structure once, apply everywhere
- Focus shifts from "where is this?" to "how do I implement this?"
- Automated tooling can validate all projects
- Consistent quality across curriculum
- Easy to add new projects following template

Next: Generate contract templates in `contracts/` directory.
