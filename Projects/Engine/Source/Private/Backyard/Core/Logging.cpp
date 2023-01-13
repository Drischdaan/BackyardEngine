#include "pch.h"

#include <Backyard/Core/Logging.h>

#include <spdlog/sinks/stdout_color_sinks.h>

static const char* s_DefaultPattern = "%^[%T] [%=11!n] [%20!s:%-4!#] [%=8!l]%$ %v";

void FLogging::Initialize()
{
    CreateEngineLogger();
    spdlog::register_logger(s_EngineLogger);

    CreateApplicationLogger();
    spdlog::register_logger(s_ApplicationLogger);

    spdlog::set_default_logger(s_ApplicationLogger);
    spdlog::set_level(spdlog::level::trace);
    spdlog::set_pattern(s_DefaultPattern);
}

void FLogging::Shutdown()
{
    spdlog::shutdown();
}

void FLogging::CreateEngineLogger()
{
    const std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    consoleSink->set_level(spdlog::level::trace);
    consoleSink->set_pattern(s_DefaultPattern);

    const spdlog::sinks_init_list sinkList = { consoleSink };
    s_EngineLogger = std::make_shared<spdlog::logger>("ENGINE", sinkList.begin(), sinkList.end());
    s_EngineLogger->set_level(spdlog::level::trace);
}

void FLogging::CreateApplicationLogger()
{
    const std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    consoleSink->set_level(spdlog::level::trace);
    consoleSink->set_pattern(s_DefaultPattern);

    const spdlog::sinks_init_list sinkList = { consoleSink };
    s_ApplicationLogger = std::make_shared<spdlog::logger>("APPLICATION", sinkList.begin(), sinkList.end());
    s_ApplicationLogger->set_level(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger> FLogging::GetEngineLogger()
{
    return s_EngineLogger;
}

std::shared_ptr<spdlog::logger> FLogging::GetApplicationLogger()
{
    return s_ApplicationLogger;
}
