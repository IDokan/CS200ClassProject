/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Window.h
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

 It is a concept class that wrap up with really Platform window.
******************************************************************************/
#pragma once
#include <memory>
#include "PlatformWindow.h"

template<typename T>
struct vector2;

class PlatformWindow;
class Window
{
public:
	Window() noexcept;
	virtual ~Window() noexcept = default;

	bool CreateWindow() noexcept;
	void PollEvent() noexcept;
	void SwapBackBuffer() const noexcept;
	void ToggleFullscreen() noexcept;
	bool IsFullscreen() noexcept;
	vector2<int> WindowSize() noexcept;
	bool IsMonitorVerticalSynchronizationOn() noexcept;
	void TurnOnMonitorVerticalSynchronization(bool enable) noexcept;
	void ClearWindow() const noexcept;
	void SetWindowTitle(const std::string& title) noexcept;
	void SetWindowTitleWithFPS(int fps) noexcept;

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	Window(Window&&) = delete;
	Window& operator=(Window&&) = delete;

private:
	std::unique_ptr<PlatformWindow> platformWindow{};
};

