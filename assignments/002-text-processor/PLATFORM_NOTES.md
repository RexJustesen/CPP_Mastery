# Cross-Platform Build Notes: Project 002 - Text File Processor

**Last Updated**: 2025-10-29  
**Project**: Text File Processor (Factory Method Pattern)  
**CMake Version**: 3.20+  
**C++ Standard**: C++17

---

## Verified Platforms

### ✅ Windows (TESTED)

**Environment**:
- OS: Windows 11
- Compiler: MSVC 19.44 (Visual Studio 2022)
- CMake: 3.31.1
- Build Tool: MSBuild (via Visual Studio)

**Build Commands**:
```powershell
# Configure
cmake -S . -B build -G "Visual Studio 17 2022"

# Build
cmake --build build --config Release

# Run tests
cd build
ctest -C Release --verbose

# Run executable
.\build\Release\text_processor_main.exe --help
```

**Status**: ✅ **FULLY WORKING**
- Library compiles: `text_processor_lib.lib`
- Executable compiles: `text_processor_main.exe`
- Tests build: `run_tests.exe`
- All 20 "Not implemented" stubs throw correctly (RED state verified)

**Notes**:
- MSVC uses `/W4 /WX` for strict warnings (set in CMakeLists.txt)
- Google Test fetched automatically via CMake FetchContent
- `gtest_force_shared_crt ON` required for MSVC compatibility
- Build artifacts in `build/Release/` or `build/Debug/`
- Fixed missing `#include <vector>` in processor_factory.h during initial build

---

### 🔲 Linux (UNTESTED - Documentation Only)

**Recommended Environment**:
- OS: Ubuntu 22.04 LTS or newer
- Compiler: GCC 11+ or Clang 14+
- CMake: 3.20+
- Build Tool: Make or Ninja

**Installation** (Ubuntu/Debian):
```bash
sudo apt-get update
sudo apt-get install -y cmake g++ libgtest-dev build-essential
```

**Build Commands** (GCC):
```bash
# Configure
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build build -j$(nproc)

# Run tests
cd build
ctest --verbose

# Run executable
./build/text_processor_main --help
```

**Expected Status**: ✅ **SHOULD WORK**

**Potential Issues**:
1. **String Manipulation**:
   - `::toupper` and `::tolower` are locale-dependent
   - May behave differently with non-ASCII characters
   - Solution: Tests use ASCII only, should be portable
   
2. **File I/O**:
   - Line ending differences (CRLF vs LF)
   - File path separators (\ vs /)
   - Solution: Tests use relative paths, Git handles line endings

---

### 🔲 macOS (UNTESTED - Documentation Only)

**Recommended Environment**:
- OS: macOS 12 (Monterey) or newer
- Compiler: Apple Clang 14+ (Xcode Command Line Tools)
- CMake: 3.20+
- Build Tool: Make or Ninja

**Installation** (Homebrew):
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Install CMake and Google Test
brew install cmake googletest
```

**Build Commands**:
```bash
# Configure
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build build -j$(sysctl -n hw.ncpu)

# Run tests
cd build
ctest --verbose

# Run executable
./build/text_processor_main --help
```

**Expected Status**: ✅ **SHOULD WORK**

---

## Project-Specific Cross-Platform Considerations

### 1. String Transformation (`::toupper`, `::tolower`)

**Issue**: Character conversion functions are locale-dependent
**Impact**: May behave differently on different platforms/locales
**Mitigation**:
- Tests use ASCII characters only
- Avoid Unicode in test strings
- Could use `std::locale` for explicit locale control (advanced)

**Example Code Pattern**:
```cpp
// Portable uppercase (ASCII only)
std::transform(input.begin(), input.end(), result.begin(), 
    [](unsigned char c) { return std::toupper(c); });
```

### 2. File I/O and Line Endings

**Issue**: Windows uses `\r\n` (CRLF), Unix uses `\n` (LF)
**Impact**: Line count might differ if files created on different platforms
**Mitigation**:
- Git configured with `core.autocrlf` handles conversion
- LineCountProcessor counts `\n` only (standardized)
- Tests create files programmatically (consistent line endings)

### 3. Command-Line Argument Parsing

**Issue**: No platform-specific issues expected
**Impact**: None (uses standard argc/argv)
**Mitigation**: N/A - fully portable

### 4. File Path Handling

**Issue**: Path separators differ (Windows `\` vs Unix `/`)
**Impact**: Minimal (using relative paths)
**Mitigation**:
- Tests use forward slashes (works on all platforms)
- CMake handles path conversion automatically
- Avoid absolute paths in tests

---

## CMakeLists.txt Configuration

### Platform-Agnostic Features ✅

The `CMakeLists.txt` is designed to work across platforms:

```cmake
# C++17 standard (all platforms)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Platform-specific warnings
if(MSVC)
  target_compile_options(text_processor_lib PRIVATE /W4 /WX)
