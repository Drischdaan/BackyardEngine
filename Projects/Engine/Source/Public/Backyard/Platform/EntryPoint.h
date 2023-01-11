#pragma once

#include <Backyard/Engine.h>

#include <memory>

// Windows entry point
#if defined(_BACKYARD_PLATFORM_WINDOWS)
    #if defined(_BACKYARD_CONFIGURATION_DEBUG)
        #define ENTRY_POINT_HEADER int main(int argc, char** argv)
        #define ENTRY_POINT_METHOD(app) EngineMain(app)
    #elif defined(_BACKYARD_CONFIGURATION_RELEASE)
        // Specific includes for release
        #include <Windows.h>

        #define ENTRY_POINT_HEADER int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
        #define ENTRY_POINT_METHOD(app) EngineMain(app)
    #endif
#endif

#define BACKYARD_ENGINE_ENTRY_POINT(appClass, ...) ENTRY_POINT_HEADER { return ENTRY_POINT_METHOD(std::move(std::make_shared<appClass>(__VA_ARGS__))); }