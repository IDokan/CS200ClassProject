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
	void InputTest();
	Application() {};

	bool isPaused;
	bool isRunning;
	
	Window window;

	Demo demo;
};

