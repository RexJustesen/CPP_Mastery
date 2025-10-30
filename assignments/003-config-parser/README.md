# Project 3: Configuration File Parser

**Design Pattern**: Builder  
**Difficulty**: Beginner (Tier 1)  
**Estimated Time**: 3-4 days  
**Prerequisites**: Basic C++, file I/O, string parsing, std::map

---

## Learning Objectives

By completing this project, you will:

1. **Understand the Builder Pattern**: Learn to construct complex objects step-by-step
2. **Apply SOLID Principles**:
   - **Single Responsibility Principle (SRP)**: Separate parsing, building, and representation
   - **Dependency Inversion Principle (DIP)**: Parser depends on builder abstraction
3. **Master INI File Parsing**: Parse sections, key-value pairs, handle comments
4. **Practice Type Conversions**: Convert strings to int, bool, double with error handling
5. **Use STL Containers**: Work with `std::map`, `std::unordered_map` for efficient lookups

---

## Project Overview

Create a configuration file parser that reads INI-style configuration files and provides a clean API for accessing values. The **Builder Pattern** separates the parsing logic from the construction of the configuration object, enabling flexible configuration building.

### Example Configuration File (INI Format)

```ini
# Database configuration
[database]
host = localhost
port = 5432
username = admin
password = secret123
ssl_enabled = true
timeout = 30.5

[logging]
level = INFO
file = /var/log/app.log
max_size = 10485760  # 10 MB in bytes
rotate = true

[features]
experimental_mode = false
max_users = 1000
api_version = 2.1
```

### Example Usage

```cpp
ConfigParser parser;
Config config = parser.parseFile("app.ini");

// Access values with type conversion
std::string host = config.getString("database", "host");
int port = config.getInt("database", "port");
bool sslEnabled = config.getBool("database", "ssl_enabled");
double timeout = config.getDouble("database", "timeout");

std::cout << "Connecting to " << host << ":" << port << std::endl;
```

---

## Functional Requirements

### REQ-001: INI File Format Support
The system SHALL parse INI-style configuration files with:
- Sections defined by `[section_name]`
- Key-value pairs in format `key = value`
- Comments starting with `#` or `;`
- Whitespace trimming around keys, values, and section names
- Empty lines (ignored)

### REQ-002: Config Class (Product)
The system SHALL provide a `Config` class that:
- Stores configuration as nested map: `section → (key → value)`
- Provides read-only access to configuration values
- Is immutable after construction (thread-safe for reading)
- Has methods: `getString()`, `getInt()`, `getBool()`, `getDouble()`
- Throws exception for missing section or key

### REQ-003: ConfigBuilder Class (Builder)
The system SHALL implement `ConfigBuilder` that:
- Constructs `Config` objects incrementally
- Has method `addSection(sectionName)` to start new section
- Has method `addKeyValue(key, value)` to add key-value pair to current section
- Has method `build()` to create final immutable `Config` object
- Validates that keys are added to a section (not global scope)
- Throws exception if `build()` called multiple times on same builder

### REQ-004: ConfigParser Class (Director)
The system SHALL implement `ConfigParser` that:
- Uses `ConfigBuilder` to construct `Config` from file
- Has method `parseFile(filename)` that returns `Config` object
- Has method `parseString(content)` for testing
- Handles file I/O errors gracefully
- Throws exceptions for syntax errors with line numbers

### REQ-005: Section Parsing
The system SHALL parse section headers:
- Format: `[section_name]`
- Section names must be alphanumeric plus underscores
- Whitespace before/after brackets is ignored
- Multiple sections with same name → throw error
- All key-value pairs after section header belong to that section

### REQ-006: Key-Value Parsing
The system SHALL parse key-value pairs:
- Format: `key = value`
- Keys must be alphanumeric plus underscores
- Values are strings (trimmed of leading/trailing whitespace)
- Equals sign required (colon not supported)
- Duplicate keys in same section → throw error (or last wins, document decision)

