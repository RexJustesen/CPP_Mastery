#ifndef CONFIG_EXCEPTIONS_H
#define CONFIG_EXCEPTIONS_H

#include <stdexcept>
#include <string>

/**
 * @brief Exception thrown during configuration file parsing.
 * 
 * This exception is thrown when the parser encounters:
 * - Invalid INI syntax
 * - Duplicate sections or keys
 * - Malformed section headers
 * - Invalid key-value pairs
 * - File I/O errors
 * 
 * The exception includes the line number where the error occurred
 * to help with debugging.
 */
class ConfigParseError : public std::runtime_error {
private:
    int lineNumber_;  ///< Line number where error occurred (1-based)

public:
    /**
     * @brief Construct a new Config Parse Error
     * 
     * @param lineNumber Line number where error occurred (1-based)
     * @param message Descriptive error message
     * 
     * @note The final error message will be formatted as:
     *       "Line <number>: <message>"
     */
    ConfigParseError(int lineNumber, const std::string& message);

    /**
     * @brief Get the line number where the error occurred
     * 
     * @return int Line number (1-based)
     */
    int getLineNumber() const noexcept;
};

/**
 * @brief Exception thrown when accessing non-existent configuration keys.
 * 
 * This exception is thrown when:
 * - Requesting a section that doesn't exist
 * - Requesting a key that doesn't exist in a section
 * - Only thrown by getInt/getBool/getDouble when no default provided
 * 
 * @note getString and versions with default values do not throw this
 */
class ConfigKeyError : public std::runtime_error {
private:
    std::string section_;  ///< Section name
    std::string key_;      ///< Key name

public:
    /**
     * @brief Construct a new Config Key Error
     * 
     * @param section Section name where key was sought
     * @param key Key name that was not found
     */
    ConfigKeyError(const std::string& section, const std::string& key);

    /**
     * @brief Get the section name
     * 
     * @return std::string Section name
     */
    std::string getSection() const;

    /**
     * @brief Get the key name
     * 
     * @return std::string Key name
     */
    std::string getKey() const;
};

/**
 * @brief Exception thrown when type conversion fails.
 * 
 * This exception is thrown when:
 * - Converting string to int fails (invalid format)
 * - Converting string to double fails (invalid format)
 * - Converting string to bool fails (not recognized boolean value)
 * 
 * Wraps underlying std::invalid_argument or std::out_of_range exceptions
 * from std::stoi, std::stod, etc.
 */
class ConfigTypeError : public std::runtime_error {
private:
    std::string section_;    ///< Section name
    std::string key_;        ///< Key name
    std::string value_;      ///< Original string value
    std::string targetType_; ///< Target type name ("int", "bool", "double")

public:
    /**
     * @brief Construct a new Config Type Error
     * 
     * @param section Section name
     * @param key Key name
     * @param value Original string value that failed conversion
     * @param targetType Target type ("int", "bool", "double")
     */
    ConfigTypeError(const std::string& section,
                    const std::string& key,
                    const std::string& value,
                    const std::string& targetType);

    /**
     * @brief Get the section name
     * 
     * @return std::string Section name
     */
    std::string getSection() const;

    /**
     * @brief Get the key name
     * 
     * @return std::string Key name
     */
    std::string getKey() const;

    /**
     * @brief Get the original string value
     * 
     * @return std::string Value that failed conversion
     */
    std::string getValue() const;

    /**
     * @brief Get the target type
     * 
     * @return std::string Target type name
     */
    std::string getTargetType() const;
};

#endif // CONFIG_EXCEPTIONS_H
