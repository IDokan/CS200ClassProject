#pragma once
#include <Level/State.hpp>

class HierarchyLevel : public State
{
public:
	HierarchyLevel(Demo& demo);

	virtual void Init() override;
	virtual void Update(float dt) override;
	virtual void Clear() override;

private:
	void Draw();
	
	vector2<float> playerPosition;
};