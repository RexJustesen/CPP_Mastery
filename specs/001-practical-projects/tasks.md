# Implementation Tasks: Practical C++ Projects Curriculum

**Feature**: `001-practical-projects`  
**Branch**: `001-practical-projects`  
**Generated**: 2025-10-29

---

## Overview

This task list breaks down the implementation of 30 practical C++ learning projects into actionable, checkable tasks. Each project is treated as an independent module with consistent structure: specification, comprehensive test suite, boilerplate code, and learning resources.

**Key Principles**:
- All tests written FIRST (RED state verified)
- Zero solution disclosure maintained throughout
- Each project independently buildable and testable
- Progressive difficulty: Tier 1 (Beginner) → Tier 4 (Expert)

**Implementation Strategy**:
- **MVP**: Complete Tier 1 (Projects 1-5) first to validate template effectiveness
- **Incremental Delivery**: Release projects tier-by-tier as students progress
- **Parallel Development**: Multiple projects within a tier can be developed simultaneously

---

## Task Legend

- `[P]` = **Parallelizable** - Can be done concurrently with other [P] tasks
- `[Tier1]`, `[Tier2]`, `[Tier3]`, `[Tier4]` = Project difficulty tier labels
- Task format: `- [ ] TXXX [P] [TierN] Description with file path`

---

## Phase 1: Setup & Infrastructure

**Goal**: Establish repository structure, tooling, and reusable templates for all 30 projects

**Success Criteria**:
- ✅ `assignments/` directory created and structured
- ✅ All contract templates validated and ready for instantiation
- ✅ Documentation complete and accessible
- ✅ Build system verified on Windows/Linux/macOS

### Tasks

- [x] T001 Create `assignments/` root directory in repository
- [x] T002 Create `docs/` directory for general documentation (if not exists)
- [x] T003 Verify all contract templates in `specs/001-practical-projects/contracts/`
- [ ] T004 Test instantiate one template to verify correctness (use Project 1 as test case)
- [ ] T005 Document template instantiation process in `docs/creating-assignments.md`
- [x] T006 Create `assignments/README.md` with curriculum overview and navigation
- [ ] T007 Set up CI/CD pipeline template for automated test verification (optional)

---

## Phase 2: Tier 1 - Beginner Projects (MVP)

**Goal**: Implement Projects 1-5 (foundational C++ syntax, basic patterns, STL usage)

**Success Criteria**:
- ✅ All 5 projects have complete specifications
- ✅ All tests written and verified in RED state (fail with boilerplate)
- ✅ Boilerplate code provided with TODO markers
- ✅ Reference solutions created privately (not committed to student branches)
- ✅ All tests pass with reference solutions (GREEN state verified)
- ✅ Each project independently buildable with CMake

---

### Project 1: Command-Line Task Manager (Strategy Pattern)

**Pattern**: Strategy | **Tier**: 1 | **SOLID**: SRP, OCP | **Estimated Time**: 2-3 days

- [x] T101 [P] [Tier1] Create `assignments/001-task-manager/` directory structure
- [x] T102 [P] [Tier1] Instantiate `assignment-readme-template.md` → `assignments/001-task-manager/README.md`
  - Fill in: Learning objectives, requirements (REQ-001 to REQ-015), Strategy pattern guidance, test scenarios
- [x] T103 [P] [Tier1] Instantiate `resources-template.md` → `assignments/001-task-manager/references/resources.md`
  - Customize: C++ features (classes, vectors, file I/O), Strategy pattern links, SRP/OCP resources
- [x] T104 [P] [Tier1] Create `assignments/001-task-manager/include/task.h`
  - Define: Task class with id, description, priority, completion status
- [x] T105 [P] [Tier1] Create `assignments/001-task-manager/include/task_manager.h`
  - Define: TaskManager class with add, remove, update, filter methods
- [x] T106 [P] [Tier1] Create `assignments/001-task-manager/include/filter_strategy.h`
  - Define: IFilterStrategy interface, PriorityFilter, StatusFilter, DateFilter concrete strategies
- [x] T107 [P] [Tier1] Instantiate `source-template.cpp` → `assignments/001-task-manager/src/task.cpp`
  - Add TODO stubs for Task constructor, getters, setters
- [x] T108 [P] [Tier1] Instantiate `source-template.cpp` → `assignments/001-task-manager/src/task_manager.cpp`
  - Add TODO stubs for TaskManager methods (add, remove, filter, save, load)
- [x] T109 [P] [Tier1] Instantiate `source-template.cpp` → `assignments/001-task-manager/src/filter_strategy.cpp`
  - Add TODO stubs for strategy implementations
- [x] T110 [P] [Tier1] Create `assignments/001-task-manager/src/main.cpp` with basic CLI skeleton and TODOs
- [x] T111 [Tier1] Instantiate `root-cmakelists-template.txt` → `assignments/001-task-manager/CMakeLists.txt`
  - Configure: C++17, add all source files to task_manager_lib
- [x] T112 [Tier1] Instantiate `test-cmakelists-template.txt` → `assignments/001-task-manager/tests/CMakeLists.txt`
- [x] T113 [Tier1] Write comprehensive test suite in `assignments/001-task-manager/tests/test_task_manager.cpp`
  - Section 1: Basic Functionality (10-15 tests): AddTask, RemoveTask, UpdateTask, GetAllTasks
  - Section 2: Edge Cases (5-10 tests): EmptyList, DuplicateIds, MaxCapacity, BoundaryDates
  - Section 3: Error Handling (5-10 tests): InvalidId, NullInput, InvalidPriority, FileNotFound
  - Section 4: Design Pattern (3-5 tests): StrategySwappable, FilterCorrectness, MultipleCriteria
  - Section 5: Persistence (3-5 tests): SaveToFile, LoadFromFile, FileIntegrity
