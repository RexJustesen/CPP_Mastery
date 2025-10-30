/**
 * @file processors.h
 * @brief Concrete text processor implementations
 * 
 * Defines all concrete processor classes that implement the ITextProcessor interface.
 * Each processor performs a specific text transformation or analysis operation.
 * 
 * @author Student Name
 * @date 2025-10-29
 */

#ifndef PROCESSORS_H
#define PROCESSORS_H

#include "processor.h"
#include <string>

/**
 * @brief Converts input text to uppercase
 * 
 * UppercaseProcessor transforms all alphabetic characters in the input to uppercase
 * while preserving whitespace, punctuation, and special characters.
 * 
 * **Pattern Role**: Concrete Product in Factory Method pattern
 * **SOLID**: Single Responsibility - does one thing (uppercase conversion)
 * 
 * **Example**:
 * Input:  "Hello World! 123"
 * Output: "HELLO WORLD! 123"
 */
class UppercaseProcessor : public ITextProcessor {
public:
    /**
     * @brief Default constructor
     * 
     * @complexity O(1)
     */
    UppercaseProcessor() = default;

    /**
     * @brief Virtual destructor
     * 
     * @complexity O(1)
     */
    ~UppercaseProcessor() override = default;

    /**
     * @brief Convert input text to uppercase
     * 
     * @param input Text to convert
     * @return std::string Uppercase version of input
     * 
     * @complexity O(n) where n = input.length()
     * 
     * **TODO for Implementation**:
     * 1. Create result string (copy of input or empty with reserve)
     * 2. Use std::transform with ::toupper to convert each character
     * 3. Return result
     * 
     * **Research Questions**:
     * - What's the signature of std::transform?
     * - Why use ::toupper instead of std::toupper?
     * - How to handle Unicode characters? (C++ standard library is ASCII-centric)
     * 
     * **Hint**: std::transform(input.begin(), input.end(), result.begin(), ::toupper);
     */
    std::string process(const std::string& input) override;

    /**
     * @brief Get processor description
     * 
     * @return std::string "Converts text to uppercase"
     * 
     * @complexity O(1)
     */
    std::string getDescription() const override;
};

/**
 * @brief Converts input text to lowercase
 * 
 * LowercaseProcessor transforms all alphabetic characters in the input to lowercase
 * while preserving whitespace, punctuation, and special characters.
 * 
 * **Pattern Role**: Concrete Product in Factory Method pattern
 * **SOLID**: Single Responsibility - does one thing (lowercase conversion)
 * 
 * **Example**:
 * Input:  "Hello World! 123"
 * Output: "hello world! 123"
 */
class LowercaseProcessor : public ITextProcessor {
public:
    /**
     * @brief Default constructor
     */
    LowercaseProcessor() = default;

    /**
     * @brief Virtual destructor
     */
    ~LowercaseProcessor() override = default;

    /**
     * @brief Convert input text to lowercase
     * 
     * @param input Text to convert
     * @return std::string Lowercase version of input
     * 
     * @complexity O(n) where n = input.length()
     * 
     * **TODO for Implementation**:
     * Similar to UppercaseProcessor but use ::tolower
     */
    std::string process(const std::string& input) override;

    /**
     * @brief Get processor description
     * 
     * @return std::string "Converts text to lowercase"
     */
    std::string getDescription() const override;
};

/**
 * @brief Counts words in input text
 * 
 * WordCountProcessor analyzes input text and returns the total word count.
 * Words are defined as sequences of non-whitespace characters separated by whitespace.
 * 
 * **Pattern Role**: Concrete Product in Factory Method pattern
 * **SOLID**: Single Responsibility - does one thing (word counting)
 * 
 * **Example**:
 * Input:  "Hello   world! This  is C++"
 * Output: "Word count: 5"
 * 
 * **Edge Cases**:
 * - Empty string → "Word count: 0"
 * - Only whitespace → "Word count: 0"
 * - Multiple spaces between words → count correctly
 */
class WordCountProcessor : public ITextProcessor {
public:
    /**
     * @brief Default constructor
     */
    WordCountProcessor() = default;

    /**
     * @brief Virtual destructor
     */
    ~WordCountProcessor() override = default;

    /**
     * @brief Count words in input text
     * 
     * @param input Text to analyze
     * @return std::string Human-readable word count (e.g., "Word count: 42")
     * 
     * @complexity O(n) where n = input.length()
     * 
     * **TODO for Implementation**:
     * 1. Use std::istringstream to parse input
     * 2. Read word by word using >> operator (automatically handles whitespace)
     * 3. Count each successfully read word
     * 4. Format result as "Word count: X"
     * 
     * **Research Questions**:
     * - How does std::istringstream::operator>> handle whitespace?
     * - What happens when stream reaches end?
     * - Could you use std::count_if with a predicate instead?
     * 
     * **Alternative Approaches**:
     * - Manual loop: count transitions from whitespace to non-whitespace
     * - Regex: std::regex_iterator with "\\S+" pattern (overkill for this use case)
     */
    std::string process(const std::string& input) override;

    /**
     * @brief Get processor description
     * 
     * @return std::string "Counts words in text"
     */
    std::string getDescription() const override;
};

