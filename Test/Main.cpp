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
