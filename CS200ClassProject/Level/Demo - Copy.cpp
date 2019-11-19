#pragma once
#include <vector>
#include "Graphics/Sketch.hpp"


class State;
class Demo
{
	friend class State;
public:
	Demo() :currentStateIndex(0) {};
	
	void Init();
	void Update(float dt);
	void Clear();

private:
	Sketch sketch;
private:
	size_t currentStateIndex;
	std::vector<State*> states;
};
