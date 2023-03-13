#include "pch.h"

#include <Backyard/Engine.h>

#include "Core/Assertion/Assertion.h"
#include "Core/Memory/DefaultAllocator.h"

Backyard::FEngine::FEngine()
{
    s_Instance = this;
    m_Allocator = new Memory::FDefaultAllocator();
    ASSERT(m_Allocator != nullptr, "Allocator is null!");
}

Backyard::FEngine::~FEngine()
{
    delete m_Allocator;
}

uint32 Backyard::FEngine::Run() const
{
    const uint32 initializeResult = Initialize();
    if (initializeResult != 0)
        return Shutdown(initializeResult);
    Loop();
    return Shutdown();
}

uint32 Backyard::FEngine::Initialize() const
{
    return 0;
}

void Backyard::FEngine::Loop() const
{
}

uint32 Backyard::FEngine::Shutdown(uint32 exitCode) const
{
    return exitCode;
}

uint32 EngineMain()
{
    const Backyard::FEngine* engine = new Backyard::FEngine();
    const uint32 exitCode = engine->Run();
    delete engine;
    return exitCode;
}
