#include "Application.hpp"
#include "Engine.hpp"

void Engine::Init()
{
	isRunning = true;
	app = Application::GetApplication();
	app->Init();
}

void Engine::Update()
{
	dt = static_cast<float>(timer.GetElapsedSeconds());
	timer.Reset();
	app->Update(dt);

	if (input.IsKeyTriggered(GLFW_KEY_ESCAPE))
	{
		app->Clear();
		isRunning = false;
	}
}

void Engine::Clear()
{
	app->Clear();
}

bool Engine::IsRunning()
{
	return isRunning;
}
