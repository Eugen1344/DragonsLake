#include "Bullet.h"
#include "Game.h"
#include "Enemy.h"

Bullet::Bullet(vec2 pos, vec2 direction, Sprite* sprite) : Object(pos, sprite), direction(direction)
{

}

void Bullet::Tick()
{
	pos += direction.normalized() * (Game::DeltaTime() * speed);
}

void Bullet::onCollisionStay(Object& obj)
{
	if (dynamic_cast<Enemy*>(&obj))
	{
		Game::DeleteObject(&obj);
		Game::DeleteObject(this);
	}
}