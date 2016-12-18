#include "ParentPlanet.h"



ParentPlanet::ParentPlanet(GLdouble radius, GLfloat rotateSpeed)
	: Planet(radius, rotateSpeed)
{
	rotationX = 0;
	extra = 0;
}


ParentPlanet::~ParentPlanet()
{
}

/*
1. 공전축 회전
2. 공전각도회전
3. 행성좌표이동
4. 위성render
5. 자전축회전
6. 행성출력
*/
void ParentPlanet::Update()
{
	glPushMatrix();
	Transformation();
	Draw();
	if (extra)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, extraTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		gluQuadricTexture(qObj, true);

		glRotatef(rotationX, 1, 0, 0);
		gluDisk(extra, 0.5, 1.0, 20, 20);

		glDisable(GL_TEXTURE_2D);
	}
	for (int i = 0; i < childs.size(); i++)
	{
		childs[i]->Update();
	}
	glPopMatrix();
}

void ParentPlanet::SetExtra(uint extraTexture)
{
	this->extraTexture = extraTexture;
	extra = gluNewQuadric();
	gluQuadricNormals(extra, GLU_SMOOTH);
	gluQuadricTexture(extra, GL_TRUE);
}

void ParentPlanet::AddChild(Planet* p)
{
	childs.push_back(p);
}