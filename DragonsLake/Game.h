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
	static Settings settings;
public:
	static Settings GetSettings();
	void SetSettings(Settings& settings);
	static void AddObject(Object* obj);
	static void DeleteObject(Object* obj);
	static double DeltaTime();
	static Player& GetPlayer();
	static vec2 MousePos();
	static vec2 MouseWorldPos();
	static bool IsColliding(Object* obj);
	static vector2<int> Resolution();
	static void RestartGame();
	static void InitScene();
	static void SpawnEnemies(int count, Sprite* sprite);
};