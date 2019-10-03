#pragma once

#include "Graphics/OpenGL/Material.hpp"
#include "Graphics/OpenGL/Vertices.hpp"
#include "Graphics/OpenGL/CameraManager.hpp"

class Sketch
{
public:
	void Init() noexcept;
	void Update(float dt) noexcept;
	void Clear() noexcept;

	void StartDrawing() const noexcept;
	void FinishDrawing() const noexcept;

	void DrawEllipses(vector2<float> position, vector2<float> size) noexcept;
	void DrawEllipses(float x, float y, vector2<float> size) noexcept;
	void DrawEllipses(vector2<float> position, float width, float height) noexcept;
	void DrawEllipses(float x, float y, float width, float height) noexcept;
	void DrawRectangles(vector2<float> position, vector2<float> size) noexcept;
	void DrawRectangles(float x, float y, vector2<float> size) noexcept;
	void DrawRectangles(vector2<float> position, float width, float height) noexcept;
	void DrawRectangles(float x, float y, float width, float height) noexcept;
	void DrawQuads() noexcept;
	void DrawTriangles() noexcept;
	void DrawLines() noexcept;
private:
	Graphics::CameraManager cameraManager;
	Graphics::material material;

	Graphics::Vertices ellipse;
	Graphics::Vertices rectangle;
	Graphics::Vertices quad;
	Graphics::Vertices triangle;
	Graphics::Vertices line;
};

