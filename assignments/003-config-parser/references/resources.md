# Learning Resources: Configuration File Parser (Builder Pattern)

This document provides curated external resources to help you complete Project 3. Use these as references when encountering unfamiliar concepts.

---

## Design Pattern Resources

### Builder Pattern

**Primary Resource - Refactoring Guru**
- **URL**: https://refactoring.guru/design-patterns/builder
- **Content**: Complete explanation with diagrams, C++ examples
- **Focus Areas**:
  - Intent and problem it solves
  - Structure diagram
  - Step-by-step construction process
  - Builder vs. Factory comparison
  - Fluent interface pattern
  - Immutability achieved through builder

**SourceMaking - Builder**
- **URL**: https://sourcemaking.com/design_patterns/builder
- **Content**: Alternative perspective with examples
- **Focus**: Complex object construction, Director role

**C++ Builder Pattern Examples**
- **URL**: https://www.bogotobogo.com/DesignPatterns/builder.php
- **Content**: C++-specific implementation details
- **Focus**: Code examples, when to use builder

---

## INI File Format

### Specification and Examples

**Wikipedia - INI File**
- **URL**: https://en.wikipedia.org/wiki/INI_file
- **Content**: Complete INI format specification
- **Topics**: Sections, key-value pairs, comments, data types

**Example INI Files**
- **URL**: Search GitHub for "example .ini files"
- **Relevant**: Configuration files from real projects (PHP, Python, etc.)
- **Study**: Common patterns, edge cases, conventions

---

## C++ Language Features

### String Manipulation

**cppreference - std::string**
- **URL**: https://en.cppreference.com/w/cpp/string/basic_string
- **Key Methods**:
  - `find(char)` - Find character position
  - `substr(pos, len)` - Extract substring  
  - `erase()` - Remove characters
  - `find_first_not_of()` - Find non-whitespace
  - `find_last_not_of()` - Find trailing non-whitespace

**Trimming Whitespace**
- **URL**: Search "C++ trim whitespace" on StackOverflow
- **Common Approaches**:
  - `find_first_not_of(" \t\n\r")` for left trim
  - `find_last_not_of(" \t\n\r")` for right trim
  - Combine for full trim

**cppreference - std::getline**
- **URL**: https://en.cppreference.com/w/cpp/string/basic_string/getline
- **Usage**: Read file line-by-line
- **Example**:
  ```cpp
  std::ifstream file("config.ini");
  std::string line;
  int lineNumber = 0;
  while (std::getline(file, line)) {
      ++lineNumber;
      // Process line...
  }
  ```

### Type Conversions

**cppreference - std::stoi**
- **URL**: https://en.cppreference.com/w/cpp/string/basic_string/stol
- **Usage**: Convert string to int
- **Exceptions**: `std::invalid_argument`, `std::out_of_range`
- **Example**:
  ```cpp
  try {
      int value = std::stoi("123");
  } catch (const std::invalid_argument& e) {
      // Handle conversion error
  }
  ```

**cppreference - std::stod**
- **URL**: https://en.cppreference.com/w/cpp/string/basic_string/stof
- **Usage**: Convert string to double
- **Exceptions**: Same as std::stoi

**Boolean Conversion**
- **No standard library function!** Must implement yourself
- **Approach**: Convert to lowercase, compare with accepted values
- **Common Values**: "true", "false", "1", "0", "yes", "no" (document which you accept)

### STL Containers

**cppreference - std::map**
- **URL**: https://en.cppreference.com/w/cpp/container/map
- **Key Concepts**:
  - Ordered key-value storage (sorted by key)
  - O(log n) insertion, lookup, deletion
  - Keys must be unique
  - `operator[]` vs `at()` for access
  - `find()` for existence checking

**cppreference - std::unordered_map**
- **URL**: https://en.cppreference.com/w/cpp/container/unordered_map
- **Comparison with std::map**:
  - Unordered (hash table)
  - O(1) average case operations
  - No guaranteed iteration order
  - Faster for large datasets

**Nested Maps**
- **Type**: `std::map<std::string, std::map<std::string, std::string>>`
- **Structure**: Outer map = sections, inner map = key-value pairs
- **Access**: `config["database"]["host"]`

**cppreference - std::optional (C++17)**
- **URL**: https://en.cppreference.com/w/cpp/utility/optional
- **Usage**: Represent optional values (may or may not exist)
- **Alternative to**: Returning nullptr or throwing exception
- **Example**:
  ```cpp
  std::optional<std::string> getValue(section, key) {
      if (exists) return value;
      return std::nullopt;
  }
  ```

### Exception Handling

**Custom Exceptions**
- **URL**: https://en.cppreference.com/w/cpp/error/exception
- **Pattern**: Derive from `std::runtime_error` or `std::exception`
- **Example**:
  ```cpp
  class ConfigParseError : public std::runtime_error {
  public:
      ConfigParseError(int lineNumber, const std::string& message)
          : std::runtime_error("Line " + std::to_string(lineNumber) + 
                               ": " + message) {}
  };
  ```

