#include <iostream>
#include <Level/Demo.hpp>
#include "BasicLevel.hpp"
#include "HierarchyLevel.hpp"
#include "ParticleLevel.hpp"

void Demo::Init()
{
	sketch.Init();
	states.push_back(new BasicLevel(*this));
	states.push_back(new HierarchyLevel(*this));
	states.push_back(new ParticleLevel(*this));
	
	states.at(currentStateIndex)->Init();
	
	std::cout << "Demo Controls:\n"
		<< "\tRight Arrow Key - Go to the next state\n"
		<< "\tLeft Arrow Key - Go to the previous test\n";
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
