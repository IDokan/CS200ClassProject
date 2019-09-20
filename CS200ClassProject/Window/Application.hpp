#pragma once
class Application
{
public:
	static Application* GetApplication();
	void Init();
	void Update();
	void Clear();
private:
	// Window
	Application() = default;
};

