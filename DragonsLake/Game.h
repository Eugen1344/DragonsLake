#pragma once
#include "Framework.h"

class Game : public Framework
{
public:
	Game();
	void PreInit(int& width, int& height, bool& fullscreen) override;
	bool Init() override;
	void Close() override;
	bool Tick() override;
	void onMouseMove(int x, int y, int xrelative, int yrelative) override;
	void onMouseButtonClick(FRMouseButton button, bool isReleased) override;
	void onKeyPressed(FRKey k) override;
	void onKeyReleased(FRKey k) override;
};