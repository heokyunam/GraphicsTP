#include "Enemy.h"
#include "DataBox.h"


Enemy::Enemy(GLfloat speed)
{
	bullets = 0;
	this->speed = speed;
	damageCount = DAMAGE_MAX_COUNT;
	hp = DEFAULT_HP;
}


Enemy::~Enemy()
{
}

void Enemy::Init(SVector<Bullet*>* bullets)
{
	InitModel(DataBox::getInstance()->getModel("enemy"));
	this->bullets = bullets;
}

bool Enemy::Update()
{
	for (int i = 0; i < bullets->size(); i++)
	{
		Bullet* b = Indexing(bullets, i);
		float dist = pos.GetDistance(b->GetPos());
		if (dist < 2)
		{
			damageCount = 0;
			hp--;
			b->Kill();
			if (hp < 0) return false;
		}
	}
	pos.vec[2] -= speed;
	return GameObject::Update();
}

void Enemy::Draw()
{
	if (damageCount < DAMAGE_MAX_COUNT)
	{
		damageCount++;
		model->SetMaterial(1, 0, 0, 1, 0, 0, 1, 0, 0);
	}
	else
	{
		model->SetMaterial(1, 1, 1, 1, 1, 1, 1, 1, 1);
	}
	GameObject::Draw();
}