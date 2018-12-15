#include <algorithm>
#include "Engine.h"
#include "Enemy.h"
#include "Game.h"
#include "Cursor.h"
#include "Camera.h"

Engine::Engine()
{
	deltaTime = 0;
	prevTickCount = 0;
	Game::engine = this;
}

void Engine::AddObject(Object* obj)
{
	objectChanges[obj] = true;
}

void Engine::DeleteObject(Object* obj)
{
	objectChanges[obj] = false;
}

void Engine::PreInit(int& width, int& height, bool& fullscreen)
{
	width = 800;
	height = 600;
	Game::screenResolution = vector2<int>(width, height);
	fullscreen = false;
}

bool Engine::Init()
{
	showCursor(false);
	AddObject(new Cursor(vec2(), createSprite("reticle.png")));

	Sprite* sprite = createSprite("enemy.png");
	Enemy* enemy = new Enemy(vec2(100, 100), sprite);
	Sprite* playerSprite = createSprite("avatar.jpg");
	vector2<int> spriteSize;
	getSpriteSize(playerSprite, spriteSize.x, spriteSize.y);
	Player* player = new Player(static_cast<vector2<double>>((Game::screenResolution - spriteSize) / 2), playerSprite);
	AddObject(player);
	Game::player = player;
	AddObject(enemy);
	return true;
}

void Engine::Close()
{
}

bool Engine::Tick()
{
	for (auto obj : objectChanges)
	{
		if (obj.second)
			objects.push_back(obj.first);
		else
		{
			objects.erase(find(objects.begin(), objects.end(), obj.first));
			delete obj.first;
		}
	}
	objectChanges.clear();

	for (Object* obj : objects)
	{
		obj->Tick();
		vector2<double> pos = obj->pos;
		if (!obj->isGui)
			pos -= Camera::pos;
		drawSprite(obj->sprite, round(pos.x), round(pos.y));
	}
	deltaTime = (getTickCount() - prevTickCount) / 1000.0;
	prevTickCount = getTickCount();
	return false;
}

void Engine::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	Game::mousePos = vec2(x, y);
}

void Engine::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	for (Object* obj : objects)
	{
		obj->onMouseButtonClick(button, isReleased);
	}
}

void Engine::onKeyPressed(FRKey k)
{
	for (Object* obj : objects)
	{
		obj->onKeyPressed(k);
	}
}

void Engine::onKeyReleased(FRKey k)
{
	for (Object* obj : objects)
	{
		obj->onKeyReleased(k);
	}
}