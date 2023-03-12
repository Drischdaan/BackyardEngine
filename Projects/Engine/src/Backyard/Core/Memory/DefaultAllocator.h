#pragma once

#include <Backyard/Core/EngineDefinitions.h>

#include <Backyard/Core/Memory/Allocator.h>

class API FDefaultAllocator : public IAllocator
{
public:
    virtual void* AllocateMemory(size_t size, EMemoryTag tag) override;
    virtual void FreeMemory(void* memory, size_t size, EMemoryTag tag) override;

    FMemoryStatistics& GetMemoryStatistics() override;

protected:
    void UpdateMemoryStatistics(size_t size, EMemoryTag tag, bool8 bAllocated);
    
protected:
    FMemoryStatistics m_MemoryStatistics;
    
};