- [x] T114 [Tier1] Instantiate `gitignore-template` → `assignments/001-task-manager/.gitignore`
- [x] T115 [Tier1] Build Project 1 and verify RED state (all tests fail with "Not implemented")
- [ ] T116 [Tier1] Create reference solution privately to verify tests pass (GREEN state) - DO NOT COMMIT [SKIPPED]
- [x] T117 [Tier1] Validate constitution compliance: No solution hints in README, resources, or stubs
- [x] T118 [Tier1] Test build on Windows, Linux, macOS (or document platform-specific notes)

---

### Project 2: Text File Processor (Factory Pattern)

**Pattern**: Factory Method | **Tier**: 1 | **SOLID**: OCP, SRP | **Estimated Time**: 2-3 days

- [x] T201 [P] [Tier1] Create `assignments/002-text-processor/` directory structure
- [x] T202 [P] [Tier1] Instantiate `assignment-readme-template.md` → `assignments/002-text-processor/README.md`
  - Fill in: Requirements for text transformations (uppercase, lowercase, word count, line count, find/replace)
- [x] T203 [P] [Tier1] Instantiate `resources-template.md` → `assignments/002-text-processor/references/resources.md`
  - Customize: Factory pattern links, file I/O references, string manipulation
- [x] T204 [P] [Tier1] Create `assignments/002-text-processor/include/processor.h`
  - Define: ITextProcessor interface with process() method
- [x] T205 [P] [Tier1] Create `assignments/002-text-processor/include/processor_factory.h`
  - Define: ProcessorFactory class with createProcessor(type) method
- [x] T206 [P] [Tier1] Create `assignments/002-text-processor/include/processors.h`
  - Define: UppercaseProcessor, LowercaseProcessor, WordCountProcessor, LineCountProcessor, FindReplaceProcessor
- [x] T207 [P] [Tier1] Instantiate source templates for processor.cpp, processor_factory.cpp, processors.cpp with TODO stubs
- [x] T208 [P] [Tier1] Create `assignments/002-text-processor/src/main.cpp` with CLI skeleton
- [x] T209 [Tier1] Instantiate CMakeLists.txt files (root and tests/)
- [x] T210 [Tier1] Write comprehensive test suite in `tests/test_text_processor.cpp`
  - Basic Functionality (10 tests): Each processor type works correctly
  - Edge Cases (8 tests): Empty files, very large files, special characters, Unicode
  - Error Handling (5 tests): File not found, invalid processor type, read-only files
  - Pattern Verification (5 tests): Factory creates correct types, new processors extensible
- [x] T211 [Tier1] Copy .gitignore from template
- [x] T212 [Tier1] Build and verify RED state
- [ ] T213 [Tier1] Create reference solution privately, verify GREEN state - DO NOT COMMIT [SKIPPED]
- [x] T214 [Tier1] Validate constitution compliance
- [x] T215 [Tier1] Cross-platform build verification

---

### Project 3: Configuration File Parser (Builder Pattern)

**Pattern**: Builder | **Tier**: 1 | **SOLID**: SRP | **Estimated Time**: 3-4 days

- [ ] T301 [P] [Tier1] Create `assignments/003-config-parser/` directory structure
- [ ] T302 [P] [Tier1] Instantiate README with requirements for INI-style config parsing
  - Requirements: Parse sections, key-value pairs, comments, type conversion (string, int, bool, double)
- [ ] T303 [P] [Tier1] Instantiate resources.md with Builder pattern, parsing strategies, std::map usage
- [ ] T304 [P] [Tier1] Create `include/config.h` - Config class representing parsed configuration
- [ ] T305 [P] [Tier1] Create `include/config_builder.h` - ConfigBuilder class for step-by-step construction
- [ ] T306 [P] [Tier1] Create `include/config_parser.h` - Parser using builder to construct Config
- [ ] T307 [P] [Tier1] Instantiate source templates with TODO stubs
- [ ] T308 [P] [Tier1] Create main.cpp for testing configuration loading
- [ ] T309 [Tier1] Instantiate CMakeLists.txt files
- [ ] T310 [Tier1] Write comprehensive test suite
  - Basic: Parse valid config, access values, type conversions
  - Edge: Empty files, malformed syntax, duplicate keys, missing sections
  - Error: Invalid syntax, type conversion failures, file I/O errors
  - Pattern: Builder constructs incrementally, immutable Config object
- [ ] T311 [Tier1] Copy .gitignore
- [ ] T312 [Tier1] Build and verify RED state
- [ ] T313 [Tier1] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T314 [Tier1] Constitution compliance check
- [ ] T315 [Tier1] Cross-platform build test

---

### Project 4: Simple File Organizer (Command Pattern)

**Pattern**: Command | **Tier**: 1 | **SOLID**: SRP, OCP | **Estimated Time**: 3-4 days

