#include "BasicLevel.hpp"
#include <vector2.hpp>

void BasicLevel::Init()
{
	sketch.Init();
}

void BasicLevel::Update(float dt)
{
	sketch.Update(dt);

	sketch.StartDrawing();
	sketch.DrawEllipses(vector2<float>(0.f), vector2<float>(100.f, 200.f));
	sketch.PushMatrix(MATRIX3::build_translation(vector2<float>(50.f)));
	{
		sketch.DrawRectangles(vector2<float>(100.f), vector2<float>(50.f));
		sketch.DrawLines(vector2<float>(-100.f, -50.f), vector2<float>(-100.f, 100.f));
		sketch.DrawTriangles(vector2<float>(60.f, 90.f), vector2<float>(70.f, 40.f), vector2<float>(50.f, 80.f));
		sketch.DrawQuads(vector2<float>(-200.f), vector2<float>(-500.f),
			vector2<float>(-400.f, -300.f), vector2<float>(-300.f, -200.f));
	}
	sketch.PopMatrix();
	sketch.FinishDrawing();
}

void BasicLevel::Clear()
{
	sketch.Clear();
}
