#pragma once
#include "vector2.h"

class Collider
{
public:
	vec2 pos;
	vec2 size;
	bool isActive;
	bool isTrigger;
	Collider();
	Collider(vec2 pos, vec2 size);
	bool IsColliding(const Collider& collider, vec2 base, vec2 baseTarget) const;
};