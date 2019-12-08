/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   OptimizationLevel.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Source file the level that show whether hierarchy is work or not.
******************************************************************************/
#include <Level/OptimizationLevel.hpp>
#include "Input/InputController.h"

OptimizationLevel::OptimizationLevel(Demo& demo)
	: State(demo), isOptimized(true)
{}

void OptimizationLevel::Init()
{
	sketch.InitCamera();
	sketch.SetBackgroundColor({ 0.f, 0.f, 1.f });
	sketch.SetImage("../assets/texture/circle.png");
}

void OptimizationLevel::Update(float /*dt*/)
{

	if (input.IsKeyTriggered(GLFW_KEY_O))
	{
		isOptimized = !isOptimized;
	}

	Graphics::Color4f color{ 0.f };
	sketch.StartDrawing();
	if (!isOptimized)
	{
		sketch.NoInstancing(Sketch::MAX_SIZE_INSTANCING);
	}
	else
	{
		sketch.Instancing(Sketch::MAX_SIZE_INSTANCING);
	}

	State::HelpBox(L"This level shows instance drawing (Optimization)\n\nWhen you pressed the button 'O', you can see that \n\tFPS going to decrease drastically.\n\n\nNotice!\n\tIf you are in DEBUG mode, \n\t\tyou may not return back to optimized version \n\t\tbecause FPS is too low to get an input.\n\tTry to test in RELEASE version.");

	sketch.FinishDrawing();
}

void OptimizationLevel::Clear()
{
	isShowHelp = false;
}
