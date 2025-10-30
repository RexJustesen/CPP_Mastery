/**
 * @file processor_factory.cpp
 * @brief Implementation of ProcessorFactory class
 */

#include "processor_factory.h"
#include "processors.h"
#include <stdexcept>
#include <algorithm>
#include <vector>

std::unique_ptr<ITextProcessor> ProcessorFactory::createProcessor(const std::string& type) {
    // TODO: Implement factory method
    // 1. Convert type to lowercase for case-insensitive comparison (optional but recommended)
    // 2. Check type and return appropriate processor:
    //    - "uppercase" → std::make_unique<UppercaseProcessor>()
    //    - "lowercase" → std::make_unique<LowercaseProcessor>()
    //    - "wordcount" → std::make_unique<WordCountProcessor>()
    //    - "linecount" → std::make_unique<LineCountProcessor>()
    //    - "findreplace" → std::make_unique<FindReplaceProcessor>("", "") (requires params later)
    // 3. If type unknown, throw std::invalid_argument("Unknown processor type: " + type)
    //
    // Research: How to convert string to lowercase? std::transform with ::tolower
    // Design: Could use std::map<std::string, function> for more extensible design

    (void)type; // Suppress unused parameter warning
    throw std::runtime_error("Not implemented: ProcessorFactory::createProcessor");
}

std::unique_ptr<ITextProcessor> ProcessorFactory::createFindReplaceProcessor(
    const std::string& findText,
    const std::string& replaceText) {
    // TODO: Implement specialized factory method for FindReplaceProcessor
    // 1. Validate findText is not empty (throw std::invalid_argument if empty)
    // 2. Create and return FindReplaceProcessor with parameters
    //
    // Research: Why validate here instead of in constructor? (Answer: Can do both!)
    // Design: This method provides type-safe way to create parameterized processor

    (void)findText;    // Suppress unused parameter warning
    (void)replaceText; // Suppress unused parameter warning
    throw std::runtime_error("Not implemented: ProcessorFactory::createFindReplaceProcessor");
}

std::vector<std::string> ProcessorFactory::getSupportedTypes() {
    // TODO: Return vector of supported type strings
    // Return: {"uppercase", "lowercase", "wordcount", "linecount", "findreplace"}
    //
    // Design: This could be auto-generated from registry if using auto-registration pattern

    throw std::runtime_error("Not implemented: ProcessorFactory::getSupportedTypes");
}