- [ ] T401 [P] [Tier1] Create `assignments/004-file-organizer/` directory structure
- [ ] T402 [P] [Tier1] Instantiate README with requirements for file organization (move by type, date, size) with undo/redo
- [ ] T403 [P] [Tier1] Instantiate resources.md with Command pattern, std::filesystem, undo/redo strategies
- [ ] T404 [P] [Tier1] Create `include/command.h` - ICommand interface with execute(), undo() methods
- [ ] T405 [P] [Tier1] Create `include/file_commands.h` - MoveFileCommand, CopyFileCommand, DeleteFileCommand
- [ ] T406 [P] [Tier1] Create `include/organizer.h` - FileOrganizer class with command queue, execute, undo, redo
- [ ] T407 [P] [Tier1] Instantiate source templates with TODO stubs
- [ ] T408 [P] [Tier1] Create main.cpp with CLI for organizing files
- [ ] T409 [Tier1] Instantiate CMakeLists.txt (note: C++17 for <filesystem>)
- [ ] T410 [Tier1] Write comprehensive test suite
  - Basic: Execute commands, organize files by type/date/size
  - Edge: Empty directories, symbolic links, read-only files, nested directories
  - Error: Insufficient permissions, disk full, invalid paths
  - Pattern: Undo/redo works correctly, command queue maintains history
- [ ] T411 [Tier1] Copy .gitignore
- [ ] T412 [Tier1] Build and verify RED state
- [ ] T413 [Tier1] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T414 [Tier1] Constitution compliance check
- [ ] T415 [Tier1] Cross-platform build test

---

### Project 5: CSV Data Analyzer (Template Method Pattern)

**Pattern**: Template Method | **Tier**: 1 | **SOLID**: OCP, SRP | **Estimated Time**: 3-4 days

- [ ] T501 [P] [Tier1] Create `assignments/005-csv-analyzer/` directory structure
- [ ] T502 [P] [Tier1] Instantiate README with requirements for CSV parsing and analysis (sum, average, min, max, custom analysis)
- [ ] T503 [P] [Tier1] Instantiate resources.md with Template Method pattern, CSV parsing, std::variant for mixed types
- [ ] T504 [P] [Tier1] Create `include/csv_reader.h` - CSV file reader class
- [ ] T505 [P] [Tier1] Create `include/analyzer.h` - Abstract Analyzer base class with template method analyze()
- [ ] T506 [P] [Tier1] Create `include/analyzers.h` - SumAnalyzer, AverageAnalyzer, MinMaxAnalyzer, CountAnalyzer
- [ ] T507 [P] [Tier1] Instantiate source templates with TODO stubs
- [ ] T508 [P] [Tier1] Create main.cpp for running analyses on CSV files
- [ ] T509 [Tier1] Instantiate CMakeLists.txt
- [ ] T510 [Tier1] Write comprehensive test suite
  - Basic: Parse CSV, run each analyzer type, correct results
  - Edge: Empty CSV, single row, single column, missing values, quoted fields
  - Error: Malformed CSV, type mismatches, file not found
  - Pattern: Template method enforces algorithm structure, new analyzers extend without modifying base
- [ ] T511 [Tier1] Copy .gitignore
- [ ] T512 [Tier1] Build and verify RED state
- [ ] T513 [Tier1] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T514 [Tier1] Constitution compliance check
- [ ] T515 [Tier1] Cross-platform build test

---

## Phase 3: Tier 2 - Intermediate Projects (Part 1: Projects 6-10)

**Goal**: Introduce OOP, templates, RAII, concurrency basics, and more complex patterns

**Success Criteria**: Same as Tier 1 (specs, tests RED/GREEN, boilerplate, constitution compliance)

---

### Project 6: WAV Audio File Reader/Writer (Adapter Pattern)

**Pattern**: Adapter | **Tier**: 2 | **SOLID**: ISP, SRP | **Estimated Time**: 5-7 days

- [ ] T601 [P] [Tier2] Create `assignments/006-wav-file-io/` directory structure
- [ ] T602 [P] [Tier2] Instantiate README with requirements for WAV file I/O (read/write PCM data, support various formats)
- [ ] T603 [P] [Tier2] Instantiate resources.md with Adapter pattern, binary I/O, WAV format specification
- [ ] T604 [P] [Tier2] Create `include/audio_data.h` - AudioData class (sample rate, channels, samples)
- [ ] T605 [P] [Tier2] Create `include/audio_reader.h` - IAudioReader interface
- [ ] T606 [P] [Tier2] Create `include/audio_writer.h` - IAudioWriter interface
- [ ] T607 [P] [Tier2] Create `include/wav_adapter.h` - WavFileAdapter adapting low-level WAV format to IAudioReader/Writer
- [ ] T608 [P] [Tier2] Instantiate source templates with TODO stubs
- [ ] T609 [P] [Tier2] Create main.cpp for reading/writing WAV files
- [ ] T610 [Tier2] Instantiate CMakeLists.txt (no external audio dependencies for I/O)
- [ ] T611 [Tier2] Write comprehensive test suite (include sample WAV files in tests/data/)
  - Basic: Read WAV, write WAV, roundtrip (read → write → read should match)
  - Edge: Mono/stereo, 8/16/24-bit depth, various sample rates, large files
  - Error: Corrupt headers, unsupported formats, file I/O errors
  - Pattern: Adapter provides clean interface to messy binary format
- [ ] T612 [Tier2] Copy .gitignore
- [ ] T613 [Tier2] Build and verify RED state
- [ ] T614 [Tier2] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T615 [Tier2] Constitution compliance check
- [ ] T616 [Tier2] Cross-platform build test

---

### Project 7: Audio Effects Processor (Decorator Pattern)

**Pattern**: Decorator | **Tier**: 2 | **SOLID**: OCP, SRP | **Estimated Time**: 5-7 days