else()
  target_compile_options(text_processor_lib PRIVATE 
    -Wall -Wextra -Wpedantic -Werror)
endif()

# Google Test FetchContent (automatic download)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
```

### Key Cross-Platform Design Decisions:

1. **No Platform-Specific Code**: All implementations use standard C++17
2. **FetchContent for Dependencies**: No manual Google Test installation needed
3. **Relative Paths**: Tests use relative file paths (portable)
4. **ASCII Test Data**: Avoids locale/encoding issues

---

## Common Issues & Solutions

### Issue 1: Missing `#include <vector>`

**Symptom**:
```
error C2039: 'vector': is not a member of 'std'
```

**Solution**:
Already fixed in `processor_factory.h`:
```cpp
#include <vector>
```

### Issue 2: Locale-Dependent toupper/tolower

**Symptom**: Different results for extended ASCII or Unicode
**Solution**: Use ASCII-only test strings, or cast to `unsigned char`:
```cpp
std::toupper(static_cast<unsigned char>(c))
```

### Issue 3: File Not Found in Tests

**Symptom**: Test file I/O fails with "File not found"
**Solution**: Tests create files in current directory, ensure write permissions

---

## Testing Checklist

Use this checklist when testing on new platforms:

### Build Phase
- [ ] CMake configures without errors
- [ ] Library compiles (`text_processor_lib`)
- [ ] Executable compiles (`text_processor_main`)
- [ ] Test executable compiles (`run_tests`)
- [ ] No compiler warnings (strict mode enabled)

### Google Test Phase
- [ ] Google Test downloads via FetchContent
- [ ] Tests discover correctly
- [ ] CTest lists 44 tests (`ctest -N`)

### RED State Verification
- [ ] All tests fail with "Not implemented" errors
- [ ] 20 function stubs confirmed throwing
- [ ] No test passes without implementation

### Runtime Phase
- [ ] Executable runs (even if functions throw)
- [ ] File I/O tests can create/read/delete files
- [ ] No segfaults or undefined behavior

---

## Differences from Project 001

| Aspect | Project 001 (Task Manager) | Project 002 (Text Processor) |
|--------|---------------------------|------------------------------|
| **File I/O** | Persistence (save/load tasks) | Read/write text files |
| **String Ops** | Minimal (task descriptions) | Heavy (transformations) |
| **Locale Issues** | None | toupper/tolower may vary |
| **CLI Parsing** | Menu-driven | Argument-based (--input, --processor) |
| **Cross-Platform Risk** | Low | Medium (string operations) |

Project 002 has slightly higher cross-platform risk due to string manipulation, but mitigated with ASCII-only test data.

---

## Summary

| Platform | Status | Compiler | Build Tool | Notes |
|----------|--------|----------|------------|-------|
| **Windows 11** | ✅ Tested | MSVC 19.44 | MSBuild | Fully working |
| **Ubuntu 22.04** | 🔲 Untested | GCC 11+ | Make | Should work |
| **macOS 12+** | 🔲 Untested | Apple Clang 14+ | Make | Should work |

**Confidence Level**: High (standard C++17, no platform-specific APIs)

**Known Issues**: None (fixed missing `#include <vector>` during build)

**Action Items**:
1. ✅ Windows build verified
2. ⏳ Test on Linux (Ubuntu VM or CI)
3. ⏳ Test on macOS (physical machine or CI)
4. ⏳ Update this file with actual test results

---

## Student Instructions

### First-Time Setup (All Platforms)

1. **Verify Prerequisites**:
   ```bash
   cmake --version  # Should be 3.20+
   g++ --version    # Or clang++ --version (C++17 support)
   ```

2. **Clone Repository**:
   ```bash
   git clone <repository-url>
   cd cpp_mastery/assignments/002-text-processor
   ```

3. **Build Project**:
   ```bash
   cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
   cmake --build build
   ```

4. **Run Tests** (expect failures):
   ```bash
   cd build
   ctest --verbose
   # All tests should fail with "Not implemented" - this is correct!
   ```

5. **Implement Functions**:
   - Open `src/*.cpp` files
   - Replace `throw std::runtime_error("Not implemented: ...")` with actual code
   - Follow TODO comments and research questions
   - Recompile and test until all tests pass (GREEN state)

6. **Test CLI** (after implementation):
   ```bash
   # Create test file
   echo "Hello World" > test.txt
   
   # Windows
   .\build\Release\text_processor_main.exe --input test.txt --processor uppercase
   
   # Linux/macOS
   ./build/text_processor_main --input test.txt --processor uppercase
   ```

---

## Maintenance

**Last Verified**: 2025-10-29  
**Next Review**: After Linux/macOS testing completed  
**Responsible**: Instructor or CI system

**Update This File When**:
- New platform tested (update status from 🔲 to ✅ or ❌)
- Platform-specific issue discovered
- CMake configuration changes
- New dependencies added

---

**Document Version**: 1.0  
**Status**: ✅ Windows verified, Linux/macOS documented but untested
