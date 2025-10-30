# Fetch Google Test framework
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0  # Latest stable version
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make Google Test available
FetchContent_MakeAvailable(googletest)

# Test executable - links against project library and Google Test
add_executable(run_tests
    test_task_manager.cpp
)

# Link test executable with project library and gtest_main
target_link_libraries(run_tests
    task_manager_lib  # Student's implementation
    gtest_main        # Google Test main function (handles test runner)
)

# Discover and register tests with CTest
include(GoogleTest)
gtest_discover_tests(run_tests)
