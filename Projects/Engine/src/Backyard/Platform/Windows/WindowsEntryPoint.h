#pragma once

#ifdef _ENGINE_PLATFORM_WINDOWS
    #ifdef _ENGINE_CONFIGURATION_DEBUG
        #define ENTRY_POINT_FUNC_HEADER int main(int argc, char** argv)
    #else
        #include <Windows.h>
        #define ENTRY_POINT_FUNC_HEADER int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    #endif
#endif
