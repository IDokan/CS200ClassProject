/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   StartLevel.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Header file for start level that teach client to use help box
******************************************************************************/
#pragma once
#include <Level/State.hpp>

class StartLevel : public State
{
public:
	StartLevel(Demo& demo);

	void Init() override;
	void Update(float dt) override;
	void Clear() override;
};