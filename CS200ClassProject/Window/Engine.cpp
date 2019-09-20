#include "Application.hpp"
#include "Engine.hpp"

void Engine::Init()
{
	app = Application::GetApplication();
	app->Init();
}

void Engine::Update()
{
	while (isRunning)
	{
		app->Update();
	}
}

void Engine::Clear()
{
	app->Clear();
}
