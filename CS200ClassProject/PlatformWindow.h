#pragma once
#include "vector2.hpp"

class PlatformWindow
{
public:
	bool CreateWindow() noexcept;
	void PollEvent() noexcept;
	void SwapBackBuffer() noexcept;
	void ToggleFullscreen() noexcept;
	bool IsFullScreen() noexcept;
	void TurnOnMonitorVerticaSynchronization(bool enable) noexcept;
	bool IsMonitorVerticalSynchronizationOn() noexcept;
	Graphics::vector2<float> GetPlatformWindowSize() const noexcept;

	void ClearWindow() const noexcept;

private:
	//GLFWwindow* window;
	int xPosition;
	int yPosition;
	int xSize = 1600;
	int ySize = 900;
	bool isVsyncOn;
	Graphics::vector2<int> windowSize{ xSize, ySize };
};

