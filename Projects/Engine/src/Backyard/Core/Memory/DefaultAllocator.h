#pragma once

#include <Backyard/Core/EngineDefinitions.h>

#include "Memory.h"

class API FDefaultAllocator : public FAllocator
{
public:
    void* AllocateMemory(size_t size, EMemoryTag tag = MEMORY_TAG_UNKNOWN) override;
    void FreeMemory(void* memory, size_t size, EMemoryTag tag = MEMORY_TAG_UNKNOWN) override;

public:
    static FAllocator* GetInstance();

private:
    inline static FDefaultAllocator* s_Instance = nullptr; 
    
};
