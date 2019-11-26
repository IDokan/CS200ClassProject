#pragma once

#include "Level/Demo.hpp"
class Demo;
class Sketch;
class State
{
public:
	explicit State(Demo& demo) noexcept
		:sketch(demo.sketch), isShowHelp(false)
	{
	}
	virtual ~State() = default;
	
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clear() = 0;

	void SetIsShowHelp(bool isShow) { isShowHelp = isShow; }
	bool IsShowHelp() { return isShowHelp; }

	void HelpBox(std::wstring wStr);
	
protected:
	Sketch& sketch;
	bool isShowHelp;
};

inline void State::HelpBox(std::wstring wStr)
{
	// Draw help
	if (isShowHelp)
	{
		sketch.DrawQuads(vector2{ -2000.f, -2000.f }, vector2{ -2000.f, 2000.f }, vector2{ 2000.f, 2000.f }, vector2{ 2000.f, -2000.f }, Graphics::Color4f{ 0.f, 0.5f }, -0.8f);
		sketch.DrawText(vector2{ -700.f, 300.f }, vector2{ 1.f }, wStr, -0.9f);
		sketch.DrawQuads(vector2{ -800.f, 500.f }, vector2{ -535.f, 500.f }, vector2{ -535.f, 400.f }, vector2{ -800.f, 400.f }, Graphics::Color4f{ 1.f, 0.f, 0.f, 1.f }, -0.85f);
		sketch.DrawText(vector2{ -800.f, 400.f }, vector2{ 1.f }, L"'H' for Close", -0.95f);
	}
	else
	{
		sketch.DrawQuads(vector2{ -800.f, 500.f }, vector2{ -550.f, 500.f }, vector2{ -550.f, 400.f }, vector2{ -800.f, 400.f }, Graphics::Color4f{ 0.f }, -0.1f);
		sketch.DrawText(vector2{ -800.f, 400.f }, vector2{ 1.f }, L"'H' for Help", -0.2f);
	}
}
