#pragma once
#include <vector>
#include "Framework.h"
#include "Object.h"
#include <map>
#include "Settings.h"

using namespace std;

class Engine : public Framework
{
private:
	vector<Object*> objects;
	map<Object*, bool> objectChanges;
	bool restart = false;
public:
	bool close = false;
	double deltaTime;
	double prevTickCount;
	Engine(Settings& settings);
	void AddObject(Object* obj);
	void DeleteObject(Object* obj);
	void PreInit(int& width, int& height, bool& fullscreen) override;
	bool Init() override;
	void Restart();
	void ReinitGame();
	void Close() override;
	bool Tick() override;
	void DetectCollisions();
	bool IsColliding(Object* obj);
	void onMouseMove(int x, int y, int xrelative, int yrelative) override;
	void onMouseButtonClick(FRMouseButton button, bool isReleased) override;
	void onKeyPressed(FRKey k) override;
	void onKeyReleased(FRKey k) override;
};