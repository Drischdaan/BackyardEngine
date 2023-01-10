#pragma once

#include <Backyard/Core/Definitions.h>

namespace Assertion
{
    void Assert(bool condition, const char* message, const char* file, int line);
    void AssertDetailed(bool condition, const char* message, const char* file, int line, const char* function, const char* expression);

    void AssertPlatform(const char* message);
    void AssertPlatformDetailed(const char* message, const char* file, int line, const char* function, const char* expression);
}

#define ASSERT(condition, message) Assertion::Assert(condition, message, __FILENAME__, __LINE__)
#define ASSERT_DETAILED(condition, message) Assertion::AssertDetailed(condition, message, __FILENAME__, __LINE__, __FUNCTION__, #condition)
