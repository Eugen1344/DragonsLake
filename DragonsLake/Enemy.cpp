#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(vec2 pos, Sprite* sprite) : Object(pos, sprite)
{

}

void Enemy::Tick()
{
	pos.x += Game::DeltaTime() * 60 * (rand() % 10 + 1);
}