- [ ] T701 [P] [Tier2] Create `assignments/007-audio-effects/` directory structure
- [ ] T702 [P] [Tier2] Instantiate README with requirements for audio effects (reverb, delay, gain, lowpass filter, effect chaining)
- [ ] T703 [P] [Tier2] Instantiate resources.md with Decorator pattern, DSP basics, effect algorithms
- [ ] T704 [P] [Tier2] Create `include/audio_effect.h` - IAudioEffect interface with process(AudioData) method
- [ ] T705 [P] [Tier2] Create `include/effects.h` - GainEffect, DelayEffect, ReverbEffect, LowPassFilterEffect decorators
- [ ] T706 [P] [Tier2] Create `include/effect_chain.h` - EffectChain class for composing multiple effects
- [ ] T707 [P] [Tier2] Instantiate source templates with TODO stubs (DSP algorithms as TODOs)
- [ ] T708 [P] [Tier2] Create main.cpp for applying effects to WAV files (reuses Project 6)
- [ ] T709 [Tier2] Instantiate CMakeLists.txt (depends on Project 6 or duplicate WAV I/O)
- [ ] T710 [Tier2] Write comprehensive test suite
  - Basic: Each effect processes audio correctly, effect chaining works
  - Edge: Silent audio (all zeros), clipping detection, extreme parameter values
  - Error: Null input, invalid parameters (negative gain, delay out of range)
  - Pattern: Effects stackable, order matters, decorator wraps cleanly
  - Performance: Effects run in reasonable time for typical audio lengths
- [ ] T711 [Tier2] Copy .gitignore
- [ ] T712 [Tier2] Build and verify RED state
- [ ] T713 [Tier2] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T714 [Tier2] Constitution compliance check
- [ ] T715 [Tier2] Cross-platform build test

---

### Project 8: Event-Driven Logger System (Observer + Singleton)

**Pattern**: Observer, Singleton | **Tier**: 2 | **SOLID**: OCP, SRP | **Estimated Time**: 5-7 days

- [ ] T801 [P] [Tier2] Create `assignments/008-event-logger/` directory structure
- [ ] T802 [P] [Tier2] Instantiate README with requirements for logging system (multiple outputs: console, file, network; log levels)
- [ ] T803 [P] [Tier2] Instantiate resources.md with Observer pattern, Singleton pattern, thread safety basics
- [ ] T804 [P] [Tier2] Create `include/log_event.h` - LogEvent class (level, timestamp, message, source)
- [ ] T805 [P] [Tier2] Create `include/log_observer.h` - ILogObserver interface with notify(LogEvent) method
- [ ] T806 [P] [Tier2] Create `include/logger.h` - Logger singleton with subscribe/unsubscribe/log methods
- [ ] T807 [P] [Tier2] Create `include/log_observers.h` - ConsoleObserver, FileObserver, NetworkObserver (stub)
- [ ] T808 [P] [Tier2] Instantiate source templates with TODO stubs
- [ ] T809 [P] [Tier2] Create main.cpp demonstrating multi-output logging
- [ ] T810 [Tier2] Instantiate CMakeLists.txt
- [ ] T811 [Tier2] Write comprehensive test suite
  - Basic: Subscribe observers, log events, observers notified
  - Edge: Multiple subscribers, unsubscribe mid-execution, log level filtering
  - Error: Null observer, file write failures, observer throws exception
  - Pattern: Singleton accessible globally, observers decoupled from logger
  - Concurrency: Basic thread safety (bonus: test concurrent logging)
- [ ] T812 [Tier2] Copy .gitignore
- [ ] T813 [Tier2] Build and verify RED state
- [ ] T814 [Tier2] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T815 [Tier2] Constitution compliance check
- [ ] T816 [Tier2] Cross-platform build test

---

### Project 9: Custom String Class with Iterators (Iterator Pattern)

**Pattern**: Iterator | **Tier**: 2 | **SOLID**: SRP, OCP | **Estimated Time**: 6-8 days

- [ ] T901 [P] [Tier2] Create `assignments/009-custom-string/` directory structure
- [ ] T902 [P] [Tier2] Instantiate README with requirements for custom string (memory management, operators, iterators)
- [ ] T903 [P] [Tier2] Instantiate resources.md with Iterator pattern, operator overloading, RAII, move semantics
- [ ] T904 [P] [Tier2] Create `include/my_string.h` - MyString class with full interface
  - Constructors (default, copy, move), destructor
  - Operators: +, +=, ==, !=, <, [], <<
  - Methods: length(), c_str(), substr(), find()
  - Iterators: begin(), end(), const iterators
- [ ] T905 [P] [Tier2] Create `include/string_iterator.h` - Iterator class implementing iterator requirements
- [ ] T906 [P] [Tier2] Instantiate source templates with TODO stubs (memory management critical)
- [ ] T907 [P] [Tier2] Create main.cpp demonstrating string usage
- [ ] T908 [Tier2] Instantiate CMakeLists.txt
- [ ] T909 [Tier2] Write comprehensive test suite
  - Basic: Construction, copy, move, operators, methods work
  - Edge: Empty string, very long strings, single character, special characters
  - Error: Out of bounds access, null pointer handling
  - Pattern: Iterators work with STL algorithms (std::find, std::sort, etc.)
  - Memory: No leaks (Valgrind/ASan required), proper cleanup
- [ ] T910 [Tier2] Copy .gitignore
- [ ] T911 [Tier2] Build and verify RED state
- [ ] T912 [Tier2] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T913 [Tier2] Constitution compliance check
- [ ] T914 [Tier2] Cross-platform build test

---

### Project 10: Thread-Safe Task Queue (Producer-Consumer Pattern)

**Pattern**: Producer-Consumer | **Tier**: 2 | **SOLID**: DIP, SRP | **Estimated Time**: 7-10 days

