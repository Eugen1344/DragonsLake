#include <algorithm>
#include "Engine.h"
#include "Enemy.h"
#include "Game.h"
#include "Cursor.h"
#include "Camera.h"
#include "Settings.h"

Engine::Engine(Settings& settings)
{
	Game::settings = settings;
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
	width = Game::GetSettings().screenResolution.x;
	height = Game::GetSettings().screenResolution.y;
	fullscreen = false;
}

bool Engine::Init()
{
	showCursor(false);
	Game::InitScene();
	return true;
}

void Engine::Restart()
{
	restart = true;
}

void Engine::ReinitGame()
{
	for (auto obj : objectChanges)
	{
		if (obj.second)
			delete obj.first;
	}
	objectChanges.clear();
	for (auto obj : objects)
	{
		delete obj;
	}
	objects.clear();
	Game::InitScene();
	Camera::pos = vec2();
	restart = false;
}

void Engine::Close()
{
}

bool Engine::Tick()
{
	if (restart)
		ReinitGame();

	for (auto obj : objectChanges)
	{
		if (obj.second)
			objects.push_back(obj.first);
		else
		{
			auto found = find(objects.begin(), objects.end(), obj.first);
			if (found != objects.end())
			{
				objects.erase(found);
				delete obj.first;
			}
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

	return close;
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
		if (collisionObj == obj)
			continue;

		if (!collisionObj->collider.isTrigger && obj->collider.IsColliding(collisionObj->collider, obj->pos, collisionObj->pos))
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