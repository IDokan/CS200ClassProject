#include "Graphics/Sketch.hpp"
#include <Graphics/OpenGL/GL.hpp>
#include "Graphics/OpenGL/Mesh.hpp"
#include "Graphics/OpenGL/StockShaders.hpp"


void Sketch::Init()
{
	Graphics::GL::setup();

	// Mesh Init
	Graphics::Mesh mesh;
	const Graphics::VertexLayoutDescription& meshData{ Graphics::SHADER::solid_color_vertex_layout() };
	mesh.SetPointListType(Graphics::PointListPattern::TriangleFan);

	// Ellipse mesh Init
	const int numOfCirclePoint = 30;
	float angle = MATH::TWO_PI / numOfCirclePoint;
	for (int i = 0; i <= numOfCirclePoint; ++i)
	{
		mesh.AddPoint(vector2<float>{ cos(angle* float(i)) * 0.5f, sin(angle* float(i)) * 0.5f });
	}
	ellipse.InitializeWithMeshAndLayout(mesh, meshData);

	mesh.ClearPoints();

	// Rectangle mesh Init
	mesh.AddPoint(vector2{ -0.5f });
	mesh.AddPoint(vector2{ -0.5f, 0.5f });
	mesh.AddPoint(vector2{ 0.5f });
	mesh.AddPoint(vector2{ 0.5f, -0.5f });
	rectangle.InitializeWithMeshAndLayout(mesh, meshData);
}

void Sketch::Update(float /*dt*/)
{
}

void Sketch::Clear()
{
}

void Sketch::StartDrawing()
{
	Graphics::GL::begin_drawing();
}

void Sketch::FinishDrawing()
{
	Graphics::GL::end_drawing();
}

void Sketch::DrawEllipses(vector2<float> position, vector2<float> size)
{
	material.shader = &Graphics::SHADER::solid_color();
	
}

void Sketch::DrawEllipses(float x, float y, float width, float height)
{
	
}