**Exception Safety**
- **URL**: Search "C++ exception safety guarantee"
- **Levels**: No-throw, strong, basic, none
- **Relevance**: Builder should provide strong guarantee (build succeeds or throws, no partial state)

---

## String Parsing Techniques

### Splitting Strings

**cppreference - std::istringstream**
- **URL**: https://en.cppreference.com/w/cpp/io/basic_istringstream
- **Usage**: Parse strings as streams
- **Example**:
  ```cpp
  std::istringstream iss("key = value");
  std::string key, equals, value;
  iss >> key >> equals >> value;
  ```

**Splitting on Delimiter**
- **URL**: Search "C++ split string on delimiter"
- **Approaches**:
  - `std::string::find()` in loop
  - `std::getline()` with custom delimiter
  - `std::istringstream` with `>>` operator

### Regular Expressions (Optional)

**cppreference - std::regex**
- **URL**: https://en.cppreference.com/w/cpp/regex
- **Usage**: Pattern matching for validation
- **Example**: Validate section header format
- **Warning**: Regex can be overkill for simple parsing (performance overhead)

---

## File I/O

**cppreference - std::ifstream**
- **URL**: https://en.cppreference.com/w/cpp/io/basic_ifstream
- **Key Methods**:
  - `open()`, `is_open()`, `good()`, `fail()`
  - Used with `std::getline()` for line-by-line reading

**Error Checking**
- **Check**: `file.is_open()` after opening
- **Check**: `file.good()` after reading
- **Throw**: Exception if file operations fail

---

## Testing Resources

### Google Test Framework

**Google Test Primer**
- **URL**: https://google.github.io/googletest/primer.html
- **Focus**: Test fixtures for setup/teardown

**Test Fixtures**
- **Usage**: Share setup code across multiple tests
- **Example**:
  ```cpp
  class ConfigTest : public ::testing::Test {
  protected:
      void SetUp() override {
          // Create test config file
      }
      void TearDown() override {
          // Cleanup test files
      }
  };
  
  TEST_F(ConfigTest, ParsesValidFile) {
      // Test uses fixture setup
  }
  ```

**Assertions for Exceptions**
- **URL**: https://google.github.io/googletest/reference/assertions.html
- **Relevant**:
  - `EXPECT_THROW(statement, exception_type)` - Expect specific exception
  - `EXPECT_NO_THROW(statement)` - Expect no exception
  - `EXPECT_ANY_THROW(statement)` - Expect any exception

---

## SOLID Principles

### Single Responsibility Principle (SRP)

**Application to Project**:
- **Config**: Stores and provides access to values (one responsibility)
- **ConfigBuilder**: Constructs Config objects (one responsibility)
- **ConfigParser**: Parses files (one responsibility)
- **Each class has single reason to change**

**Uncle Bob Article**
- **URL**: Search "Robert Martin Single Responsibility Principle"
- **Content**: In-depth explanation with examples

### Dependency Inversion Principle (DIP)

**Wikipedia - Dependency Inversion**
- **URL**: https://en.wikipedia.org/wiki/Dependency_inversion_principle
- **Definition**: Depend on abstractions, not concretions
- **Application**: Parser depends on builder interface (could use IConfigBuilder)

---

## Design Decisions to Make

### 1. Duplicate Handling

**Question**: What happens if same section defined twice?
**Options**:
- Throw error (strict parsing)
- Merge sections (lenient parsing)
- Last wins (overwrite)

**Recommendation**: Document decision clearly in README

### 2. Case Sensitivity

**Question**: Are section/key names case-sensitive?
**Options**:
- Case-sensitive: `[Database]` ≠ `[database]`
- Case-insensitive: Convert all to lowercase

**Recommendation**: Be consistent, document choice

### 3. Global Key-Value Pairs

**Question**: Allow key-value pairs before first section?
**Options**:
- Reject (throw error)
- Allow (global section with name "")

**Recommendation**: Most INI parsers reject, but document choice

### 4. Empty Values

**Question**: Is `key =` (no value) valid?
**Options**:
- Reject (throw error)
- Allow (store empty string)

**Recommendation**: Allow (real configs often have empty values)

### 5. Inline Comments

**Question**: Are inline comments allowed? `key = value # comment`
**Options**:
- Yes (split on `#` after finding `=`)
- No (everything after `=` is value)

**Recommendation**: Support inline comments (common in INI files)

---

## Immutability Patterns

### Const Correctness

**cppreference - const**
- **URL**: https://en.cppreference.com/w/cpp/language/cv
- **Application**:
  - All Config getters are `const` methods
  - Config data members are `const` (optional)
  - Builder's `build()` returns `const` Config (optional)

