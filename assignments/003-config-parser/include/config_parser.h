#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include "config.h"
#include "config_builder.h"
#include <string>

/**
 * @brief Parser for INI-style configuration files (Builder Pattern - Director)
 * 
 * This class is the "Director" in the Builder pattern. It orchestrates
 * the parsing process and uses ConfigBuilder to construct the Config object.
 * 
 * Supported INI format:
 * - Sections: [section_name]
 * - Key-value pairs: key = value
 * - Comments: # comment or ; comment
 * - Inline comments: key = value # comment
 * - Blank lines and whitespace are ignored
 * 
 * Example INI file:
 * @code
 * # Database configuration
 * [database]
 * host = localhost
 * port = 5432
 * 
 * [logging]
 * level = info  ; Log level
 * enabled = true
 * @endcode
 * 
 * Error Handling:
 * - Throws ConfigParseError with line numbers for syntax errors
 * - Reports duplicate sections/keys
 * - Reports malformed section headers
 * - Reports keys without sections
 * 
 * @note This is the "Director" in Builder pattern terminology
 * @note ConfigBuilder is the "Builder"
 * @note Config is the "Product"
 */
class ConfigParser {
public:
    /**
     * @brief Parse configuration from file
     * 
     * @param filename Path to INI file
     * @return Config Parsed immutable configuration
     * 
     * @throws ConfigParseError If file cannot be opened
     * @throws ConfigParseError If syntax errors encountered
     * 
     * @note Reads entire file into memory
     * @note Line numbers in errors are 1-based
     * 
     * TODO: Research std::ifstream for file reading
     * TODO: Research std::getline for line-by-line reading
     * Hint: Use std::ifstream and std::getline
     */
    static Config parseFile(const std::string& filename);

    /**
     * @brief Parse configuration from string
     * 
     * @param content INI-formatted string
     * @return Config Parsed immutable configuration
     * 
     * @throws ConfigParseError If syntax errors encountered
     * 
     * @note Useful for testing without file I/O
     * @note Line numbers in errors are 1-based
     * 
     * TODO: Research std::istringstream for string parsing
     * Hint: Use std::istringstream with std::getline
     */
    static Config parseString(const std::string& content);

private:
    /**
     * @brief Parse a single line of INI file
     * 
     * @param line Raw line from file
     * @param lineNumber Line number (1-based) for error reporting
     * @param builder Builder to populate
     * 
     * @throws ConfigParseError If line has syntax errors
     * 
     * @note This is the core parsing logic
     * @note Delegates to helper methods for specific line types
     * 
     * Parsing algorithm:
     * 1. Trim whitespace
     * 2. Check if blank line (ignore)
     * 3. Check if comment (ignore)
     * 4. Check if section header (parse section)
     * 5. Check if key-value pair (parse key-value)
     * 6. Otherwise, syntax error
     * 
     * TODO: Research how to implement this algorithm
     * Hint: Use helper methods (isBlank, isComment, isSectionHeader, etc.)
     */
    static void parseLine(const std::string& line,
                         int lineNumber,
                         ConfigBuilder& builder);

    // ==================== String Utilities ====================

    /**
     * @brief Trim whitespace from both ends of string
     * 
     * @param str String to trim (modified in-place)
     * 
     * @note Removes spaces, tabs, newlines, carriage returns
     * @note Modifies string in-place
     * 
     * TODO: Research std::string::find_first_not_of and find_last_not_of
     * Hint: Remove characters from beginning and end
     */
    static void trim(std::string& str);

    /**
     * @brief Remove inline comments from string
     * 
     * @param str String to process (modified in-place)
     * 
     * @note Removes everything after # or ; character
     * @note Example: "key = value # comment" -> "key = value "
     * @note Must preserve # or ; inside quotes (optional feature)
     * 
     * TODO: Research std::string::find to locate comment characters
     * Hint: Find first occurrence of # or ; and erase everything after
     */
    static void removeInlineComment(std::string& str);

    // ==================== Line Type Detection ====================

