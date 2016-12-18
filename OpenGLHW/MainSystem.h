#pragma once
#include <gl/glut.h>
#include <vector>
#include "Player.h"
#include "StdAfx.h"
#include "Bullet.h"
#include "Enemy.h"
class MainSystem
{
private:
	SVector<Enemy*> enemies;
	SVector<Bullet*> bullets;
	Player* player;
	Light* worldlight;
public:
	MainSystem();
	~MainSystem();
	void Init();
	void InitLight();
	void Display();
	void Input(uchar key, int x, int y);
	void InputSpecial(int key, int x, int y);
};

