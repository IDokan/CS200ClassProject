/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   PlatformWindow.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

 It is a concept class that wrap up with really Platform window.
******************************************************************************/
#include "Window.h"
#include "PlatformWindow.h"

Window::Window() noexcept
	: platformWindow(std::make_unique<PlatformWindow>())
{
}

bool Window::CreateWindow() noexcept
{
	return platformWindow->CreateWindow();
}

void Window::PollEvent() noexcept
{
	platformWindow->PollEvent();
}

void Window::SwapBackBuffer() const noexcept
{
	platformWindow->SwapBackBuffer();
}

void Window::ToggleFullscreen() noexcept
{
	platformWindow->ToggleFullscreen();
}

bool Window::IsFullscreen() noexcept
{
	return platformWindow->IsFullScreen();
}

vector2<int> Window::WindowSize() noexcept
{
	return platformWindow->GetPlatformWindowSize();
}

bool Window::IsMonitorVerticalSynchronizationOn() noexcept
{
	return platformWindow->IsMonitorVerticalSynchronizationOn();
}

void Window::TurnOnMonitorVerticalSynchronization(bool enable) noexcept
{
	platformWindow->TurnOnMonitorVerticaSynchronization(enable);
}

void Window::ClearWindow() const noexcept
{
	platformWindow->ClearWindow();
}

void Window::SetWindowTitle(const std::string& title) noexcept
{
	platformWindow->SetWindowTitle(title);
}

void Window::SetWindowTitleWithFPS(int fps) noexcept
{
	platformWindow->SetWindowTitleWithFPS(fps);
}
