#include "pch.h"

#include <Backyard/Core/Assertion/Assertion.h>
#include <cstdlib>
#include <iostream>

void Backyard::Debug::AssertCritical(bool condition, const char* message, const char* file, int line, const char* function, const char* expression)
{
    if(!condition)
    {
        std::cout << "[ASSERT] Expression failed: " << expression << std::endl;
        std::cout << "[ASSERT] " << message << " [" << file << ":" << line << "->" << function << "]" << std::endl;
        Platform::Debug::PlatformAssertCritical(expression, message, file, line, function);
        exit(1);
    }
}
