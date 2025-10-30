#ifndef CONFIG_H
#define CONFIG_H

#include <map>
#include <string>
#include <vector>

/**
 * @brief Immutable configuration object (Builder Pattern - Product)
 * 
 * This class represents a parsed INI-style configuration file.
 * Once constructed, the configuration is immutable - all modification
 * happens through the ConfigBuilder.
 * 
 * Structure:
 * - Sections contain key-value pairs
 * - All values stored as strings internally
 * - Type-safe getters perform conversions on access
 * - Getters provide default values for missing keys
 * 
 * Example:
 * @code
 * Config config = ...;
 * std::string host = config.getString("database", "host", "localhost");
 * int port = config.getInt("database", "port", 5432);
 * bool enabled = config.getBool("features", "logging", true);
 * @endcode
 * 
 * @note All getters are const - config is read-only after construction
 * @note Section and key names are case-sensitive
 * @note This class is thread-safe for reading (immutable)
 */
class Config {
private:
    /**
     * @brief Nested map: section -> (key -> value)
     * 
     * Outer map: Section name -> Inner map
     * Inner map: Key name -> Value (always string)
     * 
     * Example structure:
     * {
     *   "database": {
     *     "host": "localhost",
     *     "port": "5432"
     *   },
     *   "logging": {
     *     "level": "info",
     *     "enabled": "true"
     *   }
     * }
     */
    std::map<std::string, std::map<std::string, std::string>> data_;

public:
    /**
     * @brief Construct empty config
     * 
     * @note Typically not used directly - use ConfigBuilder instead
     */
    Config() = default;

    /**
     * @brief Construct config from pre-built data
     * 
     * @param data Nested map of sections and key-value pairs
     * 
     * @note Used by ConfigBuilder::build() to transfer ownership
     */
    explicit Config(std::map<std::string, std::map<std::string, std::string>> data);

    // ==================== String Access ====================

    /**
     * @brief Get string value with default
     * 
     * @param section Section name
     * @param key Key name
     * @param defaultValue Value to return if key not found
     * @return std::string Value from config, or defaultValue if not found
     * 
     * @note Does not throw - always returns a value
     * @note Returns value as-is (no trimming or processing)
     */
    std::string getString(const std::string& section,
                         const std::string& key,
                         const std::string& defaultValue = "") const;

    // ==================== Integer Access ====================

    /**
     * @brief Get integer value with default
     * 
     * @param section Section name
     * @param key Key name
     * @param defaultValue Value to return if key not found or conversion fails
     * @return int Converted integer value, or defaultValue
     * 
     * @note Does not throw - returns default on any error
     * @note Uses std::stoi internally
     */
    int getInt(const std::string& section,
               const std::string& key,
               int defaultValue = 0) const;

    // ==================== Boolean Access ====================

    /**
     * @brief Get boolean value with default
     * 
     * @param section Section name
     * @param key Key name
     * @param defaultValue Value to return if key not found or conversion fails
     * @return bool Converted boolean value, or defaultValue
     * 
     * @note Does not throw - returns default on any error
     * @note Accepted values (case-insensitive):
     *       true: "true", "1", "yes", "on"
     *       false: "false", "0", "no", "off"
     */
    bool getBool(const std::string& section,
                 const std::string& key,
                 bool defaultValue = false) const;

    // ==================== Double Access ====================

    /**
     * @brief Get double value with default
     * 
     * @param section Section name
     * @param key Key name
     * @param defaultValue Value to return if key not found or conversion fails
     * @return double Converted double value, or defaultValue
     * 
     * @note Does not throw - returns default on any error
     * @note Uses std::stod internally
     */
    double getDouble(const std::string& section,
                    const std::string& key,
                    double defaultValue = 0.0) const;

    // ==================== Introspection ====================

    /**
     * @brief Check if section exists
     * 
     * @param section Section name to check
     * @return true Section exists
     * @return false Section does not exist
     */
    bool hasSection(const std::string& section) const;

    /**
     * @brief Check if key exists in section
     * 
     * @param section Section name
     * @param key Key name
     * @return true Key exists in section
     * @return false Section doesn't exist or key doesn't exist in section
     */
    bool hasKey(const std::string& section, const std::string& key) const;

    /**
     * @brief Get all section names
     * 
     * @return std::vector<std::string> List of section names (may be empty)
     * 
     * @note Sections are returned in sorted order (std::map is ordered)
     */
    std::vector<std::string> getSections() const;

    /**
     * @brief Get all keys in a section
     * 
     * @param section Section name
     * @return std::vector<std::string> List of keys (empty if section doesn't exist)
     * 
     * @note Keys are returned in sorted order
     */
    std::vector<std::string> getKeys(const std::string& section) const;

    /**
     * @brief Get count of sections
     * 
     * @return size_t Number of sections
     */
    size_t getSectionCount() const;

    /**
     * @brief Get count of keys in a section
     * 
     * @param section Section name
     * @return size_t Number of keys (0 if section doesn't exist)
     */
    size_t getKeyCount(const std::string& section) const;

private:
    /**
     * @brief Convert string to boolean (case-insensitive)
     * 
     * @param value String value to convert
     * @return bool Converted boolean value
     * 
     * @throws ConfigTypeError If value is not a recognized boolean
     * 
     * @note Accepted values:
     *       true: "true", "1", "yes", "on" (any case)
     *       false: "false", "0", "no", "off" (any case)
     * 
     * TODO: Research how to implement case-insensitive string comparison
     * Hint: Convert to lowercase before comparing
     */
    bool stringToBool(const std::string& value,
                     const std::string& section,
                     const std::string& key) const;
};

#endif // CONFIG_H
