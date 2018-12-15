#pragma once
#include "vector2.h"
#include "Framework.h"

class Object
{
public:
	vec2 pos;
	Sprite* sprite;
	bool isGui = false;
	Object(vec2 pos, Sprite* sprite);
	virtual ~Object();
	virtual void Tick() = 0;
	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);
	virtual void onKeyPressed(FRKey k);
	virtual void onKeyReleased(FRKey k);
};