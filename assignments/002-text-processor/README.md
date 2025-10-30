# Project 2: Text File Processor

**Design Pattern**: Factory Method  
**Difficulty**: Beginner (Tier 1)  
**Estimated Time**: 2-3 days  
**Prerequisites**: Basic C++, file I/O, string manipulation

---

## Learning Objectives

By completing this project, you will:

1. **Understand the Factory Method Pattern**: Learn how to create objects without specifying their exact classes
2. **Apply SOLID Principles**:
   - **Open/Closed Principle (OCP)**: Add new processors without modifying factory code
   - **Single Responsibility Principle (SRP)**: Each processor handles one transformation
3. **Master File I/O**: Read and write text files, handle errors gracefully
4. **Practice String Manipulation**: Work with `std::string`, `std::stringstream`, STL algorithms
5. **Write Testable Code**: Design interfaces that enable comprehensive unit testing

---

## Project Overview

Create a command-line text processing utility that applies various transformations to text files. The program uses the **Factory Method Pattern** to create different processor types dynamically based on user input.

### Example Usage

```bash
# Convert file to uppercase
./text_processor --input file.txt --output upper.txt --processor uppercase

# Count words in a file
./text_processor --input file.txt --processor wordcount

# Find and replace text
./text_processor --input file.txt --output fixed.txt --processor findreplace --find "bug" --replace "feature"
```

---

## Functional Requirements

### REQ-001: ITextProcessor Interface
The system SHALL define an abstract `ITextProcessor` interface with:
- `virtual std::string process(const std::string& input) = 0` - Transform input text
- `virtual std::string getDescription() const = 0` - Return processor description
- Virtual destructor for polymorphism

### REQ-002: Uppercase Processor
The system SHALL implement `UppercaseProcessor` that:
- Converts all characters to uppercase
- Preserves whitespace and punctuation
- Returns transformed string

### REQ-003: Lowercase Processor
The system SHALL implement `LowercaseProcessor` that:
- Converts all characters to lowercase
- Preserves whitespace and punctuation
- Returns transformed string

### REQ-004: Word Count Processor
The system SHALL implement `WordCountProcessor` that:
- Counts total words in input text
- Defines word as sequence of non-whitespace characters
- Returns count as string (e.g., "Word count: 42")

### REQ-005: Line Count Processor
The system SHALL implement `LineCountProcessor` that:
- Counts total lines in input text
- Empty lines count as lines
- Returns count as string (e.g., "Line count: 10")

### REQ-006: Find and Replace Processor
The system SHALL implement `FindReplaceProcessor` that:
- Finds all occurrences of target string
- Replaces with replacement string
- Performs case-sensitive matching
- Constructor accepts `findText` and `replaceText` parameters

### REQ-007: Processor Factory
The system SHALL implement `ProcessorFactory` with:
- `static std::unique_ptr<ITextProcessor> createProcessor(const std::string& type)` method
- Support for processor types: "uppercase", "lowercase", "wordcount", "linecount", "findreplace"
- Throw `std::invalid_argument` for unknown processor types
- Optional: `createFindReplaceProcessor(find, replace)` overload

### REQ-008: File Input/Output
The system SHALL provide file operations:
- Read entire text file into `std::string`
- Write `std::string` to text file
- Throw exceptions on I/O errors (file not found, permission denied)
- Handle large files efficiently (avoid loading entire file if possible for counting)

### REQ-009: Command-Line Interface
The system SHALL provide CLI with arguments:
- `--input <path>` - Input file path (required)
- `--output <path>` - Output file path (optional, defaults to stdout)
- `--processor <type>` - Processor type (required)
- `--find <text>` - Find text for findreplace processor
- `--replace <text>` - Replace text for findreplace processor
- Display help message with `--help`

### REQ-010: Error Handling
The system SHALL handle errors gracefully:
- Missing required arguments → display error and usage
- File not found → throw exception with descriptive message
- Invalid processor type → throw `std::invalid_argument`
- Find/replace arguments missing for findreplace processor → throw error

### REQ-011: Extensibility
The system SHALL support adding new processors by:
- Implementing `ITextProcessor` interface
- Registering with factory (future: auto-registration pattern)
- NO modification to existing processor code (OCP)

