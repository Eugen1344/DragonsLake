#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player(vec2 pos, Sprite* sprite);
	void Tick() override;
};