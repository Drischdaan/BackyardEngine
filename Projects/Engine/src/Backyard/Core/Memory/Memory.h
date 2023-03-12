#pragma once

#include <Backyard/Core/EngineDefinitions.h>

namespace Backyard::Memory
{
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
    
    void UpdateMemoryStatistics(size_t size, EMemoryTag tag, bool8 bAllocated);
    FMemoryStatistics& GetMemoryStatistics();
}
