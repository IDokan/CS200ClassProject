#include <Level/Demo.hpp>
#include "BasicLevel.hpp"
#include <iostream>
#include <Level/Demo.hpp>

void Demo::Init()
{
	sketch.Init();
	states.push_back(new BasicLevel(*this));

	std::cout << "Demo Controls:\n"
		<< "\tRight Arrow Key - Go to the next state\n"
		<< "\tLeft Arrow Key - Go to the previous test\n";
}

void Demo::Update(float dt)
{
	states.at(currentStateIndex)->Update(dt);
}

void Demo::Clear()
{
	sketch.Clear();
}
