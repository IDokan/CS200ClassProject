/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Main.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

 It is a main function that
	implement game loop to run the my CS200 Project
******************************************************************************/
#include <Window/Engine.hpp>

int main(void)
{
	Engine engine;

	engine.Init();

	while (engine.IsRunning())
	{
		engine.Update();
	}
	engine.Clear();
}
