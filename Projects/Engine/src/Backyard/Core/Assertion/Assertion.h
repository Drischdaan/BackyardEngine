#pragma once

#include <Backyard/Core/EngineDefinitions.h>

namespace Backyard::Platform::Debug
{
    void PlatformAssertCritical(const char* expression, const char* message, const char* file, int line, const char* function);
}

namespace Backyard::Debug
{
    void AssertCritical(bool condition, const char* message, const char* file, int line, const char* function, const char* expression);
}

#define ASSERT(condition, message) \
    Backyard::Debug::AssertCritical(condition, message, __FILENAME__, __LINE__, __FUNCTION__, #condition)