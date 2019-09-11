#pragma once
#include <memory>
#include <vector2.hpp>

class PlatformWindow;
class Window
{
public:
	Window() noexcept;
	virtual ~Window() noexcept;

	bool CreateWindow() noexcept;
	void PollEvent() noexcept;
	void SwapBackBuffer() const noexcept;
	void ToggleFullscreen() noexcept;
	bool IsFullscreen() noexcept;
	Graphics::vector2<int> WindowSize() noexcept;
	bool IsMonitorVerticalSynchronizationOn() noexcept;
	void TurnOnMonitorVerticalSynchronization(bool enable) noexcept;
	void ClearWindow() const noexcept;

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	Window(Window&&) = delete;
	Window& operator=(Window&&) = delete;

private:
	std::unique_ptr<PlatformWindow> platformWindow{};
};

