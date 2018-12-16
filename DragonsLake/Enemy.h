#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	double speed;
	Enemy(vec2 pos, Sprite* sprite);
	void Tick() override;
	void onCollisionStay(Object& obj) override;
};