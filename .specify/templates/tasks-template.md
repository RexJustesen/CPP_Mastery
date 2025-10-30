---

description: "Task list template for learning module development"
---

# Tasks: [ASSIGNMENT MODULE NAME]

**Input**: Assignment specification from `/specs/[###-topic-name]/spec.md`
**Prerequisites**: Learning objectives defined, prerequisite modules identified

**Purpose**: These tasks are for CREATING the learning module (assignment spec + tests + boilerplate), NOT for the learner solving the assignment.

---

## Format: `[ID] [P?] [Category] Description`

- **[P]**: Can run in parallel (different files, no dependencies)
- **[Category]**: Type of task (SPEC, TEST, BOILERPLATE, DOCS)
- Include exact file paths in descriptions

---

## Path Conventions for C++ Learning Modules

```text
assignments/[###-topic-name]/
├── README.md                    # Assignment specification
├── CMakeLists.txt              # Build configuration
├── include/                    # Header files for student implementation
│   └── [module].h
├── src/                        # Source files (student implements these)
│   └── main.cpp                # Entry point or boilerplate
├── tests/                      # Pre-written test suite
│   ├── CMakeLists.txt
│   └── test_[module].cpp
└── references/                 # Links to learning resources
    └── resources.md
```

---

## Phase 1: Assignment Specification (SPEC)

**Purpose**: Define the learning problem clearly and unambiguously

- [ ] T001 [SPEC] Create assignment specification in `assignments/[###-topic-name]/README.md`
  - Include: learning objectives, problem statement, requirements, input/output specs
- [ ] T002 [SPEC] Define test suite overview and success criteria
- [ ] T003 [P] [SPEC] Curate reference materials (cppreference, docs, textbooks)
- [ ] T004 [P] [SPEC] Define code review criteria specific to this assignment

**Constitution Verification**:
- [ ] No solution hints or algorithm reveals in specification
- [ ] Learning objectives clearly stated
- [ ] Real-world relevance articulated
- [ ] Prerequisites identified

---

## Phase 2: Test Suite Development (TEST)

**Purpose**: Create comprehensive pre-written tests defining success

**⚠️ CRITICAL**: Tests must be written BEFORE any assignment is given to learners

- [ ] T005 Select C++ testing framework (Google Test recommended)
- [ ] T006 [P] [TEST] Implement basic functionality tests in `tests/test_[module].cpp`
  - [ ] Core requirement verification (REQ-001, REQ-002, etc.)
- [ ] T007 [P] [TEST] Implement edge case tests
  - [ ] Boundary conditions
  - [ ] Empty input handling
  - [ ] Maximum/minimum values
- [ ] T008 [P] [TEST] Implement error handling tests
  - [ ] Invalid input detection
  - [ ] Exception behavior validation
  - [ ] Error message verification
- [ ] T009 [TEST] Configure test build system in `tests/CMakeLists.txt`
- [ ] T010 [TEST] Create test runner script for automated execution
- [ ] T011 [TEST] Verify test suite fails with missing implementation (RED state)

**Test Quality Verification**:
- [ ] All requirements have corresponding tests
- [ ] Tests have clear, descriptive names
- [ ] Test output provides diagnostic information on failure
- [ ] 100% code coverage of specification requirements

---

## Phase 3: Boilerplate & Setup (BOILERPLATE)

**Purpose**: Provide necessary project structure WITHOUT revealing solutions

- [ ] T012 [P] [BOILERPLATE] Create CMake build configuration in `assignments/[###-topic-name]/CMakeLists.txt`
- [ ] T013 [P] [BOILERPLATE] Create header file skeleton in `include/[module].h`
  - [ ] Function/class declarations
  - [ ] Documentation comments for interface
  - [ ] NO implementations
- [ ] T014 [P] [BOILERPLATE] Create source file stub in `src/main.cpp` or `src/[module].cpp`
  - [ ] Minimal entry point or structure
  - [ ] TODO comments indicating where student implements solution
  - [ ] NO solution logic
