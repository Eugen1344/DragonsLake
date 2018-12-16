#pragma once
#include "Object.h"
#include "Rifle.h"

class Player : public Object
{
private:
	vec2 movement;
public:
	double speed;
	Rifle rifle;
	Player(vec2 pos, Sprite* sprite);
	void Tick() override;
	void onKeyPressed(FRKey k) override;
	void onKeyReleased(FRKey k) override;
	void onMouseButtonClick(FRMouseButton button, bool isReleased) override;
	void onCollisionStay(Object& obj) override;
};