/**
 * @brief Counts lines in input text
 * 
 * LineCountProcessor analyzes input text and returns the total line count.
 * Lines are separated by newline characters ('\n'). Empty lines are counted.
 * 
 * **Pattern Role**: Concrete Product in Factory Method pattern
 * **SOLID**: Single Responsibility - does one thing (line counting)
 * 
 * **Example**:
 * Input:  "Line 1\nLine 2\n\nLine 4"
 * Output: "Line count: 4"
 * 
 * **Edge Cases**:
 * - Empty string → "Line count: 0" or "Line count: 1" (decide on convention)
 * - No newlines → "Line count: 1" (single line)
 * - Trailing newline → Does it count as extra line?
 */
class LineCountProcessor : public ITextProcessor {
public:
    /**
     * @brief Default constructor
     */
    LineCountProcessor() = default;

    /**
     * @brief Virtual destructor
     */
    ~LineCountProcessor() override = default;

    /**
     * @brief Count lines in input text
     * 
     * @param input Text to analyze
     * @return std::string Human-readable line count (e.g., "Line count: 10")
     * 
     * @complexity O(n) where n = input.length()
     * 
     * **TODO for Implementation**:
     * 1. Count newline characters ('\n') in input
     * 2. Handle edge case: if string is not empty and doesn't end with '\n', add 1 to count
     * 3. Format result as "Line count: X"
     * 
     * **Research Questions**:
     * - How to count occurrences of character in string? (std::count)
     * - What's the line counting convention for files (does final newline count)?
     * - How would you handle different line endings (\n vs \r\n)?
     * 
     * **Hint**: Use std::count(input.begin(), input.end(), '\n')
     */
    std::string process(const std::string& input) override;

    /**
     * @brief Get processor description
     * 
     * @return std::string "Counts lines in text"
     */
    std::string getDescription() const override;
};

/**
 * @brief Finds and replaces all occurrences of text
 * 
 * FindReplaceProcessor searches for all occurrences of a target string and replaces
 * them with a replacement string. Matching is case-sensitive.
 * 
 * **Pattern Role**: Concrete Product in Factory Method pattern
 * **SOLID**: Single Responsibility - does one thing (find/replace)
 * 
 * **Example**:
 * FindText: "bug"
 * ReplaceText: "feature"
 * Input:  "This bug is a bug"
 * Output: "This feature is a feature"
 * 
 * **Edge Cases**:
 * - No matches → return original string
 * - Empty findText → throw std::invalid_argument
 * - Empty replaceText → delete all occurrences of findText
 * - Overlapping matches → handle correctly (don't re-process replaced text)
 */
class FindReplaceProcessor : public ITextProcessor {
private:
    std::string m_findText;     ///< Text to search for
    std::string m_replaceText;  ///< Text to replace with

public:
    /**
     * @brief Construct find-replace processor with search parameters
     * 
     * @param findText Text to search for (must not be empty)
     * @param replaceText Text to replace with (can be empty to delete matches)
     * 
     * @throws std::invalid_argument If findText is empty
     * 
     * @complexity O(1)
     * 
     * **TODO for Implementation**:
     * 1. Validate findText is not empty (throw std::invalid_argument if empty)
     * 2. Store both parameters in member variables
     * 
     * **Research Question**: Why can't findText be empty? What would happen if it were?
     */
    FindReplaceProcessor(const std::string& findText, const std::string& replaceText);

    /**
     * @brief Virtual destructor
     */
    ~FindReplaceProcessor() override = default;

    /**
     * @brief Find and replace all occurrences in input
     * 
     * @param input Text to process
     * @return std::string Text with all occurrences replaced
     * 
     * @complexity O(n * m) where n = input.length(), m = number of replacements
     *             (can be optimized but simple approach is acceptable)
     * 
     * **TODO for Implementation**:
     * 1. Create result string (copy of input)
     * 2. Use std::string::find() in loop to locate each occurrence
     * 3. Use std::string::replace() to replace found occurrence
     * 4. Update search position to AFTER replaced text (avoid infinite loop!)
     * 5. Return result
     * 
     * **Research Questions**:
     * - What does std::string::find() return when substring not found? (std::string::npos)
     * - How does std::string::replace(pos, len, str) work?
     * - Why must you advance position after replacement?
     * 
     * **Critical Bug to Avoid**:
     * If replaceText contains findText (e.g., replace "a" with "aa"),
     * and you don't advance position, you'll create infinite loop!
     * 
     * **Example Code Pattern**:
     * @code
     * size_t pos = 0;
     * while ((pos = result.find(findText, pos)) != std::string::npos) {
     *     result.replace(pos, findText.length(), replaceText);
     *     pos += replaceText.length(); // CRITICAL: advance past replacement
     * }
     * @endcode
     */
    std::string process(const std::string& input) override;

    /**
     * @brief Get processor description
     * 
     * @return std::string "Finds and replaces text occurrences"
     */
    std::string getDescription() const override;

    /**
     * @brief Get the text being searched for
     * 
     * @return const std::string& Find text (read-only reference)
     * 
     * @note Provided for testing/debugging
     */
    const std::string& getFindText() const { return m_findText; }

    /**
     * @brief Get the replacement text
     * 
     * @return const std::string& Replace text (read-only reference)
     * 
     * @note Provided for testing/debugging
     */
    const std::string& getReplaceText() const { return m_replaceText; }
};

#endif // PROCESSORS_H
