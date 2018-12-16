#include "Object.h"

Object::Object(vec2 pos, Sprite* sprite) : pos(pos), sprite(sprite)
{
	int w, h;
	getSpriteSize(sprite, w, h);
	collider.size = vec2(w, h);
	collider.active = true;
}

Object::~Object()
{
}

void Object::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
}

void Object::onKeyPressed(FRKey k)
{
}

void Object::onKeyReleased(FRKey k)
{
}

void Object::onCollisionStay(Object& obj)
{
}