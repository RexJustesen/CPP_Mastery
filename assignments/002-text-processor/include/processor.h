/**
 * @file processor.h
 * @brief Text processor interface definition
 * 
 * Defines the ITextProcessor abstract interface that all concrete text processors
 * must implement. This interface follows the Factory Method pattern, allowing
 * the ProcessorFactory to create different processor types polymorphically.
 * 
 * @author Student Name
 * @date 2025-10-29
 */

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <memory>

/**
 * @brief Abstract interface for text processing operations
 * 
 * ITextProcessor defines the contract that all concrete text processors must follow.
 * This enables polymorphic behavior where client code can work with any processor
 * type through this interface without knowing the concrete implementation.
 * 
 * **Design Pattern**: Product interface in Factory Method pattern
 * **SOLID Principle**: Interface Segregation Principle - minimal interface with only
 *                      methods that all processors need
 * 
 * @note This is a pure abstract class (interface) - it cannot be instantiated directly.
 *       All derived classes MUST implement all pure virtual methods.
 */
class ITextProcessor {
public:
    /**
     * @brief Virtual destructor for polymorphic deletion
     * 
     * Ensures proper cleanup when deleting derived class objects through base class pointer.
     * This is CRITICAL for any class with virtual methods to prevent memory leaks.
     * 
     * **Why virtual?**: Without virtual destructor, deleting derived object through base
     *                   pointer only calls base destructor, leaking derived resources.
     * 
     * @complexity O(1)
     */
    virtual ~ITextProcessor() = default;

    /**
     * @brief Process input text and return transformed result
     * 
     * Pure virtual method that defines the core text processing operation.
     * Each concrete processor implements this method to perform its specific transformation.
     * 
     * @param input The text to process (passed by const reference for efficiency)
     * @return std::string The processed text (returned by value - compiler optimizes with move semantics)
     * 
     * @throws std::runtime_error If processing fails (e.g., invalid input for specific processor)
     * 
     * @note Implementations should handle empty strings gracefully
     * @note For transformations (uppercase/lowercase/findreplace), return transformed text
     * @note For analysis (wordcount/linecount), return human-readable result string
     * 
     * @complexity Depends on concrete implementation (typically O(n) where n = input length)
     * 
     * **Design Consideration**: Why pass by const reference?
     * - Avoids copying large strings (performance)
     * - const ensures we don't accidentally modify input
     * 
     * **Design Consideration**: Why return by value instead of reference?
     * - Returning reference to local variable is undefined behavior
     * - Return-by-value enables move semantics (no copy overhead in C++11+)
     * - Makes ownership clear - caller owns the returned string
     */
    virtual std::string process(const std::string& input) = 0;

    /**
     * @brief Get human-readable description of this processor
     * 
     * Returns a string describing what this processor does. Useful for:
     * - Displaying available processors to user
     * - Logging which processor was applied
     * - Debugging and testing
     * 
     * @return std::string Description of processor functionality
     * 
     * @note Should return consistent description (not depend on state)
     * 
     * @complexity O(1)
     * 
     * **Example Returns**:
     * - "Converts text to uppercase"
     * - "Counts words in text"
     * - "Finds and replaces text occurrences"
     */
    virtual std::string getDescription() const = 0;
};

#endif // PROCESSOR_H
