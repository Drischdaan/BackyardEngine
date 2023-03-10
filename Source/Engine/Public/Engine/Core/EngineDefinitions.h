#pragma once

#if defined(_MSC_VER)
    #undef _COMPILER_MSVC
    #undef _COMPILER_GCC
    #undef _COMPILER_CLANG
    #undef _COMPILER_MINGW32
    #undef _COMPILER_MINGW64
    #define _COMPILER_MSVC 1
#elif defined(__GNUC__)
    #undef _COMPILER_MSVC
    #undef _COMPILER_GCC
    #undef _COMPILER_CLANG
    #undef _COMPILER_MINGW32
    #undef _COMPILER_MINGW64
    #define _COMPILER_GCC 1
#elif defined(__clang__)
    #undef _COMPILER_MSVC
    #undef _COMPILER_GCC
    #undef _COMPILER_CLANG
    #undef _COMPILER_MINGW32
    #undef _COMPILER_MINGW64
    #define _COMPILER_CLANG 1
#elif defined(__MINGW32__)
    #undef _COMPILER_MSVC
    #undef _COMPILER_GCC
    #undef _COMPILER_CLANG
    #undef _COMPILER_MINGW32
    #undef _COMPILER_MINGW64
    #define _COMPILER_MINGW32 1
#elif defined(__MINGW64__)
    #undef _COMPILER_MSVC
    #undef _COMPILER_GCC
    #undef _COMPILER_CLANG
    #undef _COMPILER_MINGW32
    #undef _COMPILER_MINGW64
    #define _COMPILER_MINGW64 1
#endif

#if defined(__COMPILER_CLANG) || defined(__COMPILER_GCC)
    #define STATIC_ASSERT _Static_assert
#else
    #define STATIC_ASSERT static_assert
#endif

#ifdef FORCEINLINE
    #undef FORCEINLINE
#endif

#ifdef _COMPILER_MSVC
    #define FORCEINLINE __forceinline
#elif defined(_COMPILER_GCC)
    #define FORCEINLINE __attribute__((always_inline))
#else
    #define FORCEINLINE inline
#endif

#ifdef _BACKYARD_PLATFORM_WINDOWS
    #define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
    #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#if _BACKYARD_BUILD_LIBRARY
    #define BACKYARD_API __declspec(dllexport)
#else
    #define BACKYARD_API __declspec(dllimport)
#endif
