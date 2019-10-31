#include <iostream>
#include "Application.hpp"
#include <Graphics/OpenGL/Screenshot.hpp>

Application* Application::GetApplication()
{
	static Application* application = new Application{};
	return application;
}

void Application::Init()
{
	window.CreateWindow();
	window.TurnOnMonitorVerticalSynchronization(true);

	level0.Init();
	
	input.Init();
}

void Application::Update(float dt)
{
	input.TriggeredReset();
	
	window.PollEvent();
	InputTest();

	level0.Update(dt);
	
	window.SwapBackBuffer();
}

void Application::InputTest()
{
	if (input.IsKeyPressed(GLFW_KEY_A))
	{
		std::cout << "A" << std::endl;
	}
	if (input.IsKeyPressed(GLFW_KEY_B))
	{
		std::cout << "B" << std::endl;
	}
	if (input.IsMouseButtonTriggered(GLFW_MOUSE_BUTTON_LEFT))
	{
		std::cout << "left mouse button triggered" << std::endl;
	}
	if (input.IsMouseButtonTriggered(GLFW_MOUSE_BUTTON_RIGHT))
	{
		std::cout << "right mouse button triggered" << std::endl;
	}
	if (input.IsMouseButtonTriggered(GLFW_MOUSE_BUTTON_MIDDLE))
	{
		std::cout << "middle mouse button triggered" << std::endl;
	}
	if (input.IsMouseDoubleClicked(GLFW_MOUSE_BUTTON_LEFT))
	{
		std::cout << "mouse button double clicked" << std::endl;
	}
	if (input.IsKeyTriggered(GLFW_KEY_V))
	{
		window.TurnOnMonitorVerticalSynchronization(!window.IsMonitorVerticalSynchronizationOn());
	}
	if (input.IsKeyTriggered(GLFW_KEY_F))
	{
		window.ToggleFullscreen();
	}
	if (input.IsKeyTriggered(GLFW_KEY_KP_9))
	{
		vector2<int> windowSize = window.WindowSize();
		Graphics::Image screenShot = Graphics::capture_screenshot_of_back_buffer_to_image(windowSize.width, windowSize.height);
		screenShot.SaveToPNG("C:/Users/KMU_USER/Desktop/CS200ClassProject/CS200ClassProject/ScreenShot/testScreenShot.png");
	}
}

void Application::Clear()
{
	level0.Clear();
	window.ClearWindow();
}

vector2<int> Application::GetWindowSize() noexcept
{
	return window.WindowSize();
}
