#pragma once
#include "Window.h"

class Application
{
public:
	static Application* GetApplication();
	void Init();
	void Update();
	void Clear();
private:
	Window window;
	Application() = default;
};

