#include "pch.h"

#include <Backyard/Core/Window.h>

FWindow::FWindow(const FWindowState& state)
    : m_State(state), m_WindowHandle(nullptr)
{
    m_WindowHandle = glfwCreateWindow(state.Width, state.Height, state.Title, nullptr, nullptr);
    glfwSetWindowUserPointer(m_WindowHandle, this);
    glfwSetWindowSizeCallback(m_WindowHandle, [](GLFWwindow* window, int width, int height)
    {
        FWindow* windowInstance = static_cast<FWindow*>(glfwGetWindowUserPointer(window));
        windowInstance->m_State.Width = width;
        windowInstance->m_State.Height = height;
    });
    if(m_State.IsFullscreen)
        SetFullscreen(m_State.IsFullscreen);
}

FWindow::~FWindow()
{
    glfwDestroyWindow(m_WindowHandle);
}

void FWindow::SetTitle(const char* title)
{
    m_State.Title = title;
    glfwSetWindowTitle(m_WindowHandle, title);
}

void FWindow::SetFullscreen(bool8 value)
{
    m_State.IsFullscreen = value;
    if(m_State.IsFullscreen)
    {
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);
        glfwSetWindowMonitor(m_WindowHandle, monitor, 0, 0, videoMode->width, videoMode->height, videoMode->refreshRate);
    }
    else
    {
        glfwSetWindowMonitor(m_WindowHandle, nullptr, 0, 0, m_State.Width, m_State.Height, 0);
    }
}

void FWindow::SetSize(uint32 width, uint32 height)
{
    m_State.Width = width;
    m_State.Height = height;
    glfwSetWindowSize(m_WindowHandle, width, height);
}

bool8 FWindow::IsCloseRequested() const
{
    return glfwWindowShouldClose(m_WindowHandle);
}

FWindowState FWindow::GetState() const
{
    return m_State;
}
