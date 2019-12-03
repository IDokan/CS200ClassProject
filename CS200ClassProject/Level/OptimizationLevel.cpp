#include <Level/OptimizationLevel.hpp>
#include "Input/InputController.h"

#define numOfInstance 100

OptimizationLevel::OptimizationLevel(Demo& demo)
	: State(demo), isOptimized(true)
{}

void OptimizationLevel::Init()
{
	sketch.InitCamera();
	sketch.SetBackgroundColor({ 0.f, 0.f, 1.f });
#ifdef _DEBUG
	sketch.SetImage("C:/Users/KMU_USER/Desktop/CS200ClassProject/CS200ClassProject/assets/texture/circle.png");
#else
	sketch.SetImage("C:/Users/KMU_USER/Desktop/CS200ClassProject/CS200ClassProject/assets/texture/circle.png");
#endif
}

void OptimizationLevel::Update(float /*dt*/)
{
	vector2<float> textureSize{ 150.f };

	if(input.IsKeyTriggered(GLFW_KEY_O))
	{
		isOptimized = !isOptimized;
	}
	
	Graphics::Color4f color{ 0.f };
	sketch.StartDrawing();
	if (!isOptimized)
	{
		for (size_t i = 0; i < 100; i++)
		{
			sketch.NoInstancing(numOfInstance);
		}
	}
	else
	{
		for (size_t i = 0; i < 100; i++)
		{
			sketch.Instancing(numOfInstance);
		}
	}

	State::HelpBox(L"This level shows instance drawing (Optimization)\n\nWhen you pressed the button 'O' which is 'O' of optimization.\n");
	
	sketch.FinishDrawing();
}

void OptimizationLevel::Clear()
{
	isShowHelp = false;
}
