/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   HierarchyLevel.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Source file the level that show whether hierarchy is work or not.
******************************************************************************/
#include <Level/HierarchyLevel.hpp>
#include "Input/InputController.h"

HierarchyLevel::HierarchyLevel(Demo& demo)
	:State(demo), playerPosition(0.f)
{
}

void HierarchyLevel::Init()
{
	sketch.InitCamera();
	sketch.SetBackgroundColor(Graphics::Color4f{ 0.f, 1.f, 1.f });
	sketch.SetImage("../assets/texture/Suhwan.png");
}

void HierarchyLevel::Update(float /*dt*/)
{
	playerPosition = input.GetMousePosition();
	Draw();
}

void HierarchyLevel::Clear()
{
	isShowHelp = false;
}

void HierarchyLevel::Draw()
{
	sketch.StartDrawing();
	sketch.DrawTexture(playerPosition, vector2<float>{120.f, 370.f});
	sketch.PushMatrix(MATRIX3::build_translation(playerPosition));
	{
		sketch.DrawText(vector2{ -140.f, 210.f }, vector2{ 1.f }, L"< Suhwan >");
		sketch.DrawQuads(vector2{ -100.f, -210.f }, vector2{ 100.f, -210.f }, vector2{ 100.f, -260.f }, vector2{ -100.f, -260.f }, Graphics::Color4f{ 1.f, 0.f, 0.f });
		sketch.DrawQuads(vector2{ -105.f, -205.f }, vector2{ 105.f, -205.f }, vector2{ 105.f, -265.f }, vector2{ -105.f, -265.f });
	}
	sketch.PopMatrix();

	State::HelpBox(L"This Level shows texture, hierarchical transform, and screen-shot.\n\nTexture:\n\tIt is a pixel art that I draw.\n\nHierarchy:\n\tThe Suwhan's position is fixed by mouse position, \n\tThe UIs such as HP bar and NickName follow him \n\tbecause they are child of him.\n\nLastly, Press F11 to take a picture.\n\tActually, Screen-shot is work everywhere.");
	
	sketch.FinishDrawing();
}
