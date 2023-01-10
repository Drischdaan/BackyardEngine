#pragma once

// Note: This is a temporary solution. It will be replaced by a more robust solution in the future
#include <iostream>
#include <format>

#define LOG_TRACE(x, ...) std::cout << "[TRACE] " << std::format(x, __VA_ARGS__) << "\n"
#define LOG_DEBUG(x, ...) std::cout << "[DEBUG] " << std::format(x, __VA_ARGS__) << "\n"
#define LOG_INFO(x, ...) std::cout << "[INFO] " << std::format(x, __VA_ARGS__) << "\n"
#define LOG_WARN(x, ...) std::cout << "[WARN] " << std::format(x, __VA_ARGS__) << "\n"
#define LOG_ERROR(x, ...) std::cout << "[ERROR] " << std::format(x, __VA_ARGS__) << "\n"
#define LOG_CRITICAL(x, ...) std::cout << "[CRITICAL] " << std::format(x, __VA_ARGS__) << "\n"
