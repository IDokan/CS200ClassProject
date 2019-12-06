/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   StartLevel.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Source file for Start Initial Level
******************************************************************************/

#include <Level/StartLevel.hpp>

StartLevel::StartLevel(Demo& demo)
	:State(demo)
{
}

void StartLevel::Init()
{
	sketch.InitCamera();
	sketch.SetBackgroundColor(Graphics::Color4f{ 0.f, 0.5f, 0.f });
}

void StartLevel::Update(float /*dt*/)
{
	sketch.StartDrawing();
	State::HelpBox(L"It is a help box that \n\tmake you know what purpose and description of each level.\n\nThere is a 5 level include current level.\n\nPress 1 to go to a BasicLevel.\nPress 2 to go to a HierarchyLevel.\nPress 3 to go to a ParticleLevel.\nPress 4 to go to a OptimizationLevel.\nLastly, if you want to return, back to here Press 0");
	sketch.FinishDrawing();
}

void StartLevel::Clear()
{
	isShowHelp = false;
}
