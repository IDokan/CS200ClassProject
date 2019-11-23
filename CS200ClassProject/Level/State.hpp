#pragma once

#include "Level/Demo.hpp"
class Demo;
class Sketch;
class State
{
public:
	explicit State(Demo& demo) noexcept
		:sketch(demo.sketch), isShowHelp(false)
	{
	}
	virtual ~State() = default;
	
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clear() = 0;

	void SetIsShowHelp(bool isShow) { isShowHelp = isShow; }
	bool IsShowHelp() { return isShowHelp; }
	
protected:
	Sketch& sketch;
	bool isShowHelp;
};
