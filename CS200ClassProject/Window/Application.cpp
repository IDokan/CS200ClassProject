#include "Application.hpp"

Application* Application::GetApplication()
{
	static Application* application = new Application;
	return application;
}

void Application::Init()
{
	//dsaf
}

void Application::Update()
{
}

void Application::Clear()
{
}
