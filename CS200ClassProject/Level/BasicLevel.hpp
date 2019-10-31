#pragma once
#include <Graphics/Sketch.hpp>

class BasicLevel
{
public:
	BasicLevel() {};
	void Init();
	void Update(float dt);
	void Clear();

private:
	Sketch sketch;
};

