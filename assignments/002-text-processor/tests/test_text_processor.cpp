/**
 * @file test_text_processor.cpp
 * @brief Comprehensive test suite for Text File Processor
 * 
 * Tests all processors, factory pattern, file I/O, and integration scenarios.
 * Total: 35+ tests covering functionality, edge cases, errors, and patterns.
 */

#include <gtest/gtest.h>
#include "processor.h"
#include "processor_factory.h"
#include "processors.h"
#include "file_utils.h"
#include <memory>
#include <fstream>
#include <string>

// ============================================================================
// Section 1: Uppercase Processor Tests (5 tests)
// ============================================================================

TEST(UppercaseProcessorTest, ConvertsLowercaseToUppercase) {
    UppercaseProcessor processor;
    std::string result = processor.process("hello world");
    EXPECT_EQ(result, "HELLO WORLD");
}

TEST(UppercaseProcessorTest, PreservesAlreadyUppercase) {
    UppercaseProcessor processor;
    std::string result = processor.process("HELLO WORLD");
    EXPECT_EQ(result, "HELLO WORLD");
}

TEST(UppercaseProcessorTest, PreservesWhitespaceAndPunctuation) {
    UppercaseProcessor processor;
    std::string result = processor.process("Hello,  World!\n\tTest 123");
    EXPECT_EQ(result, "HELLO,  WORLD!\n\tTEST 123");
}

TEST(UppercaseProcessorTest, HandlesEmptyString) {
    UppercaseProcessor processor;
    std::string result = processor.process("");
    EXPECT_EQ(result, "");
}

TEST(UppercaseProcessorTest, HasCorrectDescription) {
    UppercaseProcessor processor;
    std::string desc = processor.getDescription();
    EXPECT_FALSE(desc.empty());
    EXPECT_NE(desc.find("uppercase"), std::string::npos);
}

// ============================================================================
// Section 2: Lowercase Processor Tests (5 tests)
// ============================================================================

TEST(LowercaseProcessorTest, ConvertsUppercaseToLowercase) {
    LowercaseProcessor processor;
    std::string result = processor.process("HELLO WORLD");
    EXPECT_EQ(result, "hello world");
}

TEST(LowercaseProcessorTest, PreservesAlreadyLowercase) {
    LowercaseProcessor processor;
    std::string result = processor.process("hello world");
    EXPECT_EQ(result, "hello world");
}

TEST(LowercaseProcessorTest, PreservesWhitespaceAndPunctuation) {
    LowercaseProcessor processor;
    std::string result = processor.process("HELLO,  WORLD!\n\tTEST 123");
    EXPECT_EQ(result, "hello,  world!\n\ttest 123");
}

TEST(LowercaseProcessorTest, HandlesEmptyString) {
    LowercaseProcessor processor;
    std::string result = processor.process("");
    EXPECT_EQ(result, "");
}

TEST(LowercaseProcessorTest, HasCorrectDescription) {
    LowercaseProcessor processor;
    std::string desc = processor.getDescription();
    EXPECT_FALSE(desc.empty());
    EXPECT_NE(desc.find("lowercase"), std::string::npos);
}

// ============================================================================
// Section 3: Word Count Processor Tests (6 tests)
// ============================================================================

TEST(WordCountProcessorTest, CountsSimpleWords) {
    WordCountProcessor processor;
    std::string result = processor.process("hello world test");
    EXPECT_EQ(result, "Word count: 3");
}

TEST(WordCountProcessorTest, HandlesMultipleSpaces) {
    WordCountProcessor processor;
    std::string result = processor.process("hello    world     test");
    EXPECT_EQ(result, "Word count: 3");
}

TEST(WordCountProcessorTest, HandlesLeadingAndTrailingSpaces) {
    WordCountProcessor processor;
    std::string result = processor.process("   hello world   ");
    EXPECT_EQ(result, "Word count: 2");
}

TEST(WordCountProcessorTest, HandlesEmptyString) {
    WordCountProcessor processor;
    std::string result = processor.process("");
    EXPECT_EQ(result, "Word count: 0");
}

TEST(WordCountProcessorTest, HandlesOnlyWhitespace) {
    WordCountProcessor processor;
    std::string result = processor.process("   \n\t  ");
    EXPECT_EQ(result, "Word count: 0");
}