- [ ] T1001 [P] [Tier2] Create `assignments/010-task-queue/` directory structure
- [ ] T1002 [P] [Tier2] Instantiate README with requirements for concurrent task queue (enqueue, dequeue, thread-safe)
- [ ] T1003 [P] [Tier2] Instantiate resources.md with concurrency, mutexes, condition variables, RAII locks
- [ ] T1004 [P] [Tier2] Create `include/task.h` - ITask interface with execute() method
- [ ] T1005 [P] [Tier2] Create `include/task_queue.h` - TaskQueue class (thread-safe queue)
- [ ] T1006 [P] [Tier2] Create `include/worker_thread.h` - WorkerThread class consuming from queue
- [ ] T1007 [P] [Tier2] Instantiate source templates with TODO stubs (concurrency primitives)
- [ ] T1008 [P] [Tier2] Create main.cpp with producer-consumer demonstration
- [ ] T1009 [Tier2] Instantiate CMakeLists.txt (link pthread on Linux)
- [ ] T1010 [Tier2] Write comprehensive test suite
  - Basic: Enqueue, dequeue, multiple producers/consumers
  - Edge: Empty queue, full queue (if bounded), rapid enqueue/dequeue
  - Error: Dequeue from empty (should block or return error)
  - Concurrency: No data races, no deadlocks (tested with thread sanitizer)
  - Pattern: Queue abstraction hides synchronization details
- [ ] T1011 [Tier2] Copy .gitignore
- [ ] T1012 [Tier2] Build and verify RED state
- [ ] T1013 [Tier2] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T1014 [Tier2] Constitution compliance check
- [ ] T1015 [Tier2] Cross-platform build test (thread library differences)

---

## Phase 4: Tier 2 - Intermediate Projects (Part 2: Projects 11-15)

**Goal**: Continue intermediate patterns and introduce plugins, serialization, and performance optimization

---

### Project 11: File System Watcher (Observer Pattern)

**Pattern**: Observer | **Tier**: 2 | **SOLID**: OCP, SRP | **Estimated Time**: 7-10 days

- [ ] T1101 [P] [Tier2] Create `assignments/011-file-watcher/` directory structure
- [ ] T1102 [P] [Tier2] Instantiate README with requirements for filesystem monitoring (watch directories, notify on changes)
- [ ] T1103 [P] [Tier2] Instantiate resources.md with Observer pattern, platform filesystem APIs, polling vs events
- [ ] T1104 [P] [Tier2] Create `include/file_event.h` - FileEvent class (type: created/modified/deleted, path, timestamp)
- [ ] T1105 [P] [Tier2] Create `include/file_observer.h` - IFileObserver interface with onFileEvent(FileEvent)
- [ ] T1106 [P] [Tier2] Create `include/file_watcher.h` - FileWatcher class (watch paths, notify observers)
- [ ] T1107 [P] [Tier2] Instantiate source templates with TODO stubs (platform-specific code conditional)
- [ ] T1108 [P] [Tier2] Create main.cpp for watching directories
- [ ] T1109 [Tier2] Instantiate CMakeLists.txt (platform-specific: inotify/FSEvents/ReadDirectoryChangesW)
- [ ] T1110 [Tier2] Write comprehensive test suite
  - Basic: Watch directory, detect file creation/modification/deletion
  - Edge: Recursive watching, large directory trees, rapid changes
  - Error: Non-existent paths, permission denied, watcher overflow
  - Pattern: Multiple observers notified, observers decoupled
  - Platform: Tests account for platform differences (or document)
- [ ] T1111 [Tier2] Copy .gitignore
- [ ] T1112 [Tier2] Build and verify RED state
- [ ] T1113 [Tier2] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T1114 [Tier2] Constitution compliance check
- [ ] T1115 [Tier2] Cross-platform build test (platform-specific implementations)

---

### Project 12: Simple HTTP Server (Chain of Responsibility)

**Pattern**: Chain of Responsibility | **Tier**: 2 | **SOLID**: OCP, SRP | **Estimated Time**: 8-10 days

- [ ] T1201 [P] [Tier2] Create `assignments/012-http-server/` directory structure
- [ ] T1202 [P] [Tier2] Instantiate README with requirements for basic HTTP server (GET/POST, static files, middleware chain)
- [ ] T1203 [P] [Tier2] Instantiate resources.md with Chain of Responsibility, HTTP protocol, socket programming
- [ ] T1204 [P] [Tier2] Create `include/http_request.h` - HttpRequest class (method, path, headers, body)
- [ ] T1205 [P] [Tier2] Create `include/http_response.h` - HttpResponse class (status, headers, body)
- [ ] T1206 [P] [Tier2] Create `include/request_handler.h` - IRequestHandler interface with handleRequest() and setNext()
- [ ] T1207 [P] [Tier2] Create `include/handlers.h` - StaticFileHandler, LoggingHandler, AuthHandler, NotFoundHandler
- [ ] T1208 [P] [Tier2] Create `include/http_server.h` - HttpServer class managing socket and handler chain
- [ ] T1209 [P] [Tier2] Instantiate source templates with TODO stubs (socket code, HTTP parsing)
- [ ] T1210 [P] [Tier2] Create main.cpp for running server
- [ ] T1211 [Tier2] Instantiate CMakeLists.txt (link ws2_32 on Windows, no extra libs on Linux/macOS)
- [ ] T1212 [Tier2] Write comprehensive test suite (use HTTP client or mock sockets)
  - Basic: Serve static files, handle GET/POST, handler chain processes requests
  - Edge: Large files, concurrent requests, malformed HTTP
  - Error: File not found (404), permission denied (403), bad request (400)
  - Pattern: Handlers chained, each decides to handle or pass to next
  - Integration: Real HTTP requests to running server (or mock sockets)
