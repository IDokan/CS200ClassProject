/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Layer.hpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 10.02.2019

	Header file for Layer to Implement Parallax scrolling
******************************************************************************/
#pragma once
#include <vector>
#include <string>
#include <memory>
#include <Object/Object.hpp>

enum LayerNames
{
	BackGround,
	Stage,
	HUD,
	NumOfLayers,
};

class Layer
{
public:
	void Init();
	void Update(float dt);
	void Clear();
	
	void AddObject(Object* obj);
	void DeleteObject(std::shared_ptr<Object> obj);

	void SetName(LayerNames name);
	[[nodiscard]] LayerNames GetName() const;

	std::vector<std::shared_ptr<Object>> & GetObjContainer();
private:
	std::pair<LayerNames, std::vector<std::shared_ptr<Object>>> layer;

	std::vector<std::shared_ptr<Object>>delete_obj{};
};

