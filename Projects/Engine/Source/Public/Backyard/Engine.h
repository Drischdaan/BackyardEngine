#pragma once

#include <Backyard/Core/Application.h>

class FEngine
{
public:
    FEngine(std::shared_ptr<FApplication> application);

    EResult Initialize();
    void Run();
    EResult Shutdown(EResult result = RESULT_OK);

private:
    std::shared_ptr<FApplication> m_Application;
    
};

static std::shared_ptr<FEngine> GEngine;

EResult EngineMain(std::shared_ptr<FApplication> application);
