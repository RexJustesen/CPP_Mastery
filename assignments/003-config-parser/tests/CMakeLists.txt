# Test configuration for Config Parser
cmake_minimum_required(VERSION 3.20)

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable Google Test integration
include(GoogleTest)

# Test executable
add_executable(config_parser_tests
    test_config_parser.cpp
)

target_link_libraries(config_parser_tests
    PRIVATE config_parser_lib
    PRIVATE GTest::gtest_main
)

# Discover tests
gtest_discover_tests(config_parser_tests)
