# Project {ID}: {Full Name}

**Design Pattern**: {Pattern Name}  
**Difficulty**: {Beginner/Intermediate/Advanced/Expert}  
**Estimated Time**: {X-Y days/weeks}  
**Prerequisites**: {List project numbers or "None for Tier 1"}

## Learning Objectives

By completing this project, you will:

1. {Specific C++ language feature to master (e.g., "Master STL containers and iterators")}
2. {Design pattern to understand and apply (e.g., "Implement and understand the Strategy pattern")}
3. {SOLID principle to practice (e.g., "Apply Single Responsibility Principle")}
4. {Software engineering discipline (e.g., "Practice test-driven development workflow")}
5. {Additional objective if applicable}

**Real-World Relevance**: {Explain how this project's skills apply in professional software development. Connect to industry use cases, production systems, or common development scenarios.}

---

## Problem Statement

{Clear, unambiguous description of the programming problem to solve. Focus on WHAT needs to be built, not HOW to build it. Describe the user's need, the application's purpose, and the value it provides.}

### Context

{Provide domain context, background information, or motivation. Why would someone want this application? What problem does it solve in real development work?}

### Requirements

{Detailed functional requirements for the solution. Each requirement should be testable and unambiguous.}

#### Core Functionality

- **REQ-001**: Your implementation MUST {specific capability with clear success criterion}
- **REQ-002**: Your implementation MUST {specific capability with clear success criterion}
- **REQ-003**: Your implementation MUST {specific behavior with clear success criterion}
- **REQ-004**: Your implementation MUST {data requirement with clear success criterion}
- **REQ-005**: {Continue for 10-15 requirements total}

#### Input Specifications

- Input format: {e.g., "command-line arguments", "stdin", "file paths"}
- Input constraints: {e.g., "non-empty strings", "integers in range 1-1000"}
- Invalid input handling: {expected behavior for malformed input—exceptions? error codes?}

#### Output Specifications

- Output format: {e.g., "stdout", "file output", "return values"}
- Output constraints: {e.g., "sorted order", "specific formatting", "JSON structure"}
- Error reporting: {how errors should be communicated to user}

---

## Build & Run

### Building the Project

```bash
# From project root directory
mkdir build
cd build
cmake ..
make

# On Windows with MSVC:
cmake ..
cmake --build .
```

### Running Tests

```bash
# From build directory
ctest --output-on-failure

# OR run test executable directly
./tests/run_tests

# On Windows:
.\tests\run_tests.exe
```

### Running the Application (if applicable)

```bash
# From build directory
./{project}_main {arguments}

# Example:
./task_manager_main list --priority=high
```

---

## Test Suite Overview

**Testing Framework**: Google Test  
**Test Location**: `tests/`  
**Minimum Test Count**: {X} tests

### Test Categories

The pre-written test suite includes:

1. **Basic Functionality Tests**: {X} tests verifying core requirements (REQ-001 through REQ-00X)
2. **Edge Case Tests**: {Y} tests for boundary conditions (empty inputs, maximum sizes, edge states)
3. **Error Handling Tests**: {Z} tests for invalid input and error conditions
4. **Design Pattern Verification Tests**: {N} tests confirming correct pattern implementation
5. **Performance Tests** (if applicable): {M} tests ensuring algorithmic complexity requirements

### Example Test Scenarios

{List 3-5 representative test cases to help learners understand expectations—WITHOUT revealing solution approaches}

1. **Test**: `{TestName}`  
   **Purpose**: {What this test verifies}  
   **Example**: Given {input}, expect {output/behavior}

2. **Test**: `{TestName}`  
   **Purpose**: {What this test verifies}  
   **Example**: Given {input}, expect {output/behavior}

3. **Test**: `{TestName}`  
   **Purpose**: {What this test verifies}  
   **Example**: Given {input}, expect {output/behavior}

4. {Additional test scenarios}

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

### {Pattern Name} Pattern

**Intent**: {One-line purpose of the pattern}

**When to use this pattern**:
- {Scenario 1 where pattern is appropriate}
- {Scenario 2 where pattern is appropriate}
- {Scenario 3 where pattern is appropriate}

**Key components** (conceptual—research how to structure these):
- **{Component 1}**: {Role in pattern, e.g., "Abstract interface that defines the algorithm"}
- **{Component 2}**: {Role in pattern, e.g., "Concrete implementations of the algorithm"}
- **{Component 3}**: {Role in pattern, e.g., "Context that uses the interface"}

**Benefits of this pattern**:
- {Benefit 1, e.g., "Algorithms can be swapped at runtime"}
- {Benefit 2, e.g., "Open/Closed Principle: extend without modifying existing code"}
- {Benefit 3, e.g., "Eliminates conditional logic based on algorithm type"}

**Research starting point**: [Refactoring Guru - {Pattern}](https://refactoring.guru/design-patterns/{pattern-slug}/cpp)

---

## SOLID Principles Focus

This project emphasizes the following SOLID principles:

### {Principle 1 (e.g., Single Responsibility Principle)}

**Definition**: {Brief explanation of the principle}

**In this project**: {How this principle applies to the problem domain—conceptual guidance, not implementation hints}

**Questions to consider**:
- {Guiding question about responsibility separation}
- {Guiding question about class cohesion}

### {Principle 2 (e.g., Open/Closed Principle)}

**Definition**: {Brief explanation}

**In this project**: {How it applies}

**Questions to consider**:
- {Guiding question about extensibility}
- {Guiding question about modification vs extension}

{Add more principles as emphasized in this specific project}

---

## Reference Materials

### C++ Language Features

**{Feature 1 (e.g., Classes and Objects)}**:
- [cppreference - {Feature}]({url})
- [C++ Core Guidelines - {Relevant guideline}]({url})

**{Feature 2 (e.g., STL Containers)}**:
- [cppreference - {Container}]({url})
- [ISO C++ - {Topic}]({url})

**{Feature 3}**:
- {Links to documentation}

### Design Pattern Resources

- [Refactoring Guru - {Pattern}](https://refactoring.guru/design-patterns/{pattern}/cpp)
- [Design Patterns book - {Pattern chapter}]({url if available online})
- {Additional pattern-specific resources}

### SOLID Principles

- [{Principle 1}]({Wikipedia or authoritative source link})
- [{Principle 2}]({link})
- [C++ Core Guidelines - {Relevant to principles}]({url})

### Debugging & Development Tools

**Debugger**:
- GDB (Linux): [GDB Tutorial](https://www.gdbtutorial.com/)
- LLDB (macOS): `lldb ./program`
- Visual Studio Debugger (Windows): F5 to start debugging

**Memory Analysis**:
- Valgrind: `valgrind --leak-check=full ./program`
- AddressSanitizer: Compile with `-fsanitize=address`

**Static Analysis**:
- clang-tidy: `clang-tidy src/*.cpp -- -std=c++17`
- cppcheck: `cppcheck --enable=all src/`

**Compiler Warnings**: Always compile with strict warnings:
```bash
-Wall -Wextra -Wpedantic -Werror  # GCC/Clang
/W4 /WX                           # MSVC
```

---

## Conceptual Hints

{ONLY include if the assignment requires awareness of non-obvious concepts. These should guide thinking WITHOUT revealing solution approaches.}

### Architectural Thinking

- **Consider**: {High-level thinking prompt, e.g., "What responsibilities should be separated into different classes?"}
- **Think about**: {Design consideration, e.g., "How can you make this extensible for new features?"}
- **Ask yourself**: {Code quality question, e.g., "If you had to explain this to another developer, would they understand immediately?"}

### Performance Considerations (if applicable)

- **Consider**: {Algorithmic thinking prompt, e.g., "What data structure provides the lookup performance you need?"}
- **Think about**: {Efficiency consideration, e.g., "Are you creating unnecessary copies of large objects?"}

### Error Handling

- **Consider**: {Error scenario, e.g., "What happens if the input file doesn't exist?"}
- **Think about**: {Exception strategy, e.g., "Should this throw an exception or return an error code?"}

**Note**: These hints point toward conceptual frameworks and design considerations, NOT solution code or specific algorithms.

---

## Code Review Criteria

Once all tests pass, request code review. Your code will be evaluated on:

### Correctness (Prerequisite)
- [ ] All tests pass (100% passage required)
- [ ] No memory leaks (verified with Valgrind or AddressSanitizer)
- [ ] No undefined behavior or data races
- [ ] Handles all error conditions gracefully

### Design Pattern Application
- [ ] {Pattern} correctly identified and chosen for this problem
- [ ] {Pattern} implemented accurately (not superficial imitation)
- [ ] Pattern provides clear benefits (flexibility, maintainability, extensibility)
- [ ] Pattern not over-engineered (appropriate complexity for problem)

### SOLID Principles Adherence
- [ ] **{Principle 1}**: {How it should be applied in this project}
- [ ] **{Principle 2}**: {How it should be applied in this project}
- [ ] {Additional principles if emphasized}

### Clean Code Practices
- [ ] Clear, descriptive naming (variables, functions, classes convey intent)
- [ ] Functions are small and focused (do one thing well)
- [ ] No code duplication (DRY principle applied)
- [ ] Comments explain WHY, not WHAT (code is self-documenting)
- [ ] Consistent formatting and style

### Modern C++ Idioms
- [ ] Appropriate use of const correctness
- [ ] Smart pointers for dynamic memory (unique_ptr, shared_ptr)
- [ ] Move semantics for efficiency (C++11+)
- [ ] Range-based for loops where appropriate
- [ ] STL algorithms preferred over hand-written loops
- [ ] Modern C++ features used idiomatically

### Code Quality
- [ ] Separation of concerns (interface vs implementation)
- [ ] Proper encapsulation (appropriate access specifiers)
- [ ] Resource management follows RAII principles
- [ ] Error handling is robust and consistent
- [ ] No raw pointers for ownership

### Performance (if relevant to this project)
- [ ] Algorithmic complexity meets requirements
- [ ] No unnecessary copies or allocations
- [ ] Efficient data structure choices
- [ ] Appropriate use of const references

### Documentation & Maintainability
- [ ] Public interfaces have Doxygen-style documentation
- [ ] Complex algorithms are explained
- [ ] README is updated with any usage notes
- [ ] Build instructions are accurate

---

## Submission Checklist

Before requesting code review:

- [ ] All tests pass without modification to test code
- [ ] Code compiles without warnings (with `-Wall -Wextra -Wpedantic`)
- [ ] No memory leaks detected (run Valgrind or AddressSanitizer)
- [ ] No undefined behavior or data races
- [ ] Code formatted consistently (consider using clang-format)
- [ ] Design pattern correctly identified and implemented
- [ ] SOLID principles applied where relevant
- [ ] Clean code practices followed (DRY, meaningful names, small functions)
- [ ] Modern C++ features used appropriately
- [ ] Public interfaces documented with Doxygen comments
- [ ] You understand every line of code you've written
- [ ] You can explain your design decisions
- [ ] You can articulate which SOLID principles you applied and why
- [ ] You can explain the design pattern choice and its benefits

---

## Getting Help

### Permitted Questions

You may ask the AI assistant for:

- "Can you clarify what [requirement REQ-XXX] means?"
- "What C++ feature should I research to handle [concept]?"
- "Which design pattern would be most appropriate for [scenario]?"
- "Can you explain [C++ language feature or standard library component]?"
- "How does [SOLID principle] apply to this situation?"
- "Where can I find documentation about [topic]?"
- "What's the difference between [pattern A] and [pattern B]?"
- "Why is the test expecting [specific behavior]?"
- "What debugging strategy would you recommend for [issue]?"
- "Can you explain this compiler error: [error message]?"

### Prohibited Questions

The assistant will NOT provide:

- "Can you show me how to implement this?"
- "What algorithm should I use?"
- "Can you give me code for [part of solution]?"
- "Can you show me a similar example?" [if it would reveal the solution]
- "Can you write the [class/function] for me?"
- "What's the answer to this problem?"
- "Can you refactor my code?" [assistant will describe improvements, not provide code]

### Remember

**The assistant acts as a mentor, not a solution provider.**

Guidance on C++ concepts, design patterns, and SOLID principles is provided freely. Implementation code is never provided. Struggle builds expertise—embrace the challenge of discovering solutions independently.

This is how you become a master software engineer, not just a code copier.

---

## Project-Specific Notes

{Optional section for any unique aspects of this project}

{For example:}
- Audio projects: Requires PortAudio library installation
- Networking projects: May require administrator privileges for port binding
- Filesystem projects: Test data provided in `test_data/` directory

---

**Good luck, and enjoy the learning journey! 🚀**
