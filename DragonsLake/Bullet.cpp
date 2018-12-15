#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(vec2 pos, vec2 direction, Sprite* sprite) : Object(pos, sprite), direction(direction)
{

}

void Bullet::Tick()
{
	pos += direction.normalized() * (Game::DeltaTime() * speed);
}