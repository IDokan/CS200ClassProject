#pragma once
#include <Level/State.hpp>

class BasicLevel : public State
{
public:
	BasicLevel(Demo& demo);

	virtual void Init();
	virtual void Update(float dt);
	virtual void Clear() ;
private:
};

