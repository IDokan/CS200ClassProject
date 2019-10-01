#pragma once

#include "Graphics/OpenGL/Material.hpp"
#include "Graphics/OpenGL/Vertices.hpp"

class Sketch
{
public:
	void Init();
	void Update(float dt);
	void Clear();

	void StartDrawing();
	void FinishDrawing();

	void DrawEllipses(vector2<float> position, vector2<float> size);
	void DrawEllipses(float x, float y, vector2<float> size);
	void DrawEllipses(vector2<float> position, float width, float height);
	void DrawEllipses(float x, float y, float width, float height);
	void DrawRectangles();
	void DrawQuads();
	void DrawTriangles();
	void DrawLines();
private:
	Graphics::material material;

	Graphics::Vertices ellipse;
	Graphics::Vertices rectangle;
	Graphics::Vertices quad;
	Graphics::Vertices triangle;
	Graphics::Vertices line;
};

