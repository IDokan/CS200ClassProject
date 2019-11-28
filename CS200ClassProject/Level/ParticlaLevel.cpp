#include <Level/ParticleLevel.hpp>

ParticleLevel::ParticleLevel(Demo& demo)
	:State(demo)
{
	
}

void ParticleLevel::Init()
{
	sketch.InitCamera();
	sketch.SetBackgroundColor(Graphics::Color4f{ 0.f, 0.f, 0.f });
	sketch.SetImage("C:/Users/KMU_USER/Desktop/CS200ClassProject/CS200ClassProject/assets/texture/circle.png");
	//sketch.SetSmokeParticleAsset("C:/Users/KMU_USER/Desktop/CS200ClassProject/CS200ClassProject/assets/texture/smoke3.png");
}

void ParticleLevel::Update(float dt)
{

	sketch.Update(dt);
	
	sketch.StartDrawing();
	
	sketch.DrawParticle(dt);
	sketch.DrawQuads(vector2{ -160.f, -250.f }, vector2{ 160.f, -250.f }, vector2{ 160.f, -260.f }, vector2{ -160.f, -260.f }, Graphics::Color4f{ 0.4708f, 0.2359f, 0.f }, -0.75f);
	sketch.DrawQuads(vector2{ -150.f, -250.f }, vector2{ 150.f, -250.f }, vector2{ 150.f, -450.f }, vector2{ -150.f, -450.f }, Graphics::Color4f{ 0.25f }, -0.75f);
	sketch.DrawWeightSmokeParticle(dt, vector2{ 0.f, -250.f });
	sketch.DrawExplosionParticle(dt, vector2{ 200.f });

	HelpBox(L"This Level Shows particles\n\nBasic Particle:\n\tThe left most one is a basic particle.\n\nDry Ice Particle:\n\tMiddle-bottom is a my first custom particle. \n\tI want to represent the effect of magic pond.\n\nExplosion Particle:\n\tRight-top is a explosion particle.\n\tI was inspired from fire works.");
	
	sketch.FinishDrawing();
}

void ParticleLevel::Clear()
{
	isShowHelp = false;
}
