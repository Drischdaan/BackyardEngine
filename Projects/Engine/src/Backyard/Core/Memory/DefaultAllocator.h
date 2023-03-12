#pragma once

#include <Backyard/Core/EngineDefinitions.h>

#include <Backyard/Core/Memory/Allocator.h>

namespace Backyard::Memory
{
    class FDefaultAllocator;
}

class API Backyard::Memory::FDefaultAllocator : public IAllocator
{
public:
    virtual void* AllocateMemory(size_t size, EMemoryTag tag) override;
    virtual void FreeMemory(void* memory, size_t size, EMemoryTag tag) override;
    
};
