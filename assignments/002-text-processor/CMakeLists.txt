cmake_minimum_required(VERSION 3.20)
project(TextProcessor VERSION 1.0 LANGUAGES CXX)

# C++17 standard required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library target (all processor logic, no main)
add_library(text_processor_lib
    src/processor_factory.cpp
    src/processors.cpp
    src/file_utils.cpp
)

target_include_directories(text_processor_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Platform-specific compiler warnings (strict mode)
if(MSVC)
    target_compile_options(text_processor_lib PRIVATE /W4 /WX)
else()
    target_compile_options(text_processor_lib PRIVATE
        -Wall -Wextra -Wpedantic -Werror
    )
endif()

# Executable target (CLI application)
add_executable(text_processor_main
    src/main.cpp
)

target_link_libraries(text_processor_main PRIVATE
    text_processor_lib
)

# Platform-specific warnings for executable
if(MSVC)
    target_compile_options(text_processor_main PRIVATE /W4 /WX)
else()
    target_compile_options(text_processor_main PRIVATE
        -Wall -Wextra -Wpedantic -Werror
    )
endif()

# Enable testing
enable_testing()
add_subdirectory(tests)
