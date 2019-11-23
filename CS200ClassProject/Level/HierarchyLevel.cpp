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
	sketch.SetImage("C:/Users/KMU_USER/Desktop/CS200ClassProject/CS200ClassProject/assets/texture/Suhwan.png");
}

void HierarchyLevel::Update(float dt)
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

	// Draw help
	if (isShowHelp)
	{
		sketch.DrawQuads(vector2{ -2000.f, -2000.f }, vector2{ -2000.f, 2000.f }, vector2{ 2000.f, 2000.f }, vector2{ 2000.f, -2000.f }, Graphics::Color4f{ 0.f, 0.5f }, -0.8f);
		sketch.DrawText(vector2{ -700.f, 300.f }, vector2{ 1.f }, L"This Level shows texture and hierarchical transform.\n\nTexture:\n\tIt is a pixel art that I draw with Aseprite.\n\nHierarchy:\n\tThe Suwhan's position is fixed by mouse position, \n\tThe UIs such as HP bar and NickName follow him \n\tbecause they are child him.\n", -0.9f);
		sketch.DrawQuads(vector2{ -800.f, 500.f }, vector2{ -535.f, 500.f }, vector2{ -535.f, 400.f }, vector2{ -800.f, 400.f }, Graphics::Color4f{ 1.f, 0.f, 0.f, 1.f }, -0.85f);
		sketch.DrawText(vector2{ -800.f, 400.f }, vector2{ 1.f }, L"'H' for Close", -0.95f);
	}
	else
	{
		sketch.DrawQuads(vector2{ -800.f, 500.f }, vector2{ -550.f, 500.f }, vector2{ -550.f, 400.f }, vector2{ -800.f, 400.f }, Graphics::Color4f{ 0.f }, -0.1f);
		sketch.DrawText(vector2{ -800.f, 400.f }, vector2{ 1.f }, L"'H' for Help", -0.2f);
	}
	
	sketch.FinishDrawing();
}