# Cross-Platform Build Notes: Project 001 - Task Manager

**Last Updated**: 2025-10-29  
**Project**: Command-Line Task Manager (Strategy Pattern)  
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
.\build\Release\task_manager_main.exe
```

**Status**: ✅ **FULLY WORKING**
- Library compiles: `task_manager_lib.lib`
- Executable compiles: `task_manager_main.exe`
- Tests build: `run_tests.exe`
- All 60+ "Not implemented" stubs throw correctly (RED state verified)

**Notes**:
- MSVC uses `/W4 /WX` for strict warnings (set in CMakeLists.txt)
- Google Test fetched automatically via CMake FetchContent
- `gtest_force_shared_crt ON` required for MSVC compatibility
- Build artifacts in `build/Release/` or `build/Debug/`

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

**Installation** (Fedora/RHEL):
```bash
sudo dnf install cmake gcc-c++ gtest-devel
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
./build/task_manager_main
```

**Build Commands** (Clang):
```bash
# Configure with Clang
cmake -S . -B build \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_CXX_COMPILER=clang++

# Build
cmake --build build -j$(nproc)

# Run tests
cd build
ctest --verbose

# Run executable
./build/task_manager_main
```

**Expected Status**: ✅ **SHOULD WORK**

**Potential Issues**:
1. **Google Test Installation**:
   - Older Ubuntu versions may have Google Test headers only (no precompiled library)
   - Solution: CMake FetchContent will download and build Google Test automatically
   
2. **Compiler Warnings**:
   - GCC/Clang use `-Wall -Wextra -Wpedantic -Werror` (set in CMakeLists.txt)
   - Ensure code has no warnings (treated as errors with `-Werror`)

3. **Line Endings**:
   - Windows uses CRLF (`\r\n`), Linux uses LF (`\n`)
   - Git should handle automatically with `.gitattributes`
   - Manual fix: `dos2unix **/*.cpp **/*.h` if needed

---

### 🔲 macOS (UNTESTED - Documentation Only)

**Recommended Environment**:
- OS: macOS 12 (Monterey) or newer
- Compiler: Apple Clang 14+ (Xcode Command Line Tools)
- CMake: 3.20+
- Build Tool: Make or Ninja

**Installation** (Homebrew):
```bash
# Install Xcode Command Line Tools first
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
./build/task_manager_main
```

**Expected Status**: ✅ **SHOULD WORK**

**Potential Issues**:
1. **Google Test Finding**:
   - CMake may not find system-installed Google Test
   - Solution: FetchContent will download if not found
   - Alternative: Specify Google Test location:
     ```bash
     cmake -S . -B build \
       -DGTEST_ROOT=/opt/homebrew/opt/googletest
     ```

2. **Apple Clang vs LLVM Clang**:
   - Apple Clang has different version numbering
   - C++17 support: Apple Clang 10+ (Xcode 10+)
   - Check version: `clang++ --version`

3. **M1/M2 Architecture**:
   - Should work transparently (CMake handles ARM64 detection)
   - Google Test builds from source work on ARM64

---

## CMakeLists.txt Configuration

### Platform-Agnostic Features ✅

The `CMakeLists.txt` is designed to work across platforms:

```cmake
# C++17 standard (all platforms)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform-specific warnings
if(MSVC)
  target_compile_options(task_manager_lib PRIVATE /W4 /WX)
else()
  target_compile_options(task_manager_lib PRIVATE 
    -Wall -Wextra -Wpedantic -Werror)
endif()

# Google Test FetchContent (automatic download)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# Windows-specific: Use shared CRT
if(MSVC)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
```

### Key Features:
1. **Automatic Google Test**: Downloads if not found locally
2. **Platform-specific warnings**: MSVC (`/W4`) vs GCC/Clang (`-Wall`)
3. **Strict compilation**: All warnings treated as errors (`-Werror`, `/WX`)
4. **CTest integration**: `enable_testing()` and `gtest_discover_tests()`

---

## Common Issues & Solutions

### Issue 1: Google Test Not Found

**Symptom**:
```
CMake Error: Could not find GTest
```

**Solution**:
CMake FetchContent will download automatically. If still fails:
```bash
# Option 1: Install system-wide
sudo apt-get install libgtest-dev  # Linux
brew install googletest            # macOS

# Option 2: Force CMake to use FetchContent
cmake -S . -B build -DFETCHCONTENT_FULLY_DISCONNECTED=OFF
```

### Issue 2: C++17 Not Supported

**Symptom**:
```
error: unsupported option '-std=c++17'
```

**Solution**:
Update compiler:
```bash
# Ubuntu
sudo apt-get install g++-11

# macOS
xcode-select --install  # Ensures latest Xcode tools
```

### Issue 3: "Not implemented" Errors During Tests

**Symptom**:
```
terminate called after throwing an instance of 'std::runtime_error'
  what():  Not implemented: Task::getId
```

**Solution**:
✅ **THIS IS EXPECTED** (RED state)
- All tests MUST fail initially with "Not implemented"
- Students implement functions to reach GREEN state
- This is NOT a build error - it's the starting point

### Issue 4: Line Ending Issues (Windows ↔ Linux)

**Symptom**:
```
warning: CRLF will be replaced by LF
```

**Solution**:
Configure Git (one-time setup):
```bash
# Windows
git config --global core.autocrlf true

