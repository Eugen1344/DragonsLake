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

	Sprite* playerSprite = createSprite("avatar.jpg");
	vector2<int> spriteSize;
	getSpriteSize(playerSprite, spriteSize.x, spriteSize.y);

	Player* player = new Player(static_cast<vector2<double>>((Game::screenResolution - spriteSize) / 2), playerSprite);
	AddObject(player);
	Game::player = player;

	Sprite* enemySprite = createSprite("enemy.png");
	Game::SpawnEnemies(Game::enemiesCount, enemySprite);
	return true;
}

void Engine::Close()
{
	for (Object* obj : objects)
	{
		delete obj;
	}
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
		drawSprite(obj->sprite, int(round(pos.x)), int(round(pos.y)));
	}

	DetectCollisions();

	deltaTime = (getTickCount() - prevTickCount) / 1000.0;
	prevTickCount = getTickCount();

	return restart;
}

void Engine::DetectCollisions()
{
	for (unsigned i = 0; i < objects.size(); i++)
	{
		Object& first = *objects[i];
		for (unsigned j = i + 1; j < objects.size(); j++)
		{
			Object& second = *objects[j];
			if (first.collider.IsColliding(second.collider, first.pos, second.pos))
			{
				first.onCollisionStay(second);
				second.onCollisionStay(first);
			}
		}
	}
}

bool Engine::IsColliding(Object* obj)
{
	for (Object* collisionObj : objects)
	{
		if (obj->collider.IsColliding(collisionObj->collider, obj->pos, collisionObj->pos))
			return true;
	}
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