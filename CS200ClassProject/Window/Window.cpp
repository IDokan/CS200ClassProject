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