**Benefits**:
- Thread-safe reading (multiple threads can read simultaneously)
- Prevents accidental modification
- Clear API (getters only, no setters)

### Move Semantics

**cppreference - std::move**
- **URL**: https://en.cppreference.com/w/cpp/utility/move
- **Usage**: Transfer data from builder to config efficiently
- **Example**:
  ```cpp
  Config ConfigBuilder::build() {
      Config config(std::move(sections));  // Move, don't copy
      return config;
  }
  ```

---

## Debugging and Tools

### Testing INI Files

**Create Test Files**:
- `test_data/valid.ini` - Well-formed config
- `test_data/invalid.ini` - Syntax errors
- `test_data/complex.ini` - Edge cases

**Manual Testing**:
```bash
# Create test file
echo "[section]" > test.ini
echo "key = value" >> test.ini

# Run your parser
./config_parser_main test.ini
```

### Debugging Parse Errors

**Add Debug Output**:
```cpp
std::cout << "Line " << lineNumber << ": " << line << std::endl;
```

**Use Debugger**:
- Set breakpoint in parsing loop
- Step through line-by-line
- Inspect variables (currentSection, key, value)

---

## Code Examples (Conceptual)

### Trimming Whitespace (Pattern)

```cpp
// Left trim
string.erase(0, string.find_first_not_of(" \t\r\n"));

// Right trim  
string.erase(string.find_last_not_of(" \t\r\n") + 1);
```

### Parsing Key-Value (Pattern)

```cpp
size_t equalsPos = line.find('=');
if (equalsPos != std::string::npos) {
    std::string key = line.substr(0, equalsPos);
    std::string value = line.substr(equalsPos + 1);
    // Trim both...
}
```

### Checking for Comment (Pattern)

```cpp
bool isComment(const std::string& line) {
    if (line.empty()) return false;
    char first = line[0];
    return first == '#' || first == ';';
}
```

---

## Advanced Topics (Optional)

### Fluent Interface

**Pattern**: Return `*this` from builder methods for chaining
**Example**:
```cpp
ConfigBuilder& addSection(const std::string& name) {
    // ... add section logic ...
    return *this;
}

// Usage:
builder.addSection("db").addKeyValue("host", "localhost");
```

### Variants for Multi-Type Storage

**cppreference - std::variant (C++17)**
- **URL**: https://en.cppreference.com/w/cpp/utility/variant
- **Usage**: Store different types in same container
- **Alternative**: Store everything as string, convert on access (simpler)

---

## Common Algorithms

### Finding Section Header

```cpp
bool isSectionHeader(const std::string& line) {
    if (line.empty()) return false;
    if (line.front() == '[' && line.back() == ']') {
        // Validate section name...
        return true;
    }
    return false;
}
```

### Extracting Section Name

```cpp
std::string extractSectionName(const std::string& line) {
    // Remove '[' and ']'
    std::string name = line.substr(1, line.length() - 2);
    // Trim whitespace...
    return name;
}
```

---

## Performance Considerations

### Map vs. Unordered Map

| Feature | std::map | std::unordered_map |
|---------|----------|-------------------|
| **Ordering** | Sorted by key | Unordered |
| **Lookup** | O(log n) | O(1) average |
| **Memory** | Lower | Higher (hash table) |
| **Use When** | Need sorted iteration | Need fast lookup |

**Recommendation for Config**: `std::map` (config files are small, sorted iteration is nice)

### String Views (C++17)

**cppreference - std::string_view**
- **URL**: https://en.cppreference.com/w/cpp/string/basic_string_view
- **Usage**: Non-owning reference to string (avoids copies)
- **Caution**: Lifetime issues (view must not outlive string)

---

## Books (Optional)

### Design Patterns
- **"Design Patterns" by Gang of Four** - Builder pattern chapter
- **"Head First Design Patterns"** - More approachable explanations

### Modern C++
- **"Effective Modern C++"** by Scott Meyers - Move semantics, smart pointers
- **"C++ Primer"** by Lippman - Comprehensive C++ reference

---

## Summary of Key Resources

| Topic | Primary Resource | Why It's Useful |
|-------|------------------|-----------------|
| **Builder Pattern** | Refactoring Guru | Clear diagrams, C++ examples |
| **INI Format** | Wikipedia | Complete specification |
| **std::map** | cppreference | Container API reference |
| **String Parsing** | cppreference (getline, find) | Core parsing operations |
| **Type Conversion** | cppreference (stoi, stod) | Safe string-to-type conversion |
| **Exceptions** | cppreference | Custom exception creation |
| **Google Test** | Official Primer | Testing framework usage |

---

**Remember**: These resources are references for when you get stuck. Read requirements first, attempt implementation, then consult documentation when you encounter specific problems. Learning happens through productive struggle!

---

**Last Updated**: 2025-10-29  
**Maintainer**: Instructor  
**Feedback**: Report helpful or unhelpful resources for future improvements
