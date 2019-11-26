#pragma once

#include <Level/State.hpp>

class ParticleLevel : public State
{
public:
	ParticleLevel(Demo& demo);
	
	void Init() override;
	void Update(float dt) override;
	void Clear() override;
	
};