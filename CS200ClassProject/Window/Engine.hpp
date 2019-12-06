/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Engine.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Engine file the level that show a bunch of drawing function by others directly.

******************************************************************************/
#pragma once
#include "Application.hpp"
#include "Timer/Timer.hpp"

class Engine
{
public:
	Engine() = default;
	
	void Init();
	void Update();
	void Clear();

	bool IsRunning();
	
private:
	bool isRunning;
	Application* app;
	Timer timer;
	float dt;
};

