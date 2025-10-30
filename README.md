# C++ Mastery Learning Repository

**Master C++ through disciplined, test-driven practice guided by an AI mentor.**

## Philosophy

This repository is designed to transform you into an absolute master of C++ and computer science through a rigorous, hands-on learning approach. Unlike traditional tutorials that provide solutions, this system:

- **Teaches through challenge**: You solve real problems independently
- **Tests define success**: Pre-written tests verify your understanding objectively
- **Mentorship, not solutions**: The AI assistant guides your thinking but never provides answers
- **Progressive mastery**: Structured curriculum from fundamentals to expert-level topics

## How It Works

### 1. Assignment Structure

Each learning module in the `assignments/` directory includes:

- **Assignment Specification**: Clear problem statement, requirements, and learning objectives
- **Pre-written Test Suite**: Comprehensive tests defining success criteria
- **Boilerplate Code**: Project structure and interface declarations (NO implementations)
- **Reference Materials**: Links to C++ documentation, standards, and learning resources

### 2. Learning Workflow

```
1. Read assignment specification → Understand the problem
2. Review test suite → Know what success looks like
3. Research & implement → Write code to pass tests
4. Run tests iteratively → Debug and refine
5. Achieve 100% test passage → Verify correctness
6. Request code review → Get feedback on quality and design
7. Refine based on feedback → Improve your craft
8. Complete assignment → Move to next challenge
```

### 3. AI Assistant Role

The AI assistant acts as your **mentor and guide**, not your solution provider:

**✅ The assistant WILL:**
- Explain C++ concepts, language features, and standard library components
- Clarify assignment requirements and test expectations
- Suggest resources for further research (cppreference.com, C++ standards, textbooks)
- Review your completed code for quality, style, and design
- Discuss best practices, design patterns, and C++ idioms at a conceptual level
- Teach debugging strategies and problem-solving approaches

**❌ The assistant WILL NOT:**
- Provide implementation code for assignments
- Reveal algorithms or solution approaches
- Show you "how to do it" directly
- Give you code snippets that solve the problem
- Refactor your code for you (only describe needed improvements)

### 4. Constitution Principles

This repository operates under strict constitutional principles documented in `.specify/memory/constitution.md`:

1. **Teaching-First Philosophy**: Education through guided discovery
2. **Test-Driven Learning**: Tests written first, 100% passage required
3. **Zero Solution Disclosure**: No answers provided, ever
4. **Progressive Mastery Path**: Structured curriculum with clear prerequisites
5. **Code Review Gate**: Quality feedback only after tests pass
6. **Self-Reliance & Research Skills**: Building independent problem-solving capability

## Getting Started

### Prerequisites

- C++ compiler (GCC 11+, Clang 13+, or MSVC 2019+)
- CMake 3.20+
- Git
- A C++ testing framework (Google Test recommended)

### Installation

```bash
# Clone the repository
git clone <repository-url>
cd cpp_mastery

# Choose your first assignment (start with 001-basics)
cd assignments/001-basics

# Build the project
mkdir build && cd build
cmake ..
make

# Run the tests (they should fail initially)
./tests/run_tests
```

### Your First Assignment

1. Navigate to `assignments/001-basics/`
2. Read the `README.md` assignment specification
3. Examine the test suite in `tests/`
4. Implement your solution in `src/` and `include/`
5. Run tests: `./build/tests/run_tests`
6. Iterate until all tests pass
7. Request code review from the AI assistant

## Curriculum Overview

The learning path progresses through these major areas:

### Fundamentals (001-020)
- Basic syntax and control flow
- Functions and scope
- Arrays and pointers
- Memory management basics
- References and const correctness

### Intermediate (021-040)
- Object-oriented programming
- Classes and encapsulation
- Inheritance and polymorphism
- Operator overloading
- RAII and resource management

### Advanced (041-060)
- Templates and generic programming
- STL containers and algorithms
- Move semantics and perfect forwarding
- Smart pointers
- Exception handling

### Expert (061-080)
- Advanced template metaprogramming
- Design patterns in C++
- Concurrency and multithreading
- Performance optimization
- Modern C++ features (C++11/14/17/20/23)

### Master (081-100)
- Systems programming
- Custom allocators
- Compile-time programming
- Advanced concurrency patterns
- Real-world project challenges

## Code Review Process

Once you achieve 100% test passage:

1. Commit your code to a feature branch
2. Ask the AI assistant: "Please review my code for assignment [number]"
3. Confirm all tests pass when prompted
4. Receive feedback on:
   - Code clarity and naming
   - Design patterns and architecture
   - C++ idioms and best practices
   - Performance considerations
   - Maintainability
5. Implement improvements independently
6. Iterate until quality standards met

## Getting Help

### Permitted Questions

- "Can you clarify what [requirement] means?"
- "What C++ feature should I research for [concept]?"
- "Why is the test expecting [specific behavior]?"
- "Can you explain [language feature or standard library component]?"
- "Where can I find documentation about [topic]?"
- "What debugging strategy would you recommend for [issue]?"

### Questions That Won't Be Answered

- "Can you show me how to implement this?"
- "What algorithm should I use?"
- "Can you give me code for [part of solution]?"
- "Can you show me a similar example?" (if it reveals the solution)

**Remember**: The struggle is the learning. Asking for solutions robs you of the growth that comes from independent problem-solving.

## Resources

### Primary References
- [cppreference.com](https://en.cppreference.com/) - Comprehensive C++ reference
- [ISO C++ Standards](https://isocpp.org/) - Official C++ standards and guidelines
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) - Best practices

### Recommended Books
- *The C++ Programming Language* by Bjarne Stroustrup
- *Effective Modern C++* by Scott Meyers
- *C++ Primer* by Stanley Lippman
- *A Tour of C++* by Bjarne Stroustrup

### Tools
- **Debuggers**: GDB, LLDB, Visual Studio Debugger
- **Memory Analysis**: Valgrind, AddressSanitizer
- **Static Analysis**: clang-tidy, cppcheck
- **Build Systems**: CMake, Make

## Project Structure

```
cpp_mastery/
├── assignments/              # Learning modules
│   ├── 001-basics/
│   │   ├── README.md        # Assignment spec
│   │   ├── CMakeLists.txt
│   │   ├── include/         # Headers (student implements)
│   │   ├── src/             # Source (student implements)
│   │   ├── tests/           # Pre-written tests
│   │   └── references/      # Learning resources
│   ├── 002-functions/
│   └── ...
├── .specify/                # Constitution and templates
│   ├── memory/
│   │   └── constitution.md  # Governing principles
│   └── templates/           # Document templates
├── .github/
│   └── prompts/             # AI assistant instructions
└── README.md               # This file
```

## Contributing

This repository is designed for individual learning. If you discover issues with:
- Test accuracy or clarity
- Assignment specification ambiguity
- Missing prerequisites
- Constitution principle violations

Please open an issue for review.

## Acknowledgments

Built on the SpecKit framework for structured software development workflows, adapted specifically for C++ mastery learning.

---

**Ready to begin your journey to C++ mastery? Start with assignment 001 and embrace the challenge!**
