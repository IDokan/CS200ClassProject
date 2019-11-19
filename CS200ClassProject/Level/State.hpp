#pragma once

#include "Level/Demo.hpp"
class Demo;
class Sketch;
class State
{
public:
	explicit State(Demo& demo) noexcept
		:sketch(demo.sketch)
	{
	}
	virtual ~State() = default;
	virtual void Update(float dt) = 0;

protected:
	Sketch& sketch;
};
