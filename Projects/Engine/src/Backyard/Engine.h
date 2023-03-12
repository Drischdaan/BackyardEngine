#pragma once

#include <Backyard/Core/EngineDefinitions.h>
#include <Backyard/Core/Types.h>

#include "Core/Application.h"

class API FEngine
{
public:
    FEngine(FApplicationInfo applicationInfo);
    ~FEngine();

    uint32 Run() const;
    
    [[nodiscard]] FApplicationInfo GetApplicationInfo() const { return m_ApplicationInfo; }

private:
    uint32 Initialize() const;
    void Loop() const;
    uint32 Shutdown(uint32 exitCode = 0) const;
    
public:
    static FEngine* GetInstance() { return s_Instance; }

private:
    inline static FEngine* s_Instance = nullptr;

    FApplicationInfo m_ApplicationInfo;
    
};

API uint32 EngineMain(FApplicationInfo applicationInfo);