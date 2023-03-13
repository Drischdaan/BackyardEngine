#include "pch.h"

#ifdef _ENGINE_PLATFORM_WINDOWS

#include <Backyard/Core/Assertion/Assertion.h>

#include <string>
#include <Windows.h>

void Backyard::Platform::Debug::PlatformAssertCritical(const char* expression, const char* message, const char* file, int line, const char* function)
{
    std::string messageString = "Expression failed: " + std::string(expression) + "\n\n";
    messageString += std::string(message) + "\n";
    messageString += "File: " + std::string(file) + "\n";
    messageString += "Line: " + std::to_string(line) + "\n";
    messageString += "Function: " + std::string(function) + "\n";
    MessageBoxA(nullptr, messageString.c_str(), "Critical Assertion", MB_OK | MB_ICONERROR);
}


#endif