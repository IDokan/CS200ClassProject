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

