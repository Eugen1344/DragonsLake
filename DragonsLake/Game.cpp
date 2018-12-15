#include "Game.h"
#include "Camera.h"

Engine* Game::engine;
vector2<int> Game::screenResolution;
Player* Game::player;
vec2 Game::mousePos;

void Game::AddObject(Object* obj)
{
	engine->AddObject(obj);
}

void Game::DeleteObject(Object* obj)
{
	engine->DeleteObject(obj);
}

double Game::DeltaTime()
{
	return engine->deltaTime;
}

Player& Game::GetPlayer()
{
	return *player;
}

vec2 Game::MousePos()
{
	return mousePos;
}

vec2 Game::MouseWorldPos()
{
	return mousePos + Camera::pos;
}

vector2<int> Game::Resolution()
{
	return screenResolution;
}
