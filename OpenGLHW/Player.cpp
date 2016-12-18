#include "Player.h"
#include "TextureLoader.h"
#include "Light.h"

Player::Player()
{
	this->bullets = 0;
	Move(0, 0, 15);
	backLight = new Light(GL_LIGHT0);
	backLight->Ambient(1, 1, 1);
	bulletCount = BULLETMAXCOUNT;
}


Player::~Player()
{
}

void Player::InitBullets(SVector<Bullet*>* bullets)
{
	this->bullets = bullets;
}

void Player::Input(char key)
{
	switch (key)
	{
	case 'W':
	case 'w':
		pos.vec[1] += 1;
		break;
	case 'A':
	case 'a':
		pos.vec[0] += 1;
		break;
	case 'S':
	case 's':
		pos.vec[1] -= 1;
		break;
	case 'D':
	case 'd':
		pos.vec[0] -= 1;
		break;
	case 32:
		if (bullets && bulletCount >= BULLETMAXCOUNT)
		{
			Bullet* b = new Bullet(BULLETSPEED);
			b->Init(this);
			bullets->push_back(b);
			bulletCount = 0;
		}
		break;
	}
}

void Player::InputSpecial(int key)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		pos.vec[2] += 1;
		break;
	case GLUT_KEY_DOWN:
		pos.vec[2] -= 1;
		break;
	case GLUT_KEY_RIGHT:
		pos.vec[0] -= 1;
		break;
	case GLUT_KEY_LEFT:
		pos.vec[0] += 1;
		break;
	}
}

bool Player::Update()
{
	if (bulletCount < BULLETMAXCOUNT)
		bulletCount++;
	// 0 -3 11
	backLight->Move(pos.vec[0], pos.vec[1] + 2.5, pos.vec[2] + 2.5);
	backLight->Update();
	gluLookAt(pos.vec[0], pos.vec[1] + 3, pos.vec[2] - 13, 
		pos.vec[0], pos.vec[1] + 3, pos.vec[2] - 11,
		0, 1, 0);

	return GameObject::Update();
}