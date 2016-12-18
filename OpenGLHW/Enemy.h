#pragma once
#include "GameObject.h"
#include "StdAfx.h"
#include "Bullet.h"

#define DAMAGE_MAX_COUNT 15
#define DEFAULT_HP 3

class Enemy : public GameObject
{
private:
	SVector<Bullet*>* bullets;
	int damageCount;
	int hp;
	GLfloat speed;
public:
	Enemy(GLfloat speed);
	~Enemy();
	void Init(SVector<Bullet*>* bullets);
	bool Update();
	void Draw();
};

