#pragma once
#include "vector2.h"
#include "Framework.h"
#include "Collider.h"

class Object
{
public:
	vec2 pos;
	Sprite* sprite;
	Collider collider;
	bool isGui = false;
	Object(vec2 pos, Sprite* sprite);
	virtual ~Object();
	virtual void Tick() = 0;
	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);
	virtual void onKeyPressed(FRKey k);
	virtual void onKeyReleased(FRKey k);
	virtual void onCollisionStay(Object& obj);
};