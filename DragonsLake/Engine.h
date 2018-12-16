#pragma once
#include <vector>
#include "Framework.h"
#include "Object.h"
#include <map>

using namespace std;

class Engine : public Framework
{
private:
	vector<Object*> objects;
	map<Object*, bool> objectChanges;
public:
	bool restart = false;
	bool close = false;
	double deltaTime;
	double prevTickCount;
	Engine();
	void AddObject(Object* obj);
	void DeleteObject(Object* obj);
	void PreInit(int& width, int& height, bool& fullscreen) override;
	bool Init() override;
	void Close() override;
	bool Tick() override;
	void DetectCollisions();
	bool IsColliding(Object* obj);
	void onMouseMove(int x, int y, int xrelative, int yrelative) override;
	void onMouseButtonClick(FRMouseButton button, bool isReleased) override;
	void onKeyPressed(FRKey k) override;
	void onKeyReleased(FRKey k) override;
};