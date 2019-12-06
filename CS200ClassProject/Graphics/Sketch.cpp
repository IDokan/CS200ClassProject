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
	mesh.AddTextureCoordinate(vector2{ 0.f });
	mesh.AddTextureCoordinate(vector2{ 1.f, 0.f });
	mesh.AddTextureCoordinate(vector2{ 1.f, });
	sprite.InitializeWithMeshAndLayout(mesh, Graphics::SHADER::textured_vertex_layout());

	// Font & Text Init
	if (!font.LoadFromFile("../assets/fonts/Malgungothic/malgungothic.fnt"))
	{
		std::cerr << "Falied to load file!" << std::endl;
		// return false;
	}
	text.SetFont(font);
	textMaterial.shader = &Graphics::SHADER::textured();
	textMaterial.color4fUniforms[Graphics::SHADER::Uniform_Color] = Graphics::Color4f{ 1.f };
	textMaterial.floatUniforms[Graphics::SHADER::Uniform_Depth] = 0.f;

	ParticleInit();

	InstancingInit();
}

void Sketch::Update(float /*dt*/) noexcept
{
	cameraManager.CameraMove(1.1f);
}

void Sketch::Clear() noexcept
{
}

void Sketch::InitCamera()
{
	cameraManager.Init();
}

void Sketch::StartDrawing() const noexcept
{
	Graphics::GL::begin_drawing();
}

void Sketch::FinishDrawing() const noexcept
{
	Graphics::GL::end_drawing();
}

void Sketch::SetBackgroundColor(Graphics::Color4f color)
{
	Graphics::GL::set_clear_color(color);
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
	vector2<float> position4, Graphics::Color4f color, float depth) noexcept
{
	Graphics::Mesh mesh_;
	mesh_.AddPoint(position1);
	mesh_.AddPoint(position2);
	mesh_.AddPoint(position3);
	mesh_.AddPoint(position4);
	mesh_.SetPointListType(Graphics::PointListPattern::TriangleFan);

	quad.InitializeWithMeshAndLayout(mesh_, Graphics::SHADER::solid_color_vertex_layout());

	Draw(&Graphics::SHADER::solid_color(), quad, color, depth);
}

