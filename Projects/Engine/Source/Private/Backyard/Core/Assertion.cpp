#include "pch.h"

#include <Backyard/Core/Assertion.h>
#include <Backyard/Core/Logging.h>

void Assertion::Assert(bool condition, const char* message, const char* file, int line)
{
    if(condition)
        return;
    LOG_CRITICAL("Assertion failed: '{0}' in {1} at line {2}", message, file, line);
    AssertPlatform(message);
}

void Assertion::AssertDetailed(bool condition, const char* message, const char* file, int line, const char* function, const char* expression)
{
    if(condition)
        return;
    LOG_CRITICAL("Assertion failed: '{0}' in {1} at line {2} in function {3} with expression '{4}'", message, file, line, function, expression);
    AssertPlatformDetailed(message, file, line, function, expression);
}