### REQ-007: Comment Handling
The system SHALL handle comments:
- Lines starting with `#` or `;` are comments (ignored)
- Inline comments supported: `key = value # comment`
- Comment characters inside quoted values are literal (optional advanced feature)

### REQ-008: Type Conversion Methods
The system SHALL provide type-safe getters in `Config`:
- `getString(section, key)` → returns value as-is
- `getInt(section, key)` → converts to int, throws on failure
- `getBool(section, key)` → converts to bool ("true", "false", "1", "0", case-insensitive)
- `getDouble(section, key)` → converts to double, throws on failure
- All methods throw exception if section or key not found

### REQ-009: Default Values
The system SHALL support default values:
- Overloaded getters: `getString(section, key, default)`
- Return default if section or key not found (no exception)
- Type-safe defaults: `getInt()` with int default, etc.

### REQ-010: Validation
The system SHALL validate configuration:
- Detect syntax errors (malformed sections, missing equals sign)
- Provide line number in error messages
- Reject key-value pairs before first section (or allow global section, document decision)

### REQ-011: Error Reporting
The system SHALL report errors with:
- Exception type: `ConfigParseError` (derived from `std::runtime_error`)
- Error message including line number and description
- Example: "Line 15: Invalid section header '[database'"

### REQ-012: Case Sensitivity
The system SHALL handle case:
- Section names are case-sensitive: `[Database]` ≠ `[database]`
- Key names are case-sensitive: `Host` ≠ `host`
- Boolean values are case-insensitive: "True" = "true" = "TRUE"
- Document this behavior clearly

---

## Design Pattern: Builder

### Intent
Separate the construction of a complex object from its representation, allowing the same construction process to create different representations.

### When to Use
- Object construction involves many steps or configurations
- You want to isolate complex construction logic from the object itself
- You need to create different representations of the same data (e.g., different config formats)
- You want immutable objects (builder handles mutable construction, produces immutable product)

### Structure (Conceptual)

```
┌─────────────┐
│   Config    │ ◄──── builds ──── ┌──────────────────┐
│  (Product)  │                   │  ConfigBuilder   │
│ - immutable │                   │   (Builder)      │
│ - sections  │                   │ + addSection()   │
│ - keys/vals │                   │ + addKeyValue()  │
└─────────────┘                   │ + build()        │
                                  └──────────────────┘
                                           △
                                           │ uses
                                           │
                                  ┌──────────────────┐
                                  │  ConfigParser    │
                                  │   (Director)     │
                                  │ + parseFile()    │
                                  │ + parseString()  │
                                  └──────────────────┘
```

### Key Components

1. **Product** (`Config`):
   - Final immutable configuration object
   - Provides read-only access to values
   - Thread-safe (no mutable state after construction)

2. **Builder** (`ConfigBuilder`):
   - Constructs `Config` step-by-step
   - Maintains mutable state during construction
   - Provides fluent interface (optional: return `*this` from add methods)
   - `build()` method produces final immutable product

3. **Director** (`ConfigParser`):
   - Orchestrates the construction process
   - Uses builder to parse file and construct config
   - Encapsulates parsing algorithm

### Benefits
- **Immutability**: Product is immutable, builder handles mutable construction
- **Flexibility**: Can create different builders for different config formats (JSON, YAML, etc.)
- **Separation of Concerns**: Parsing logic separate from Config representation
- **Step-by-Step Construction**: Complex object built incrementally

### Builder vs. Factory
- **Factory**: Creates object in one step (simple construction)
- **Builder**: Creates object in multiple steps (complex construction)
- Use Builder when construction has many optional parameters or steps

---

## SOLID Principles Application

### Single Responsibility Principle (SRP)
- **Config**: Responsible ONLY for storing and providing access to values
- **ConfigBuilder**: Responsible ONLY for constructing Config objects
- **ConfigParser**: Responsible ONLY for parsing files and orchestrating builder
- Each class has one reason to change

### Open/Closed Principle (OCP)
- Can add new builder types (JsonConfigBuilder, YamlConfigBuilder) without modifying Config
- Can add new parsers without modifying builder or config
- Extensible through inheritance or composition

