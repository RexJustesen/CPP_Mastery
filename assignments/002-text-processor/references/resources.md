# Learning Resources: Text File Processor (Factory Method Pattern)

This document provides curated external resources to help you complete Project 2. Use these as references when you encounter concepts you're unfamiliar with.

---

## Design Pattern Resources

### Factory Method Pattern

**Primary Resource - Refactoring Guru**
- **URL**: https://refactoring.guru/design-patterns/factory-method
- **Content**: Complete explanation with diagrams, C++ examples
- **Focus Areas**:
  - Intent and motivation
  - Structure diagram
  - Applicability (when to use)
  - Implementation techniques
  - Pros and cons
  - Relations with other patterns

**SourceMaking - Factory Method**
- **URL**: https://sourcemaking.com/design_patterns/factory_method
- **Content**: Alternative perspective with examples
- **Focus**: Problem it solves, solution structure, real-world analogies

**C++ Design Patterns - Factory Method**
- **URL**: https://www.bogotobogo.com/DesignPatterns/factorymethod.php
- **Content**: C++-specific implementation details
- **Focus**: Code examples, memory management with factories

**YouTube - Factory Pattern Explained**
- **URL**: Search "Factory Method Pattern C++" on YouTube
- **Recommended**: Christopher Okhravi's series, Derek Banas tutorials
- **Focus**: Visual explanation, step-by-step implementation

---

## C++ Language Features

### String Manipulation

**cppreference - std::string**
- **URL**: https://en.cppreference.com/w/cpp/string/basic_string
- **Key Methods**:
  - `find(substr)` - Find substring position
  - `replace(pos, len, str)` - Replace substring
  - `substr(pos, len)` - Extract substring
  - `length()` / `size()` - Get string length
  - `empty()` - Check if empty

**cppreference - std::transform**
- **URL**: https://en.cppreference.com/w/cpp/algorithm/transform
- **Usage**: Apply function to each element in range
- **Example Context**: Converting characters to uppercase/lowercase

**cppreference - std::toupper / std::tolower**
- **URL**: https://en.cppreference.com/w/cpp/string/byte/toupper
- **Usage**: Convert single character case
- **Important**: Returns `int`, cast back to `char`

**cppreference - std::istringstream**
- **URL**: https://en.cppreference.com/w/cpp/io/basic_istringstream
- **Usage**: Parse strings as streams
- **Example Context**: Splitting strings by whitespace for word counting

### File I/O

**cppreference - std::ifstream**
- **URL**: https://en.cppreference.com/w/cpp/io/basic_ifstream
- **Key Methods**:
  - `open(filename)` - Open file for reading
  - `is_open()` - Check if file opened successfully
  - `good()` - Check stream state
  - `close()` - Close file (automatic with RAII)

**cppreference - std::ofstream**
- **URL**: https://en.cppreference.com/w/cpp/io/basic_ofstream
- **Key Methods**:
  - `open(filename)` - Open file for writing
  - `write(data, size)` - Write data to file
  - `flush()` - Flush output buffer

**cppreference - std::istreambuf_iterator**
- **URL**: https://en.cppreference.com/w/cpp/iterator/istreambuf_iterator
- **Usage**: Efficient way to read entire file
- **Example**:
  ```cpp
  std::ifstream file("input.txt");
  std::string content((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
  ```

**LearnCpp - File I/O**
- **URL**: https://www.learncpp.com/cpp-tutorial/basic-file-io/
- **Content**: Beginner-friendly file I/O tutorial
- **Topics**: Opening, reading, writing, error checking

### Smart Pointers

**cppreference - std::unique_ptr**
- **URL**: https://en.cppreference.com/w/cpp/memory/unique_ptr
- **Key Concepts**:
  - Unique ownership (non-copyable)
  - Automatic deletion when out of scope
  - Move semantics for transfer
  - `std::make_unique<T>(args)` - Preferred construction

**cppreference - std::make_unique**
- **URL**: https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique
- **Usage**: Factory function for creating unique_ptr
- **Example**: `auto ptr = std::make_unique<MyClass>(arg1, arg2);`

**Microsoft Docs - Smart Pointers**
- **URL**: https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp
- **Content**: When to use which smart pointer
- **Focus**: unique_ptr vs shared_ptr vs weak_ptr

### Inheritance and Polymorphism

