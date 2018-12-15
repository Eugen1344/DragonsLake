#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(vec2 pos, Sprite* sprite) : Object(pos, sprite)
{
	speed = 60 * (rand() % 10 + 1);
}

void Enemy::Tick()
{
	vec2 lookAt = (Game::GetPlayer().pos - pos).normalized();
	pos += lookAt * (Game::DeltaTime() * speed);
}