### Liskov Substitution Principle (LSP)
- If you create IConfigBuilder interface, any concrete builder can replace another
- Config objects are interchangeable regardless of how they were built

### Dependency Inversion Principle (DIP)
- ConfigParser depends on ConfigBuilder (could be abstraction if using interface)
- High-level parsing logic doesn't depend on low-level Config details
- Builder acts as abstraction layer

---

## Technical Requirements

### C++ Standard
- **C++17** minimum
- Use modern C++ features:
  - `std::optional<T>` for optional values
  - `std::map` for ordered sections/keys
  - `std::unordered_map` for faster lookups (optional)
  - `std::string_view` for parsing (optional optimization)

### STL Containers
- `std::map<std::string, std::map<std::string, std::string>>` for nested config
- Alternative: `std::unordered_map` for O(1) lookups vs O(log n)
- Trade-off: Ordered iteration vs. faster access

### String Parsing
- `<sstream>` for string manipulation
- `<regex>` for validation (optional, regex can be overkill)
- `std::stoi`, `std::stod` for type conversions (with exception handling)

### Error Handling
- Custom exception: `ConfigParseError` derived from `std::runtime_error`
- Include line number and descriptive message
- Catch conversion exceptions and rethrow with context

### File I/O
- Use `<fstream>` for reading configuration files
- Read line-by-line for error reporting with line numbers
- Handle file not found gracefully

---

## Test Suite Overview

Your implementation will be validated against 35+ comprehensive tests:

### Section 1: Basic Parsing (8 tests)
- `ParsesSimpleKeyValuePair`
- `ParsesSectionHeaders`
- `ParsesMultipleSections`
- `ParsesCommentsCorrectly`
- `TrimsWhitespaceFromKeys`
- `TrimsWhitespaceFromValues`
- `ParsesEmptyFile`
- `ParsesFileWithOnlyComments`

### Section 2: Type Conversions (7 tests)
- `GetStringReturnsCorrectValue`
- `GetIntConvertsStringToInt`
- `GetBoolConvertsStringToBool` (true/false/1/0)
- `GetDoubleConvertsStringToDouble`
- `GetIntThrowsOnInvalidConversion`
- `GetBoolThrowsOnInvalidValue`
- `GetDoubleThrowsOnInvalidConversion`

### Section 3: Default Values (4 tests)
- `GetStringWithDefaultReturnsDefault`
- `GetIntWithDefaultReturnsDefault`
- `GetBoolWithDefaultReturnsDefault`
- `GetDoubleWithDefaultReturnsDefault`

### Section 4: Error Handling (8 tests)
- `ThrowsOnMissingSectionAccess`
- `ThrowsOnMissingKeyAccess`
- `ThrowsOnDuplicateSectionDefinition`
- `ThrowsOnDuplicateKeyInSection`
- `ThrowsOnMalformedSectionHeader`
- `ThrowsOnMissingEqualsSign`
- `ThrowsOnKeyValueBeforeSection`
- `ErrorMessageIncludesLineNumber`

### Section 5: Builder Pattern (6 tests)
- `BuilderCreatesValidConfig`
- `BuilderAddsMultipleSections`
- `BuilderHandlesChainedCalls` (fluent interface)
- `BuilderThrowsOnBuildCalledTwice`
- `BuilderThrowsOnKeyValueWithoutSection`
- `ConfigIsImmutableAfterBuild`

### Section 6: Integration (4 tests)
- `ParseCompleteConfigFile`
- `RoundTripConfiguration` (parse, build, compare)
- `ParserUsesBuilderCorrectly`
- `MultipleConfigObjectsIndependent`

---

## Project Structure

