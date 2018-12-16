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
	static int enemiesCount;
	static int ammoCount;
	static vector2<int> mapSize;
	static void AddObject(Object* obj);
	static void DeleteObject(Object* obj);
	static double DeltaTime();
	static Player& GetPlayer();
	static vec2 MousePos();
	static vec2 MouseWorldPos();
	static vector2<int> Resolution();
	static void RestartGame();
	static void SpawnEnemies(int count, Sprite* sprite);
};