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