```
003-config-parser/
├── CMakeLists.txt              # Root build configuration
├── README.md                   # This file
├── .gitignore                  # Ignore build artifacts, reference solutions
├── include/
│   ├── config.h                # Config class (immutable product)
│   ├── config_builder.h        # ConfigBuilder class (builder)
│   ├── config_parser.h         # ConfigParser class (director)
│   └── config_exceptions.h     # Custom exception types
├── src/
│   ├── config.cpp              # Config implementation
│   ├── config_builder.cpp      # Builder implementation
│   ├── config_parser.cpp       # Parser implementation
│   └── main.cpp                # Demo/testing application
├── tests/
│   ├── CMakeLists.txt          # Test build configuration
│   ├── test_config_parser.cpp  # Comprehensive test suite
│   └── test_data/              # Sample .ini files for testing
│       ├── valid.ini
│       ├── invalid.ini
│       └── complex.ini
└── references/
    └── resources.md            # Learning resources
```

---

## Implementation Hints (Conceptual Only)

### Builder Pattern Implementation
**Research Questions**:
- How does the Builder pattern differ from a constructor with many parameters?
- Why return `*this` from builder methods (fluent interface)?
- How does the builder maintain state during construction?

**Design Considerations**:
- Builder has mutable state (current section, key-value map)
- `build()` moves or copies data to create immutable Config
- Builder can be reused after `build()` (or make single-use, document decision)

### Parsing Strategy
**Research Questions**:
- How to read file line-by-line while tracking line numbers?
- What's the best way to trim whitespace from strings?
- How to split string on first `=` (not all `=` in value)?

**Design Considerations**:
- Use `std::getline` in loop, increment line counter
- Trim with `string.erase()` or custom trim function
- Use `string.find('=')` to locate delimiter, then `substr()` for key/value

### Type Conversion
**Research Questions**:
- What exceptions do `std::stoi`, `std::stod` throw?
- How to distinguish between "0" and conversion failure?
- Should boolean accept "yes"/"no" or only "true"/"false"?

**Design Considerations**:
- Wrap `std::stoi` in try-catch, rethrow with context
- For bool: convert value to lowercase, compare with "true"/"false"/"1"/"0"
- Document accepted boolean values clearly

### Immutability
**Research Questions**:
- How to make Config immutable? (const methods, no setters)
- Should `build()` move or copy data from builder?
- Can multiple threads read Config simultaneously? (yes, if truly immutable)

**Design Considerations**:
- Config has only getters (all const)
- Builder's `build()` uses `std::move` to transfer data (efficient)
- Mark all Config data members as `const` (optional, for guaranteed immutability)

---

## Getting Started

### 1. Understand Requirements
- Read all REQ-001 through REQ-012
- Study INI file format examples
- Review Builder pattern structure

### 2. Implement Config First
- Start with `include/config.h` - define data structure
- Use nested `std::map<std::string, std::map<std::string, std::string>>`
- Implement getters: `getString()`, `getInt()`, `getBool()`, `getDouble()`
- Test each getter with sample data

### 3. Implement ConfigBuilder
- Create `ConfigBuilder` with mutable state
- Implement `addSection()`, `addKeyValue()`, `build()`
- Make sure `build()` produces immutable Config
- Test builder directly (without parser)

### 4. Implement ConfigParser
- Parse line-by-line, track line numbers
- Detect sections, key-value pairs, comments
- Use builder to construct Config
- Handle errors with line number context

### 5. Test-Driven Development
- Run tests frequently (`ctest --verbose`)
- Fix one failing test at a time
- RED → GREEN → REFACTOR

### 6. Handle Edge Cases
- Empty files, files with only comments
- Malformed syntax (missing brackets, equals signs)
- Type conversion errors
- Duplicate sections/keys

### 7. Refactor and Polish
- Extract helper functions (trim, isComment, etc.)
- Add comprehensive error messages
- Document design decisions (case sensitivity, duplicate handling)

---

## Conceptual Hints

### INI Parsing Algorithm
1. Read file line-by-line
2. For each line:
   - Trim whitespace
   - If empty or comment → skip
   - If starts with `[` → parse section header
   - If contains `=` → parse key-value pair
   - Otherwise → syntax error
3. Use builder to construct config incrementally
4. Return final config from builder

