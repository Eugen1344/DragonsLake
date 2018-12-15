#pragma once
#include "Engine.h"
#include "Player.h"

class Game
{
	friend class Engine;
private:
	static Engine* engine;
	static Player* player;
	static vec2 mousePos;
	static vector2<int> screenResolution;
public:
	static void AddObject(Object* obj);
	static void DeleteObject(Object* obj);
	static double DeltaTime();
	static Player& GetPlayer();
	static vec2 MousePos();
	static vec2 MouseWorldPos();
	static vector2<int> Resolution();
};