#pragma once
#include "vector2.h"
#include "Framework.h"

class Object
{
public:
	vec2 pos;
	Sprite* sprite;
	Object(vec2 pos, Sprite* sprite);
	virtual ~Object();
	virtual void Tick() = 0;
};