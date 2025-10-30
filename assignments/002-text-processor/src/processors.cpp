/**
 * @file processors.cpp
 * @brief Implementation of concrete text processor classes
 */

#include "processors.h"
#include <algorithm>
#include <sstream>
#include <cctype>
#include <stdexcept>

// ===== UppercaseProcessor =====

std::string UppercaseProcessor::process(const std::string& input) {
    // TODO: Convert input to uppercase
    // 1. Create result string (copy of input or empty with reserve)
    // 2. Use std::transform(input.begin(), input.end(), result.begin(), ::toupper)
    // 3. Return result
    //
    // Research: Why ::toupper instead of std::toupper?
    // - ::toupper is C function, std::toupper is C++ overload that may require locale
    // - For ASCII, ::toupper is simpler
    //
    // Edge cases to consider:
    // - Empty string → return empty string
    // - Already uppercase → return unchanged
    // - Non-alphabetic chars → preserve them

    (void)input; // Suppress unused parameter warning
    throw std::runtime_error("Not implemented: UppercaseProcessor::process");
}

std::string UppercaseProcessor::getDescription() const {
    // TODO: Return processor description
    // Return: "Converts text to uppercase"

    throw std::runtime_error("Not implemented: UppercaseProcessor::getDescription");
}

// ===== LowercaseProcessor =====

std::string LowercaseProcessor::process(const std::string& input) {
    // TODO: Convert input to lowercase
    // Same approach as UppercaseProcessor but use ::tolower

    (void)input; // Suppress unused parameter warning
    throw std::runtime_error("Not implemented: LowercaseProcessor::process");
}

std::string LowercaseProcessor::getDescription() const {
    // TODO: Return processor description
    // Return: "Converts text to lowercase"

    throw std::runtime_error("Not implemented: LowercaseProcessor::getDescription");
}

// ===== WordCountProcessor =====

std::string WordCountProcessor::process(const std::string& input) {
    // TODO: Count words in input
    // 1. Create std::istringstream from input
    // 2. Read words using >> operator in loop
    // 3. Count each word read
    // 4. Format result as "Word count: X"
    //
    // Research: How does std::istringstream::operator>> work?
    // - Skips leading whitespace automatically
    // - Reads until next whitespace
    // - Returns false when no more tokens
    //
    // Example code pattern:
    //   std::istringstream iss(input);
    //   std::string word;
    //   int count = 0;
    //   while (iss >> word) {
    //       count++;
    //   }
    //   return "Word count: " + std::to_string(count);
    //
    // Edge cases:
    // - Empty string → "Word count: 0"
    // - Only whitespace → "Word count: 0"
    // - Multiple spaces between words → count correctly (>> handles this!)

    (void)input; // Suppress unused parameter warning
    throw std::runtime_error("Not implemented: WordCountProcessor::process");
}

std::string WordCountProcessor::getDescription() const {
    // TODO: Return processor description
    // Return: "Counts words in text"

    throw std::runtime_error("Not implemented: WordCountProcessor::getDescription");
}

// ===== LineCountProcessor =====

std::string LineCountProcessor::process(const std::string& input) {
    // TODO: Count lines in input
    // 1. Count newline characters ('\n') using std::count
    // 2. Handle edge case: if input not empty and doesn't end with '\n', add 1
    // 3. Format result as "Line count: X"
    //
    // Research: std::count usage
    //   int newlines = std::count(input.begin(), input.end(), '\n');
    //
    // Line counting convention:
    // - "hello" → 1 line (no newline but has content)
    // - "hello\n" → 1 line (trailing newline doesn't add line)
    // - "hello\nworld" → 2 lines
    // - "hello\nworld\n" → 2 lines
    // - "" → 0 lines (empty string)
    //
    // Edge cases:
    // - Empty string → "Line count: 0"
    // - No newlines → "Line count: 1" (if not empty)
    // - Only newlines "\n\n\n" → "Line count: 3"

    (void)input; // Suppress unused parameter warning
    throw std::runtime_error("Not implemented: LineCountProcessor::process");
}

std::string LineCountProcessor::getDescription() const {
    // TODO: Return processor description
    // Return: "Counts lines in text"

    throw std::runtime_error("Not implemented: LineCountProcessor::getDescription");
}

// ===== FindReplaceProcessor =====

FindReplaceProcessor::FindReplaceProcessor(const std::string& findText, 
                                           const std::string& replaceText) {
    // TODO: Validate and store parameters
    // 1. Check if findText is empty → throw std::invalid_argument("Find text cannot be empty")
    // 2. Store findText in m_findText
    // 3. Store replaceText in m_replaceText
    //
    // Research: Why can't findText be empty?
    // - Finding empty string would match everywhere (infinite loop potential)
    // - Doesn't make logical sense to "replace nothing"
    //
    // Design: replaceText CAN be empty (deletes all occurrences of findText)

    (void)findText;    // Suppress unused parameter warning
    (void)replaceText; // Suppress unused parameter warning
    throw std::runtime_error("Not implemented: FindReplaceProcessor constructor");
}

std::string FindReplaceProcessor::process(const std::string& input) {
    // TODO: Find and replace all occurrences
    // 1. Create result string (copy of input)
    // 2. Use loop to find and replace:
    //    size_t pos = 0;
    //    while ((pos = result.find(m_findText, pos)) != std::string::npos) {
    //        result.replace(pos, m_findText.length(), m_replaceText);
    //        pos += m_replaceText.length();  // CRITICAL: advance past replacement!
    //    }
    // 3. Return result
    //
    // Research: What is std::string::npos?
    // - Special value returned by find() when substring not found
    // - Typically maximum value of size_t
    //
    // CRITICAL BUG TO AVOID:
    // If you don't advance pos past replacement, you'll re-find the replacement text
    // Example: replace "a" with "aa" without advancing → infinite loop!
    //
    // Edge cases:
    // - No matches → return original string
    // - Multiple consecutive matches → handle correctly
    // - Overlapping potential matches → first match wins (don't re-search)

    (void)input; // Suppress unused parameter warning
    throw std::runtime_error("Not implemented: FindReplaceProcessor::process");
}

std::string FindReplaceProcessor::getDescription() const {
    // TODO: Return processor description
    // Return: "Finds and replaces text occurrences"

    throw std::runtime_error("Not implemented: FindReplaceProcessor::getDescription");
}
