/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Application.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Demo file the level that show a bunch of lecture by others directly.

******************************************************************************/
#include <iostream>
#include "Application.hpp"
#include <Graphics/OpenGL/Screenshot.hpp>
#include <Graphics/OpenGL/GL.hpp>

Application* Application::GetApplication()
{
	static Application* application = new Application{};
	return application;
}

void Application::Init()
{
	isRunning = true;
	isPaused = false;
	
	window.CreateWindow();
	window.TurnOnMonitorVerticalSynchronization(true);

	demo.Init();
	
	input.Init();
}

void Application::Update(float dt)
{
	input.TriggeredReset();
	window.PollEvent();
	
	if (isPaused)
	{
		return;
	}
	CalculateFPS(dt);
	
	BroadInputProcess();

	demo.Update(dt);
	
	window.SwapBackBuffer();
}

void Application::BroadInputProcess()
{
	if (input.IsKeyTriggered(GLFW_KEY_H))
	{
		demo.SetIsShowHelp(!demo.IsShowHelp());
	}
	if (input.IsKeyTriggered(GLFW_KEY_0) || input.IsKeyTriggered(GLFW_KEY_KP_0))
	{
		demo.SetStateIndex(0);
	}
	else if (input.IsKeyTriggered(GLFW_KEY_1) || input.IsKeyTriggered(GLFW_KEY_KP_1))
	{
		demo.SetStateIndex(1);
	}
	else if (input.IsKeyTriggered(GLFW_KEY_2) || input.IsKeyTriggered(GLFW_KEY_KP_2))
	{
		demo.SetStateIndex(2);
	}
	else if (input.IsKeyTriggered(GLFW_KEY_3) || input.IsKeyTriggered(GLFW_KEY_KP_3))
	{
		demo.SetStateIndex(3);
	}
	else if (input.IsKeyTriggered(GLFW_KEY_4) || input.IsKeyTriggered(GLFW_KEY_KP_4))
	{
		demo.SetStateIndex(4);
	}
	if (input.IsKeyTriggered(GLFW_KEY_V))
	{
		window.TurnOnMonitorVerticalSynchronization(!window.IsMonitorVerticalSynchronizationOn());
	}
	if (input.IsKeyTriggered(GLFW_KEY_F))
	{
		window.ToggleFullscreen();
	}
	if (input.IsKeyTriggered(GLFW_KEY_F11))
	{
		vector2<int> windowSize = window.WindowSize();
		Graphics::Image screenShot = Graphics::capture_screenshot_of_back_buffer_to_image(windowSize.width, windowSize.height);
		screenShot.SaveToPNG("../testScreenShot.png");
	}
}

void Application::CalculateFPS(float dt)
{
	fpsEllapsedTime += dt;
	++fpsFrames;
	if (fpsEllapsedTime >= 1.f)
	{
		window.SetWindowTitleWithFPS(fpsFrames);
		fpsFrames = 0;
		fpsEllapsedTime = 0;
	}
}

void Application::Clear()
{
	demo.Clear();
	window.ClearWindow();
}

vector2<int> Application::GetWindowSize() noexcept
{
	return window.WindowSize();
}

bool Application::IsRunning() const noexcept
{
	return isRunning;
}

void Application::SetIsRunning(bool flag) noexcept
{
	isRunning = flag;
}

bool Application::IsPaused() const noexcept
{
	return isPaused;
}

void Application::SetIsPaused(bool flag) noexcept
{
	isPaused = flag;
}
