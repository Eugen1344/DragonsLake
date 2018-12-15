#include "Rifle.h"
#include "Game.h"

Rifle::Rifle(int ammoCount, Sprite* bulletSprite) : maxAmmo(ammoCount), ammo(ammoCount), bulletSprite(bulletSprite)
{
}

void Rifle::Shoot(vec2 pos, vec2 direction)
{
	if (ammo == 0)
	{
		Game::DeleteObject(bullets[0]);
		bullets.pop_front();
		ammo = 1;
	}

	Bullet* bullet = new Bullet(pos, direction, bulletSprite);
	Game::AddObject(bullet);
	bullets.push_back(bullet);
	ammo--;
}