#include "BasicLevel.hpp"
#include <vector2.hpp>

void BasicLevel::Init()
{
	sketch.Init();
}

void BasicLevel::Update(float /*dt*/)
{
	sketch.StartDrawing();
	sketch.DrawEllipses(vector2<float>(0.f), vector2<float>(100.f, 200.f));
	sketch.DrawRectangles(vector2<float>(100.f), vector2<float>(50.f));
	sketch.DrawLines(vector2<float>(-100.f, -50.f), vector2<float>(-100.f, 100.f));
	sketch.DrawTriangles(vector2<float>(60.f, 90.f), vector2<float>(70.f, 40.f), vector2<float>(50.f, 80.f));
	sketch.FinishDrawing();
}

void BasicLevel::Clear()
{
	sketch.Clear();
}
