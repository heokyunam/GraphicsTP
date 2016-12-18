#include "Model.h"

void Model::SetMaterial(float ar, float ag, float ab,
	float dr, float dg, float db, float sr, float sg, float sb)
{
	mat->Ambient(ar, ag, ab);
	mat->Diffuse(dr, dg, db);
	mat->Specular(sr, sg, sb);
}

Sphere::Sphere(GLdouble radius)
{
	this->radius = radius;
	this->texIndex = 0;

	this->qObj = gluNewQuadric();
	gluQuadricNormals(qObj, GLU_SMOOTH);
	gluQuadricTexture(qObj, GL_TRUE);

	glEnable(GL_DEPTH_TEST);
}

void Sphere::Draw(Material* mat)
{
	if (!mat) mat = this->mat;
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