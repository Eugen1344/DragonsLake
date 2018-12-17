#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include "Framework.h"
#include "Engine.h"
#include "vector2.h"
#include "Game.h"

using namespace std;

int tryRead(string str, int def);
void getTwo(string str, int& first, int& second);

int main(int argc, char* argv[])
{
	srand(static_cast<unsigned int>(time(nullptr)));

	map<string, string> args;
	for (int i = 0; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			if (i != argc - 1)
			{
				args[string(&argv[i][1])] = argv[i + 1];
				i++;
			}
		}
	}

	Settings settings;

	vector2<int> res(800, 600);
	if (args.count("window"))
		getTwo(args["window"], res.x, res.y);
	settings.screenResolution = res;

	vector2<int> map(1000, 1000);
	if (args.count("map"))
		getTwo(args["map"], map.x, map.y);
	settings.mapSize = map;

	settings.enemiesCount = args.count("num_enemies") ? tryRead(args["num_enemies"], 10) : 10;
	settings.ammoCount = args.count("num_ammo") ? tryRead(args["num_ammo"], 3) : 3;

	return run(new Engine(settings));
}

void getTwo(string str, int& first, int& second)
{
	auto x = str.find('x');
	if (x != -1)
	{
		first = tryRead(str.substr(0, x), first);
		second = tryRead(str.substr(x + 1), second);
	}
}

int tryRead(string str, int def)
{
	try
	{
		return std::stoi(str);
	}
	catch (exception&)
	{
		return def;
	}
}