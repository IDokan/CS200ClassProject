#pragma once

#include <Level/State.hpp>

class ParticleLevel : public State
{/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Particle.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Header file the level that show a bunch of lecture by others directly.

******************************************************************************/
	
public:
	ParticleLevel(Demo& demo);
	
	void Init() override;
	void Update(float dt) override;
	void Clear() override;

private:
	void DrawPot() noexcept;
	float time;
};