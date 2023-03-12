#pragma once

#include <type_traits>
#include <Backyard/Core/EngineDefinitions.h>
#include <Backyard/Core/Types.h>

#include "Core/Memory/Allocator.h"

class API FEngine
{
public:
    FEngine();
    ~FEngine();

    [[nodiscard]] uint32 Run() const;

    [[nodiscard]] IAllocator& GetAllocator() const { return *m_Allocator; }

private:
    [[nodiscard]] uint32 Initialize() const;
    void Loop() const;
    [[nodiscard]] uint32 Shutdown(uint32 exitCode = 0) const;
    
public:
    static FEngine* GetInstance() { return s_Instance; }

private:
    inline static FEngine* s_Instance = nullptr;

    IAllocator* m_Allocator = nullptr;
    
};

API uint32 EngineMain();