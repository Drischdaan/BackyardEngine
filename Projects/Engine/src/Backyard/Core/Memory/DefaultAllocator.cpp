#include "pch.h"

#include <Backyard/Core/Memory/DefaultAllocator.h>
#include <cstdlib>

void* FDefaultAllocator::AllocateMemory(size_t size, EMemoryTag tag)
{
    UpdateMemoryStatistics(size, tag, true);
    return malloc(size);
}

void FDefaultAllocator::FreeMemory(void* memory, size_t size, EMemoryTag tag)
{
    UpdateMemoryStatistics(size, tag, false);
    free(memory);
}

FMemoryStatistics& FDefaultAllocator::GetMemoryStatistics()
{
    return m_MemoryStatistics;
}

void FDefaultAllocator::UpdateMemoryStatistics(size_t size, EMemoryTag tag, bool8 bAllocated)
{
    if(bAllocated)
    {
        m_MemoryStatistics.TotalAllocations++;
        m_MemoryStatistics.AllocatedMemory += static_cast<uint32>(size);
        m_MemoryStatistics.AllocatedMemoryByTag[tag] += static_cast<uint32>(size);
    }
    else
    {
        m_MemoryStatistics.TotalFrees++;
        m_MemoryStatistics.AllocatedMemory -= static_cast<uint32>(size);
        m_MemoryStatistics.AllocatedMemoryByTag[tag] -= static_cast<uint32>(size);
    }
}
