# Creating Learning Assignments

**Guide for developing new C++ learning modules**

This document explains how to create new assignments for the C++ Mastery repository following constitutional principles.

## Constitutional Requirements

Every assignment MUST adhere to these principles:

1. **Teaching-First**: Guide discovery, never provide solutions
2. **Test-Driven**: Pre-written comprehensive test suite
3. **Zero Solution Disclosure**: Boilerplate only, no implementation code
4. **Progressive Path**: Clear prerequisites and difficulty level
5. **Code Review Gate**: Quality criteria defined
6. **Self-Reliance**: References to documentation and resources

## Assignment Development Workflow

### Phase 1: Specification

Create the assignment specification that defines:

- **Learning Objectives**: What the learner will master
- **Problem Statement**: Clear description of what to build
- **Requirements**: Functional specifications (REQ-001, REQ-002, etc.)
- **Input/Output Specifications**: Expected behavior
- **Real-World Relevance**: Why this matters professionally

**Template Location**: `.specify/templates/spec-template.md`

**Constitution Check**:
- [ ] No solution hints or algorithm reveals
- [ ] Learning objectives explicitly stated
- [ ] Prerequisites identified
- [ ] Difficulty level appropriate for curriculum position

### Phase 2: Test Suite Development

Create comprehensive tests BEFORE any code:

```cpp
// Example test structure using Google Test
#include <gtest/gtest.h>
#include "student_solution.h"

class BasicFunctionalityTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(BasicFunctionalityTest, CoreRequirement001) {
    // Test core functionality
    EXPECT_EQ(expected, actual);
}

TEST_F(BasicFunctionalityTest, EdgeCaseEmptyInput) {
    // Test boundary condition
    EXPECT_THROW(function_call(), std::invalid_argument);
}
```

**Test Categories Required**:

1. **Basic Functionality Tests**: Verify core requirements
2. **Edge Case Tests**: Boundary conditions, empty inputs, extremes
3. **Error Handling Tests**: Invalid inputs, exception behavior
4. **Performance Tests** (if applicable): Complexity requirements

**Constitution Check**:
- [ ] Tests written first (RED state)
- [ ] All requirements have corresponding tests
- [ ] Tests provide diagnostic output on failure
- [ ] Automated execution configured

### Phase 3: Boilerplate Code

Provide necessary structure WITHOUT implementations:

**Header File** (`include/module.h`):

```cpp
#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <vector>

/**
 * @brief Brief description of what this should do
 * 
 * @param input Description of parameter
 * @return Description of return value
 * 
 * TODO: Implement this function according to requirements
 */
int functionToImplement(const std::string& input);

/**
 * @brief Another function to implement
 * 
 * TODO: Implement according to REQ-002
 */
class ClassToImplement {
public:
    // TODO: Define public interface
    
private:
    // TODO: Define private members
};

#endif // MODULE_H
```

**Source File** (`src/main.cpp` or `src/module.cpp`):

```cpp
#include "module.h"

int functionToImplement(const std::string& input) {
    // TODO: Implement according to assignment specification REQ-001
    // Research: What C++ features are appropriate here?
    // Hint: Review references/resources.md for guidance
    throw std::runtime_error("Not implemented");
}

ClassToImplement::ClassToImplement() {
    // TODO: Implement constructor
}

// Additional function stubs...
```

**CMakeLists.txt**:

```cmake
cmake_minimum_required(VERSION 3.20)
project(Assignment_XXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
elseif(MSVC)
    add_compile_options(/W4)
endif()

# Source files
add_library(assignment_lib
    src/module.cpp
)

target_include_directories(assignment_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Main executable (optional)
add_executable(assignment_main
    src/main.cpp
)

target_link_libraries(assignment_main assignment_lib)

# Tests subdirectory
enable_testing()
add_subdirectory(tests)
```

**Constitution Check**:
- [ ] No implementation logic provided
- [ ] Clear TODO markers indicate what student implements
- [ ] Interface declarations only, no definitions
- [ ] Build system configured but incomplete implementation fails tests

### Phase 4: Documentation & Resources

Create reference materials that enable self-directed learning:

**references/resources.md**:

```markdown
# Learning Resources for Assignment XXX

## Primary References

### C++ Language Features
- [cppreference - Relevant Feature](https://en.cppreference.com/w/...)
- [ISO C++ Guidelines - Topic](https://isocpp.github.io/...)

### Standard Library Components
- [std::vector documentation](https://en.cppreference.com/w/cpp/container/vector)
- [std::string documentation](https://en.cppreference.com/w/cpp/string/basic_string)

## Conceptual Background

### Topic Area
Brief explanation of the concept without revealing implementation approach.

### Design Considerations
- What factors should you consider?
- What are the trade-offs?
- How do you evaluate different approaches?

## Debugging Resources

### Common Issues
- Compilation errors: [what to look for]
- Runtime errors: [debugging strategies]
- Memory issues: Use valgrind or AddressSanitizer

### Tools
- **GDB**: [link to gdb tutorial]
- **Valgrind**: `valgrind --leak-check=full ./your_program`

## Supplementary Materials

### Textbook Chapters
- [Book name], Chapter X: [Topic]

### Articles & Tutorials
- [Link to relevant article] - Explains [concept]

### Practice Problems
- [Link to similar but different problems for practice]

**Note**: These resources guide your learning. You should research, experiment, and discover the solution independently.
```

