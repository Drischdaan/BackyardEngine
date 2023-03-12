#include "pch.h"

#include <Backyard/Core/Memory/DefaultAllocator.h>
#include <cstdlib>

void* Backyard::Memory::FDefaultAllocator::AllocateMemory(size_t size, EMemoryTag tag)
{
    UpdateMemoryStatistics(size, tag, true);
    return malloc(size);
}

void Backyard::Memory::FDefaultAllocator::FreeMemory(void* memory, size_t size, EMemoryTag tag)
{
    UpdateMemoryStatistics(size, tag, false);
    free(memory);
}
