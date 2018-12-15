#pragma once
#include "Object.h"

class Cursor : public Object
{
public:
	Cursor(vec2 pos, Sprite* sprite);
	void Tick() override;
};