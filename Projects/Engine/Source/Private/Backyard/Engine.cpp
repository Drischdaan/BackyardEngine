#include "pch.h"

#include <Backyard/Engine.h>

// Temporary
#ifdef _BACKYARD_CONFIGURATION_DEBUG
    #include <iostream>
#endif

FEngine::FEngine(std::shared_ptr<FApplication> application)
    : m_bIsInitialized(false), m_Application(std::move(application))
{
}

EResult FEngine::Initialize()
{
    ASSERT_RETURN(!m_bIsInitialized, RESULT_FAILURE, "Engine already initialized!")
    m_bIsInitialized = true;
    
    const EResult applicationInitResult = m_Application->Initialize();
    ASSERT_RETURN(IS_SUCCESS(applicationInitResult), applicationInitResult, "Application initialization failed!")

    LOG_INFO("Engine initialized successfully!");
    return RESULT_OK;
}

void FEngine::Run() const
{
}

EResult FEngine::Shutdown(EResult result) const
{
    m_Application->Shutdown();
    return result;
}

EResult EngineMain(std::shared_ptr<FApplication> application)
{
    FLogging::Initialize();
    GEngine = std::make_shared<FEngine>(std::move(application));
    EResult result = GEngine->Initialize();
    if(IS_FAILURE(result))
        return GEngine->Shutdown(result);
    GEngine->Run();
    result = GEngine->Shutdown(result);
    if(GEngine.use_count() > 1)
        LOG_WARNING("Global engine reference count is greater than 1 after shutdown");
    FLogging::Shutdown();
    
    #pragma region DevelopmentStuff
    // This is very temporary, just to make sure that the engine is properly shut down when developing.
    // There is a bug in the ide that I am using that causes the integrated terminal to split the output into multiple lines.
    // Therefore I have to use an external console to see the output correctly and this code prevents the console from closing immediately.
#ifdef _BACKYARD_CONFIGURATION_DEBUG
    std::cout << "\n";
    std::cout << "[Cortana] > Chief, press <enter> to exit!" << "\n";
    std::cout << "[Chief]   > ";
    std::cout.flush();
    std::cin.get();
#endif
    #pragma endregion
    return result;
}
