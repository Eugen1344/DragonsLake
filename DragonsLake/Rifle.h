#pragma once
#include <deque>
#include "Bullet.h"

using namespace std;

class Rifle
{
private:
	deque<Bullet*> bullets;
	Sprite* bulletSprite;
public:
	int maxAmmo;
	int ammo;
	Rifle(int ammoCount, Sprite* bulletSprite);
	void Shoot(vec2 pos, vec2 direction);
};