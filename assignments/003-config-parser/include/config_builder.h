#ifndef CONFIG_BUILDER_H
#define CONFIG_BUILDER_H

#include "config.h"
#include <map>
#include <string>

/**
 * @brief Builder for constructing immutable Config objects (Builder Pattern - Builder)
 * 
 * This class uses the Builder pattern to construct Config objects step-by-step.
 * The builder maintains mutable state during construction, then produces an
 * immutable Config object via build().
 * 
 * Usage:
 * @code
 * ConfigBuilder builder;
 * builder.addSection("database");
 * builder.addKeyValue("database", "host", "localhost");
 * builder.addKeyValue("database", "port", "5432");
 * Config config = builder.build();  // Produces immutable Config
 * @endcode
 * 
 * Design Notes:
 * - Mutable during construction (allows step-by-step building)
 * - Produces immutable Config (via build())
 * - Can be reused after build() (optional: reset state)
 * - Validates structure (duplicate checking, etc.)
 * 
 * @note This is the "Concrete Builder" in Builder pattern terminology
 * @note ConfigParser acts as the "Director" that uses this builder
 */
class ConfigBuilder {
private:
    /**
     * @brief Internal data structure (same as Config)
     * 
     * Nested map: section -> (key -> value)
     * Mutable during construction, transferred to Config on build()
     */
    std::map<std::string, std::map<std::string, std::string>> data_;

    /**
     * @brief Current section being populated
     * 
     * Used by ConfigParser to track which section keys belong to
     * Empty string = no section active (error if addKeyValue called)
     */
    std::string currentSection_;

public:
    /**
     * @brief Construct a new Config Builder
     * 
     * @note Starts with no sections and no current section
     */
    ConfigBuilder() = default;

    // ==================== Section Management ====================

    /**
     * @brief Add a new section
     * 
     * @param sectionName Name of section (e.g., "database")
     * @return ConfigBuilder& Reference to this builder (for fluent interface)
     * 
     * @throws ConfigParseError If section already exists (duplicate)
     * 
     * @note Sets currentSection_ to sectionName
     * @note Section names are case-sensitive
     * @note Empty section name is not allowed
     * 
     * TODO: Research how to validate section names
     * Hint: Check if section already exists in data_ map
     */
    ConfigBuilder& addSection(const std::string& sectionName);

    /**
     * @brief Get current active section
     * 
     * @return std::string Current section name (empty if none active)
     * 
     * @note Used by ConfigParser to verify section exists before adding keys
     */
    std::string getCurrentSection() const;

    /**
     * @brief Set current section (without adding it)
     * 
     * @param sectionName Section to make active
     * 
     * @throws ConfigParseError If section doesn't exist
     * 
     * @note Used by ConfigParser when encountering second key in same section
     */
    void setCurrentSection(const std::string& sectionName);

    // ==================== Key-Value Management ====================

    /**
     * @brief Add key-value pair to a section
     * 
     * @param section Section name
     * @param key Key name
     * @param value Value (always stored as string)
     * @return ConfigBuilder& Reference to this builder (for fluent interface)
     * 
     * @throws ConfigParseError If section doesn't exist
     * @throws ConfigParseError If key already exists in section (duplicate)
     * 
     * @note Section must be added via addSection() first
     * @note Key names are case-sensitive
     * @note Value is stored as-is (no trimming or validation)
     * @note Duplicate keys in same section are rejected
     * 
     * TODO: Research how to check if key already exists
     * Hint: Use std::map::find() or std::map::count()
     */
    ConfigBuilder& addKeyValue(const std::string& section,
                              const std::string& key,
                              const std::string& value);

    /**
     * @brief Add key-value pair to current section
     * 
     * @param key Key name
     * @param value Value (always stored as string)
     * @return ConfigBuilder& Reference to this builder (for fluent interface)
     * 
     * @throws ConfigParseError If no current section set
     * @throws ConfigParseError If key already exists (duplicate)
     * 
     * @note Convenience method - uses currentSection_
     * @note Equivalent to addKeyValue(currentSection_, key, value)
     */
    ConfigBuilder& addKeyValue(const std::string& key,
                              const std::string& value);

    // ==================== Building ====================

    /**
     * @brief Build immutable Config from accumulated data
     * 
     * @return Config Immutable configuration object
     * 
     * @note Transfers ownership of data_ to Config (use std::move)
     * @note Builder can be reused after build() (data_ will be empty)
     * @note Alternative: throw if build() called twice without reset
     * 
     * TODO: Research std::move semantics
     * Hint: std::move transfers ownership without copying
     */
    Config build();

    // ==================== Utility ====================

    /**
     * @brief Reset builder to initial state
     * 
     * Clears all sections, keys, and current section.
     * Allows builder to be reused.
     * 
     * @note Optional - build() can also clear state
     */
    void reset();

    /**
     * @brief Check if section exists
     * 
     * @param sectionName Section to check
     * @return true Section exists
     * @return false Section does not exist
     * 
     * @note Used internally and by ConfigParser for validation
     */
    bool hasSection(const std::string& sectionName) const;

    /**
     * @brief Check if key exists in section
     * 
     * @param section Section name
     * @param key Key name
     * @return true Key exists in section
     * @return false Section or key doesn't exist
     */
    bool hasKey(const std::string& section, const std::string& key) const;

    /**
     * @brief Get count of sections
     * 
     * @return size_t Number of sections added
     */
    size_t getSectionCount() const;

    /**
     * @brief Get count of keys in section
     * 
     * @param section Section name
     * @return size_t Number of keys (0 if section doesn't exist)
     */
    size_t getKeyCount(const std::string& section) const;
};

#endif // CONFIG_BUILDER_H