**Constitution Check**:
- [ ] Resources enable discovery, not solution disclosure
- [ ] cppreference.com links provided
- [ ] Debugging strategies included
- [ ] Conceptual guidance only, no algorithms revealed

### Phase 5: Validation

Before releasing the assignment:

1. **Verify Test Suite**:
   ```bash
   cd assignments/XXX-topic/build
   cmake ..
   make
   ./tests/run_tests
   ```
   - [ ] Tests compile and run
   - [ ] Tests fail with boilerplate (RED state)
   - [ ] Test output is clear and diagnostic

2. **Implement Reference Solution** (for validation only, NOT shared):
   - [ ] Solution passes all tests (GREEN state)
   - [ ] Solution demonstrates appropriate C++ practices
   - [ ] Solution complexity meets requirements

3. **Constitution Compliance Review**:
   - [ ] Teaching-First: No solutions in materials
   - [ ] Test-Driven: Comprehensive tests pre-written
   - [ ] Zero Disclosure: Boilerplate separate from solution
   - [ ] Progressive Path: Prerequisites documented
   - [ ] Review Gate: Quality criteria defined
   - [ ] Self-Reliance: Resources support independent learning

4. **Document in Curriculum**:
   - Add to curriculum roadmap
   - Update prerequisite dependency graph
   - Sequence appropriately in difficulty progression

## Directory Structure

```
assignments/XXX-topic-name/
├── README.md                    # Assignment specification
├── CMakeLists.txt              # Build configuration
├── .gitignore                  # Ignore build artifacts
├── include/
│   └── module.h                # Header declarations (interface only)
├── src/
│   ├── main.cpp                # Entry point (optional)
│   └── module.cpp              # Implementation stubs with TODOs
├── tests/
│   ├── CMakeLists.txt          # Test build configuration
│   └── test_module.cpp         # Comprehensive test suite
└── references/
    └── resources.md            # Learning resources and references
```

## Testing Framework Setup

### Google Test Integration

**tests/CMakeLists.txt**:

```cmake
# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(run_tests
    test_module.cpp
)

target_link_libraries(run_tests
    assignment_lib
    gtest_main
)

# Discover tests
include(GoogleTest)
gtest_discover_tests(run_tests)
```

## Example Assignment Progression

### 001-basics (Beginner)
- **Prerequisites**: None
- **Topics**: Variables, types, basic I/O
- **Complexity**: Single function implementations

### 010-pointers (Intermediate)
- **Prerequisites**: 001-005 (basics, functions, arrays)
- **Topics**: Pointer arithmetic, memory addressing
- **Complexity**: Multiple functions, pointer manipulation

### 025-classes (Intermediate)
- **Prerequisites**: 001-015 (fundamentals)
- **Topics**: OOP, encapsulation, constructors
- **Complexity**: Full class implementation

### 050-templates (Advanced)
- **Prerequisites**: 001-040 (fundamentals + OOP)
- **Topics**: Generic programming, template metaprogramming
- **Complexity**: Template class and function implementations

## Common Pitfalls to Avoid

❌ **Don't**:
- Include "example" code that's too similar to the solution
- Provide step-by-step implementation guides
- Reveal algorithms or data structures needed
- Write tests that are too easy to pass trivially
- Skip edge cases in test suite

✅ **Do**:
- Guide thinking with questions, not answers
- Provide conceptual frameworks
- Link to authoritative documentation
- Test thoroughly including edge cases
- Separate boilerplate from solution code clearly

## Assignment Checklist

Before finalizing an assignment:

- [ ] Assignment specification complete and clear
- [ ] Learning objectives explicitly stated
- [ ] Prerequisites documented
- [ ] Difficulty level appropriate
- [ ] Test suite comprehensive (basic, edge, error)
- [ ] Tests configured and automated
- [ ] Tests fail with boilerplate (RED)
- [ ] Boilerplate code provided (no implementations)
- [ ] Reference materials curated
- [ ] Resources enable discovery, not disclosure
- [ ] Build system configured (CMake)
- [ ] .gitignore for build artifacts
- [ ] Code review criteria defined
- [ ] Reference solution implemented privately
- [ ] Reference solution passes all tests (GREEN)
- [ ] Constitution compliance verified
- [ ] Added to curriculum roadmap
- [ ] Peer reviewed (recommended)

## Getting Help

If you need assistance creating assignments, consult:

- **Constitution**: `.specify/memory/constitution.md`
- **Templates**: `.specify/templates/`
- **Example Assignments**: Existing modules in `assignments/`
- **SpecKit Docs**: `.github/prompts/` for workflow guidance

Remember: The quality of assignments directly impacts learning outcomes. Take time to create excellent, challenging, fair assignments that enable mastery through discovery.
