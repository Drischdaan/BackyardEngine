#pragma once

#include <Backyard/Core/Application.h>

class FEngine
{
public:
    FEngine(std::shared_ptr<FApplication> application);

private:
    /**
     * @brief Initializes all core components of the engine.
     * @return Returns a result code indicating whether the initialization was successful.
     */
    EResult Initialize();

    /**
     * @brief Starts the update and render loop.
     */
    void Run();

    /**
     * @brief Shuts down all core components of the engine.
     * @return Returns a result code indicating whether the shutdown was successful.
     * @param result A optional result code indicating the reason for the shutdown.
     */
    EResult Shutdown(EResult result = RESULT_OK);

private:
    /** Determines if the engine is initialized */
    bool m_bIsInitialized;

    /** The application that is running on the engine */
    std::shared_ptr<FApplication> m_Application;

    // Friend classes and functions
    friend EResult EngineMain(std::shared_ptr<FApplication> application);
};

static std::shared_ptr<FEngine> GEngine;

/**
 * @brief Initializes the engine and starts the update and render loop. When the loop is finished, the engine is shut down.
 * @param application The application that is running on the engine.
 * @return Returns a result code indicating whether the operation was successful.
 */
EResult EngineMain(std::shared_ptr<FApplication> application);
