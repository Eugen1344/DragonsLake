#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	double speed = 500;
	vec2 direction;
	Bullet(vec2 pos, vec2 direction, Sprite* sprite);
	void Tick() override;
	void onCollisionStay(Object& obj) override;
};