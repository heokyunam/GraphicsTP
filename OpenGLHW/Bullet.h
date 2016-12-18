#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
private:
	GLfloat speed;
	bool needDie;
public:
	Bullet(GLfloat speed);
	~Bullet();
	void Init(GameObject* obj);
	bool Update();
	void Kill() { needDie = true; }
};

