# Quick Start Guide: C++ Mastery Practical Projects

Welcome to the C++ Mastery curriculum! This guide will help you get started with your first project and understand the learning workflow.

---

## Table of Contents

1. [Prerequisites](#prerequisites)
2. [Environment Setup](#environment-setup)
3. [Your First Project](#your-first-project)
4. [The Learning Workflow](#the-learning-workflow)
5. [Getting Help](#getting-help)
6. [What Comes Next](#what-comes-next)

---

## Prerequisites

### Required Knowledge

Before starting this curriculum, you should have:

- **Basic C++ knowledge**: Variables, control flow (if/else, loops), functions
- **Basic command-line skills**: Navigate directories, run commands
- **Text editor/IDE familiarity**: Comfortable editing and saving code files

If you're missing any of these, see [recommended preparation resources](#preparation-resources) below.

### Required Tools

You'll need the following installed on your system:

1. **C++ Compiler** (C++17 or later)
   - Linux: GCC 7+ or Clang 5+
   - macOS: Xcode Command Line Tools (Apple Clang 9+)
   - Windows: Visual Studio 2019+, MinGW-w64, or MSYS2

2. **CMake 3.20+**: Build system generator
   - Download: [https://cmake.org/download/](https://cmake.org/download/)

3. **Git**: Version control (optional but recommended)
   - Download: [https://git-scm.com/downloads](https://git-scm.com/downloads)

4. **Text Editor or IDE**: Choose one:
   - **VS Code** (recommended): [https://code.visualstudio.com/](https://code.visualstudio.com/)
   - CLion, Visual Studio, Vim, Emacs, etc.

---

## Environment Setup

### 1. Verify Compiler Installation

**Linux/macOS:**
```bash
g++ --version    # Should show version 7.0 or higher
# or
clang++ --version  # Should show version 5.0 or higher
```

**Windows (PowerShell):**
```powershell
# For Visual Studio (MSVC)
cl.exe

# For MinGW/MSYS2
g++ --version
```

### 2. Verify CMake Installation

```bash
cmake --version  # Should show version 3.20 or higher
```

### 3. Clone the Repository (if using Git)

```bash
git clone <repository-url>
cd cpp_mastery
```

Or download and extract the repository as a ZIP file.

### 4. Install VS Code Extensions (if using VS Code)

Recommended extensions:
- **C/C++** by Microsoft (IntelliSense, debugging)
- **CMake Tools** by Microsoft (CMake integration)
- **Test Explorer UI** (view and run tests)

Install via: VS Code → Extensions (Ctrl+Shift+X) → Search and install

---

## Your First Project

Let's walk through **Project 001: Task Manager** to learn the workflow.

### Step 1: Navigate to the Project

```bash
cd assignments/001-task-manager
```

### Step 2: Read the Assignment

Open `README.md` in the project directory. This contains:

- **Learning Objectives**: What you'll learn
- **Problem Statement**: What you're building
- **Requirements**: Specific functionality required
- **SOLID Principles**: What principles this project teaches

**Take your time reading.** Understanding the requirements is crucial.

### Step 3: Review the Test Suite

Open `tests/task_manager_test.cpp`. This file contains **all the tests** your implementation must pass.

```bash
# Read the test file
cat tests/task_manager_test.cpp
# or open in your editor
```

**Important**: The tests define exactly what your code must do. Study them carefully.

### Step 4: Understand the Boilerplate Code

You're provided with:

- **Header file** (`include/task_manager.h`): Class declaration with function signatures
- **Source file** (`src/task_manager.cpp`): Function stubs with `throw std::runtime_error("Not implemented")`
- **CMake files** (`CMakeLists.txt`, `tests/CMakeLists.txt`): Build configuration

**Your job**: Replace the "Not implemented" stubs with working code.

### Step 5: Build the Project

```bash
# Create build directory
cmake -B build

# Compile the code
cmake --build build
```

**Expected result**: Compilation succeeds (no syntax errors).

### Step 6: Run the Tests (RED State)

```bash
# Run tests
cd build
ctest --output-on-failure
```

**Expected result**: All tests FAIL. This is the **RED state** — tests exist but code is not implemented.

**Output example:**
```
[ RUN      ] TaskManagerTest.ConstructorInitializesCorrectly
tests/task_manager_test.cpp:25: Failure
Value of: obj.getTaskCount()
  Actual: throws std::runtime_error: Not implemented
Expected: 0
[  FAILED  ] TaskManagerTest.ConstructorInitializesCorrectly
```

### Step 7: Implement the Code (GREEN State)

Now start implementing functions in `src/task_manager.cpp`.

**Workflow**:

1. Pick ONE failing test (start with the simplest)
2. Read what the test expects
3. Implement the minimal code to pass that test
4. Rebuild: `cmake --build .` (from the `build/` directory)
5. Rerun tests: `ctest --output-on-failure`
6. Repeat until all tests pass

**Example**: Implement the constructor

```cpp
// src/task_manager.cpp
TaskManager::TaskManager() 
    : tasks_() {
    // Initialize empty task list
    // No exception - remove the "throw std::runtime_error" line
}
```

Rebuild and rerun tests. The constructor test should now pass.

### Step 8: Achieve GREEN State

Continue implementing until **all tests pass**:

```
[==========] Running 15 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 15 tests from TaskManagerTest
[ RUN      ] TaskManagerTest.ConstructorInitializesCorrectly
[       OK ] TaskManagerTest.ConstructorInitializesCorrectly (0 ms)
[ RUN      ] TaskManagerTest.AddTaskIncreasesCount
[       OK ] TaskManagerTest.AddTaskIncreasesCount (0 ms)
...
[==========] 15 tests from 1 test suite ran. (2 ms total)
[  PASSED  ] 15 tests.
```

**Congratulations!** You've reached the **GREEN state**.

### Step 9: Refactor (REFACTOR State)

Now that tests pass, improve your code:

- **Readability**: Are names clear? Is logic simple?
- **DRY**: Any duplicate code to extract?
- **SOLID Principles**: Does your code follow the principles in the README?
- **Comments**: Are non-obvious parts documented?

**After each refactor**, rerun tests to ensure they still pass.

### Step 10: Code Review Checklist

Before considering the project complete, check:

- [ ] All tests pass (`ctest` shows 100% pass rate)
- [ ] No compiler warnings (`cmake --build build` shows no warnings)
- [ ] Code follows design pattern specified in README
- [ ] SOLID principles are applied
- [ ] No code duplication (DRY principle)
- [ ] Functions are small and focused
- [ ] Meaningful variable and function names
- [ ] Edge cases are handled (empty input, invalid values, etc.)
- [ ] Memory is managed correctly (no leaks, use Valgrind or AddressSanitizer)

---

## The Learning Workflow

### The Test-Driven Learning Cycle

This curriculum uses **Test-Driven Learning**:

```
READ → RED → GREEN → REFACTOR → REVIEW
  ↑                                      ↓
  └──────────────────────────────────────┘
```

1. **READ**: Understand requirements and study tests
2. **RED**: Verify tests fail (they define what you must build)
3. **GREEN**: Implement code to pass all tests
4. **REFACTOR**: Improve code quality while keeping tests green
5. **REVIEW**: Self-review using checklist, then move to next project

### Time Expectations

- **Tier 1 Projects (1-5)**: 4-8 hours each
- **Tier 2 Projects (6-15)**: 6-12 hours each
- **Tier 3 Projects (16-25)**: 10-20 hours each
- **Tier 4 Projects (26-30)**: 20-40 hours each

**Total curriculum**: ~6-12 months at a comfortable pace (1-2 projects per week).

### Learning Principles

This curriculum is governed by six principles (see [`.specify/memory/constitution.md`](../../.specify/memory/constitution.md)):

1. **Teaching-First**: The goal is deep learning, not just completion
2. **Test-Driven**: Tests define requirements; passing them proves correctness
3. **Zero Solution Disclosure**: You must write all implementation code
4. **Progressive Mastery**: Each project builds on previous knowledge
5. **Code Review Gate**: Quality matters as much as correctness
6. **Self-Reliance**: Research and problem-solving are part of learning

**What this means for you:**

- Struggle is expected and valuable
- Research is encouraged (but not copy-pasting solutions)
- The AI assistant will guide but never give you the answer
- Each project makes you stronger for the next

---

## Getting Help

### When You're Stuck

**1. Read the README.md again**: Often the answer is there.

**2. Study the tests**: Tests show exactly what behavior is expected.

**3. Check resources.md**: Each project includes curated learning resources.

**4. Research concepts**: Use cppreference.com, C++ Core Guidelines, Refactoring Guru.

**5. Ask conceptual questions**: The AI assistant can explain concepts.

**6. Debug incrementally**: Use `std::cout`, breakpoints, or debugger to understand behavior.

### Permitted Questions

You can ask the AI assistant:

- ✅ "What does the Strategy pattern mean?"
- ✅ "How do I use Google Test assertions?"
- ✅ "What is const correctness?"
- ✅ "Why is this test failing?" (with test output)
- ✅ "How do I validate input parameters?"

### Prohibited Questions

Do NOT ask:

- ❌ "Write the implementation for me"
- ❌ "What's the solution to this assignment?"
- ❌ "Give me the code to pass this test"
- ❌ "Show me a complete example of this project"

**Why?** The AI follows the **Zero Solution Disclosure** principle. Learning requires you to struggle and solve problems yourself.

### External Resources

- **Stack Overflow**: Search existing questions; ask new ones with [mcve](https://stackoverflow.com/help/minimal-reproducible-example)
- **C++ Subreddit**: Weekly Q&A threads for beginner questions
- **Textbooks**: Recommended in each project's `resources.md`

---

## What Comes Next

### Curriculum Progression

The 30 projects are organized into 4 tiers:

- **Tier 1 (Projects 1-5)**: Beginner - Foundation patterns and basic SOLID principles
- **Tier 2 (Projects 6-15)**: Intermediate - More complex patterns, utilities, basic performance
- **Tier 3 (Projects 16-25)**: Advanced - Real-world systems, advanced patterns, optimization
- **Tier 4 (Projects 26-30)**: Expert - Low-level systems, async I/O, compilers, advanced concurrency

**Start with Tier 1, Project 001.** Complete projects in order.

### After Your First Project

Once you've completed Project 001:

1. **Commit your work** (if using Git):
   ```bash
   git add assignments/001-task-manager
   git commit -m "Complete Project 001: Task Manager"
   ```

2. **Move to Project 002**: Text Processor
   ```bash
   cd ../002-text-processor
   ```

3. **Repeat the workflow**: Read → RED → GREEN → REFACTOR → REVIEW

### Tracking Progress

- Create a personal log (e.g., `progress.md`) to track:
  - Completion dates
  - Time spent
  - Key learnings
  - Challenges faced

- Celebrate milestones:
  - Complete Tier 1: Foundation complete! 🎉
  - Complete Tier 2: Intermediate skills unlocked! 🚀
  - Complete Tier 3: Advanced C++ mastery! 💪
  - Complete Tier 4: Expert level achieved! 🏆

---

## Preparation Resources

If you need to strengthen prerequisites:

### C++ Basics

- **Learn C++**: [https://www.learncpp.com/](https://www.learncpp.com/) (Chapters 1-8)
- **C++ Tutorial**: [https://cplusplus.com/doc/tutorial/](https://cplusplus.com/doc/tutorial/)
- **Codecademy C++**: [https://www.codecademy.com/learn/learn-c-plus-plus](https://www.codecademy.com/learn/learn-c-plus-plus)

### Command Line

- **Linux/macOS**: [The Linux Command Line](http://linuxcommand.org/tlcl.php) (First 4 chapters)
- **Windows**: [PowerShell in a Month of Lunches](https://www.manning.com/books/learn-windows-powershell-in-a-month-of-lunches-third-edition) (Chapters 1-5)

### Git Basics

- **Git Tutorial**: [https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control](https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control)
- **Interactive Git**: [https://learngitbranching.js.org/](https://learngitbranching.js.org/)

---

## Troubleshooting Common Issues

### CMake Configuration Fails

**Error**: "CMake 3.20 or higher is required"

**Solution**: Update CMake from [https://cmake.org/download/](https://cmake.org/download/)

---

### Compiler Not Found

**Error**: "No CMAKE_CXX_COMPILER could be found"

**Solution**:
- **Linux**: Install GCC: `sudo apt-get install g++`
- **macOS**: Install Xcode Command Line Tools: `xcode-select --install`
- **Windows**: Install Visual Studio or MinGW-w64

---

### Tests Don't Run

**Error**: "No tests were found"

**Solution**: Make sure you ran `cmake --build build` before `ctest`.

---

### All Tests Fail Immediately

**Error**: All tests show "Not implemented" errors

**Solution**: This is expected! It's the RED state. Start implementing the code.

---

### Memory Leak Detected

**Error**: Valgrind reports "definitely lost" or AddressSanitizer detects leaks

**Solution**:
- Use RAII (Resource Acquisition Is Initialization)
- Use smart pointers (`std::unique_ptr`, `std::shared_ptr`) instead of raw `new`/`delete`
- Match every `new` with a `delete`, every `new[]` with a `delete[]`

---

## Final Checklist

Before starting Project 001, verify:

- [ ] Compiler is installed and works (`g++ --version` or equivalent)
- [ ] CMake is installed and version is 3.20+ (`cmake --version`)
- [ ] You've read this entire Quick Start Guide
- [ ] You understand the RED → GREEN → REFACTOR cycle
- [ ] You know what questions you can/cannot ask the AI assistant
- [ ] You're ready to learn through struggle and research

---

## Welcome to the Journey!

Learning C++ deeply takes time and effort. This curriculum is designed to guide you from foundational patterns to expert-level system programming. Each project will challenge you, but completing them will give you real mastery.

**Remember**:
- The goal is learning, not speed
- Struggle is part of the process
- Every project builds skills for the next
- Mastery comes through practice and reflection

**You've got this.** 🚀

Now, let's begin with [Project 001: Task Manager](../assignments/001-task-manager/README.md)!

---

*Last Updated: [Date]*
*Constitutional Compliance: Verified under all six principles*
