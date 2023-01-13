#pragma once

#include <Backyard/Core/Definitions.h>

namespace Assertion
{
    /**
     * @brief Asserts that the given condition is true.
     * @param condition The condition to assert.
     * @param message The message to print if the condition is false.
     * @param file The file in which the assertion is made.
     * @param line The line in which the assertion is made.
     */
    void Assert(bool condition, const char* message, const char* file, int line);

    /**
     * @brief Asserts that the given condition is true.
     * @param condition The condition to assert.
     * @param message The message to print if the condition is false.
     * @param file The file in which the assertion is made.
     * @param line The line in which the assertion is made.
     * @param function The function in which the assertion is made.
     * @param expression The expression that was evaluated.
     */
    void AssertDetailed(bool condition, const char* message, const char* file, int line, const char* function, const char* expression);

    /**
     * @brief Executes platform specific code for handling an assertion failure.
     * @param message The message to print if the condition is false.
     */
    void AssertPlatform(const char* message);

    /**
     * @brief Executes platform specific code for handling an assertion failure.
     * @param message The message to print if the condition is false.
     * @param file The file in which the assertion is made.
     * @param line The line in which the assertion is made.
     * @param function The function in which the assertion is made.
     * @param expression The expression that was evaluated.
     */
    void AssertPlatformDetailed(const char* message, const char* file, int line, const char* function, const char* expression);
}

#define ASSERT(condition, message) Assertion::Assert(condition, message, __FILENAME__, __LINE__)
#define ASSERT_RETURN(condition, returnValue, message) if (!(condition)) { Assertion::Assert(condition, message, __FILENAME__, __LINE__); return returnValue; }

#ifdef _BACKYARD_CONFIGURATION_DEBUG
    #define ASSERT_DETAILED(condition, message) Assertion::AssertDetailed(condition, message, __FILENAME__, __LINE__, __FUNCTION__, #condition)
#else
    #define ASSERT_DETAILED(condition, message)
#endif
