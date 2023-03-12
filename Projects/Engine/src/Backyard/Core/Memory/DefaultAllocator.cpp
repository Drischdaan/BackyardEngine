#include "pch.h"

#include <Backyard/Core/Memory/DefaultAllocator.h>

void* FDefaultAllocator::AllocateMemory(size_t size, EMemoryTag tag)
{
    AddToTag(tag, size);
    return malloc(size);
}

void FDefaultAllocator::FreeMemory(void* memory, size_t size, EMemoryTag tag)
{
    RemoveFromTag(tag, size);
    free(memory);
}

FAllocator* FDefaultAllocator::GetInstance()
{
    if(!s_Instance)
        s_Instance = new FDefaultAllocator();
    return s_Instance;
}
