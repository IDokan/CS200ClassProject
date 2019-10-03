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
