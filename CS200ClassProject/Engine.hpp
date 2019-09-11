#pragma once

class Engine
{
public:
	Engine() = default;
	
	void Init();
	void Update();
	void Clear();

private:
	bool isRunning;
	Application* app;
};

