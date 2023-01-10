#include "pch.h"

#ifdef _BACKYARD_PLATFORM_WINDOWS

#include <Backyard/Core/Assertion.h>

#include <Windows.h>
#include <string>

void Assertion::AssertPlatform(const char* message)
{
    MessageBoxA(nullptr, message, "Assertion Failed | Backyard Engine", MB_OK | MB_ICONERROR);
}

void Assertion::AssertPlatformDetailed(const char* message, const char* file, int line, const char* function, const char* expression)
{
    std::string msg = std::string(message) + "\n\n";
    msg += "Expression: " + std::string(expression) + "\n";
    msg += "File: " + std::string(file) + "\n";
    msg += "Function: " + std::string(function) + "\n";
    msg += "Line: " + std::to_string(line) + "\n";
    MessageBoxA(nullptr, msg.c_str(), "Assertion Failed | Backyard Engine", MB_OK | MB_ICONERROR);
}

#endif