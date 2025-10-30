#include "config_parser.h"
#include "config_exceptions.h"
#include <iostream>
#include <exception>

/**
 * @brief Demo application for Configuration Parser
 * 
 * This program demonstrates the Builder pattern implementation
 * for parsing INI-style configuration files.
 * 
 * Usage:
 *   config_parser_main <config_file.ini>
 * 
 * Example INI file (config.ini):
 * @code
 * # Database configuration
 * [database]
 * host = localhost
 * port = 5432
 * username = admin
 * password = secret
 * use_ssl = true
 * timeout = 30.5
 * 
 * [logging]
 * level = info
 * enabled = true
 * file = /var/log/app.log
 * @endcode
 */

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " <config_file.ini>\n";
    std::cout << "\n";
    std::cout << "Example:\n";
    std::cout << "  " << programName << " config.ini\n";
}

int main(int argc, char* argv[]) {
    (void)argc; (void)argv;
    // TODO: Implement command-line argument parsing
    // Research questions:
    // 1. How to check argument count?
    // 2. What to do if wrong number of arguments?
    // 
    // Algorithm:
    // 1. Check if argc == 2 (program name + filename)
    // 2. If not, print usage and return 1
    // 3. Get filename from argv[1]
    //
    // Hint: argc is argument count, argv[0] is program name, argv[1] is first argument
    
    std::cerr << "Error: Not implemented\n";
    return 1;

    // TODO: Implement configuration parsing
    // Research questions:
    // 1. How to parse file using ConfigParser?
    // 2. What exceptions can be thrown?
    // 3. How to catch and handle exceptions?
    // 
    // Algorithm:
    // 1. Try to parse file with ConfigParser::parseFile()
    // 2. Catch ConfigParseError for parse errors
    // 3. Catch std::exception for other errors (file not found, etc.)
    // 4. Print error message and return non-zero
    //
    // Hint: Use try-catch blocks
    // Hint: ConfigParseError has getLineNumber() for debugging

    // TODO: Implement demonstrating config access
    // Research questions:
    // 1. How to access different data types?
    // 2. How to handle missing keys?
    // 
    // Example demonstration:
    // - Print database host
    // - Print database port (int)
    // - Print SSL enabled (bool)
    // - Print timeout (double)
    // - Show default values for missing keys
    // - List all sections and keys
    //
    // Hint: Use config.getString(), config.getInt(), etc.
    // Hint: Use config.getSections() and config.getKeys()
}
