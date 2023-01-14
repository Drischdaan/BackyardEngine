﻿#pragma once

#include <Backyard/Core/Types.h>

#include <GLFW/glfw3.h>

struct FWindowState
{
    const char* Title;
    uint32 Width;
    uint32 Height;
    bool8 IsFullscreen;
};

class FWindow
{
public:
    FWindow(const FWindowState& state);
    ~FWindow();

    void SetTitle(const char* title);
    void SetFullscreen(bool8 value);
    void SetSize(uint32 width, uint32 height);

    [[nodiscard]] bool8 IsCloseRequested() const;
    
    [[nodiscard]] FWindowState GetState() const;

private:
    FWindowState m_State;

    GLFWwindow* m_WindowHandle;
    
};