/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   Layer.cpp
Author
	- Sinil.Kang rtd99062@gmail.com
Creation Date: 10.02.2019

	Source file for Layer to Implement Parallax scrolling
******************************************************************************/
#include "Layer.hpp"

void Layer::Init()
{
	layer.second.clear();
	delete_obj.clear();
}

void Layer::Update(float dt)
{
	delete_obj.clear();

	for (const auto& obj : layer.second) {
		for (const auto& comp : obj->GetComponentContainer())
		{
			comp->Update(dt);
		}
		if (obj->GetDead()) {
			delete_obj.push_back(obj);
		}
	}

	for (const auto& obj : delete_obj) {
		DeleteObject(obj);
	}
}

void Layer::Clear()
{
	layer.second.clear();
	delete_obj.clear();
}

void Layer::AddObject(Object* obj)
{
	layer.second.push_back(std::shared_ptr<Object>(obj));
}

void Layer::DeleteObject(std::shared_ptr<Object> obj)
{
	const auto tmp = std::find(layer.second.begin(), layer.second.end(), obj);
	if (tmp == layer.second.end())
	{
		return;
	}
	layer.second.erase(tmp);
}

void Layer::SetName(LayerNames name)
{
	layer.first = name;
}

LayerNames Layer::GetName() const
{
	return layer.first;
}

std::vector<std::shared_ptr<Object>>& Layer::GetObjContainer()
{
	return layer.second;
}
