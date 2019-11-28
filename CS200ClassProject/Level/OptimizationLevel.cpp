#include <Level/OptimizationLevel.hpp>

OptimizationLevel::OptimizationLevel(Demo& demo)
	: State(demo)
{}

void OptimizationLevel::Init()
{
	sketch.InitCamera();
	sketch.SetBackgroundColor({ 0.f, 0.f, 1.f });
	sketch.SetImage("C:/Users/KMU_USER/Desktop/CS200ClassProject/CS200ClassProject/assets/texture/circle.png");
}

void OptimizationLevel::Update(float dt)
{
	sketch.Update(dt);
	
	sketch.StartDrawing();

	sketch.Instancing(100);

	sketch.FinishDrawing();
}

void OptimizationLevel::Clear()
{
	isShowHelp = false;
}
