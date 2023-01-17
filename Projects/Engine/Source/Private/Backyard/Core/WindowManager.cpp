#include "pch.h"

#include <Backyard/Core/WindowManager.h>

FWindowManager::FWindowManager()
    : m_PrimaryMonitor(nullptr), m_PrimaryMonitorVideoMode(nullptr), m_PrimaryWindow(nullptr)
{
}

FWindowManager::~FWindowManager() = default;

EResult FWindowManager::Initialize()
{
    glfwInit();
    m_PrimaryMonitor = glfwGetPrimaryMonitor();
    m_PrimaryMonitorVideoMode = glfwGetVideoMode(m_PrimaryMonitor);
    LOG_DEBUG("Monitor Specification:");
    LOG_DEBUG(" - Name: {}", glfwGetMonitorName(m_PrimaryMonitor));
    LOG_DEBUG(" - Width: {}px", m_PrimaryMonitorVideoMode->width);
    LOG_DEBUG(" - Height: {}px", m_PrimaryMonitorVideoMode->height);
    LOG_DEBUG(" - Refreshrate: {}hz", m_PrimaryMonitorVideoMode->refreshRate);
    return RESULT_OK;
}

void FWindowManager::Shutdown()
{
    for (const auto& window : m_Windows)
        delete window;
    m_Windows.clear();
    m_PrimaryWindow = nullptr;
    glfwTerminate();
}

FWindow* FWindowManager::Create(const FWindowState& state)
{
    FWindow* window = new FWindow(state, m_PrimaryMonitor, m_PrimaryMonitorVideoMode);
    m_Windows.push_back(window);
    return window;
}

void FWindowManager::SetPrimaryWindow(FWindow* window)
{
    m_PrimaryWindow = window;
}

void FWindowManager::HandleInput() const
{
    glfwPollEvents();
}

GLFWmonitor* FWindowManager::GetPrimaryMonitor() const
{
    return m_PrimaryMonitor;
}

const GLFWvidmode* FWindowManager::GetPrimaryMonitorVideoMode() const
{
    return m_PrimaryMonitorVideoMode;
}

std::vector<FWindow*> FWindowManager::GetWindows() const
{
    return m_Windows;
}

FWindow* FWindowManager::GetPrimaryWindow() const
{
    return m_PrimaryWindow;
}
