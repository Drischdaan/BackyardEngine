#pragma once

// Windows entry point
#if defined(_BACKYARD_PLATFORM_WINDOWS)
    #if defined(_BACKYARD_CONFIGURATION_DEBUG)
        #define ENTRY_POINT_HEADER int main(int argc, char** argv)
        #define ENTRY_POINT_METHOD return 0;
    #elif defined(_BACKYARD_CONFIGURATION_RELEASE)
        // Specific includes for release
        #include <Windows.h>

        #define ENTRY_POINT_HEADER int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
        #define ENTRY_POINT_METHOD return 0;
    #endif
#endif

#define BACKYARD_ENGINE_ENTRY_POINT() ENTRY_POINT_HEADER { ENTRY_POINT_METHOD }