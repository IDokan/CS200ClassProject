/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   BasicLevel.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Header file for basic level that shows text, simple shapes, input, and camera
******************************************************************************/
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