void Sketch::DrawQuads(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, Graphics::Color4f color, float depth) noexcept
{
	DrawQuads(vector2<float>(x1, y1), vector2<float>(x2, y2), vector2<float>(x3, y3), vector2<float>(x4, y4), color, depth);
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

void Sketch::DrawTexture(vector2<float> position, vector2<float> size, Graphics::Color4f color) noexcept
{
	const matrix3<float> modelToWorld = MATRIX3::build_translation(position) * MATRIX3::build_scale(size);

	textureMaterial.shader = &Graphics::SHADER::textured();
	textureMaterial.floatUniforms[Graphics::SHADER::Uniform_Depth] = 0.f;
	textureMaterial.color4fUniforms[Graphics::SHADER::Uniform_Color] = color;
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

void Sketch::DrawText(vector2<float> position, vector2<float> scale, std::wstring textWritten, float depth)
{
	text.SetString(textWritten);

	for (const auto& verticesTexturePair : text.GetVerticesWithMatchingTextures())
	{
		const Graphics::Vertices& textVertices = *verticesTexturePair.first;
		const Graphics::Texture* textTexture = verticesTexturePair.second;
		textMaterial.floatUniforms[Graphics::SHADER::Uniform_Depth] = depth;
		textMaterial.textureUniforms.insert_or_assign(Graphics::SHADER::Uniform_Texture, Graphics::texture_uniform{ textTexture });
		textMaterial.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = cameraManager.GetWorldToNDCTransform() * CalculateHierarchical() * MATRIX3::build_scale(scale) * MATRIX3::build_translation(position);
		Graphics::GL::draw(textVertices, textMaterial);
	}
}

void Sketch::DrawParticle(float dt) noexcept
{
	// Then in each frame, we spawn several new particles with starting values
	// Then for each particle that is still alive we update their values.
	Object object{ };
	// Sketch::Update();
	const unsigned numOfNewParticlePerFrame = 1;

	// Add new partices
	for (unsigned int i = 0; i < numOfNewParticlePerFrame; ++i)
	{
		const int unusedParticle = FirstUnusedParticle(exampleParticles);
		if (unusedParticle == -1)
		{
			break;
		}
		const float xRandom = static_cast<float>((rand() % 500) - 250);
		const float  yRandom = -static_cast<float>(rand() % 5000);
		object.velocity = vector2<float>{ xRandom, yRandom };
		vector2<float> offset{ -500.f,350.f };
		
		RespwanParticle(exampleParticles[unusedParticle], object, offset,
			Graphics::Color4f{
				((rand() % 100) / 100.f),
				((rand() % 100) / 100.f),
				((rand() % 100) / 100.f)
			});
	}
	// Update all particles
	for (unsigned int i = 0; i < particleSize; ++i)
	{
		Particle& p = exampleParticles[i];
		p.life -= dt; // reduce life
		if (p.life > 0.f)
		{	// particle is alive, thus update
			p.position += p.velocity * dt;
			p.color.alpha -= dt * 0.5f;
			if (p.color.alpha <= 0.f)
			{
				p.color.alpha = 0.f;
			}
		}
	}
	std::sort(exampleParticles.begin(), exampleParticles.end(), [](const Particle& a, const Particle& b) {return a.color.alpha > b.color.alpha; });
	for (unsigned int i = 0; i < particleSize; ++i)
	{
		Particle& particle = exampleParticles.at(i);
		if (particle.life > 0.1f)
		{
			textureMaterial.shader = &Graphics::SHADER::particle();
			textureMaterial.floatUniforms[Graphics::SHADER::Uniform_Depth] = -0.5f;
			textureMaterial.color4fUniforms[Graphics::SHADER::Uniform_Color] = particle.color;
			textureMaterial.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = cameraManager.GetWorldToNDCTransform() * CalculateHierarchical() * MATRIX3::build_translation(particle.position) * MATRIX3::build_scale(vector2{ 0.5f });
			Graphics::GL::draw(sprite, textureMaterial);
		}
	}
}

void Sketch::DrawWeightSmokeParticle(float dt, vector2<float> position) noexcept
{
	Object obj;
	const unsigned numOfNewParticlePerFrame = 1;

	// Revive dead particle into new Alive particle
	for (unsigned int i = 0; i < numOfNewParticlePerFrame; ++i)
	{
		const int unusedParticle = FirstUnusedParticle(smokeParticle);
		if (unusedParticle == -1)
		{
			break;
		}
		const float xRandomPosition = position.x + static_cast<float>((rand() % 300) - 150);
		const float yPosition = position.y;
		const float xRandomVelocity = static_cast<float>(rand() % 1000) - 500;
		const float yRandomVelocity = static_cast<float>(rand() % 500);
		obj.position = vector2{ xRandomPosition, yPosition };
		obj.velocity = vector2{ xRandomVelocity, yRandomVelocity };
		RespwanParticle(smokeParticle[unusedParticle], obj, vector2{ 0.f }, Graphics::Color4f{ 0.545f, 0.f, 0.545f });
	}

	// Update all particles
	for (size_t i = 0; i < particleSize; ++i)
	{
		Particle& p = smokeParticle.at(i);
		p.life -= dt;
		if (p.life > 0.f)
		{	// particle is alive, thus update
			p.position += p.velocity * dt;
			p.velocity.y -= 1.f;
			if (p.position.y <= position.y - 150.f)
			{
				p.velocity.y = (-p.velocity.y) / 2.f;
			}
			p.color.alpha -= dt * 0.25f;
			if (p.color.alpha <= 0.f)
			{
				p.color.alpha = 0.f;
			}
		}
	}
	// Why do we need? For now, commented out
	std::sort(begin(smokeParticle), end(smokeParticle), [](const Particle& particle1, const Particle& particle2)
		{
			return particle1.color.alpha > particle2.color.alpha;
		});

	smokeParticleMaterial.shader = &Graphics::SHADER::particle();
	smokeParticleMaterial.floatUniforms[Graphics::SHADER::Uniform_Depth] = -0.5f;
	for (size_t i = 0; i < smokeParticleSize; ++i)
	{
		Particle& particle = smokeParticle.at(i);
		if (particle.life > 0.1f)
		{
			smokeParticleMaterial.color4fUniforms[Graphics::SHADER::Uniform_Color] = particle.color;
			smokeParticleMaterial.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = cameraManager.GetWorldToNDCTransform() * CalculateHierarchical() * MATRIX3::build_translation(particle.position) * MATRIX3::build_scale(vector2{ 1.25f });
			Graphics::GL::draw(sprite, smokeParticleMaterial);
		}
	}
}

void Sketch::DrawExplosionParticle(float dt, vector2<float> position) noexcept
{
	Object obj;
	const unsigned numOfNewParticlePerFrame = 500;

	// Revive dead particle into new Alive particle
	for (unsigned int i = 0; i < numOfNewParticlePerFrame; ++i)
	{
		const int unusedParticle = FirstUnusedParticle(explosionParticle);
		if (unusedParticle == -1)
		{
			break;
		}
		const float xRandomPosition = position.x;
		const float yPosition = position.y;
		const float radius = static_cast<float>(rand() % 1000);
		const float radian = static_cast<float>(rand() % 314000) * 0.0001;
		
		const float xRandomVelocity = radius * cos(radian);
		float yRandomVelocity = radius * sin(radian);

		if (i % 2)
		{
			yRandomVelocity = -yRandomVelocity;
		}

		obj.position = vector2{ xRandomPosition, yPosition };
		obj.velocity = vector2{ xRandomVelocity, yRandomVelocity };
		RespwanParticle(explosionParticle[unusedParticle], obj, vector2{ 0.f }, Graphics::Color4f{ 1.f, 1.f, 0.f });
	}

	// Update all particles
	for (size_t i = 0; i < particleSize; ++i)
	{
		Particle& p = explosionParticle.at(i);
		p.life -= dt;
		if (p.life > 0.f)
		{	// particle is alive, thus update
			p.position += p.velocity * dt;
			p.velocity.x -= p.velocity.x * 0.01f;
			p.velocity.y -= p.velocity.y * 0.01f;
			if (abs(p.velocity.x) <= 0.01f)
			{
				p.velocity.x = 0.f;
			}
			if (abs(p.velocity.y) <= 0.01f)
			{
				p.velocity.y = 0.f;
			}

			const float t = magnitude(p.position - position);
			p.color.green = (1 - (t / 200));
			
			p.color.alpha -= dt * 0.25f;
			if (p.color.alpha <= 0.f)
			{
				p.color.alpha = 0.f;
			}
		}
	}
	// Why do we need? For now, commented out
	std::sort(begin(explosionParticle), end(explosionParticle), [](const Particle& particle1, const Particle& particle2)
		{
			return particle1.color.alpha > particle2.color.alpha;
		});

	smokeParticleMaterial.shader = &Graphics::SHADER::particle();
	smokeParticleMaterial.floatUniforms[Graphics::SHADER::Uniform_Depth] = -0.5f;
	for (size_t i = 0; i < smokeParticleSize; ++i)
	{
		Particle& particle = explosionParticle.at(i);
		if (particle.life > 0.1f)
		{
			smokeParticleMaterial.color4fUniforms[Graphics::SHADER::Uniform_Color] = particle.color;
			smokeParticleMaterial.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = cameraManager.GetWorldToNDCTransform() * CalculateHierarchical() * MATRIX3::build_translation(particle.position) * MATRIX3::build_scale(vector2{ 0.5f });
			Graphics::GL::draw(sprite, smokeParticleMaterial);
		}
	}
}

void Sketch::Instancing(int instanceCount) noexcept
{
	textureMaterial.shader = &Graphics::SHADER::texturedInstanced();
	textureMaterial.floatUniforms[Graphics::SHADER::Uniform_Depth] = 0.f;
	textureMaterial.color4fUniforms[Graphics::SHADER::Uniform_Color] = Graphics::Color4f{ 1.f };
	textureMaterial.arrayVector2Uniforms[Graphics::SHADER::Uniform_Offsets] = translations;
	textureMaterial.arrayVector3Uniforms[Graphics::SHADER::Uniform_Color_Array] = colors;
	textureMaterial.arrayVector2Uniforms[Graphics::SHADER::Uniform_Scales] = scales;
	textureMaterial.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = cameraManager.GetWorldToNDCTransform() * CalculateHierarchical();
	Graphics::GL::drawInstanced(sprite, textureMaterial, instanceCount);
}

void Sketch::NoInstancing(int instanceCount) noexcept
{
	for (size_t i = 0; i < instanceCount; ++i)
	{
		DrawTexture(translations[i], scales[i], Graphics::Color4f{ colors[i].x, colors[i].y, colors[i].z });
	}
}

int Sketch::FirstUnusedParticle(const std::vector<Particle>& particles)
{
	static unsigned int lastusedParticle = 0;

	// Seartch from last used particle, this will usually return almost instantly
	for (unsigned int i = lastusedParticle; i < particles.size(); ++i)
	{
		if (particles[i].life <= 0.f)
		{
			lastusedParticle = i;
			return i;
		}
	}
	// Otherwise, do a linear search
	for (unsigned int i = 0; i < lastusedParticle; ++i)
	{
		if (particles[i].life <= 0.f)
		{
			lastusedParticle = i;
			return i;
		}
	}

	// Otherwise, return -1
	return -1;
}

void Sketch::RespwanParticle(Particle& particle, Object& object, vector2<float> offset, Graphics::Color4f color)
{

	particle.position.x = object.position.x + offset.x;
	particle.position.y = object.position.y + offset.y;

	particle.color = color;
	particle.life = 5.f;
	particle.velocity = object.velocity * 0.1f;
}

void Sketch::InstancingInit()
{
	Graphics::Color4f color{ 0.f };
	int index = 0;
	for (int y = -450; y < 90000; y+=120)
	{
		for (int x = -750; x < 850; x += 150)
		{
			if (index >= maxSizeInstancing)
			{
				return;
			}
			translations[index] = vector2<float>(static_cast<float>(x), static_cast<float>(y));
			colors[index] = vector3<float>{ static_cast<float>(rand() % 255)/255.f, static_cast<float>(rand() % 255)/255.f, static_cast<float>(rand() % 255)/255.f };
			scales[index] = vector2<float>{ static_cast<float>((rand() % 100)+50) };
			++index;
		}
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
	const matrix3<float>& modelToWorld, Graphics::Color4f color, float depth) noexcept
{
	material.shader = shader;
	material.floatUniforms[Graphics::SHADER::Uniform_Depth] = depth;
	material.color4fUniforms[Graphics::SHADER::Uniform_Color] = color;
	material.matrix3Uniforms[Graphics::SHADER::Uniform_ToNDC] = cameraManager.GetWorldToNDCTransform() * CalculateHierarchical() * modelToWorld;
	Graphics::GL::draw(vertices, material);
	material.floatUniforms[Graphics::SHADER::Uniform_Depth] = 0;
}

void Sketch::Draw(Graphics::Shader* shader, const Graphics::Vertices& vertices, Graphics::Color4f color, float depth) noexcept
{
	Draw(shader, vertices, MATRIX3::build_identity<float>(), color, depth);
}

void Sketch::ParticleInit()
{
	// Sketch::Init()
	for (unsigned int i = 0; i < particleSize; ++i)
	{
		exampleParticles.emplace_back();
	}
	for (unsigned int i = 0; i < smokeParticleSize; ++i)
	{
		smokeParticle.emplace_back();
	}
	for (size_t i = 0; i < explosionParticleSize; ++i)
	{
		explosionParticle.emplace_back();
	}
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

void Sketch::SetSmokeParticleAsset(const std::filesystem::path& filepath) noexcept
{
	if (texture.LoadFromPNG(filepath))
	{
		const Graphics::texture_uniform container{ &texture, 1 };
		smokeParticleMaterial.textureUniforms[Graphics::SHADER::Uniform_Texture] = container;
		smokeParticleMaterial.vector2Uniforms[Graphics::SHADER::Uniform_ImageSize] = vector2{ float(texture.GetWidth()), float(texture.GetHeight()) };
	}
	else
	{
		std::cout << "fail to load image for particle 1\n";
	}
}
