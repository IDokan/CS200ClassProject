/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   PlatformWindow.h
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

History file the level that show a bunch of drawing function by others directly.
	Yes, sometimes it worked like it.
******************************************************************************/
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

