#include <cstdlib>
#include <iostream>
#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(vec2 pos, Sprite* sprite) : Object(pos, sprite)
{
	collider.isTrigger = false;
	speed = 30 * (rand() % 10 + 1);
}

void Enemy::Tick()
{
	vec2 lookAt = (Game::GetPlayer().pos - pos).normalized();

	vec2 prevPos = pos;
	pos += lookAt * (Game::DeltaTime() * speed);

	if (Game::IsColliding(this)) //TODO rewrite hard collisions, delete IsColliding function
	{
		pos = prevPos;
	}
}

void Enemy::onCollisionStay(Object& obj)
{
	if (dynamic_cast<Player*>(&obj))
	{
		cout << "You lose!" << endl;
		Game::RestartGame();
	}
}