TEST(WordCountProcessorTest, HasCorrectDescription) {
    WordCountProcessor processor;
    std::string desc = processor.getDescription();
    EXPECT_FALSE(desc.empty());
    EXPECT_NE(desc.find("word"), std::string::npos);
}

// ============================================================================
// Section 4: Line Count Processor Tests (6 tests)
// ============================================================================

TEST(LineCountProcessorTest, CountsSingleLine) {
    LineCountProcessor processor;
    std::string result = processor.process("hello world");
    EXPECT_EQ(result, "Line count: 1");
}

TEST(LineCountProcessorTest, CountsMultipleLines) {
    LineCountProcessor processor;
    std::string result = processor.process("line 1\nline 2\nline 3");
    EXPECT_EQ(result, "Line count: 3");
}

TEST(LineCountProcessorTest, CountsEmptyLines) {
    LineCountProcessor processor;
    std::string result = processor.process("line 1\n\nline 3");
    EXPECT_EQ(result, "Line count: 3");
}

TEST(LineCountProcessorTest, HandlesTrailingNewline) {
    LineCountProcessor processor;
    std::string result = processor.process("line 1\nline 2\n");
    EXPECT_EQ(result, "Line count: 2");
}

TEST(LineCountProcessorTest, HandlesEmptyString) {
    LineCountProcessor processor;
    std::string result = processor.process("");
    EXPECT_EQ(result, "Line count: 0");
}

TEST(LineCountProcessorTest, HasCorrectDescription) {
    LineCountProcessor processor;
    std::string desc = processor.getDescription();
    EXPECT_FALSE(desc.empty());
    EXPECT_NE(desc.find("line"), std::string::npos);
}

// ============================================================================
// Section 5: Find Replace Processor Tests (8 tests)
// ============================================================================

TEST(FindReplaceProcessorTest, ReplacesAllOccurrences) {
    FindReplaceProcessor processor("bug", "feature");
    std::string result = processor.process("This bug is a bug");
    EXPECT_EQ(result, "This feature is a feature");
}

TEST(FindReplaceProcessorTest, HandlesCaseSensitivity) {
    FindReplaceProcessor processor("bug", "feature");
    std::string result = processor.process("Bug bug BUG");
    EXPECT_EQ(result, "Bug feature BUG");
}

TEST(FindReplaceProcessorTest, HandlesNoMatches) {
    FindReplaceProcessor processor("xyz", "abc");
    std::string result = processor.process("hello world");
    EXPECT_EQ(result, "hello world");
}

TEST(FindReplaceProcessorTest, HandlesEmptyReplaceText) {
    FindReplaceProcessor processor("bug", "");
    std::string result = processor.process("This bug is a bug");
    EXPECT_EQ(result, "This  is a ");
}

TEST(FindReplaceProcessorTest, HandlesOverlappingPrevention) {
    FindReplaceProcessor processor("aa", "aaa");
    std::string result = processor.process("aaaa");
    EXPECT_EQ(result, "aaaaaa"); // Replace first two 'aa', don't re-process
}

TEST(FindReplaceProcessorTest, ThrowsOnEmptyFindText) {
    EXPECT_THROW({
        FindReplaceProcessor processor("", "something");
    }, std::invalid_argument);
}

TEST(FindReplaceProcessorTest, HandlesEmptyString) {
    FindReplaceProcessor processor("bug", "feature");
    std::string result = processor.process("");
    EXPECT_EQ(result, "");
}

TEST(FindReplaceProcessorTest, HasCorrectDescription) {
    FindReplaceProcessor processor("a", "b");
    std::string desc = processor.getDescription();
    EXPECT_FALSE(desc.empty());
}

// ============================================================================
// Section 6: Processor Factory Tests (7 tests)
// ============================================================================

TEST(ProcessorFactoryTest, CreatesUppercaseProcessor) {
    auto processor = ProcessorFactory::createProcessor("uppercase");
    ASSERT_NE(processor, nullptr);
    std::string result = processor->process("hello");
    EXPECT_EQ(result, "HELLO");
}

TEST(ProcessorFactoryTest, CreatesLowercaseProcessor) {
    auto processor = ProcessorFactory::createProcessor("lowercase");
    ASSERT_NE(processor, nullptr);
    std::string result = processor->process("HELLO");
    EXPECT_EQ(result, "hello");
}

