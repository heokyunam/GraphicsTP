#include "Light.h"



Light::Light(GLenum index)
{
	this->index = index;
	glEnable(index);

	Ambient(0, 0, 0);
	Diffuse(1, 1, 1);
	Specular(1, 1, 1);
	Move(0, 0, 0);
}


Light::~Light()
{
}


void Light::Update()
{
	glLightfv(index, GL_POSITION, pos.vec);
	glLightfv(index, GL_AMBIENT, amb.vec);
	glLightfv(index, GL_DIFFUSE, diff.vec);
	glLightfv(index, GL_SPECULAR, spec.vec);
}

void Light::Move(float x, float y, float z)
{
	pos.Change(x, y, z, 1);
}

void Light::Ambient(float x, float y, float z)
{
	amb.Change(x, y, z, 1);
}

void Light::Diffuse(float x, float y, float z)
{
	diff.Change(x, y, z, 1);
}

void Light::Specular(float x, float y, float z)
{
	spec.Change(x, y, z, 1);
}