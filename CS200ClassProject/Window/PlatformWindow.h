#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
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
	vector2<int> GetPlatformWindowSize() const noexcept;

	void SetWindowTitle(const std::string& title) noexcept;
	void SetWindowTitleWithFPS(int fps) noexcept;

	void ClearWindow() const noexcept;

private:
	GLFWwindow* window;
	
	int xPosition;
	int yPosition;
	int xSize = 1600;
	int ySize = 900;
	bool isVsyncOn;
	vector2<int> windowSize{ xSize, ySize };
};

