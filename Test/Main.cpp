#include <Window/Engine.hpp>

int main(int argc, char* argv[])
{
	Engine engine;

	engine.Init();

	while (engine.IsRunning())
	{
		engine.Update();
	}
	engine.Clear();
}
