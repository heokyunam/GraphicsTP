#pragma once
#include "GameObject.h"
#include "StdAfx.h"
#include "Bullet.h"
#define BULLETMAXCOUNT 20
#define BULLETSPEED 0.1
class Light;
class Player : public GameObject
{
private:
	SVector<Bullet*>* bullets;
	Light* backLight;
	int bulletCount;
public:
	Player();
	~Player();
	void InitBullets(SVector<Bullet*>* bullets);
	void Input(char key);
	void InputSpecial(int key);
	bool Update();
};

