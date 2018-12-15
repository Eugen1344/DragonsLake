#include "Object.h"

Object::Object(vec2 pos, Sprite* sprite) : pos(pos), sprite(sprite)
{
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