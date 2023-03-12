#include "pch.h"

#include <Backyard/Engine.h>

#include "Core/Memory/DefaultAllocator.h"

FEngine::FEngine(FApplicationInfo applicationInfo)
    : m_ApplicationInfo(applicationInfo)
{
    s_Instance = this;
}

FEngine::~FEngine() = default;

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

uint32 EngineMain(FApplicationInfo applicationInfo)
{
    const FEngine* engine = FDefaultAllocator::GetInstance()->NewObject<FEngine>(applicationInfo);
    const uint32 exitCode = engine->Run();
    FDefaultAllocator::GetInstance()->DeleteObject(engine);
    delete FDefaultAllocator::GetInstance();
    return exitCode;
}
