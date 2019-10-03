#include "Graphics/Sketch.hpp"
#include <Graphics/OpenGL/GL.hpp>
#include "Graphics/OpenGL/Mesh.hpp"
#include "Graphics/OpenGL/StockShaders.hpp"


void Sketch::Init() noexcept
{
	Graphics::GL::setup();
	cameraManager.Init();

	// Mesh Init
	Graphics::Mesh mesh;
	const Graphics::VertexLayoutDescription& solidLayout = { Graphics::SHADER::solid_color_vertex_layout() };
	mesh.SetPointListType(Graphics::PointListPattern::TriangleFan);

	// Ellipse mesh Init
	const int numOfCirclePoint = 30;
	float angle = MATH::TWO_PI / numOfCirclePoint;
	for (int i = 0; i <= numOfCirclePoint; ++i)
	{
		mesh.AddPoint(vector2<float>{ cos(angle* float(i)) * 0.5f, sin(angle* float(i)) * 0.5f });
	}
	ellipse.InitializeWithMeshAndLayout(mesh, solidLayout);

	mesh.ClearPoints();

	// Rectangle mesh Init
	mesh.AddPoint(vector2{ -0.5f });
	mesh.AddPoint(vector2{ -0.5f, 0.5f });
	mesh.AddPoint(vector2{ 0.5f });
	mesh.AddPoint(vector2{ 0.5f, -0.5f });
	rectangle.InitializeWithMeshAndLayout(mesh, solidLayout);
}

void Sketch::Update(float /*dt*/) noexcept
{
}

void Sketch::Clear() noexcept
{
}

void Sketch::StartDrawing() const noexcept
{
	Graphics::GL::begin_drawing();
}

void Sketch::FinishDrawing() const noexcept
{
	Graphics::GL::end_drawing();
}

void Sketch::DrawEllipses(vector2<float> position, vector2<float> size) noexcept
{
	material.shader = &Graphics::SHADER::solid_color();

	// Set color
	material.color4fUniforms[Graphics::SHADER::Uniform_Color] = Graphics::Color4f{ 1.f };

	const matrix3<float> modelToWorld = cameraManager.GetWorldToNDCTransform() * MATRIX3::build_translation(position) * MATRIX3::build_scale(size);
	material.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = modelToWorld;
	Graphics::GL::draw(ellipse, material);
}

void Sketch::DrawEllipses(float x, float y, vector2<float> size) noexcept
{
	DrawEllipses(vector2<float>(x, y), size);
}

void Sketch::DrawEllipses(vector2<float> position, float width, float height) noexcept
{
	DrawEllipses(position, vector2<float>(width, height));
}

void Sketch::DrawEllipses(float x, float y, float width, float height) noexcept
{
	DrawEllipses(vector2<float>(x, y), vector2<float>(width, height));
}

void Sketch::DrawRectangles(vector2<float> position, vector2<float> size) noexcept
{
	material.shader = &Graphics::SHADER::solid_color();

	// Set color
	material.color4fUniforms[Graphics::SHADER::Uniform_Color] = Graphics::Color4f{ 1.f };

	const matrix3<float> modelToWorld = cameraManager.GetWorldToNDCTransform() * MATRIX3::build_translation(position) * MATRIX3::build_scale(size);
	material.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = modelToWorld;
	Graphics::GL::draw(rectangle, material);
}

void Sketch::DrawRectangles(float x, float y, vector2<float> size) noexcept
{
	DrawRectangles(vector2<float>(x, y), size);
}

void Sketch::DrawRectangles(vector2<float> position, float width, float height) noexcept
{
	DrawRectangles(position, vector2<float>(width, height));
}

void Sketch::DrawRectangles(float x, float y, float width, float height) noexcept
{
	DrawRectangles(vector2<float>(x, y), vector2<float>(width, height));
}

void Sketch::DrawTriangles(vector2<float> position1, vector2<float> position2, vector2<float> position3) noexcept
{
	Graphics::Mesh mesh;
	mesh.AddPoint(position1);
	mesh.AddPoint(position2);
	mesh.AddPoint(position3);
	mesh.SetPointListType(Graphics::PointListPattern::Triangles);

	material.shader = &Graphics::SHADER::solid_color();
	material.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = cameraManager.GetWorldToNDCTransform();

	Graphics::Vertices triangle;
	triangle.InitializeWithMeshAndLayout(mesh, Graphics::SHADER::solid_color_vertex_layout());

	Graphics::GL::draw(triangle, material);
}

void Sketch::DrawTriangles(float x1, float y1, float x2, float y2, float x3, float y3) noexcept
{
	DrawTriangles(vector2<float>(x1, y1), vector2<float>(x2, y2), vector2<float>(x3, y3));
}

void Sketch::DrawLines(vector2<float> position1, vector2<float> position2) noexcept
{
	Graphics::Mesh mesh;
	mesh.AddPoint(position1);
	mesh.AddPoint(position2);
	mesh.SetPointListType(Graphics::PointListPattern::Lines);

	material.shader = &Graphics::SHADER::solid_color();
	material.color4fUniforms[Graphics::SHADER::Uniform_Color] = Graphics::Color4f{ 1.f };
	material.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = cameraManager.GetWorldToNDCTransform();

	Graphics::Vertices line;
	line.InitializeWithMeshAndLayout(mesh, Graphics::SHADER::solid_color_vertex_layout());
	
	Graphics::GL::draw(line, material);
}

void Sketch::DrawLines(float x1, float y1, float x2, float y2) noexcept
{
	DrawLines(vector2<float>(x1, y1), vector2<float>(x2, y2));
}
