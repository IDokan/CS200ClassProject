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
	sketch.DrawWeightSmokeParticle(dt, vector2{ -200.f });
	sketch.DrawExplosionParticle(dt, vector2{ 200.f });

	HelpBox(L"This Level Shows particles\n\nBasic Particle:\n\tIt is a basic particle.\n\nDry Ice Particle:\n\t");
	
	sketch.FinishDrawing();
}

void ParticleLevel::Clear()
{
	isShowHelp = false;
}
