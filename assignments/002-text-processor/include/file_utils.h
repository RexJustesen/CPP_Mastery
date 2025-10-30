/**
 * @file file_utils.h
 * @brief File I/O utility functions
 * 
 * Provides utility functions for reading from and writing to text files.
 * These functions handle error checking and throw exceptions on failure.
 * 
 * @author Student Name
 * @date 2025-10-29
 */

#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>

/**
 * @brief Read entire contents of text file into string
 * 
 * Opens the specified file, reads all content, and returns as std::string.
 * Uses efficient reading method (std::istreambuf_iterator) to minimize copying.
 * 
 * @param filename Path to file to read (relative or absolute)
 * @return std::string Complete file contents
 * 
 * @throws std::runtime_error If file cannot be opened or read
 * 
 * @complexity O(n) where n = file size
 * 
 * **Error Conditions**:
 * - File does not exist → throw std::runtime_error("File not found: " + filename)
 * - File is not readable (permissions) → throw std::runtime_error("Cannot read file: " + filename)
 * - I/O error during reading → throw std::runtime_error("Error reading file: " + filename)
 * 
 * **Usage Example**:
 * @code
 * try {
 *     std::string content = readFile("input.txt");
 *     std::cout << "File has " << content.length() << " characters\n";
 * } catch (const std::runtime_error& e) {
 *     std::cerr << "Error: " << e.what() << std::endl;
 * }
 * @endcode
 * 
 * **TODO for Implementation**:
 * 1. Create std::ifstream with filename
 * 2. Check if file opened successfully (is_open())
 * 3. If failed, throw std::runtime_error with descriptive message
 * 4. Read entire file using std::istreambuf_iterator:
 *    std::string content((std::istreambuf_iterator<char>(file)),
 *                         std::istreambuf_iterator<char>());
 * 5. Return content
 * 
 * **Research Questions**:
 * - What's std::istreambuf_iterator and why is it efficient?
 * - What does the extra parentheses around first iterator do? (Most vexing parse!)
 * - How would you read very large files (>1GB) without loading into memory?
 * 
 * **Alternative Approaches**:
 * - std::getline() in loop (less efficient, multiple allocations)
 * - file.read() with pre-sized buffer (requires knowing file size first)
 * - Memory-mapped file (platform-specific, complex)
 */
std::string readFile(const std::string& filename);

/**
 * @brief Write string content to text file
 * 
 * Opens the specified file for writing (creates if doesn't exist, truncates if exists)
 * and writes the entire content string.
 * 
 * @param filename Path to file to write (relative or absolute)
 * @param content Text content to write
 * 
 * @throws std::runtime_error If file cannot be opened or written
 * 
 * @complexity O(n) where n = content.length()
 * 
 * **Error Conditions**:
 * - Cannot create file (directory doesn't exist) → throw std::runtime_error
 * - Cannot write (disk full, read-only) → throw std::runtime_error
 * - I/O error during writing → throw std::runtime_error
 * 
 * **Usage Example**:
 * @code
 * try {
 *     writeFile("output.txt", "Hello, World!\n");
 *     std::cout << "File written successfully\n";
 * } catch (const std::runtime_error& e) {
 *     std::cerr << "Error: " << e.what() << std::endl;
 * }
 * @endcode
 * 
 * **TODO for Implementation**:
 * 1. Create std::ofstream with filename
 * 2. Check if file opened successfully (is_open())
 * 3. If failed, throw std::runtime_error with descriptive message
 * 4. Write content using << operator or write()
 * 5. Check for write errors (good() or fail())
 * 6. File closes automatically when ofstream goes out of scope (RAII)
 * 
 * **Research Questions**:
 * - What's the difference between std::ofstream and std::fstream?
 * - How do you append to file instead of truncating? (std::ios::app mode)
 * - How to check if write succeeded?
 * 
 * **Design Consideration**: Should this function append or truncate?
 * - Current design: truncate (default ofstream behavior)
 * - Rationale: Most common use case for text processing output
 * - Alternative: Add parameter for write mode
 */
void writeFile(const std::string& filename, const std::string& content);

#endif // FILE_UTILS_H
