/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   InputController.hpp
Author
	- sinil.gang rtd99062@gmail.com

Creation Date: 08.06.2019

	Header file for the Input.cpp
******************************************************************************/
#pragma once
#include <bitset>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "vector2.hpp"

class Input
{
public:
	void Init();
	void TriggeredReset();
	void SetKeyboardInput(int key, int action);
	void SetMousePos(float xPos, float yPos);
	void SetMouseButtonInput(int button, int action);
	void SetMouseWheel(double x, double y);

	bool IsKeyTriggered(int key);
	bool IsKeyPressed(int key);
	bool IsKeyReleased(int key);

	vector2<float> GetPresentMousePosition() const noexcept;
	void SetPresentMousePosition(const vector2<float>& mousePosition) noexcept;
	vector2<float> GetMousePosition() const  noexcept;
	double MouseWheelScroll();
	bool IsMouseButtonPressed(int button);
	bool IsMouseButtonTriggered(int button);
	bool IsMouseButtonReleased(int button);
	bool IsMouseDoubleClicked(int button);

private:
	std::bitset<GLFW_KEY_LAST> keyTriggered;
	std::bitset<GLFW_KEY_LAST> keyPressed;
	std::bitset<GLFW_KEY_LAST> keyReleased;

	vector2<float> presentMousePosition{};
	vector2<float> mousePosition{};
	std::bitset<GLFW_MOUSE_BUTTON_LAST> mouseButtonTriggered;
	std::bitset<GLFW_MOUSE_BUTTON_LAST> mouseButtonPressed;
	std::bitset<GLFW_MOUSE_BUTTON_LAST> mouseButtonReleased;
	std::bitset<GLFW_MOUSE_BUTTON_LAST> mouseButtonDoubleClicked;

	double xOffset = 0.0;
	double yOffset = 0.0;
};

extern Input input;