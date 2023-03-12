#pragma once

#include <Backyard/Platform/Windows/WindowsEntryPoint.h>
#include <Backyard/Engine.h>

#define ENGINE_ENTRY_POINT(applicationInfo) \
    ENTRY_POINT_FUNC_HEADER \
    { \
        return EngineMain(applicationInfo); \
    }