**cppreference - Virtual Functions**
- **URL**: https://en.cppreference.com/w/cpp/language/virtual
- **Key Concepts**:
  - Pure virtual functions (`= 0`)
  - Virtual destructors (required for polymorphic classes)
  - Override specifier (C++11+)

**cppreference - Abstract Classes**
- **URL**: https://en.cppreference.com/w/cpp/language/abstract_class
- **Definition**: Class with at least one pure virtual function
- **Usage**: Cannot instantiate, used as interface

**LearnCpp - Virtual Functions**
- **URL**: https://www.learncpp.com/cpp-tutorial/virtual-functions/
- **Content**: Detailed tutorial on polymorphism
- **Topics**: Vtable, virtual destructors, pure virtual functions

### Exception Handling

**cppreference - std::exception**
- **URL**: https://en.cppreference.com/w/cpp/error/exception
- **Standard Exceptions**:
  - `std::runtime_error` - Runtime errors (file I/O failures)
  - `std::invalid_argument` - Invalid argument passed
  - `std::logic_error` - Logic errors in program
  - `std::out_of_range` - Index out of range

**cppreference - throw**
- **URL**: https://en.cppreference.com/w/cpp/language/throw
- **Usage**: Throw exception objects
- **Example**: `throw std::runtime_error("File not found: " + filename);`

**cppreference - try-catch**
- **URL**: https://en.cppreference.com/w/cpp/language/try_catch
- **Usage**: Handle exceptions
- **Best Practice**: Catch by const reference (`catch (const std::exception& e)`)

---

## STL Algorithms

**cppreference - Algorithms Library**
- **URL**: https://en.cppreference.com/w/cpp/algorithm
- **Relevant Algorithms**:
  - `std::transform` - Apply function to range
  - `std::find` - Find element in range
  - `std::count` - Count elements matching value
  - `std::count_if` - Count elements matching predicate
  - `std::for_each` - Apply function to each element

**cppreference - std::transform**
- **URL**: https://en.cppreference.com/w/cpp/algorithm/transform
- **Signature**: `transform(first, last, result, operation)`
- **Example Context**: Converting string to uppercase character-by-character

**cppreference - std::count_if**
- **URL**: https://en.cppreference.com/w/cpp/algorithm/count_if
- **Signature**: `count_if(first, last, predicate)`
- **Example Context**: Counting specific characters or conditions

---

## Command-Line Argument Parsing

**cppreference - main() Function**
- **URL**: https://en.cppreference.com/w/cpp/language/main_function
- **Parameters**:
  - `int argc` - Argument count
  - `char* argv[]` - Argument vector (array of C-strings)

**LearnCpp - Command Line Arguments**
- **URL**: https://www.learncpp.com/cpp-tutorial/command-line-arguments/
- **Content**: How to parse argc/argv
- **Example**: Looping through arguments, parsing flags

**CLI11 Library (Optional)**
- **URL**: https://github.com/CLIUtils/CLI11
- **Content**: Modern C++ command-line parser library
- **Note**: Optional - you can write parser manually or use this library

---

## Testing Resources

### Google Test Framework

**Google Test Primer**
- **URL**: https://google.github.io/googletest/primer.html
- **Content**: Complete introduction to Google Test
- **Key Concepts**:
  - Test cases and test suites
  - Assertions (EXPECT_*, ASSERT_*)
  - Test fixtures for setup/teardown

**Google Test Advanced Topics**
- **URL**: https://google.github.io/googletest/advanced.html
- **Topics**:
  - Type-parameterized tests
  - Death tests (testing exceptions)
  - Custom matchers

**Assertions Reference**
- **URL**: https://google.github.io/googletest/reference/assertions.html
- **Common Assertions**:
  - `EXPECT_EQ(val1, val2)` - Values equal
  - `EXPECT_TRUE(condition)` - Condition true
  - `EXPECT_THROW(statement, exception)` - Statement throws exception
  - `EXPECT_STREQ(str1, str2)` - C-strings equal

---

## SOLID Principles

### Open/Closed Principle (OCP)

**Wikipedia - Open/Closed Principle**
- **URL**: https://en.wikipedia.org/wiki/Open%E2%80%93closed_principle
- **Definition**: "Open for extension, closed for modification"
- **Application**: Add new processors without changing factory (with auto-registration)

