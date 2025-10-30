#include "config_exceptions.h"

// ==================== ConfigParseError Implementation ====================

ConfigParseError::ConfigParseError(int lineNumber, const std::string& message)
    : std::runtime_error("Line " + std::to_string(lineNumber) + ": " + message),
      lineNumber_(lineNumber) {
    // TODO: Research exception constructors and initialization lists
    // Hint: Base class constructor formats the error message
}

int ConfigParseError::getLineNumber() const noexcept {
    // TODO: Implement getter for line number
    // Hint: Return the lineNumber_ member variable
    return lineNumber_;
}

// ==================== ConfigKeyError Implementation ====================

ConfigKeyError::ConfigKeyError(const std::string& section, const std::string& key)
    : std::runtime_error("Key '" + key + "' not found in section '" + section + "'"),
      section_(section),
      key_(key) {
    // TODO: Research how to construct error messages with multiple fields
    // Hint: Use string concatenation to build descriptive message
}

std::string ConfigKeyError::getSection() const {
    return section_;
}

std::string ConfigKeyError::getKey() const {
    return key_;
}

// ==================== ConfigTypeError Implementation ====================

ConfigTypeError::ConfigTypeError(const std::string& section,
                                const std::string& key,
                                const std::string& value,
                                const std::string& targetType)
    : std::runtime_error("Cannot convert '" + value + "' to " + targetType +
                        " for key '" + key + "' in section '" + section + "'"),
      section_(section),
      key_(key),
      value_(value),
      targetType_(targetType) {
    // TODO: Research how to format complex error messages
    // Hint: Error message should be descriptive for debugging
}

std::string ConfigTypeError::getSection() const {
    return section_;
}

std::string ConfigTypeError::getKey() const {
    return key_;
}

std::string ConfigTypeError::getValue() const {
    return value_;
}

std::string ConfigTypeError::getTargetType() const {
    return targetType_;
}
