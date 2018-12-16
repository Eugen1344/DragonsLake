#include "Game.h"
#include "Camera.h"
#include "Enemy.h"

Engine* Game::engine;
vector2<int> Game::screenResolution;
Player* Game::player;
vec2 Game::mousePos;
int Game::enemiesCount = 5;
int Game::ammoCount = 3;
vector2<int> Game::mapSize = vector2<int>(1000, 1000);

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

void Game::RestartGame()
{
	engine->restart = true;
}

void Game::SpawnEnemies(int count, Sprite* sprite)
{
	vector<Enemy*> enemies;

	for (int i = 0; i < count; i++)
	{
		vec2 pos;
		bool intersecting;
		do
		{
			intersecting = false;

			pos = vec2(rand() % (mapSize.x + 1), rand() % (mapSize.y + 1));
			for (Enemy* enemy : enemies)
			{
				if (pos.distance(enemy->pos) < (enemy->collider.size * 2).length())
					intersecting = true;

			}
			if (pos.distance(GetPlayer().pos) < 500)
				intersecting = true;
		} while (intersecting);

		Enemy* enemy = new Enemy(pos, sprite);
		AddObject(enemy);
		enemies.push_back(enemy);
	}
}