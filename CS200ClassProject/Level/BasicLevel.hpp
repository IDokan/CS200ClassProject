#pragma once
#include <Graphics/Sketch.hpp>
#include <Level/State.hpp>

class BasicLevel : public State
{
public:
	BasicLevel(Demo& demo):State(demo) {};
	void Update(float dt);

private:
};

