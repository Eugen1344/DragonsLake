#include "Engine.h"
#include "Enemy.h"
#include "Game.h"

Engine::Engine()
{
	deltaTime = 0;
	prevTickCount = 0;
	Game::engine = this;
}

void Engine::AddObject(Object* obj)
{
	objects.push_back(obj);
}

void Engine::PreInit(int& width, int& height, bool& fullscreen)
{
	width = 800;
	height = 600;
	Game::screenResolution = vector2<int>(width, height);
	Player* player = new Player(static_cast<vector2<double>>(Game::screenResolution / 2), createSprite("player.png"));
	fullscreen = false;
}

bool Engine::Init()
{
	Sprite* sprite = createSprite("enemy.png");
	Enemy* enemy = new Enemy(vec2(100, 100), sprite);
	AddObject(enemy);
	return true;
}

void Engine::Close()
{
}

bool Engine::Tick()
{
	drawTestBackground();
	for (Object* obj : objects)
	{
		obj->Tick();
		drawSprite(obj->sprite, obj->pos.x, obj->pos.y);
	}
	deltaTime = (getTickCount() - prevTickCount) / 1000.0;
	prevTickCount = getTickCount();
	return false;
}

void Engine::onMouseMove(int x, int y, int xrelative, int yrelative)
{
}

void Engine::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
}

void Engine::onKeyPressed(FRKey k)
{
}

void Engine::onKeyReleased(FRKey k)
{
}