- [ ] T015 [BOILERPLATE] Create `.gitignore` for build artifacts
- [ ] T016 [BOILERPLATE] Verify boilerplate compiles but tests fail (expected state)

**Constitution Verification**:
- [ ] No implementation code provided
- [ ] Clear separation: boilerplate vs. solution code
- [ ] Student knows exactly what to implement

---

## Phase 4: Documentation & Resources (DOCS)

**Purpose**: Guide learners without revealing solutions

- [ ] T017 [P] [DOCS] Create reference materials document in `references/resources.md`
  - [ ] Links to cppreference.com sections
  - [ ] Relevant C++ Core Guidelines
  - [ ] Textbook chapter references
  - [ ] Debugging tool recommendations
- [ ] T018 [P] [DOCS] Add conceptual hints (if needed) to README
  - [ ] High-level thinking prompts only
  - [ ] NO algorithm or solution reveals
- [ ] T019 [P] [DOCS] Document test execution procedure
- [ ] T020 [P] [DOCS] Create code review checklist in README
- [ ] T021 [DOCS] Add "Getting Help" guidelines to README

**Constitution Verification**:
- [ ] Resources enable self-directed learning
- [ ] No solution disclosure in documentation
- [ ] Debugging strategies included

---

## Phase 5: Validation & Integration (VALIDATION)

**Purpose**: Ensure module meets constitution standards

- [ ] T022 Conduct constitution compliance review:
  - [ ] Teaching-First Philosophy: No solutions provided
  - [ ] Test-Driven Learning: Comprehensive tests pre-written
  - [ ] Zero Solution Disclosure: All materials checked
  - [ ] Progressive Mastery Path: Difficulty appropriate, prerequisites clear
  - [ ] Code Review Gate: Review criteria defined
  - [ ] Self-Reliance: Reference materials support independent learning
- [ ] T023 Verify test suite:
  - [ ] Tests compile and run
  - [ ] Tests fail with boilerplate (RED state confirmed)
  - [ ] Test output is clear and diagnostic
- [ ] T024 Verify build system:
  - [ ] CMake configuration works
  - [ ] Compilation succeeds
  - [ ] Test execution automated
- [ ] T025 [P] Create solution (for instructor verification only—NOT shared with learners)
- [ ] T026 Verify solution passes all tests (GREEN state confirmed)
- [ ] T027 Document module in curriculum roadmap
- [ ] T028 Add module to prerequisite dependency graph

---

## Phase 6: Peer Review (Optional but Recommended)

**Purpose**: Second pair of eyes for quality and constitution compliance

- [ ] T029 [P] Peer review assignment specification for clarity
- [ ] T030 [P] Peer review test suite for comprehensiveness
- [ ] T031 [P] Peer review for solution disclosure (constitution compliance)
- [ ] T032 Incorporate feedback and iterate

---

## Dependencies & Execution Order

### Phase Dependencies

1. **Specification (Phase 1)**: No dependencies—can start immediately
2. **Test Suite (Phase 2)**: Depends on completed specification
3. **Boilerplate (Phase 3)**: Can run parallel with test suite after specification
4. **Documentation (Phase 4)**: Depends on specification and test suite outline
5. **Validation (Phase 5)**: Depends on all previous phases
6. **Peer Review (Phase 6)**: Depends on validation completion

### Parallel Opportunities

- Within Phase 1: T003 (reference curation) and T004 (review criteria) can run parallel
- Within Phase 2: All test category implementations (T006, T007, T008) can run parallel
- Within Phase 3: All boilerplate tasks (T012-T014) can run parallel
- Within Phase 4: All documentation tasks (T017-T021) can run parallel

---

## Notes

- [P] tasks = different files, no dependencies, can be done simultaneously
- [Category] labels for easy tracking: SPEC, TEST, BOILERPLATE, DOCS, VALIDATION
- Test-first is mandatory: Tests written → Tests fail → Module ready for learner
- Constitution compliance verified at multiple stages
- Solution implementation (T025) is for validation only—NEVER shared with learners
- Learners will work in the assignment directory, implementing code to pass pre-written tests
