#include "pch.h"

#include <Backyard/Engine.h>

FEngine::FEngine(std::shared_ptr<FApplication> application)
    : m_Application(std::move(application))
{
}

EResult FEngine::Initialize()
{
    const EResult applicationInitResult = m_Application->Initialize();
    if(IS_FAILURE(applicationInitResult))
        return applicationInitResult;
    return RESULT_OK;
}

void FEngine::Run()
{
}

EResult FEngine::Shutdown(EResult result)
{
    m_Application->Shutdown();
    return result;
}

EResult EngineMain(std::shared_ptr<FApplication> application)
{
    GEngine = std::make_shared<FEngine>(std::move(application));

    EResult result = GEngine->Initialize();
    if(IS_FAILURE(result))
        return GEngine->Shutdown(result);
    GEngine->Run();
    result = GEngine->Shutdown(result);
    if(GEngine.use_count() > 1)
        LOG_WARN("Global engine reference count is greater than 1 after shutdown");
    return result;
}
