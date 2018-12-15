#include "Game.h"

Engine* Game::engine;
vector2<int> Game::screenResolution;
Player* Game::player;

void Game::AddObject(Object* obj)
{
	engine->AddObject(obj);
}

double Game::DeltaTime()
{
	return engine->deltaTime;
}