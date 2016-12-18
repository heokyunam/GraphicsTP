#include "Planet.h"



Planet::Planet(GLdouble radius, GLfloat rotateSpeed)
{
	this->radius = radius;
	this->rotateSpeed = rotateSpeed;
	this->texIndex = 0;

	mat = new Material();
	pos.Change(0, 0, 0, 1);

	qObj = gluNewQuadric();
	gluQuadricNormals(qObj, GLU_SMOOTH);
	gluQuadricTexture(qObj, GL_TRUE);
	
	glEnable(GL_DEPTH_TEST);
}


Planet::~Planet()
{
}

void Planet::InitTexture(uint texture)
{
	this->texIndex = texture;
}

void Planet::Move(float x, float y, float z)
{
	pos.Change(x, y, z, 0);
}

void Planet::Rotate(float angle, float x, float y, float z)
{
	rot.Change(angle, x, y, z);
}

void Planet::Transformation()
{
	rot.Rotate();
	pos.Translate();
}

void Planet::Draw()
{
	mat->Update();
	if (texIndex > 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texIndex);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		gluQuadricTexture(qObj, true);
	}

	gluSphere(qObj, radius, 100, 100);
	if (texIndex > 0)
	{
		glDisable(GL_TEXTURE_2D);
	}
}

void Planet::Update()
{
	glPushMatrix();
	Transformation();
	Draw();
	glPopMatrix();
}


void Planet::SetMaterial(float ar, float ag, float ab,
	float dr, float dg, float db, float sr, float sg, float sb)
{
	mat->Ambient(1, 1, 1);
	mat->Diffuse(0, 0, 0);
	mat->Specular(0, 0, 0);
}