### REQ-012: Output Format
The system SHALL format output as:
- For transformations (uppercase, lowercase, findreplace): Return transformed text
- For counting (wordcount, linecount): Return human-readable string
- Write to file if `--output` specified, otherwise print to stdout

---

## Design Pattern: Factory Method

### Intent
Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.

### When to Use
- A class can't anticipate the class of objects it must create
- You want to localize knowledge of which class gets created
- You need to provide a library of products without exposing implementation classes
- You want to enable extensibility (new types without modifying existing code)

### Structure (Conceptual)

```
┌─────────────────┐
│ ITextProcessor  │ ◄─────────┐
│ (Interface)     │            │
└─────────────────┘            │
        △                      │
        │                      │
        │ implements           │ creates
        │                      │
┌───────┴───────────────────┐  │
│  Concrete Processors      │  │
│  - UppercaseProcessor     │  │
│  - LowercaseProcessor     │  │
│  - WordCountProcessor     │  │
│  - LineCountProcessor     │  │
│  - FindReplaceProcessor   │  │
└───────────────────────────┘  │
                               │
                    ┌──────────┴──────────┐
                    │  ProcessorFactory   │
                    │  (Creator)          │
                    │  + createProcessor()│
                    └─────────────────────┘
```

### Key Components

1. **Product Interface** (`ITextProcessor`):
   - Declares operations all concrete products must implement
   - Pure virtual methods ensure interface contract

2. **Concrete Products** (`UppercaseProcessor`, etc.):
   - Implement the product interface
   - Each provides specific behavior

3. **Factory** (`ProcessorFactory`):
   - Declares factory method returning product interface
   - Creates concrete products based on input parameter (type string)

### Benefits
- **Loose Coupling**: Client code works with interface, not concrete classes
- **Single Responsibility**: Object creation logic centralized
- **Open/Closed**: Add new processors without modifying factory (with improvements)

### Trade-offs
- **Complexity**: Adds abstraction layer (but worth it for extensibility)
- **Indirection**: Factory lookup adds slight overhead (negligible in this context)

---

## SOLID Principles Application

### Single Responsibility Principle (SRP)
- **ITextProcessor**: Defines processing contract
- **Each Processor**: Handles ONE transformation type
- **ProcessorFactory**: Responsible ONLY for object creation
- **File I/O functions**: Separate from processing logic
- **main()**: Handles CLI parsing and orchestration

### Open/Closed Principle (OCP)
- **Open for extension**: Add new processors by implementing `ITextProcessor`
- **Closed for modification**: Existing processors don't change when new ones added
- **Factory limitation**: Current implementation requires modifying `createProcessor()` for new types
  - **Challenge**: How could you make factory auto-register new types? (Advanced: static registration pattern)

### Liskov Substitution Principle (LSP)
- Any `ITextProcessor*` can replace another without breaking client code
- All processors follow same interface contract
- Client code (main) works with interface, not concrete types

### Interface Segregation Principle (ISP)
- `ITextProcessor` is minimal - only methods all processors need
- No "fat interface" forcing processors to implement unused methods

### Dependency Inversion Principle (DIP)
- High-level module (main) depends on abstraction (`ITextProcessor`)
- Low-level modules (concrete processors) also depend on abstraction
- Factory returns interface pointers, hiding concrete implementations

---

## Technical Requirements

### C++ Standard
- **C++17** minimum
- Use modern C++ features:
  - `std::unique_ptr` for ownership
  - Range-based for loops
  - `std::string_view` (optional, for performance)
  - Structured bindings (optional)

### File I/O
- Use `<fstream>` for file operations
- `std::ifstream` for reading
- `std::ofstream` for writing
- Check stream state after operations
- Throw exceptions on errors

### String Manipulation
- `<string>` for `std::string`
- `<cctype>` for `std::toupper`, `std::tolower`
- `<sstream>` for string parsing
- `<algorithm>` for STL algorithms (`std::transform`, etc.)

### Error Handling
- Use exceptions for error reporting
- `std::invalid_argument` for invalid input
- `std::runtime_error` for file I/O errors
- Custom exception types (optional)

### Build System
- CMake 3.20+
- Google Test 1.14.0+ for unit tests
- Strict compiler warnings enabled

---

## Test Suite Overview

Your implementation will be validated against 30+ comprehensive tests:

