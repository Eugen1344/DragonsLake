#pragma once
#include "vector2.h"

class Settings
{
public:
	vector2<int> screenResolution;
	vector2<int> mapSize;
	int enemiesCount;
	int ammoCount;
	Settings();
};