# Linux/macOS
git config --global core.autocrlf input
```

Or use `.gitattributes`:
```
*.cpp text eol=lf
*.h text eol=lf
*.md text eol=lf
CMakeLists.txt text eol=lf
```

### Issue 5: Permission Denied (Linux/macOS)

**Symptom**:
```
bash: ./build/task_manager_main: Permission denied
```

**Solution**:
```bash
chmod +x build/task_manager_main
./build/task_manager_main
```

---

## Testing Checklist

Use this checklist when testing on new platforms:

### Build Phase
- [ ] CMake configures without errors (`cmake -S . -B build`)
- [ ] Library compiles (`task_manager_lib`)
- [ ] Executable compiles (`task_manager_main`)
- [ ] Test executable compiles (`run_tests`)
- [ ] No compiler warnings (strict mode enabled)

### Google Test Phase
- [ ] Google Test downloads via FetchContent (or finds system install)
- [ ] Tests discover correctly (`gtest_discover_tests()`)
- [ ] CTest lists all tests (`ctest -N`)

### RED State Verification
- [ ] All tests fail with "Not implemented" errors (not build errors)
- [ ] Total of 30+ tests exist
- [ ] No test passes without student implementation

### Runtime Phase
- [ ] Executable runs without segfaults
- [ ] CLI displays menu (even if functions throw)
- [ ] File I/O paths work with platform conventions

---

## Continuous Integration Recommendations

### GitHub Actions (Future T007)

**.github/workflows/ci.yml** (example):
```yaml
name: Cross-Platform Build

on: [push, pull_request]

jobs:
  build:
    strategy:
      matrix:
        os: [ubuntu-latest, macos-latest, windows-latest]
        include:
          - os: ubuntu-latest
            compiler: g++
          - os: macos-latest
            compiler: clang++
          - os: windows-latest
            compiler: msvc

    runs-on: ${{ matrix.os }}

    steps:
    - uses: actions/checkout@v3
    
    - name: Configure CMake
      run: cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    
    - name: Build
      run: cmake --build build --config Release
    
    - name: Test
      run: |
        cd build
        ctest -C Release --verbose || echo "Tests expected to fail (RED state)"
```

---

## Platform-Specific Recommendations

### Windows Developers
- ✅ Use Visual Studio 2022 (MSVC 19.44+)
- ✅ Git Bash or PowerShell for terminal
- ✅ Windows Terminal recommended
- ⚠️ Avoid MinGW unless experienced (ABI compatibility issues)

### Linux Developers
- ✅ Use GCC 11+ or Clang 14+
- ✅ Install `build-essential` package
- ✅ Consider Ninja for faster builds: `cmake -G Ninja`
- ⚠️ WSL2 users: Follow Linux instructions

### macOS Developers
- ✅ Install Xcode Command Line Tools
- ✅ Use Homebrew for dependencies
- ✅ Apple Silicon (M1/M2) fully supported
- ⚠️ Older macOS: Check C++17 support

---

## Summary

| Platform | Status | Compiler | Build Tool | Google Test | Notes |
|----------|--------|----------|------------|-------------|-------|
| **Windows 11** | ✅ Tested | MSVC 19.44 | MSBuild | FetchContent | Fully working |
| **Ubuntu 22.04** | 🔲 Untested | GCC 11+ | Make | apt/FetchContent | Should work |
| **macOS 12+** | 🔲 Untested | Apple Clang 14+ | Make | Homebrew/FetchContent | Should work |

**Confidence Level**: High (CMake designed for cross-platform compatibility)

**Action Items**:
1. ✅ Windows build verified
2. ⏳ Test on Linux (Ubuntu VM or CI)
3. ⏳ Test on macOS (physical machine or CI)
4. ⏳ Document any platform-specific issues discovered
5. ⏳ Update this file with actual test results

---

## Student Instructions

### First-Time Setup (All Platforms)

1. **Verify Prerequisites**:
   ```bash
   cmake --version  # Should be 3.20+
   g++ --version    # Or clang++ --version
   ```

2. **Clone Repository** (when available):
   ```bash
   git clone <repository-url>
   cd cpp_mastery/assignments/001-task-manager
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
   - Recompile and test until all tests pass (GREEN state)

6. **Run Executable**:
   ```bash
   # Windows
   .\build\Release\task_manager_main.exe
   
   # Linux/macOS
   ./build/task_manager_main
   ```

### Development Workflow (RED → GREEN → REFACTOR)

1. **RED**: Run tests, see failures (starting point)
2. **GREEN**: Implement minimal code to pass one test
3. **REFACTOR**: Improve code quality while keeping tests passing
4. **Repeat**: Move to next failing test

---

## Maintenance

**Last Verified**: 2025-10-29  
**Next Review**: After Linux/macOS testing completed  
**Responsible**: Instructor or CI system

**Update This File When**:
- New platform tested (update status from 🔲 to ✅ or ❌)
- Platform-specific issue discovered (add to "Common Issues")
- CMake configuration changes
- Google Test version updated
- New C++ standard adopted (C++20, C++23)

---

**Document Version**: 1.0  
**Status**: ✅ Windows verified, Linux/macOS documented but untested
