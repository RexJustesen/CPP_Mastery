cmake_minimum_required(VERSION 3.20)

# Google Test dependency via FetchContent
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Windows: Use shared CRT to match project settings
if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(run_tests
    test_text_processor.cpp
)

target_link_libraries(run_tests PRIVATE
    text_processor_lib
    gtest_main
)

# Platform-specific warnings
if(MSVC)
    target_compile_options(run_tests PRIVATE /W4 /WX)
else()
    target_compile_options(run_tests PRIVATE
        -Wall -Wextra -Wpedantic -Werror
    )
endif()

# Discover tests for CTest integration
include(GoogleTest)
gtest_discover_tests(run_tests)
