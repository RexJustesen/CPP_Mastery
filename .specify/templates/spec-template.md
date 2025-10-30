# Assignment Specification: [ASSIGNMENT NAME]

**Assignment Module**: `[###-topic-name]`  
**Created**: [DATE]  
**Difficulty**: [Beginner/Intermediate/Advanced/Expert]  
**Prerequisites**: [List of prerequisite modules or topics]  
**Estimated Time**: [Approximate completion time]

## Learning Objectives *(mandatory)*

By completing this assignment, you will:

1. [Specific skill or concept to master, e.g., "Understand and implement dynamic memory management"]
2. [Specific skill or concept to master, e.g., "Apply RAII principles to resource management"]
3. [Specific skill or concept to master, e.g., "Use modern C++ smart pointers effectively"]
4. [Additional objectives as needed]

**Real-World Relevance**: [Explain how these skills apply to professional C++ development]

---

## Problem Statement *(mandatory)*

[Clear, unambiguous description of the programming problem to solve. Focus on WHAT needs to be built, not HOW to build it.]

### Context

[Provide any domain context, background information, or motivation for the problem]

### Requirements

[Detailed functional requirements for the solution]

#### Core Functionality

- **REQ-001**: Your implementation MUST [specific capability, e.g., "support adding elements to the data structure"]
- **REQ-002**: Your implementation MUST [specific capability, e.g., "handle empty container operations safely"]  
- **REQ-003**: Your implementation MUST [specific behavior, e.g., "throw appropriate exceptions for invalid operations"]
- **REQ-004**: Your implementation MUST [data requirement, e.g., "maintain elements in sorted order"]

#### Input Specifications

[Define expected inputs, formats, constraints]

- Input format: [e.g., "command-line arguments", "stdin", "file input"]
- Input constraints: [e.g., "integer values in range 1-1000", "non-empty strings"]
- Invalid input handling: [expected behavior for malformed input]

#### Output Specifications

[Define expected outputs, formats, requirements]

- Output format: [e.g., "stdout", "file output", "return value"]
- Output constraints: [e.g., "sorted order", "specific formatting"]
- Error reporting: [how errors should be communicated]

---

## Test Suite Overview *(mandatory)*

**Testing Framework**: [Google Test / Catch2 / Other]  
**Test Location**: `tests/[module-name]/`  
**Test Execution**: `[command to run tests]`

### Test Categories

The pre-written test suite includes:

1. **Basic Functionality Tests**: [Number] tests verifying core requirements
2. **Edge Case Tests**: [Number] tests for boundary conditions and special cases
3. **Error Handling Tests**: [Number] tests for invalid input and error conditions
4. **Performance Tests**: [Optional—if applicable] [Number] tests for efficiency requirements

### Example Test Scenarios

[List 3-5 representative test cases to help learners understand expectations—WITHOUT revealing solution approaches]

1. **Test**: [Test name]  
   **Purpose**: [What this test verifies]  
   **Example**: Given [input], expect [output/behavior]

2. **Test**: [Test name]  
   **Purpose**: [What this test verifies]  
   **Example**: Given [input], expect [output/behavior]

3. **Test**: [Test name]  
   **Purpose**: [What this test verifies]  
   **Example**: Given [input], expect [output/behavior]

### Running Tests

```bash
# Command to compile and run tests
[e.g., "cd build && cmake .. && make && ./tests/run_tests"]
```

**Success Criteria**: ALL tests must pass (100% passage) before code review is available.

---

## Reference Materials *(mandatory)*

**Primary Resources**:

- [cppreference.com link to relevant C++ feature]
- [ISO C++ documentation or guideline]
- [Textbook chapter reference, if applicable]
- [Relevant C++ core guideline]

**Supplementary Resources**:

- [Articles or tutorials for conceptual understanding]
- [Video lectures, if appropriate]
- [Example problems for practice—NOT solutions to THIS assignment]

**Debugging & Tools**:

- Recommended debugger: [gdb, lldb, Visual Studio debugger, etc.]
- Compiler flags for helpful diagnostics: [e.g., `-Wall -Wextra -Wpedantic`]
- Static analysis tools: [e.g., clang-tidy, cppcheck]

---

## Conceptual Hints *(optional—use sparingly)*

[ONLY include if the assignment requires awareness of non-obvious concepts. These should guide thinking WITHOUT revealing solution approaches.]

- Consider: [High-level thinking prompt, e.g., "What data structure provides O(1) lookup?"]
- Remember: [Relevant C++ principle, e.g., "RAII ensures automatic resource cleanup"]
- Think about: [Design consideration, e.g., "How will you handle ownership of dynamically allocated memory?"]

**Note**: These hints point toward conceptual frameworks, NOT solution code or algorithms.

---

## Code Review Criteria *(mandatory)*

Once all tests pass, request code review. Your code will be evaluated on:

### Correctness (Prerequisite)
- [ ] All tests pass (100% passage required)
- [ ] No memory leaks (verify with valgrind or similar)
- [ ] No undefined behavior

### Code Quality
- [ ] Clear, descriptive naming for variables, functions, classes
- [ ] Appropriate use of const correctness
- [ ] Proper application of C++ idioms and modern features
- [ ] Effective use of standard library where appropriate

### Design
- [ ] Appropriate data structures and algorithms chosen
- [ ] Clean separation of concerns
- [ ] SOLID principles applied where relevant
- [ ] Resource management follows RAII principles

### Style & Maintainability
- [ ] Consistent formatting and indentation
- [ ] Comments explain WHY, not WHAT (code should be self-documenting)
- [ ] Readable control flow and logic structure
- [ ] Appropriate error handling and edge case management

### Performance (if relevant to assignment)
- [ ] Algorithm complexity meets requirements
- [ ] No unnecessary copies or allocations
- [ ] Move semantics used appropriately for C++11 and beyond

---

## Submission Checklist

Before requesting code review:

- [ ] All tests pass without modification to test code
- [ ] Code compiles without warnings (with `-Wall -Wextra -Wpedantic`)
- [ ] No memory leaks detected by valgrind or equivalent
- [ ] Code formatted consistently
- [ ] You understand every line of code you've written
- [ ] You can explain your design decisions

---

## Getting Help

**Permitted Questions**:

- "Can you clarify what [requirement] means?"
- "What C++ feature should I research to handle [concept]?"
- "Why is the test expecting [specific behavior]?"
- "Can you explain [C++ language feature or standard library component]?"
- "Where can I find documentation about [concept]?"

**Prohibited Questions**:

- "Can you show me how to implement this?"
- "What algorithm should I use?"
- "Can you give me code for [part of solution]?"
- "Can you show me a similar example?" [if it would reveal the solution]

**Remember**: Struggle is part of learning. The assistant is here to guide your thinking, not to solve the problem for you. Mastery comes from independent problem-solving.
