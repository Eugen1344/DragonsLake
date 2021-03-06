#include "Player.h"
#include "Game.h"
#include "Camera.h"
#include <iostream>

Player::Player(vec2 pos, Sprite* sprite) : Object(pos, sprite), speed(300), rifle(Game::GetSettings().ammoCount, createSprite("bullet.png"))
{
	collider.isTrigger = true;
}

void Player::Tick()
{
	vec2 move = movement.normalized() * (Game::DeltaTime() * speed);
	pos += move;
	Camera::pos += move;
}

void Player::onKeyPressed(FRKey k)
{
	switch (k)
	{
	case FRKey::RIGHT:
		movement.x = 1;
		break;
	case FRKey::LEFT:
		movement.x = -1;
		break;
	case FRKey::DOWN:
		movement.y = 1;
		break;
	case FRKey::UP:
		movement.y = -1;
		break;
	default:;
	}
}

void Player::onKeyReleased(FRKey k)
{
	switch (k)
	{
	case FRKey::RIGHT:
		movement.x = 0;
		break;
	case FRKey::LEFT:
		movement.x = 0;
		break;
	case FRKey::DOWN:
		movement.y = 0;
		break;
	case FRKey::UP:
		movement.y = 0;
		break;
	default:;
	}
}

void Player::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	if (button != FRMouseButton::LEFT || isReleased) return;

	vec2 direction = Game::MouseWorldPos() - pos;
	if (direction.x != 0 || direction.y != 0)
		rifle.Shoot(pos, direction);
}

void Player::onCollisionStay(Object& obj)
{
}