#pragma once
#include "Window.h"
#include "Input/InputController.h"
#include "Graphics/Sketch.hpp"

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
	
private:
	void InputTest();
	
	Window window;
	Application() = default;

	Sketch sketch;
};