### Section 1: Basic Processor Functionality (10 tests)
- `UppercaseProcessorConvertsToUppercase`
- `LowercaseProcessorConvertsToLowercase`
- `WordCountProcessorCountsWords`
- `LineCountProcessorCountsLines`
- `FindReplaceProcessorReplacesAllOccurrences`
- `UppercasePreservesWhitespace`
- `LowercasePreservesWhitespace`
- `WordCountHandlesMultipleSpaces`
- `LineCountHandlesEmptyLines`
- `FindReplaceHandlesCaseSensitivity`

### Section 2: Edge Cases (8 tests)
- `EmptyStringReturnsEmpty` (for uppercase/lowercase)
- `SingleCharacterProcessing`
- `VeryLongStringPerformance` (stress test)
- `UnicodeCharacterHandling` (UTF-8)
- `SpecialCharactersPreserved`
- `FindReplaceNoMatchesReturnsOriginal`
- `FindReplaceEmptyFindStringThrows`
- `WordCountWithOnlyWhitespace`

### Section 3: Factory Pattern (5 tests)
- `FactoryCreatesUppercaseProcessor`
- `FactoryCreatesLowercaseProcessor`
- `FactoryCreatesWordCountProcessor`
- `FactoryCreatesLineCountProcessor`
- `FactoryCreatesFindReplaceProcessor`
- `FactoryThrowsForInvalidType`
- `FactoryReturnsCorrectTypes` (dynamic_cast verification)

### Section 4: File I/O (5 tests)
- `ReadFileReturnsContents`
- `WriteFileCreatesFile`
- `ReadNonexistentFileThrows`
- `WriteToReadOnlyLocationThrows` (platform-specific)
- `RoundTripPreservesContent`

### Section 5: Integration (5 tests)
- `EndToEndUppercaseTransformation`
- `EndToEndWordCounting`
- `EndToEndFindReplaceMultipleOccurrences`
- `ChainMultipleProcessors` (apply two processors sequentially)
- `ProcessLargeFile` (1MB+ test file)

---

## Project Structure

```
002-text-processor/
├── CMakeLists.txt              # Root build configuration
├── README.md                   # This file
├── .gitignore                  # Ignore build artifacts, reference solutions
├── include/
│   ├── processor.h             # ITextProcessor interface
│   ├── processor_factory.h     # ProcessorFactory class
│   ├── processors.h            # Concrete processor declarations
│   └── file_utils.h            # File I/O utilities
├── src/
│   ├── processor.cpp           # Interface implementation (if needed)
│   ├── processor_factory.cpp  # Factory implementation
│   ├── processors.cpp          # All concrete processors
│   ├── file_utils.cpp          # File I/O implementation
│   └── main.cpp                # CLI entry point
├── tests/
│   ├── CMakeLists.txt          # Test build configuration
│   └── test_text_processor.cpp # Comprehensive test suite
└── references/
    └── resources.md            # Learning resources
```

---

## Implementation Hints (Conceptual Only)

### Factory Method Pattern
**Research Questions**:
- How does `std::unique_ptr` ensure proper memory management?
- Why return interface pointers instead of concrete types?
- How could you avoid modifying factory code when adding new processors? (static registration)

**Design Considerations**:
- Factory method is `static` (no factory instance needed)
- Use `std::make_unique<ConcreteType>()` for creation
- Return `std::unique_ptr<ITextProcessor>` for ownership transfer

### String Transformation
**Research Questions**:
- What's the difference between `std::toupper()` and `std::transform()`?
- How do you handle Unicode characters in C++?
- What's the performance of `std::string::find()` for multiple replacements?

**Design Considerations**:
- Uppercase/lowercase: Use `std::transform` with `::toupper`/`::tolower`
- Word counting: Use `std::istringstream` and whitespace delimiters
- Find/replace: Loop with `std::string::find()` and `std::string::replace()`

### File I/O
**Research Questions**:
- How do you read entire file into `std::string` efficiently?
- What exceptions does `std::ifstream` throw?
- How do you check if file operations succeeded?

**Design Considerations**:
- Use `std::istreambuf_iterator` for efficient file reading
- Check `stream.is_open()` and `stream.good()` for errors
- Throw custom exceptions with descriptive messages

