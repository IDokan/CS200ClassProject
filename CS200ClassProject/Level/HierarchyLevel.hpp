/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   HierarchyLevel.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Header file the level that show whether hierarchy is work or not.
******************************************************************************/
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