#pragma once

#if _BACKYARD_BUILD_LIBRARY
    #define BACKYARD_API __declspec(dllexport)
#else
    #define BACKYARD_API __declspec(dllimport)
#endif
