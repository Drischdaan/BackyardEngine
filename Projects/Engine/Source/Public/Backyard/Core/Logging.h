#pragma once

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>

class FApplication;

class FLogging
{
private:
    /**
     * @brief Initializes the logging library and creates the engine and application loggers
     */
    static void Initialize();

    /**
     * @brief Shuts down the logging library
     */
    static void Shutdown();

    /**
     * @brief Creates the required sinks and the engine logger
     */
    static void CreateEngineLogger();

    /**
     * @brief Creates the required sinks and the engine logger
     */
    static void CreateApplicationLogger();
    
public:
    /**
     * @brief Returns the engine logger
     * @return The engine logger
     */
    [[nodiscard]] static std::shared_ptr<spdlog::logger> GetEngineLogger();

    /**
     * @brief Returns the engine logger
     * @return The application logger
     */
    [[nodiscard]] static std::shared_ptr<spdlog::logger> GetApplicationLogger();

private:
    /** \brief The engine logger */
    inline static std::shared_ptr<spdlog::logger> s_EngineLogger = nullptr;

    /** \brief The application logger */
    inline static std::shared_ptr<spdlog::logger> s_ApplicationLogger = nullptr;

    friend EResult EngineMain(std::shared_ptr<FApplication> application);
};

#ifdef _BACKYARD_ENGINE_COMPILE
    #define DEFAULT_LOGGER FLogging::GetEngineLogger()
#else
    #define DEFAULT_LOGGER FLogging::GetApplicationLogger()
#endif

#define LOG_TRACE(message, ...) SPDLOG_LOGGER_TRACE(DEFAULT_LOGGER, message, __VA_ARGS__)
#define LOG_DEBUG(message, ...) SPDLOG_LOGGER_DEBUG(DEFAULT_LOGGER, message, __VA_ARGS__)
#define LOG_INFO(message, ...) SPDLOG_LOGGER_INFO(DEFAULT_LOGGER, message, __VA_ARGS__)
#define LOG_WARNING(message, ...) SPDLOG_LOGGER_WARN(DEFAULT_LOGGER, message, __VA_ARGS__)
#define LOG_ERROR(message, ...) SPDLOG_LOGGER_ERROR(DEFAULT_LOGGER, message, __VA_ARGS__)
#define LOG_CRITICAL(message, ...) SPDLOG_LOGGER_CRITICAL(DEFAULT_LOGGER, message, __VA_ARGS__)
