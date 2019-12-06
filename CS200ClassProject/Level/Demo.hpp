/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Demo.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 12.07.2019

	Header file Demo file
******************************************************************************/
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
