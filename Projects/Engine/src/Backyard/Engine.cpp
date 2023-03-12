#include "pch.h"

#include <Backyard/Engine.h>

#include "Core/Memory/DefaultAllocator.h"

FEngine::FEngine()
{
    s_Instance = this;
    m_Allocator = new FDefaultAllocator();
}

FEngine::~FEngine()
{
    delete m_Allocator;
}

uint32 FEngine::Run() const
{
    const uint32 initializeResult = Initialize();
    if (initializeResult != 0)
        return Shutdown(initializeResult);
    Loop();
    return Shutdown();
}

uint32 FEngine::Initialize() const
{
    return 0;
}

void FEngine::Loop() const
{
}

uint32 FEngine::Shutdown(uint32 exitCode) const
{
    return exitCode;
}

uint32 EngineMain()
{
    const FEngine* engine = new FEngine();
    const uint32 exitCode = engine->Run();
    delete engine;
    return exitCode;
}
