cmake_minimum_required(VERSION 3.20)
project(task_manager VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings - strict compilation
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
        -Wall                # Enable most warnings
        -Wextra              # Enable extra warnings
        -Wpedantic           # Strict standard compliance
        -Werror              # Treat warnings as errors
    )
elseif(MSVC)
    add_compile_options(
        /W4                  # Warning level 4
        /WX                  # Treat warnings as errors
    )
endif()

# Project library - student implements these files
add_library(task_manager_lib
    src/task.cpp
    src/task_manager.cpp
    src/filter_strategy.cpp
)

# Public include directories
target_include_directories(task_manager_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Main executable (CLI interface)
add_executable(task_manager_main src/main.cpp)
target_link_libraries(task_manager_main task_manager_lib)

# Enable testing
enable_testing()
add_subdirectory(tests)
