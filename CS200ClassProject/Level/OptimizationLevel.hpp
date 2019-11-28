#pragma once
#include <Level/State.hpp>

class OptimizationLevel : public State
{
public:
	OptimizationLevel(Demo& demo);

	void Init() override;
	void Update(float dt) override;
	void Clear() override;
};