/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   BasicLevel.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Source file for basic level that shows text, simple shapes, input, and camera
******************************************************************************/
#include "BasicLevel.hpp"
#include <vector2.hpp>

BasicLevel::BasicLevel(Demo& demo)
	:State(demo)
{
}

void BasicLevel::Init()
{
	sketch.InitCamera();
	sketch.SetBackgroundColor(Graphics::Color4f{ 0.f, 0.2f, 1.f });
}

void BasicLevel::Clear()
{
	isShowHelp = false;
}

void BasicLevel::Update(float dt)
{
	sketch.Update(dt);

	sketch.StartDrawing();
	sketch.PushMatrix(MATRIX3::build_translation(vector2{ 200.f, 0.f }));
	sketch.DrawEllipses(vector2<float>{-300.f, 300.f}, vector2<float>{150.f, 30.f});
	sketch.DrawText(vector2<float>{
		-375.f, 200.f}, vector2<float>(1.f), L"Ellipse");
	sketch.DrawRectangles(vector2<float>(-100.f, 300.f), vector2<float>(50.f, 125.f));
	sketch.DrawText(vector2<float>{
		-155.f, 175.f}, vector2<float>(1.f), L"Rectangle");
	sketch.DrawQuads(vector2<float>(50.f, 350.f), vector2<float>(450.f, 350.f),
		vector2<float>(350.f,150.f), vector2<float>(150.f, 150.f));
	sketch.DrawText(vector2<float>{
		225.f, 75.f}, vector2<float>(1.f), L"Quad");
	sketch.DrawTriangles(vector2<float>(0.f), vector2<float>(0.f, -400.f), vector2<float>(-400.f, -400.f));
	sketch.DrawText(vector2<float>{
		-400.f, -25.f}, vector2<float>(1.f), L"Triangle");
	sketch.DrawLines(vector2{ 100.f, 0.f }, vector2{ 500.f, -400.f });
	sketch.DrawText(vector2<float>{
		300.f, -125.f}, vector2<float>(1.f), L"Line");
	sketch.PopMatrix();
	sketch.DrawText(vector2{-750.f, 300.f}, vector2{1.f}, L"Test Text:\n\tThe quick brown \n\tfox jumps over \n\tthe lazy dog.");


	State::HelpBox(L"This Level shows simple shapes, text, and camera moving.\n\nCamera Moving:\n\tRight mouse click and drag -> Camera Translation.\n\t'Q' & 'E' -> Camera Rotation.\n\tMouse Wheel Up & Down -> Camera Zooming.\n\nSimple Shapes:\n\tThere are Ellipses, Rectangles, Quads, Triangles, Lines.\n\nText:\n\tThere are text that describe what their kind is.");
	
	sketch.FinishDrawing();
}
