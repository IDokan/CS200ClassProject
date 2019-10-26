#include "Graphics/Sketch.hpp"
#include <Graphics/OpenGL/GL.hpp>
#include "Graphics/OpenGL/Mesh.hpp"
#include "Graphics/OpenGL/StockShaders.hpp"
#include "Graphics/OpenGL/Color4f.hpp"
#include <iostream>


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

	// Texture Init
	mesh.AddTextureCoordinate(vector2{ 0.f, 1.f });
	mesh.AddTextureCoordinate(vector2{ 1.f });
	mesh.AddTextureCoordinate(vector2{ 1.f, 0.f });
	mesh.AddTextureCoordinate(vector2{ 0.f });
	sprite.InitializeWithMeshAndLayout(mesh, Graphics::SHADER::textured_vertex_layout());

	// Font & Text Init
	if (!font.LoadFromFile("C:/Users/KMU_USER/Desktop/CS200ClassProject/CS200ClassProject/assets/fonts/Malgungothic/malgungothic.fnt"))
	{
		std::cerr << "Falied to load file!" << std::endl;
		// return false;
	}
	text.SetFont(font);
	textMaterial.shader = &Graphics::SHADER::textured();
	textMaterial.color4fUniforms[Graphics::SHADER::Uniform_Color] = Graphics::Color4f{ 1.f };
	textMaterial.floatUniforms[Graphics::SHADER::Uniform_Depth] = -0.9f;
}

void Sketch::Update(float /*dt*/) noexcept
{
	cameraManager.CameraMove(1.1f);
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
	const matrix3<float> modelToWorld = MATRIX3::build_translation(position) * MATRIX3::build_scale(size);
	Draw(&Graphics::SHADER::solid_color(), ellipse, modelToWorld);
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
	const matrix3<float> modelToWorld = MATRIX3::build_translation(position) * MATRIX3::build_scale(size);
	Draw(&Graphics::SHADER::solid_color(), rectangle, modelToWorld);
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

void Sketch::DrawQuads(vector2<float> position1, vector2<float> position2, vector2<float> position3,
	vector2<float> position4) noexcept
{
	Graphics::Mesh mesh;
	mesh.AddPoint(position1);
	mesh.AddPoint(position2);
	mesh.AddPoint(position3);
	mesh.AddPoint(position4);
	mesh.SetPointListType(Graphics::PointListPattern::TriangleFan);

	quad.InitializeWithMeshAndLayout(mesh, Graphics::SHADER::solid_color_vertex_layout());

	Draw(&Graphics::SHADER::solid_color(), quad);
}

void Sketch::DrawQuads(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) noexcept
{
	DrawQuads(vector2<float>(x1, y1), vector2<float>(x2, y2), vector2<float>(x3, y3), vector2<float>(x4, y4));
}

void Sketch::DrawTriangles(vector2<float> position1, vector2<float> position2, vector2<float> position3) noexcept
{
	Graphics::Mesh mesh;
	mesh.AddPoint(position1);
	mesh.AddPoint(position2);
	mesh.AddPoint(position3);
	mesh.SetPointListType(Graphics::PointListPattern::Triangles);

	triangle.InitializeWithMeshAndLayout(mesh, Graphics::SHADER::solid_color_vertex_layout());

	Draw(&Graphics::SHADER::solid_color(), triangle);
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

	line.InitializeWithMeshAndLayout(mesh, Graphics::SHADER::solid_color_vertex_layout());
	
	Draw(&Graphics::SHADER::solid_color(), line);
}

void Sketch::DrawLines(float x1, float y1, float x2, float y2) noexcept
{
	DrawLines(vector2<float>(x1, y1), vector2<float>(x2, y2));
}

void Sketch::DrawTexture(vector2<float> position, vector2<float> size, const std::filesystem::path& filepath) noexcept
{
	SetImage(filepath);
	const matrix3<float> modelToWorld = MATRIX3::build_translation(position) * MATRIX3::build_scale(size);

	Draw(&Graphics::SHADER::textured(), sprite);
	textureMaterial.shader = &Graphics::SHADER::textured();
	textureMaterial.color4fUniforms[Graphics::SHADER::Uniform_Color] = Graphics::Color4f{ 1.f };
	textureMaterial.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = cameraManager.GetWorldToNDCTransform() * CalculateHierarchical() * modelToWorld;
	Graphics::GL::draw(sprite, textureMaterial);
}

void Sketch::PushMatrix(const matrix3<float>& matrix) noexcept
{
	hierarchical.push(matrix);
}

void Sketch::PopMatrix() noexcept
{
	hierarchical.pop();
}

void Sketch::DrawText(vector2<float> position, vector2<float> scale, std::wstring textWritten)
{
	text.SetString(textWritten);

	for (const auto& verticesTexturePair : text.GetVerticesWithMatchingTextures())
	{
		const Graphics::Vertices& textVertices = *verticesTexturePair.first;
		const Graphics::Texture* textTexture = verticesTexturePair.second;
		textMaterial.textureUniforms.insert_or_assign(Graphics::SHADER::Uniform_Texture, Graphics::texture_uniform{ textTexture });
		Draw(&Graphics::SHADER::textured(), textVertices, MATRIX3::build_translation(position) * MATRIX3::build_scale(scale));
	}
}

matrix3<float> Sketch::CalculateHierarchical() noexcept
{
	matrix3 result = MATRIX3::build_identity < float >();

	std::stack<matrix3<float>> tmpStack = hierarchical;
	while (!hierarchical.empty())
	{
		result *= hierarchical.top();
		hierarchical.pop();
	}
	hierarchical = tmpStack;
	return result;
}

void Sketch::Draw(Graphics::Shader* shader, const Graphics::Vertices& vertices,
	const matrix3<float>& modelToWorld) noexcept
{
	material.shader = shader;
	material.color4fUniforms[Graphics::SHADER::Uniform_Color] = Graphics::Color4f{ 1.f };
	material.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = cameraManager.GetWorldToNDCTransform() * CalculateHierarchical() * modelToWorld ;
	Graphics::GL::draw(vertices, material);
}

void Sketch::Draw(Graphics::Shader* shader, const Graphics::Vertices& vertices) noexcept
{
	Draw(shader, vertices, MATRIX3::build_identity<float>());
}

void Sketch::SetImage(const std::filesystem::path& filepath) noexcept
{
	if (texture.LoadFromPNG(filepath))
	{
		const Graphics::texture_uniform container{ &texture, 0 };
		textureMaterial.textureUniforms[Graphics::SHADER::Uniform_Texture] = container;
		textureMaterial.vector2Uniforms[Graphics::SHADER::Uniform_ImageSize] = vector2{ float(texture.GetWidth()), float(texture.GetHeight()) };
	}
	else
	{
		std::cout << "fail to load image\n";
	}
}
