#pragma once
#include <vector>
#include "Graphics/Sketch.hpp"


class State;
class Demo
{
	friend class State;
public:
	Demo() :currentStateIndex(0), newStateIndex(-1) {};
	
	void Init();
	void Update(float dt);
	void Clear();

	// Index Setter
	void SetStateIndex(size_t newIndex) noexcept;


	void SetIsShowHelp(bool isShow);
	bool IsShowHelp() ;

private:
	Sketch sketch;
private:
	size_t currentStateIndex;
	std::vector<State*> states;

	int newStateIndex;
};
