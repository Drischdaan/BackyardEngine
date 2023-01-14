#pragma once

#include <GLFW/glfw3.h>

#include "Window.h"

class FWindowManager
{
public:
    FWindowManager();
    ~FWindowManager();

    EResult Initialize();
    void Shutdown();

    FWindow* Create(const FWindowState& state);
    void SetPrimaryWindow(FWindow* window);

    void HandleInput() const;

    [[nodiscard]] GLFWmonitor* GetPrimaryMonitor() const;
    [[nodiscard]] const GLFWvidmode* GetPrimaryMonitorVideoMode() const;
    [[nodiscard]] std::vector<FWindow*> GetWindows() const;
    [[nodiscard]] FWindow* GetPrimaryWindow() const;

private:
    GLFWmonitor* m_PrimaryMonitor;
    const GLFWvidmode* m_PrimaryMonitorVideoMode;

    std::vector<FWindow*> m_Windows;
    FWindow* m_PrimaryWindow;
    
};
