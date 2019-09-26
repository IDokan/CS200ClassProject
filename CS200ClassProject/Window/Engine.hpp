#pragma once
#include "Application.hpp"

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
};

