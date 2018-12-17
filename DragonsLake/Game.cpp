#include <cstdlib>
#include "Game.h"
#include "Camera.h"
#include "Enemy.h"
#include "Cursor.h"

Engine* Game::engine;
Player* Game::player;
vec2 Game::mousePos;
Settings Game::settings;

Settings Game::GetSettings()
{
	return settings;
}

void Game::SetSettings(Settings& settings)
{
	Game::settings = settings;
}

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

bool Game::IsColliding(Object* obj)
{
	return engine->IsColliding(obj);
}

void Game::RestartGame()
{
	engine->Restart();
}

void Game::InitScene()
{
	AddObject(new Cursor(vec2(), createSprite("reticle.png")));

	Sprite* playerSprite = createSprite("avatar.jpg");
	vector2<int> spriteSize;
	getSpriteSize(playerSprite, spriteSize.x, spriteSize.y);

	Player* player = new Player(static_cast<vector2<double>>((settings.screenResolution - spriteSize) / 2), playerSprite);
	AddObject(player);
	Game::player = player;

	Sprite* enemySprite = createSprite("enemy.png");
	SpawnEnemies(settings.enemiesCount, enemySprite);
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

			pos = vec2(rand() % (settings.mapSize.x + 1), rand() % (settings.mapSize.y + 1));
			/*for (Enemy* enemy : enemies)
			{
				if (pos.distance(enemy->pos) < (enemy->collider.size).length())
					intersecting = true;

			}*/
			if (pos.distance(GetPlayer().pos) < 500)
				intersecting = true;
		} while (intersecting);

		Enemy* enemy = new Enemy(pos, sprite);
		AddObject(enemy);
		enemies.push_back(enemy);
	}
}