**Uncle Bob - OCP Article**
- **URL**: Search "Robert Martin Open Closed Principle"
- **Content**: In-depth explanation from SOLID principles creator

### Single Responsibility Principle (SRP)

**Wikipedia - Single Responsibility Principle**
- **URL**: https://en.wikipedia.org/wiki/Single-responsibility_principle
- **Definition**: "A class should have one, and only one, reason to change"
- **Application**: Each processor handles one transformation type

---

## Build System Resources

### CMake

**CMake Tutorial**
- **URL**: https://cmake.org/cmake/help/latest/guide/tutorial/index.html
- **Topics**: Basic project setup, adding libraries, testing

**CMake FetchContent**
- **URL**: https://cmake.org/cmake/help/latest/module/FetchContent.html
- **Usage**: Download and build dependencies (Google Test)

**CTest**
- **URL**: https://cmake.org/cmake/help/latest/manual/ctest.1.html
- **Usage**: Run tests with `ctest --verbose`

---

## Debugging and Tools

### Compiler Error Messages

**GCC Error Messages**
- **URL**: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
- **Content**: Understanding compiler warnings and errors

**MSVC Error Messages**
- **URL**: https://learn.microsoft.com/en-us/cpp/error-messages/
- **Content**: Microsoft Visual C++ error reference

### Memory Error Detection

**AddressSanitizer (ASan)**
- **URL**: https://github.com/google/sanitizers/wiki/AddressSanitizer
- **Usage**: Detect memory leaks, buffer overflows
- **Compile Flag**: `-fsanitize=address`

**Valgrind**
- **URL**: https://valgrind.org/docs/manual/quick-start.html
- **Usage**: Memory profiling and leak detection (Linux/macOS)
- **Command**: `valgrind --leak-check=full ./program`

### Debuggers

**GDB Tutorial**
- **URL**: https://www.gdbtutorial.com/
- **Usage**: Command-line debugger for Linux/macOS
- **Commands**: `break`, `run`, `step`, `print`, `backtrace`

**LLDB Tutorial**
- **URL**: https://lldb.llvm.org/use/tutorial.html
- **Usage**: Debugger for macOS (Xcode)

**Visual Studio Debugger**
- **URL**: https://learn.microsoft.com/en-us/visualstudio/debugger/
- **Usage**: GUI debugger for Windows

---

## Unicode and Internationalization

**UTF-8 Everywhere**
- **URL**: https://utf8everywhere.org/
- **Content**: Why and how to use UTF-8 in C++
- **Relevance**: Handling non-ASCII characters in text files

**cppreference - Locales**
- **URL**: https://en.cppreference.com/w/cpp/locale
- **Content**: Internationalization support in C++
- **Note**: Advanced topic, optional for this project

---

## Code Quality

### Code Style

**C++ Core Guidelines**
- **URL**: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
- **Topics**: Modern C++ best practices
- **Relevant Sections**:
  - R (Resource Management) - smart pointers
  - F (Functions) - parameter passing
  - ES (Expressions and Statements) - coding style

**Google C++ Style Guide**
- **URL**: https://google.github.io/styleguide/cppguide.html
- **Content**: Comprehensive style guide
- **Note**: Some rules are Google-specific, adapt as needed

### Documentation

**Doxygen Manual**
- **URL**: https://www.doxygen.nl/manual/docblocks.html
- **Usage**: Document code with special comments
- **Tags**: `@brief`, `@param`, `@return`, `@throws`

---

## Performance Optimization

**LearnCpp - Performance Tips**
- **URL**: https://www.learncpp.com/cpp-tutorial/performance-tips/
- **Topics**: Pass by reference, move semantics, avoid copies

**cppreference - Move Semantics**
- **URL**: https://en.cppreference.com/w/cpp/language/move_constructor
- **Relevance**: Efficient string passing with `std::move`

---

## Additional Design Patterns (Optional)

### Strategy Pattern
- **URL**: https://refactoring.guru/design-patterns/strategy
- **Relation**: Factory Method often used with Strategy
- **Note**: You've already learned this in Project 1!

### Abstract Factory
- **URL**: https://refactoring.guru/design-patterns/abstract-factory
- **Relation**: Extension of Factory Method for families of objects
- **Note**: Advanced, not needed for this project

### Registry Pattern (Auto-Registration)
- **URL**: Search "C++ Static Registration Pattern"
- **Relevance**: Bonus challenge - auto-register processors without modifying factory
- **Complexity**: Advanced, requires static initialization techniques

