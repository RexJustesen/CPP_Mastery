/**
 * @file processor_factory.h
 * @brief Factory class for creating text processor instances
 * 
 * Implements the Factory Method pattern to create different types of text processors
 * without exposing concrete classes to client code. This promotes loose coupling and
 * follows the Open/Closed Principle (open for extension, closed for modification).
 * 
 * @author Student Name
 * @date 2025-10-29
 */

#ifndef PROCESSOR_FACTORY_H
#define PROCESSOR_FACTORY_H

#include "processor.h"
#include <string>
#include <memory>
#include <vector>

/**
 * @brief Factory class for creating ITextProcessor instances
 * 
 * ProcessorFactory provides static factory methods that create concrete processor objects
 * and return them as ITextProcessor interface pointers. This hides concrete types from
 * client code, enabling polymorphic usage.
 * 
 * **Design Pattern**: Factory Method (simple static factory variant)
 * **SOLID Principles**:
 * - Single Responsibility: Only responsible for object creation
 * - Open/Closed: Can extend with new processor types (though current implementation
 *               requires modification - see bonus challenge for auto-registration)
 * 
 * @note Factory methods are static - no need to instantiate factory object
 * @note Returns std::unique_ptr for automatic memory management (RAII)
 */
class ProcessorFactory {
public:
    /**
     * @brief Create a text processor based on type string
     * 
     * Factory method that instantiates and returns the appropriate processor type
     * based on the provided type string. This is the primary way to create processors.
     * 
     * **Supported Types**:
     * - "uppercase"  → UppercaseProcessor
     * - "lowercase"  → LowercaseProcessor
     * - "wordcount"  → WordCountProcessor
     * - "linecount"  → LineCountProcessor
     * - "findreplace" → FindReplaceProcessor (requires subsequent parameter setting)
     * 
     * @param type Processor type identifier (case-insensitive recommended)
     * @return std::unique_ptr<ITextProcessor> Unique pointer to created processor
     * 
     * @throws std::invalid_argument If type is not recognized
     * 
     * @complexity O(1) - simple type lookup and instantiation
     * 
     * **Design Considerations**:
     * - Why unique_ptr? Ensures automatic cleanup, transfers ownership to caller
     * - Why return interface pointer? Enables polymorphism, hides concrete types
     * - Why static? No factory state needed, convenient usage: ProcessorFactory::createProcessor(...)
     * 
     * **Usage Example**:
     * @code
     * auto processor = ProcessorFactory::createProcessor("uppercase");
     * std::string result = processor->process("hello world");
     * // result == "HELLO WORLD"
     * @endcode
     * 
     * **Error Handling**:
     * @code
     * try {
     *     auto processor = ProcessorFactory::createProcessor("invalid");
     * } catch (const std::invalid_argument& e) {
     *     std::cerr << "Error: " << e.what() << std::endl;
     * }
     * @endcode
     * 
     * **TODO for Implementation**:
     * 1. Convert type string to lowercase for case-insensitive comparison
     * 2. Use if-else chain or switch (on hash) to determine type
     * 3. Return std::make_unique<ConcreteType>() for matched type
     * 4. Throw std::invalid_argument("Unknown processor type: " + type) if no match
     * 
     * **Research Questions**:
     * - How does std::make_unique work? Why prefer it over new?
     * - What happens to unique_ptr when it goes out of scope?
     * - Could you use std::map<std::string, function> to make this more extensible?
     */
    static std::unique_ptr<ITextProcessor> createProcessor(const std::string& type);

    /**
     * @brief Create a find-and-replace processor with specified parameters
     * 
     * Specialized factory method for creating FindReplaceProcessor which requires
     * construction parameters (find text and replace text). This overload provides
     * a convenient way to create parameterized processors.
     * 
     * @param findText Text to search for (passed to FindReplaceProcessor constructor)
     * @param replaceText Text to replace with (passed to FindReplaceProcessor constructor)
     * @return std::unique_ptr<ITextProcessor> Unique pointer to FindReplaceProcessor
     * 
     * @throws std::invalid_argument If findText is empty (can't replace nothing)
     * 
     * @complexity O(1) - just object construction
     * 
     * **Usage Example**:
     * @code
     * auto processor = ProcessorFactory::createFindReplaceProcessor("bug", "feature");
     * std::string fixed = processor->process("This bug is a bug");
     * // fixed == "This feature is a feature"
     * @endcode
     * 
     * **Design Consideration**: Why separate method instead of passing params to createProcessor?
     * - Type safety: Compile-time guarantee of correct parameters
     * - Clarity: Intent is explicit in method name
     * - Extensibility: Can add more specialized factory methods for other parameterized processors
     * 
     * **Alternative Design**: Could pass parameters as std::map<std::string, std::string> to single factory method
     * 
     * **TODO for Implementation**:
     * 1. Validate findText is not empty (throw std::invalid_argument if empty)
     * 2. Return std::make_unique<FindReplaceProcessor>(findText, replaceText)
     * 
     * **Research Questions**:
     * - What's the difference between throwing exception vs returning nullptr?
     * - When would you use a builder pattern instead of factory method for complex objects?
     */
    static std::unique_ptr<ITextProcessor> createFindReplaceProcessor(
        const std::string& findText,
        const std::string& replaceText);

    /**
     * @brief Get list of supported processor types
     * 
     * Returns a vector of all processor type strings that can be passed to createProcessor().
     * Useful for displaying help information or validating user input.
     * 
     * @return std::vector<std::string> List of supported type identifiers
     * 
     * @complexity O(1) - returns pre-defined list
     * 
     * **Usage Example**:
     * @code
     * auto types = ProcessorFactory::getSupportedTypes();
     * std::cout << "Available processors:\n";
     * for (const auto& type : types) {
     *     std::cout << "  - " << type << "\n";
     * }
     * @endcode
     * 
     * **TODO for Implementation**:
     * Return std::vector<std::string>{"uppercase", "lowercase", "wordcount", "linecount", "findreplace"}
     * 
     * **Design Note**: This could be generated dynamically if using auto-registration pattern
     */
    static std::vector<std::string> getSupportedTypes();
};

#endif // PROCESSOR_FACTORY_H
