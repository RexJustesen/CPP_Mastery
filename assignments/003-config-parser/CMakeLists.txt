cmake_minimum_required(VERSION 3.20)
project(ConfigParser VERSION 1.0.0 LANGUAGES CXX)

# C++17 required (std::optional, std::string_view available but not required)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Strict compiler warnings
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

# Library: config_parser_lib
add_library(config_parser_lib STATIC
    src/config_exceptions.cpp
    src/config.cpp
    src/config_builder.cpp
    src/config_parser.cpp
)

target_include_directories(config_parser_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Executable: config_parser_main
add_executable(config_parser_main
    src/main.cpp
)

target_link_libraries(config_parser_main
    PRIVATE config_parser_lib
)

# Tests
enable_testing()
add_subdirectory(tests)

# Installation (optional)
install(TARGETS config_parser_lib config_parser_main
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/
    DESTINATION include/config_parser
    FILES_MATCHING PATTERN "*.h"
)
