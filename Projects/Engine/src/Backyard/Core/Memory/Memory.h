#pragma once

#include <Backyard/Core/EngineDefinitions.h>

enum API EMemoryTag
{
    MEMORY_TAG_UNKNOWN = 0,
    MEMORY_TAG_CORE = 1,
    MEMORY_TAG_RENDERER = 2,
    
    MEMORY_TAG_MAX_TAGS,
};

struct API FMemoryStatistics
{
    uint32 TotalAllocations = 0;
    uint32 TotalFrees = 0;
    uint32 AllocatedMemory = 0;

    uint32 AllocatedMemoryByTag[MEMORY_TAG_MAX_TAGS] = { 0 };
};
