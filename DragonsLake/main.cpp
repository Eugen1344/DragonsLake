#include <cstdlib>
#include <ctime>
#include "Framework.h"
#include "Engine.h"
#include "vector2.h"

int main(int argc, char* argv[])
{
	Engine* game;
	do
	{
		srand(static_cast<unsigned int>(time(nullptr)));

		game = new Engine();
		int result = run(game);
		if (result)
			return result;
	} while (!game->close);
	return 0;
}