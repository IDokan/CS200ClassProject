/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Engine.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

Engine file the level that show a bunch of drawing function by others directly.

******************************************************************************/
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

	if (input.IsKeyTriggered(GLFW_KEY_ESCAPE) || !app->IsRunning())
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
