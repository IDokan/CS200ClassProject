/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Sketch.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Header file for Sketch file that do all thing related with drawing stuff
******************************************************************************/
#pragma once
#include <stack>
#include "Graphics/OpenGL/Mesh.hpp"
#include "Graphics/OpenGL/Material.hpp"
#include "Graphics/OpenGL/Vertices.hpp"
#include "Graphics/OpenGL/CameraManager.hpp"
#include "Graphics/OpenGL/Texture.hpp"
#include "Graphics/OpenGL/BitmapFont.hpp"
#include "Graphics/OpenGL/Text.hpp"

namespace std {
	namespace filesystem {
		class path;
	}
}

class Sketch
{
public:
	// Maximum size of each particle
	const size_t particleSize = 500;
	const size_t smokeParticleSize = 500;
	const size_t explosionParticleSize = 500;

	// Maximum size of translation to use instancing
	const static size_t MAX_SIZE_INSTANCING = 10000;
private:

	// Declare particle struct
	struct Particle
	{
		vector2<float> position, velocity;
		Graphics::Color4f color;
		float life;

		Particle()
			: position(0.f), velocity(0.f), color(1.f), life(0.f) {}
	};

	struct Object
	{
		vector2<float> position;
		vector2<float> velocity;

		Object()
			: position(0.f), velocity(0.f) {}
	};
	
public:
	Sketch();
	void Init() noexcept;
	void Update(float dt) noexcept;
	void Clear() noexcept;

	void InitCamera();
	
	// These two functions should be called
	// before and after draw function in each frame
	void StartDrawing() noexcept;
	void FinishDrawing() const noexcept;

	// Setter functions
	void SetBackgroundColor(Graphics::Color4f color);
	void SetImage(const std::filesystem::path& filepath) noexcept;
	
	// Draw Shapes Functions
	void DrawEllipses(vector2<float> position, vector2<float> size) noexcept;
	void DrawEllipses(float x, float y, vector2<float> size) noexcept;
	void DrawEllipses(vector2<float> position, float width, float height) noexcept;
	void DrawEllipses(float x, float y, float width, float height) noexcept;
	void DrawRectangles(vector2<float> position, vector2<float> size) noexcept;
	void DrawRectangles(float x, float y, vector2<float> size) noexcept;
	void DrawRectangles(vector2<float> position, float width, float height) noexcept;
	void DrawRectangles(float x, float y, float width, float height) noexcept;
	void DrawQuads(vector2<float> position1, vector2<float> position2, vector2<float> position3,
		vector2<float> position4, Graphics::Color4f color = Graphics::Color4f{ 1.f }, float depth = 0.f) noexcept;
	void DrawQuads(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, Graphics::Color4f color = Graphics::Color4f{ 1.f }, float depth = 0.f) noexcept;
	void DrawTriangles(vector2<float> position1, vector2<float> position2, vector2<float> position3) noexcept;
	void DrawTriangles(float x1, float y1, float x2, float y2, float x3, float y3) noexcept;
	void DrawLines(vector2<float> position1, vector2<float> position2) noexcept;
	void DrawLines(float x1, float y1, float x2, float y2) noexcept;

	// Draw Texture function
	void DrawTexture(vector2<float> position, vector2<float> size, Graphics::Color4f color = Graphics::Color4f{1.f}) noexcept;

	void PushMatrix(const matrix3<float>& matrix) noexcept;
	void PopMatrix() noexcept;

	void DrawText(vector2<float> position, vector2<float> scale, std::wstring text, float depth = 0.f);

	// Particle Tutorial
	void DrawParticle(float dt) noexcept;
	void DrawPoisonPotParticle(float dt, vector2<float> position) noexcept;
	void DrawExplosionParticle(float dt, vector2<float> position) noexcept;

	// Instancing Tutorial
	void Instancing(int instanceCount) noexcept;
	void NoInstancing(size_t instanceCount);
private:
	[[nodiscard]] matrix3<float> CalculateHierarchical() noexcept;
	
	void Draw(Graphics::Shader* shader, const Graphics::Vertices& vertices, const matrix3<float>& modelToWorld, Graphics::Color4f color = Graphics::Color4f{1.f}, float depth = 0.f) noexcept;
	void Draw(Graphics::Shader* shader, const Graphics::Vertices& vertices, Graphics::Color4f color = Graphics::Color4f{ 1.f }, float depth = 0.f) noexcept;


	// Particle Helper functions
	void ParticleInit();
	int FirstUnusedParticle(const std::vector<Particle>& particles);
	void RespwanParticle(Particle& particle, Object& object, vector2<float> offset, Graphics::Color4f color);
	// Instancing Helper functions
	void InstancingInit();
	
private:
	std::stack<matrix3<float>> hierarchical{};
	
	Graphics::CameraManager cameraManager;
	Graphics::material material;

	Graphics::Mesh mesh;
	
	Graphics::Vertices ellipse;
	Graphics::Vertices rectangle;
	Graphics::Vertices quad;
	Graphics::Vertices triangle;
	Graphics::Vertices line;

	Graphics::Texture texture;
	Graphics::Vertices sprite;
	Graphics::material textureMaterial;

	Graphics::BitmapFont font;
	Graphics::Text text;
	Graphics::material textMaterial;


	// Particle member variables
	std::vector<Particle> exampleParticles;

	std::vector<Particle> smokeParticle;

	std::vector<Particle> explosionParticle;

	// Instancing translations
	vector2<float> translations[MAX_SIZE_INSTANCING];
	vector3<float> colors[MAX_SIZE_INSTANCING];
	vector2<float> scales[MAX_SIZE_INSTANCING];
};

