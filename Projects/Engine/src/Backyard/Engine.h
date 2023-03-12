#pragma once

#include <Backyard/Core/EngineDefinitions.h>
#include <Backyard/Core/Types.h>

#include "Core/Memory/Allocator.h"

namespace Backyard
{
    class FEngine;
}

class API Backyard::FEngine
{
public:
    FEngine();
    ~FEngine();

    [[nodiscard]] uint32 Run() const;

    [[nodiscard]] Memory::IAllocator& GetAllocator() const { return *m_Allocator; }

private:
    [[nodiscard]] uint32 Initialize() const;
    void Loop() const;
    [[nodiscard]] uint32 Shutdown(uint32 exitCode = 0) const;
    
public:
    static FEngine* GetInstance() { return s_Instance; }

private:
    inline static FEngine* s_Instance = nullptr;

    Memory::IAllocator* m_Allocator = nullptr;
    
};

API uint32 EngineMain();