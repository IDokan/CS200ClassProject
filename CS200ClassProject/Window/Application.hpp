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
#pragma once
#include "Window.h"
#include "Input/InputController.h"
#include <Level/BasicLevel.hpp>
#include <Level/State.hpp>

	template<typename>
	struct vector2;

class Application
{
public:
	static Application* GetApplication();
	void Init();
	void Update(float dt);
	void Clear();

	vector2<int> GetWindowSize() noexcept;

	bool IsRunning() const noexcept;
	void SetIsRunning(bool flag) noexcept;

	bool IsPaused() const noexcept;
	void SetIsPaused(bool flag) noexcept;
	
private:
	void BroadInputProcess();
	void CalculateFPS(float dt);
	Application() : isPaused(false), isRunning(true), fpsEllapsedTime(0.f), fpsFrames(0) {};

	bool isPaused;
	bool isRunning;
	
	Window window;

	Demo demo;

	/* FPS variables */
	float fpsEllapsedTime;
	int fpsFrames;
};