- [ ] T1213 [Tier2] Copy .gitignore
- [ ] T1214 [Tier2] Build and verify RED state
- [ ] T1215 [Tier2] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T1216 [Tier2] Constitution compliance check
- [ ] T1217 [Tier2] Cross-platform build test (socket APIs differ)

---

### Project 13: Serialization Framework (Visitor Pattern)

**Pattern**: Visitor | **Tier**: 2 | **SOLID**: OCP, SRP | **Estimated Time**: 8-10 days

- [ ] T1301 [P] [Tier2] Create `assignments/013-serialization/` directory structure
- [ ] T1302 [P] [Tier2] Instantiate README with requirements for serialization (to JSON, XML, binary; support various types)
- [ ] T1303 [P] [Tier2] Instantiate resources.md with Visitor pattern, serialization concepts, JSON/XML formats
- [ ] T1304 [P] [Tier2] Create `include/serializable.h` - ISerializable interface with accept(ISerializer&) method
- [ ] T1305 [P] [Tier2] Create `include/serializer.h` - ISerializer visitor interface (visitInt, visitString, visitObject, etc.)
- [ ] T1306 [P] [Tier2] Create `include/serializers.h` - JsonSerializer, XmlSerializer, BinarySerializer
- [ ] T1307 [P] [Tier2] Create `include/sample_types.h` - Example serializable classes (Person, Address, etc.)
- [ ] T1308 [P] [Tier2] Instantiate source templates with TODO stubs
- [ ] T1309 [P] [Tier2] Create main.cpp demonstrating serialization/deserialization
- [ ] T1310 [Tier2] Instantiate CMakeLists.txt
- [ ] T1311 [Tier2] Write comprehensive test suite
  - Basic: Serialize/deserialize each type (int, string, object, array), roundtrip matches
  - Edge: Nested objects, null values, empty collections, large data
  - Error: Invalid JSON/XML, type mismatches, missing required fields
  - Pattern: New serialization formats added without modifying objects (OCP)
  - Integration: Serialized output parseable by external tools (optional validation)
- [ ] T1312 [Tier2] Copy .gitignore
- [ ] T1313 [Tier2] Build and verify RED state
- [ ] T1314 [Tier2] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T1315 [Tier2] Constitution compliance check
- [ ] T1316 [Tier2] Cross-platform build test

---

### Project 14: Plugin System with Dynamic Loading (Abstract Factory)

**Pattern**: Abstract Factory | **Tier**: 2 | **SOLID**: DIP, OCP | **Estimated Time**: 8-10 days

- [ ] T1401 [P] [Tier2] Create `assignments/014-plugin-system/` directory structure
- [ ] T1402 [P] [Tier2] Instantiate README with requirements for plugin loading (dynamic libraries, plugin interface)
- [ ] T1403 [P] [Tier2] Instantiate resources.md with Abstract Factory, dynamic loading (dlopen/LoadLibrary), plugin architecture
- [ ] T1404 [P] [Tier2] Create `include/plugin.h` - IPlugin interface with initialize(), execute(), shutdown() methods
- [ ] T1405 [P] [Tier2] Create `include/plugin_manager.h` - PluginManager class (load, unload, list plugins)
- [ ] T1406 [P] [Tier2] Create `include/plugin_factory.h` - Plugin factory interface for creating plugin instances
- [ ] T1407 [P] [Tier2] Create example plugin in `example_plugins/` directory (separate CMake target as shared library)
- [ ] T1408 [P] [Tier2] Instantiate source templates with TODO stubs (dynamic loading code platform-specific)
- [ ] T1409 [P] [Tier2] Create main.cpp for loading and executing plugins
- [ ] T1410 [Tier2] Instantiate CMakeLists.txt (add_library SHARED for plugins, platform-specific dlopen/LoadLibrary)
- [ ] T1411 [Tier2] Write comprehensive test suite
  - Basic: Load plugin, execute plugin methods, unload plugin
  - Edge: Multiple plugins, plugin dependencies, hot reload
  - Error: Plugin not found, incompatible plugin version, plugin crash isolation
  - Pattern: New plugins added without recompiling host application
  - Integration: Build real .so/.dll plugin, load at runtime
- [ ] T1412 [Tier2] Copy .gitignore
- [ ] T1413 [Tier2] Build and verify RED state
- [ ] T1414 [Tier2] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T1415 [Tier2] Constitution compliance check
- [ ] T1416 [Tier2] Cross-platform build test (dlopen vs LoadLibrary)

---

### Project 15: Memory Pool Allocator (Object Pool Pattern)

**Pattern**: Object Pool | **Tier**: 2 | **SOLID**: SRP | **Estimated Time**: 8-10 days

