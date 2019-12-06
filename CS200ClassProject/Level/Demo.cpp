/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Demo.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Source file Demo file
******************************************************************************/
#include <iostream>
#include <Level/Demo.hpp>
#include "Level/StartLevel.hpp"
#include "Level/BasicLevel.hpp"
#include "Level/HierarchyLevel.hpp"
#include "Level/ParticleLevel.hpp"
#include "Level/OptimizationLevel.hpp"

void Demo::Init()
{
	states.push_back(new StartLevel(*this));
	states.push_back(new BasicLevel(*this));
	states.push_back(new HierarchyLevel(*this));
	states.push_back(new ParticleLevel(*this));
	states.push_back(new OptimizationLevel(*this));
	
	states.at(currentStateIndex)->Init();
	
	sketch.Init();
}

void Demo::Update(float dt)
{
	states.at(currentStateIndex)->Update(dt);

	if (newStateIndex != -1)
	{
		states.at(currentStateIndex)->Clear();
		currentStateIndex = newStateIndex;
		newStateIndex = -1;
		states.at(currentStateIndex)->Init();
	}
}

void Demo::Clear()
{
	sketch.Clear();
}

void Demo::SetStateIndex(size_t newIndex) noexcept
{
	if (newIndex >= states.size())
	{
		return;
	}
	
	newStateIndex = static_cast<int>(newIndex);
}

void Demo::SetIsShowHelp(bool isShow)
{
	 states.at(currentStateIndex)->SetIsShowHelp(isShow); 
}

bool Demo::IsShowHelp()
{
	return states.at(currentStateIndex)->IsShowHelp(); 
}