    /**
     * @brief Check if line is blank (empty or whitespace only)
     * 
     * @param line Line to check (should be trimmed first)
     * @return true Line is blank
     * @return false Line has content
     */
    static bool isBlank(const std::string& line);

    /**
     * @brief Check if line is a comment
     * 
     * @param line Line to check (should be trimmed first)
     * @return true Line starts with # or ;
     * @return false Line is not a comment
     */
    static bool isComment(const std::string& line);

    /**
     * @brief Check if line is a section header
     * 
     * @param line Line to check (should be trimmed first)
     * @return true Line matches [section_name] format
     * @return false Line is not a section header
     * 
     * Valid section headers:
     * - [section]
     * - [section_name]
     * - [section123]
     * 
     * Invalid section headers:
     * - [section name] (spaces)
     * - [section-name] (hyphen)
     * - [] (empty)
     * - [section (missing ])
     * 
     * TODO: Research how to validate section name format
     * Hint: Check first and last characters, validate name
     */
    static bool isSectionHeader(const std::string& line);

    /**
     * @brief Check if line is a key-value pair
     * 
     * @param line Line to check
     * @return true Line contains '=' character
     * @return false Line does not contain '='
     * 
     * @note Does not validate format (parseLine handles that)
     */
    static bool isKeyValue(const std::string& line);

    // ==================== Line Parsing ====================

    /**
     * @brief Parse section header and add to builder
     * 
     * @param line Line containing section header (e.g., "[database]")
     * @param lineNumber Line number for error reporting
     * @param builder Builder to add section to
     * 
     * @throws ConfigParseError If section header malformed
     * @throws ConfigParseError If section already exists (via builder)
     * 
     * Steps:
     * 1. Extract section name (remove [ and ])
     * 2. Trim whitespace from name
     * 3. Validate name (alphanumeric + underscore only)
     * 4. Add to builder
     * 
     * TODO: Research std::string::substr to extract section name
     * Hint: Remove first and last characters, then trim
     */
    static void parseSection(const std::string& line,
                            int lineNumber,
                            ConfigBuilder& builder);

    /**
     * @brief Parse key-value pair and add to builder
     * 
     * @param line Line containing key-value (e.g., "host = localhost")
     * @param lineNumber Line number for error reporting
     * @param builder Builder to add key-value to
     * 
     * @throws ConfigParseError If no current section in builder
     * @throws ConfigParseError If key-value malformed
     * @throws ConfigParseError If key already exists (via builder)
     * 
     * Steps:
     * 1. Find '=' character
     * 2. Split into key and value
     * 3. Trim both key and value
     * 4. Validate key (not empty, alphanumeric + underscore)
     * 5. Add to builder (value can be empty)
     * 
     * Valid examples:
     * - key = value
     * - key=value (no spaces)
     * - key = (empty value)
     * 
     * Invalid examples:
     * - = value (no key)
     * - key = value = extra (multiple =)
     * 
     * TODO: Research std::string::find to locate '=' character
     * TODO: Research std::string::substr to extract key and value
     * Hint: Split on '=', trim both parts
     */
    static void parseKeyValue(const std::string& line,
                             int lineNumber,
                             ConfigBuilder& builder);

    // ==================== Validation ====================

    /**
     * @brief Validate section name format
     * 
     * @param name Section name to validate
     * @return true Name is valid
     * @return false Name is invalid
     * 
     * Valid: alphanumeric + underscore, not empty
     * Invalid: spaces, hyphens, special characters, empty
     * 
     * Examples:
     * - "database" ✓
     * - "section_123" ✓
     * - "section name" ✗ (space)
     * - "section-name" ✗ (hyphen)
     * - "" ✗ (empty)
     * 
     * TODO: Research how to check if all characters are alphanumeric or underscore
     * Hint: Use std::all_of with ::isalnum or manual loop
     */
    static bool isValidSectionName(const std::string& name);

    /**
     * @brief Validate key name format
     * 
     * @param name Key name to validate
     * @return true Name is valid
     * @return false Name is invalid
     * 
     * Same validation as section names
     */
    static bool isValidKeyName(const std::string& name);
};

#endif // CONFIG_PARSER_H
