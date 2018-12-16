#include "Cursor.h"
#include "Game.h"

Cursor::Cursor(vec2 pos, Sprite* sprite) : Object(pos, sprite)
{
	isGui = true;
	collider.active = false;
}

void Cursor::Tick()
{
	pos = Game::MousePos();
}