#include "Bullet.h"
#include "DataBox.h"


Bullet::Bullet(GLfloat speed)
{
	this->speed = speed;
}

void Bullet::Init(GameObject* obj)
{
	pos = obj->GetPos();
	pos.vec[1] += 1;
	InitModel(DataBox::getInstance()->getModel("bullet"));
}

Bullet::~Bullet()
{
}

bool Bullet::Update()
{
	pos.vec[2] += this->speed;
	if (pos.vec[2] > 200) 
		return false;
	if (pos.vec[2] < -10) 
		return false;
	if (needDie)
		return false;
	return GameObject::Update();
}