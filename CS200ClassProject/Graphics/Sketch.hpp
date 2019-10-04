#pragma once
#include <stack>
#include "Graphics/OpenGL/Material.hpp"
#include "Graphics/OpenGL/Vertices.hpp"
#include "Graphics/OpenGL/CameraManager.hpp"

class Sketch
{
public:
	void Init() noexcept;
	void Update(float dt) noexcept;
	void Clear() noexcept;

	// These two functions should be called
	// before and after draw function in each frame
	void StartDrawing() const noexcept;
	void FinishDrawing() const noexcept;

	// Draw Shapes Functions
	void DrawEllipses(vector2<float> position, vector2<float> size) noexcept;
	void DrawEllipses(float x, float y, vector2<float> size) noexcept;
	void DrawEllipses(vector2<float> position, float width, float height) noexcept;
	void DrawEllipses(float x, float y, float width, float height) noexcept;
	void DrawRectangles(vector2<float> position, vector2<float> size) noexcept;
	void DrawRectangles(float x, float y, vector2<float> size) noexcept;
	void DrawRectangles(vector2<float> position, float width, float height) noexcept;
	void DrawRectangles(float x, float y, float width, float height) noexcept;
	void DrawQuads(vector2<float> position1, vector2<float> position2, vector2<float> position3, vector2<float> position4) noexcept;
	void DrawQuads(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) noexcept;
	void DrawTriangles(vector2<float> position1, vector2<float> position2, vector2<float> position3) noexcept;
	void DrawTriangles(float x1, float y1, float x2, float y2, float x3, float y3) noexcept;
	void DrawLines(vector2<float> position1, vector2<float> position2) noexcept;
	void DrawLines(float x1, float y1, float x2, float y2) noexcept;

	void PushMatrix(const matrix3<float>& matrix) noexcept;
	void PopMatrix() noexcept;
private:
	[[nodiscard]] matrix3<float> CalculateHierarchical() noexcept;
	
	void Draw(Graphics::Shader* shader, const Graphics::Vertices& vertices, const matrix3<float>& modelToWorld) noexcept;
	void Draw(Graphics::Shader* shader, const Graphics::Vertices& vertices) noexcept;

private:
	std::stack<matrix3<float>> hierarchical{};
	
	Graphics::CameraManager cameraManager;
	Graphics::material material;
	
	Graphics::Vertices ellipse;
	Graphics::Vertices rectangle;
	Graphics::Vertices quad;
	Graphics::Vertices triangle;
	Graphics::Vertices line;
};