### Command-Line Parsing
**Research Questions**:
- How does `argc` and `argv` work in C++?
- How do you parse optional arguments?
- Should you use a library (e.g., CLI11) or write custom parser?

**Design Considerations**:
- Simple loop through `argv` for basic parsing
- Use `std::string` comparison for argument names
- Store arguments in variables or `std::map<std::string, std::string>`

---

## Getting Started

### 1. Understand Requirements
- Read all REQ-001 through REQ-012 carefully
- Review test suite to understand expected behavior
- Sketch class diagram on paper

### 2. Implement Interface First
- Start with `include/processor.h` - define `ITextProcessor`
- Ensure virtual destructor
- Pure virtual methods: `process()`, `getDescription()`

### 3. Create One Concrete Processor
- Implement `UppercaseProcessor` first (simplest)
- Make sure it compiles
- Run tests - should fail with "Not implemented" initially

### 4. Implement Factory
- Create `ProcessorFactory::createProcessor()`
- Support "uppercase" type first
- Return `std::unique_ptr<ITextProcessor>`

### 5. Test-Driven Development
- Run tests frequently (`ctest --verbose`)
- Fix one failing test at a time
- RED → GREEN → REFACTOR cycle

### 6. Add Remaining Processors
- Implement lowercase, wordcount, linecount
- Add cases to factory
- Keep tests passing (GREEN state)

### 7. Implement Find/Replace
- Most complex processor (requires parameters)
- Add factory overload: `createFindReplaceProcessor(find, replace)`
- Handle edge cases (empty find string)

### 8. Build CLI
- Implement argument parsing in `main()`
- Handle `--input`, `--output`, `--processor`, etc.
- Test manually with files

### 9. Refactor and Polish
- Remove code duplication
- Add comments for complex logic
- Ensure all warnings resolved
- Run full test suite

---

## Conceptual Hints

### Factory Method Pattern
- **Purpose**: Decouple object creation from usage
- **Key Insight**: Client code works with interface, factory handles instantiation
- **Extensibility**: Add new types by implementing interface and registering with factory

### String Algorithms
- **Transformation**: Apply function to each character
- **Counting**: Iterate and count based on criteria
- **Find/Replace**: Search for substring, replace with another