- [ ] T1501 [P] [Tier2] Create `assignments/015-memory-pool/` directory structure
- [ ] T1502 [P] [Tier2] Instantiate README with requirements for memory pool (fixed-size allocator, allocation/deallocation)
- [ ] T1503 [P] [Tier2] Instantiate resources.md with Object Pool pattern, memory management, allocator concepts
- [ ] T1504 [P] [Tier2] Create `include/memory_pool.h` - MemoryPool template class
- [ ] T1505 [P] [Tier2] Create `include/pooled_object.h` - Example object using pool allocator
- [ ] T1506 [P] [Tier2] Instantiate source templates with TODO stubs (allocation algorithm, free list management)
- [ ] T1507 [P] [Tier2] Create main.cpp demonstrating pool performance vs standard allocator
- [ ] T1508 [Tier2] Instantiate CMakeLists.txt
- [ ] T1509 [Tier2] Write comprehensive test suite
  - Basic: Allocate/deallocate objects, reuse freed slots, grow pool if needed
  - Edge: Pool exhaustion, fragmentation, alignment requirements
  - Error: Double-free detection, allocate after pool destroyed
  - Performance: Pool faster than malloc/new for many small allocations (benchmark test)
  - Memory: No leaks, all pool memory freed on destruction
- [ ] T1510 [Tier2] Copy .gitignore
- [ ] T1511 [Tier2] Build and verify RED state
- [ ] T1512 [Tier2] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] T1513 [Tier2] Constitution compliance check
- [ ] T1514 [Tier2] Cross-platform build test

---

## Phase 5: Tier 3 - Advanced Projects (Projects 16-25)

**Goal**: Advanced C++ features, performance optimization, complex system architecture

**Note**: Due to length, Tier 3 tasks follow same pattern as Tier 1-2 but with increased complexity. Each project requires 1-3 weeks.

**Projects**:
- 16: Audio Synthesizer Engine (State + Composite)
- 17: Build System Generator (Interpreter)
- 18: Database Query Engine (Interpreter + Composite)
- 19: Real-Time Audio Stream Processor (Bridge)
- 20: Concurrent Web Scraper (Flyweight)
- 21: Smart Pointer Library (Proxy)
- 22: Expression Template Math Library (Template Metaprogramming)
- 23: Code Formatter/Linter (Visitor)
- 24: Process Monitor & Resource Tracker (Mediator)
- 25: Lock-Free Data Structures

**Task Template for Each Tier 3 Project** (multiply by 10 projects):

- [ ] TXXX1 [P] [Tier3] Create project directory structure
- [ ] TXXX2 [P] [Tier3] Instantiate README with advanced requirements
- [ ] TXXX3 [P] [Tier3] Instantiate resources.md with advanced topics
- [ ] TXXX4-TXXX8 [P] [Tier3] Create all header files (more complex class hierarchies)
- [ ] TXXX9-TXXX12 [P] [Tier3] Instantiate source templates with TODO stubs
- [ ] TXXX13 [P] [Tier3] Create main.cpp
- [ ] TXXX14 [Tier3] Instantiate CMakeLists.txt (possibly with C++20 for some projects)
- [ ] TXXX15 [Tier3] Write comprehensive test suite (20-30 tests per project, including performance tests)
- [ ] TXXX16 [Tier3] Copy .gitignore
- [ ] TXXX17 [Tier3] Build and verify RED state
- [ ] TXXX18 [Tier3] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] TXXX19 [Tier3] Constitution compliance check
- [ ] TXXX20 [Tier3] Cross-platform build test

**Estimated Total Tasks for Tier 3**: 10 projects × 20 tasks = **200 tasks** (T1601-T2500)

---

## Phase 6: Tier 4 - Expert Projects (Projects 26-30)

**Goal**: System-level programming, advanced concurrency, architectural integration

**Projects**:
- 26: Custom Memory Allocator with Debugging (Strategy + Decorator)
- 27: Coroutine-Based Async I/O Framework (C++20 Coroutines)
- 28: Mini Game Engine (Multiple Patterns Integration)
- 29: Distributed Task Processing System (Master-Worker)
- 30: JIT Compiler for Simple Language (Interpreter + multiple patterns)

**Task Template for Each Tier 4 Project** (multiply by 5 projects):

- [ ] TXXX1 [P] [Tier4] Create project directory structure
- [ ] TXXX2 [P] [Tier4] Instantiate README with expert-level requirements
- [ ] TXXX3 [P] [Tier4] Instantiate resources.md with system programming topics
- [ ] TXXX4-TXXX10 [P] [Tier4] Create all header files (complex architectures, C++20 features)
- [ ] TXXX11-TXXX15 [P] [Tier4] Instantiate source templates with TODO stubs
- [ ] TXXX16 [P] [Tier4] Create main.cpp (often complex driver programs)
- [ ] TXXX17 [Tier4] Instantiate CMakeLists.txt (C++20 required for some)
- [ ] TXXX18 [Tier4] Write comprehensive test suite (30+ tests, stress tests, integration tests)
- [ ] TXXX19 [Tier4] Copy .gitignore
- [ ] TXXX20 [Tier4] Build and verify RED state
- [ ] TXXX21 [Tier4] Create reference solution, verify GREEN - DO NOT COMMIT
- [ ] TXXX22 [Tier4] Constitution compliance check
- [ ] TXXX23 [Tier4] Cross-platform build test (may have platform limitations for expert projects)

**Estimated Total Tasks for Tier 4**: 5 projects × 23 tasks = **115 tasks** (T2601-T3030)

---

## Phase 7: Polish & Cross-Cutting Concerns

**Goal**: Final validation, documentation, and release preparation

