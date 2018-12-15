#pragma once
#include "Engine.h"
#include "Player.h"

class Game
{
	friend class Engine;
private:
	static Engine* engine;
public:
	static Player* player;
	static vector2<int> screenResolution;
	static void AddObject(Object* obj);
	static double DeltaTime();
};