TEST(ProcessorFactoryTest, CreatesWordCountProcessor) {
    auto processor = ProcessorFactory::createProcessor("wordcount");
    ASSERT_NE(processor, nullptr);
    std::string result = processor->process("hello world");
    EXPECT_EQ(result, "Word count: 2");
}

TEST(ProcessorFactoryTest, CreatesLineCountProcessor) {
    auto processor = ProcessorFactory::createProcessor("linecount");
    ASSERT_NE(processor, nullptr);
    std::string result = processor->process("line1\nline2");
    EXPECT_EQ(result, "Line count: 2");
}

TEST(ProcessorFactoryTest, CreatesFindReplaceProcessor) {
    auto processor = ProcessorFactory::createFindReplaceProcessor("old", "new");
    ASSERT_NE(processor, nullptr);
    std::string result = processor->process("old text old");
    EXPECT_EQ(result, "new text new");
}

TEST(ProcessorFactoryTest, ThrowsOnInvalidType) {
    EXPECT_THROW({
        auto processor = ProcessorFactory::createProcessor("invalid");
    }, std::invalid_argument);
}

TEST(ProcessorFactoryTest, GetSupportedTypesReturnsAll) {
    auto types = ProcessorFactory::getSupportedTypes();
    EXPECT_GE(types.size(), 5); // At least 5 processor types
    
    // Check that all expected types are present
    bool hasUppercase = false, hasLowercase = false, hasWordcount = false;
    bool hasLinecount = false, hasFindreplace = false;
    
    for (const auto& type : types) {
        if (type == "uppercase") hasUppercase = true;
        if (type == "lowercase") hasLowercase = true;
        if (type == "wordcount") hasWordcount = true;
        if (type == "linecount") hasLinecount = true;
        if (type == "findreplace") hasFindreplace = true;
    }
    
    EXPECT_TRUE(hasUppercase);
    EXPECT_TRUE(hasLowercase);
    EXPECT_TRUE(hasWordcount);
    EXPECT_TRUE(hasLinecount);
    EXPECT_TRUE(hasFindreplace);
}

// ============================================================================
// Section 7: File I/O Tests (5 tests)
// ============================================================================

TEST(FileUtilsTest, WriteAndReadFile) {
    const std::string filename = "test_output.txt";
    const std::string content = "Hello, World!\nTest content.";
    
    // Write file
    ASSERT_NO_THROW(writeFile(filename, content));
    
    // Read file back
    std::string readContent;
    ASSERT_NO_THROW(readContent = readFile(filename));
    
    // Verify content matches
    EXPECT_EQ(readContent, content);
    
    // Cleanup
    std::remove(filename.c_str());
}

TEST(FileUtilsTest, ReadNonexistentFileThrows) {
    EXPECT_THROW({
        readFile("nonexistent_file_12345.txt");
    }, std::runtime_error);
}

TEST(FileUtilsTest, HandlesEmptyFile) {
    const std::string filename = "test_empty.txt";
    
    // Create empty file
    std::ofstream ofs(filename);
    ofs.close();
    
    // Read should return empty string
    std::string content;
    ASSERT_NO_THROW(content = readFile(filename));
    EXPECT_EQ(content, "");
    
    // Cleanup
    std::remove(filename.c_str());
}

TEST(FileUtilsTest, HandlesLargeFile) {
    const std::string filename = "test_large.txt";
    
    // Create large content (1000 lines)
    std::string largeContent;
    for (int i = 0; i < 1000; i++) {
        largeContent += "This is line " + std::to_string(i) + "\n";
    }
    
    // Write and read back
    ASSERT_NO_THROW(writeFile(filename, largeContent));
    
    std::string readContent;
    ASSERT_NO_THROW(readContent = readFile(filename));
    
    EXPECT_EQ(readContent, largeContent);
    
    // Cleanup
    std::remove(filename.c_str());
}

TEST(FileUtilsTest, OverwritesExistingFile) {
    const std::string filename = "test_overwrite.txt";
    
    // Write first content
    writeFile(filename, "first content");
    
    // Write second content (should overwrite)
    writeFile(filename, "second content");
    
    // Read should return second content
    std::string content = readFile(filename);
    EXPECT_EQ(content, "second content");
    
    // Cleanup
    std::remove(filename.c_str());
}

// ============================================================================
// Section 8: Integration Tests (5 tests)
// ============================================================================

