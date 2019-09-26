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
	app->Update();
}

void Engine::Clear()
{
	app->Clear();
}

bool Engine::IsRunning()
{
	return isRunning;
}
