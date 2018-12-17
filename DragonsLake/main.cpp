#include <cstdlib>
#include <ctime>
#include "Framework.h"
#include "Engine.h"
#include "vector2.h"

int main(int argc, char* argv[])
{
	int result;
	Engine* game;

	srand(static_cast<unsigned int>(time(nullptr)));

	result = run(new Engine());
	return result;
}