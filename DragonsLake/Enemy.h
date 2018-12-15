#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	Enemy(vec2 pos, Sprite* sprite);
	void Tick() override;
};