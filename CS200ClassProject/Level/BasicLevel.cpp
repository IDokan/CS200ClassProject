#include "BasicLevel.hpp"
#include <vector2.hpp>

void BasicLevel::Update(float dt)
{
	sketch.Update(dt);

	sketch.StartDrawing();
//	sketch.DrawText(vector2<float>(0.f), vector2<float>(1.f), 
//L"AaBbCcDdEeFf\n\nGgHhIiJjKkLl\n\tMmNnOoPpQqRrSs\n\n\nTtUuVv\n\t\tWwXxYyZz");
	//sketch.DrawEllipses(vector2<float>(0.f), vector2<float>(100.f, 200.f));
	// C:/Users/KMU_USER/Desktop/CS200ClassProject/CS200ClassProject/texture/rect.png
	// C:/Users/KMU_USER/Desktop/GAM200Engine/texture/testSpriteSheet.png
	//sketch.DrawTexture(vector2<float>(-100.f), vector2<float>(100.f));

	sketch.DrawEllipses(vector2<float>{-300.f, 300.f}, vector2<float>{150.f, 30.f});
	sketch.DrawRectangles(vector2<float>(-100.f, 300.f), vector2<float>(50.f, 125.f));
	sketch.DrawQuads(vector2<float>(50.f, 350.f), vector2<float>(450.f, 350.f),
		vector2<float>(350.f,150.f), vector2<float>(150.f, 150.f));
	sketch.DrawTriangles(vector2<float>(0.f), vector2<float>(0.f, -400.f), vector2<float>(-400.f, -400.f));
	sketch.DrawLines(vector2{ 100.f, -500.f }, vector2{ 500.f, -100.f });
	
	sketch.FinishDrawing();
}