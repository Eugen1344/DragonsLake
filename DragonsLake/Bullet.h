#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet(vec2 pos, Sprite* sprite);
	void Tick() override;
};