- [ ] T3101 Review all 30 projects for consistent naming, style, structure
- [ ] T3102 Verify all CMakeLists.txt compile with no warnings on Windows/Linux/macOS
- [ ] T3103 Run all test suites and verify 100% RED state with boilerplate (no tests pass prematurely)
- [ ] T3104 Create curriculum navigation guide in `assignments/README.md`
- [ ] T3105 Write installation/setup guide for all platforms in root README.md
- [ ] T3106 Create troubleshooting guide for common build/test issues
- [ ] T3107 Document platform-specific quirks and workarounds
- [ ] T3108 Generate project dependency graph showing tier prerequisites
- [ ] T3109 Create estimated completion timeline guide
- [ ] T3110 Set up automated CI/CD for verifying RED state on all platforms (optional but recommended)
- [ ] T3111 Final constitutional compliance audit: verify ZERO solution code in any repository file
- [ ] T3112 Create instructor guide for code review (separate private document)
- [ ] T3113 Tag release version: v1.0 - Full 30-Project C++ Curriculum

---

## Task Summary

**Total Tasks**: ~650 tasks across all phases

**Breakdown**:
- Phase 1 (Setup): 7 tasks
- Phase 2 (Tier 1 MVP - Projects 1-5): 90 tasks (18 tasks × 5 projects)
- Phase 3 (Tier 2 Part 1 - Projects 6-10): 95 tasks (19 tasks × 5 projects)
- Phase 4 (Tier 2 Part 2 - Projects 11-15): 100 tasks (20 tasks × 5 projects)
- Phase 5 (Tier 3 - Projects 16-25): 200 tasks (20 tasks × 10 projects)
- Phase 6 (Tier 4 - Projects 26-30): 115 tasks (23 tasks × 5 projects)
- Phase 7 (Polish): 13 tasks

---

## Parallel Execution Opportunities

**Within Each Tier**:
- All `[P]` tasks can be done concurrently (e.g., writing multiple READMEs simultaneously)
- Header file creation parallelizable across projects
- Test writing parallelizable across projects
- Build system instantiation parallelizable

**Across Tiers**:
- Tier 2 can begin once Tier 1 MVP validated (after T518)
- Tier 3 can begin once Tier 2 Part 1 complete
- Tier 4 can begin once Tier 3 fully validated

**Example Parallel Workflow for Tier 1**:
1. Create all 5 project directories simultaneously (T101, T201, T301, T401, T501)
2. Write all 5 READMEs in parallel (T102, T202, T302, T402, T502)
3. Create all header files across projects (parallelizable)
4. Write all test suites in parallel (most time-consuming step)
5. Sequential: Build and verify RED/GREEN states per project

---

## Dependencies

**Sequential Dependencies**:
- Phase 1 (Setup) MUST complete before any project work
- Each project's README must be complete before tests can be written
- Tests must be complete and RED state verified before reference solution created
- Reference solution must verify GREEN state before moving to next project

**Tier Dependencies**:
- Tier 1 completion recommended before starting Tier 2 (validates templates)
- No hard dependency between Tier 2-3-4, but pedagogical progression important
- Students must complete tiers sequentially (curriculum design), but developers can build projects in any order

---

## Independent Test Criteria

**Per Project**:
- ✅ Builds successfully with CMake on Windows/Linux/macOS
- ✅ All tests compile without errors
- ✅ RED state verified: All tests fail with boilerplate code
- ✅ GREEN state verified: All tests pass with reference solution (private)
- ✅ No memory leaks detected (Valgrind/AddressSanitizer)
- ✅ No compiler warnings with `-Wall -Wextra -Wpedantic`
- ✅ Constitutional compliance: Zero solution hints in any provided materials

**Per Tier**:
- ✅ All projects in tier meet per-project criteria
- ✅ Progressive difficulty validated (each project builds on previous skills)
- ✅ Learning objectives clearly achieved by completing tier

---

## Suggested MVP Scope

**Minimum Viable Product**: Complete Tier 1 (Projects 1-5)

**Rationale**:
- Validates all contract templates work as intended
- Demonstrates complete workflow: spec → tests → boilerplate → verification
- Provides usable foundation for students to begin learning
- Earliest feedback on template effectiveness and constitutional compliance

**Deliverables for MVP**:
1. 5 complete, tested, verified projects
2. All documentation and resources
3. Proven cross-platform builds
4. Constitutional compliance demonstrated
5. Student-ready materials

**MVP Timeline Estimate**: 2-3 weeks with focused effort

---

## Implementation Strategy

**Phase-Based Approach**:
1. **Setup (Week 1)**: Complete Phase 1, set up infrastructure
2. **MVP (Weeks 2-3)**: Complete Tier 1, validate templates
3. **Expansion (Weeks 4-12)**: Complete Tier 2 in two parts
4. **Advanced (Weeks 13-24)**: Complete Tier 3, incremental releases
5. **Expert (Weeks 25-30)**: Complete Tier 4, most complex projects
6. **Polish (Week 31)**: Final review, documentation, release

**Incremental Releases**:
- **v0.1**: Phase 1 + Project 1 (proof of concept)
- **v0.5**: Tier 1 complete (MVP)
- **v1.0**: Tiers 1-2 complete (beginner + intermediate)
- **v1.5**: Tiers 1-3 complete (beginner through advanced)
- **v2.0**: All 30 projects complete (full curriculum)

---

## Format Validation

✅ **All tasks follow checklist format**:
- Checkbox: `- [ ]`
- Task ID: `TXXX`
- Labels: `[P]` (if parallelizable), `[TierN]` (tier indicator)
- Description: Clear action with file path or specific artifact

✅ **Project organization by tier**: Tasks grouped logically by difficulty level

✅ **File paths specified**: Every task creating a file includes full path

✅ **Dependencies clear**: Sequential dependencies noted, parallelization opportunities marked

✅ **Constitutional compliance**: Verification tasks ensure zero solution disclosure maintained

---

**Document Status**: ✅ COMPLETE - Ready for implementation
**Next Action**: Begin Phase 1 (Setup) with task T001