### Trimming Whitespace
```cpp
// Pseudocode (not implementation!)
trim(string):
    remove leading whitespace
    remove trailing whitespace
    return trimmed string
```

### Boolean Conversion
```cpp
// Pseudocode (not implementation!)
stringToBool(value):
    lowercase_value = toLower(value)
    if lowercase_value in ["true", "1"]:
        return true
    if lowercase_value in ["false", "0"]:
        return false
    throw exception
```

---

## Code Quality Standards

### Compilation
- **MUST** compile without errors
- **MUST** compile without warnings (`-Wall -Wextra -Wpedantic -Werror`)

### Testing
- **MUST** pass all 35+ provided unit tests
- **SHOULD** add tests for discovered edge cases
- Target 80%+ code coverage

### Documentation
- **Header files**: Doxygen-style comments for all public methods
- **Complex parsing logic**: Inline comments
- **Design decisions**: Document in comments (e.g., "Duplicate keys: last wins")

### Code Style
- Consistent formatting (clang-format or manual)
- Naming conventions (choose one, stick to it)
- RAII (no raw new/delete)

---

## Bonus Challenges (Optional)

### Challenge 1: Fluent Interface
Make builder methods return `*this` for chaining:
```cpp
config = builder.addSection("database")
               .addKeyValue("host", "localhost")
               .addKeyValue("port", "5432")
               .build();
```

### Challenge 2: Nested Sections
Support nested sections:
```ini
[database.connection]
host = localhost

[database.pool]
size = 10
```

### Challenge 3: Array Values
Support array values:
```ini
[servers]
hosts = server1,server2,server3
```
Provide `getArray(section, key)` method.

### Challenge 4: Environment Variable Expansion
Expand environment variables in values:
```ini
[paths]
home = ${HOME}/app
```

### Challenge 5: Include Directives
Support file inclusion:
```ini
@include common.ini

[app]
name = MyApp
```

---

## Common Pitfalls

### Pitfall 1: Not Trimming Whitespace
**Problem**: ` key = value ` stores key as " key" instead of "key"  
**Solution**: Trim whitespace from keys, values, and section names

### Pitfall 2: Inline Comments Breaking Values
**Problem**: `key = value # comment` stores value as "value # comment"  
**Solution**: Find `#` after `=`, split value and comment

### Pitfall 3: Mutable Config Object
**Problem**: Config can be modified after construction (not thread-safe)  
**Solution**: No setters, only getters (all const)

### Pitfall 4: Poor Error Messages
**Problem**: "Parse error" without line number or details  
**Solution**: Always include line number and specific issue

### Pitfall 5: Not Handling Empty Values
**Problem**: `key =` (no value) causes parser to fail  
**Solution**: Allow empty values (store as empty string)

---

## Assessment Criteria

### Functionality (40%)
- All 35+ tests pass
- All requirements (REQ-001 to REQ-012) implemented
- Handles edge cases gracefully

### Design (30%)
- Proper use of Builder pattern
- SOLID principles applied
- Clear separation of concerns

### Code Quality (20%)
- No compiler warnings
- Consistent style
- Comprehensive comments
- No memory leaks

### Testing (10%)
- All provided tests pass
- Optional: Additional tests added
- Edge cases handled

---

## Submission Checklist

- [ ] All header files created with complete interface definitions
- [ ] All source files implement required functionality
- [ ] No "Not implemented" stubs remaining
- [ ] CMake builds without errors or warnings
- [ ] All 35+ unit tests pass
- [ ] Manual testing with sample .ini files successful
- [ ] Error messages include line numbers
- [ ] Config is immutable after construction
- [ ] Code reviewed for quality and style
- [ ] No memory leaks (verified with sanitizers)

---

## Resources

See `references/resources.md` for curated learning materials on:
- Builder pattern
- INI file format
- String parsing in C++
- std::map and STL containers
- Type conversions and error handling

---

**Project Version**: 1.0  
**Last Updated**: 2025-10-29  
**Estimated Completion Time**: 3-4 days (9-12 hours of focused work)
