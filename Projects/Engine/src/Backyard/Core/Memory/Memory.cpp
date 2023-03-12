#include "pch.h"

#include <Backyard/Core/Memory/Memory.h>

static Backyard::Memory::FMemoryStatistics s_MemoryStatistics;

void Backyard::Memory::UpdateMemoryStatistics(size_t size, EMemoryTag tag, bool8 bAllocated)
{
    if(bAllocated)
    {
        s_MemoryStatistics.TotalAllocations++;
        s_MemoryStatistics.AllocatedMemory += static_cast<uint32>(size);
        s_MemoryStatistics.AllocatedMemoryByTag[tag] += static_cast<uint32>(size);
    }
    else
    {
        s_MemoryStatistics.TotalFrees++;
        s_MemoryStatistics.AllocatedMemory -= static_cast<uint32>(size);
        s_MemoryStatistics.AllocatedMemoryByTag[tag] -= static_cast<uint32>(size);
    }
}

Backyard::Memory::FMemoryStatistics& Backyard::Memory::GetMemoryStatistics()
{
    return s_MemoryStatistics;
}
