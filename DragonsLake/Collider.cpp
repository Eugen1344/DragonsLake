#include "Collider.h"
#include "Framework.h"
#include "Camera.h"

Collider::Collider()
{
	active = false;
}

Collider::Collider(vec2 pos, vec2 size) : pos(pos), size(size)
{
	active = true;
}

bool Collider::IsColliding(const Collider& collider, vec2 base, vec2 baseTarget) const
{
	if (!active || !collider.active)
		return false;

	vec2 pos1 = pos + base;
	vec2 pos2 = collider.pos + baseTarget;

	//drawSprite(createSprite("reticle.png"), pos1.x - Camera::pos.x, pos1.y - Camera::pos.y);
	//drawSprite(createSprite("reticle.png"), pos2.x - Camera::pos.x, pos2.y - Camera::pos.y);

	return !(pos1.x + size.x < pos2.x || pos2.x + collider.size.x < pos1.x) &&
		!(pos1.y + size.y < pos2.y || pos2.y + collider.size.y < pos1.y);
}