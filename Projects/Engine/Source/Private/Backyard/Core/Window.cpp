#include "pch.h"

#include <Backyard/Core/Window.h>

FWindow::FWindow(const FWindowState& state, GLFWmonitor* monitor, const GLFWvidmode* videoMode)
    : m_State(state), m_Monitor(monitor), m_VideoMode(videoMode), m_WindowHandle(nullptr)
{
    m_WindowHandle = glfwCreateWindow(state.Width, state.Height, state.Title, nullptr, nullptr);
    glfwSetWindowUserPointer(m_WindowHandle, this);
    glfwSetWindowSizeCallback(m_WindowHandle, [](GLFWwindow* window, int width, int height)
    {
        FWindow* windowInstance = static_cast<FWindow*>(glfwGetWindowUserPointer(window));
        windowInstance->m_State.Width = width;
        windowInstance->m_State.Height = height;
    });
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
        glfwSetWindowMonitor(m_WindowHandle, m_Monitor, 0, 0, m_VideoMode->width, m_VideoMode->height, m_VideoMode->refreshRate);
    }
    else
    {
        const uint32 posX = (m_VideoMode->width - m_State.Width) / 2;
        const uint32 posY = (m_VideoMode->height - m_State.Height) / 2;
        glfwSetWindowMonitor(m_WindowHandle, nullptr, posX, posY, m_State.Width, m_State.Height, m_VideoMode->refreshRate);
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