TEST(IntegrationTest, EndToEndUppercaseTransformation) {
    const std::string inputFile = "test_integration_input.txt";
    const std::string outputFile = "test_integration_output.txt";
    const std::string inputContent = "hello world\nthis is a test";
    
    // Write input
    writeFile(inputFile, inputContent);
    
    // Process
    auto processor = ProcessorFactory::createProcessor("uppercase");
    std::string processedContent = processor->process(readFile(inputFile));
    
    // Write output
    writeFile(outputFile, processedContent);
    
    // Verify
    std::string result = readFile(outputFile);
    EXPECT_EQ(result, "HELLO WORLD\nTHIS IS A TEST");
    
    // Cleanup
    std::remove(inputFile.c_str());
    std::remove(outputFile.c_str());
}

TEST(IntegrationTest, EndToEndWordCountingLarge file) {
    const std::string inputFile = "test_wordcount_input.txt";
    
    // Create file with known word count
    std::string content = "word " * 100; // 100 words
    writeFile(inputFile, content);
    
    // Process
    auto processor = ProcessorFactory::createProcessor("wordcount");
    std::string result = processor->process(readFile(inputFile));
    
    EXPECT_EQ(result, "Word count: 100");
    
    // Cleanup
    std::remove(inputFile.c_str());
}

TEST(IntegrationTest, EndToEndFindReplaceMultipleOccurrences) {
    const std::string inputFile = "test_findreplace_input.txt";
    const std::string outputFile = "test_findreplace_output.txt";
    const std::string inputContent = "error error error\nno error here\nerror";
    
    // Write input
    writeFile(inputFile, inputContent);
    
    // Process
    auto processor = ProcessorFactory::createFindReplaceProcessor("error", "success");
    std::string processedContent = processor->process(readFile(inputFile));
    
    // Write output
    writeFile(outputFile, processedContent);
    
    // Verify
    std::string result = readFile(outputFile);
    EXPECT_EQ(result, "success success success\nno success here\nsuccess");
    
    // Cleanup
    std::remove(inputFile.c_str());
    std::remove(outputFile.c_str());
}

TEST(IntegrationTest, PolymorphicProcessorUsage) {
    // Test that processors can be used polymorphically through interface
    std::vector<std::unique_ptr<ITextProcessor>> processors;
    processors.push_back(ProcessorFactory::createProcessor("uppercase"));
    processors.push_back(ProcessorFactory::createProcessor("lowercase"));
    processors.push_back(ProcessorFactory::createProcessor("wordcount"));
    
    std::string input = "Hello World";
    
    // All should work through interface pointer
    for (auto& processor : processors) {
        ASSERT_NE(processor, nullptr);
        std::string result = processor->process(input);
        EXPECT_FALSE(result.empty());
        
        std::string desc = processor->getDescription();
        EXPECT_FALSE(desc.empty());
    }
}

TEST(IntegrationTest, ChainMultipleProcessors) {
    std::string input = "hello WORLD test";
    
    // First: lowercase
    auto lowercase = ProcessorFactory::createProcessor("lowercase");
    std::string afterLowercase = lowercase->process(input);
    EXPECT_EQ(afterLowercase, "hello world test");
    
    // Then: uppercase the result
    auto uppercase = ProcessorFactory::createProcessor("uppercase");
    std::string afterUppercase = uppercase->process(afterLowercase);
    EXPECT_EQ(afterUppercase, "HELLO WORLD TEST");
}

// ============================================================================
// Section 9: Edge Cases and Stress Tests (3 tests)
// ============================================================================

TEST(EdgeCaseTest, VeryLongString) {
    UppercaseProcessor processor;
    
    // Create 10,000 character string
    std::string longString(10000, 'a');
    std::string expected(10000, 'A');
    
    std::string result = processor.process(longString);
    EXPECT_EQ(result, expected);
}

TEST(EdgeCaseTest, SpecialCharactersPreserved) {
    UppercaseProcessor processor;
    std::string input = "!@#$%^&*()_+-=[]{}|;':\",./<>?`~";
    std::string result = processor.process(input);
    EXPECT_EQ(result, input); // All special chars should be unchanged
}

TEST(EdgeCaseTest, NewlinesAndTabsPreserved) {
    LowercaseProcessor processor;
    std::string input = "HELLO\n\tWORLD\r\nTEST";
    std::string result = processor.process(input);
    EXPECT_EQ(result, "hello\n\tworld\r\ntest");
}

// ============================================================================
// Main function (provided by gtest_main)
// ============================================================================
