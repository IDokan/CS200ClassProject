#include "Application.hpp"

Application* Application::GetApplication()
{
	static Application* application = new Application;
	return application;
}

void Application::Init()
{
	window.CreateWindow();
	window.TurnOnMonitorVerticalSynchronization(true);
	
}

void Application::Update()
{
	window.PollEvent();
	window.SwapBackBuffer();
}

void Application::Clear()
{
	window.ClearWindow();
}