---

## Research Strategy

### How to Use These Resources

1. **Start with Conceptual Understanding**:
   - Read Factory Method pattern explanation on Refactoring Guru
   - Understand the problem it solves before coding

2. **Reference During Implementation**:
   - Keep cppreference open for C++ syntax
   - Look up specific methods as you need them

3. **Debug with Documentation**:
   - Compiler error? Check error message reference
   - Unexpected behavior? Re-read relevant cppreference page

4. **Deepen Understanding**:
   - After completing project, read C++ Core Guidelines sections
   - Watch YouTube videos for alternative explanations

### Effective Research Questions

**Good Questions** (specific, searchable):
- "How do I read an entire file into std::string in C++?"
- "What's the difference between std::unique_ptr and std::shared_ptr?"
- "How to convert string to uppercase using STL algorithms?"

**Poor Questions** (too broad):
- "How do I do file I/O?" (read documentation first)
- "Explain Factory pattern" (watch tutorial first)
- "Why doesn't my code work?" (debug first, isolate problem)

---

## Books (Optional)

### Design Patterns
- **"Design Patterns: Elements of Reusable Object-Oriented Software"** by Gang of Four
  - Chapter on Factory Method
  - Classic reference, examples in C++/Smalltalk

- **"Head First Design Patterns"** by Freeman et al.
  - More approachable, uses Java but concepts translate
  - Excellent diagrams and explanations

### Modern C++
- **"Effective Modern C++"** by Scott Meyers
  - Smart pointers (Item 18-22)
  - Move semantics and perfect forwarding

- **"C++ Primer"** by Lippman, Lajoie, Moo
  - Comprehensive C++ reference
  - Chapters on strings, I/O, classes, inheritance

### Testing
- **"Modern C++ Programming with Test-Driven Development"** by Jeff Langr
  - TDD workflow with Google Test
  - Practical examples

---

## Video Tutorials

### YouTube Channels

**The Cherno (C++ Series)**
- **URL**: https://www.youtube.com/c/TheChernoProject
- **Relevant Videos**: Smart pointers, polymorphism, file I/O

**CppCon Talks**
- **URL**: https://www.youtube.com/user/CppCon
- **Search**: "Factory pattern", "Modern C++ best practices"

**Jason Turner (C++ Weekly)**
- **URL**: https://www.youtube.com/c/JasonTurner-lefticus
- **Content**: Short, focused C++ tips and tricks

---

## When You're Stuck

### Debugging Checklist
1. **Read the error message carefully** - it usually tells you what's wrong
2. **Check cppreference** - verify you're using APIs correctly
3. **Add debug prints** - `std::cout` to trace execution
4. **Run single test** - `ctest -R TestName -V` to isolate problem
5. **Use debugger** - step through code line by line
6. **Search error message** - often someone had same issue
7. **Take a break** - fresh perspective helps

### Getting Help (While Maintaining Learning)
- ✅ **Ask conceptual questions**: "Why would I use unique_ptr here instead of shared_ptr?"
- ✅ **Request debugging help**: "My code throws segfault on line 42, what could cause this?"
- ✅ **Seek design feedback**: "Is this a good way to structure my factory?"
- ❌ **Don't ask for solutions**: "Can you write the UppercaseProcessor for me?"
- ❌ **Don't copy without understanding**: Even if you find example code online

---

## Summary of Key Resources

| Topic | Primary Resource | Why It's Useful |
|-------|------------------|-----------------|
| **Factory Method** | Refactoring Guru | Clear diagrams, C++ examples |
| **std::string** | cppreference | Complete API reference |
| **File I/O** | LearnCpp tutorial | Beginner-friendly explanations |
| **Smart Pointers** | cppreference + MS Docs | Understand ownership semantics |
| **Google Test** | Official Primer | Learn testing framework |
| **SOLID Principles** | Wikipedia + Uncle Bob | Understand design principles |
| **Debugging** | GDB/LLDB tutorials | Fix runtime errors |

---

**Remember**: These resources are references, not replacements for thinking. Read documentation, experiment with small examples, and struggle productively. The learning happens when you encounter problems and work through them!

---

**Last Updated**: 2025-10-29  
**Maintainer**: Instructor  
**Feedback**: If you find a resource particularly helpful (or unhelpful), let us know!