### Error Handling Strategy
- **File Errors**: Throw exceptions (caller can't proceed without file)
- **Invalid Arguments**: Throw `std::invalid_argument` (programming error)
- **Business Logic**: Consider returning error codes or optional values (if operation can fail normally)

### Testing Strategy
- **Unit Tests**: Test each processor in isolation
- **Factory Tests**: Verify correct types created
- **Integration Tests**: Test full workflow (file → process → output)

---

## Code Quality Standards

### Compilation
- **MUST** compile without errors
- **MUST** compile without warnings (with `-Wall -Wextra -Wpedantic -Werror`)

### Testing
- **MUST** pass all provided unit tests (30+ tests)
- **SHOULD** add additional tests for edge cases you discover
- Achieve 80%+ code coverage (optional, measured with gcov/lcov)

### Documentation
- **Header files**: Doxygen-style comments for all public methods
- **Complex algorithms**: Inline comments explaining logic
- **README**: Update if you add optional features

### Code Style
- **Consistent formatting**: Use clang-format or similar
- **Naming conventions**: 
  - Classes: `PascalCase`
  - Functions/variables: `camelCase` or `snake_case` (pick one)
  - Constants: `UPPER_CASE` or `kPascalCase`
- **RAII**: Use smart pointers, avoid raw `new`/`delete`

---

## Bonus Challenges (Optional)

### Challenge 1: Auto-Registration Pattern
Modify the factory to auto-register processors using static initialization:
```cpp
// Each processor registers itself
static bool registered = ProcessorFactory::registerProcessor("uppercase", 
    []() { return std::make_unique<UppercaseProcessor>(); });
```

### Challenge 2: Streaming Processing
For very large files, process line-by-line instead of loading entire file:
```cpp
// Process 1GB file without loading into memory
processFileStreaming(inputPath, outputPath, processor);
```

### Challenge 3: Regex Support
Add `RegexProcessor` that applies regex transformations:
```cpp
// Replace all email addresses with "[EMAIL]"
auto processor = factory.createRegexProcessor("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z]{2,}\\b", "[EMAIL]");
```

### Challenge 4: Composite Processor
Allow chaining multiple processors:
```cpp
// First uppercase, then count words
auto composite = std::make_unique<CompositeProcessor>();
composite->addProcessor(factory.createProcessor("uppercase"));
composite->addProcessor(factory.createProcessor("wordcount"));
```

### Challenge 5: Configuration File
Support processor configuration from JSON/YAML:
```yaml
processors:
  - type: findreplace
    find: bug
    replace: feature
  - type: uppercase
```

---

## Common Pitfalls

### Pitfall 1: Memory Leaks
**Problem**: Forgetting to delete dynamically allocated objects  
**Solution**: Use `std::unique_ptr` or `std::shared_ptr` - RAII handles cleanup

### Pitfall 2: Slicing
**Problem**: Returning concrete type instead of pointer/reference loses polymorphism  
**Solution**: Always return pointers/references to base class from factory

### Pitfall 3: Improper Exception Handling
**Problem**: File errors not caught, program crashes  
**Solution**: Wrap file operations in try-catch, provide meaningful error messages

### Pitfall 4: Case Sensitivity Issues
**Problem**: Factory lookup fails because of case mismatch ("Uppercase" vs "uppercase")  
**Solution**: Convert type string to lowercase before comparison

### Pitfall 5: Find/Replace Infinite Loop
**Problem**: Replacing "a" with "aa" causes infinite loop (keeps finding new "a")  
**Solution**: Track position after replacement, don't re-search replaced text

---

## Assessment Criteria

### Functionality (40%)
- All 30+ tests pass
- All requirements (REQ-001 to REQ-012) implemented correctly
- CLI works as specified

### Design (30%)
- Proper use of Factory Method pattern
- SOLID principles applied correctly
- Clean separation of concerns

### Code Quality (20%)
- No compiler warnings
- Consistent code style
- Appropriate comments
- No memory leaks (verified with valgrind/sanitizers)

### Testing (10%)
- All provided tests pass
- Optional: Additional tests added
- Edge cases handled

---

## Submission Checklist

Before considering the project complete:

- [ ] All header files created with proper interface definitions
- [ ] All source files implement required functionality
- [ ] No "Not implemented" stubs remaining
- [ ] CMake builds without errors or warnings
- [ ] All 30+ unit tests pass (`ctest --verbose`)
- [ ] CLI accepts required arguments and produces correct output
- [ ] Manual testing with sample files successful
- [ ] Code reviewed for quality and style
- [ ] No memory leaks (run with AddressSanitizer or valgrind)
- [ ] README updated if you added bonus features
- [ ] All files committed to Git (except build artifacts and reference solutions)

---

## Resources

See `references/resources.md` for curated learning materials on:
- Factory Method pattern
- C++ file I/O
- String manipulation
- STL algorithms
- Google Test framework

---

## Getting Help

### Debugging Strategies
1. **Compile errors**: Read error message carefully, check syntax and types
2. **Test failures**: Run single test (`ctest -R TestName -V`), add debug prints
3. **Segmentation faults**: Use debugger (GDB/LLDB) or AddressSanitizer
4. **Logic errors**: Add assertions, verify assumptions with print statements

### Research Approach
1. **Read documentation**: cppreference.com for C++ standard library
2. **Study examples**: Refactoring Guru for Factory Method pattern
3. **Ask specific questions**: "How do I read an entire file into std::string?" (not "How do I do file I/O?")
4. **Experiment**: Write small test programs to understand concepts

### AI Assistant Usage (Constitutional Guidelines)
- ✅ **DO**: Ask for explanations of concepts, debugging help, design alternatives
- ✅ **DO**: Request code review, suggestions for improvement
- ✅ **DO**: Get help understanding error messages
- ❌ **DON'T**: Ask for complete implementations
- ❌ **DON'T**: Copy-paste solutions without understanding
- ❌ **DON'T**: Skip the struggle - learning happens through productive failure

---

**Remember**: The goal is learning, not just completing the assignment. Struggle is part of the process. If something seems too easy, you're probably missing an edge case or design consideration. Dig deeper!

---

**Project Version**: 1.0  
**Last Updated**: 2025-10-29  
**Estimated Completion Time**: 2-3 days (6-9 hours of focused work)
