#include "Material.h"



Material::Material()
{
	Ambient(0.2, 0.2, 0.2);
	Diffuse(0.5, 0.5, 0.5);
	Specular(0.5, 0.5, 0.5);
	Emission(0, 0, 0);
	Shininess(100);
}


Material::~Material()
{
}

void Material::Ambient(float x, float y, float z)
{
	amb.Change(x, y, z, 1);
}

void Material::Diffuse(float x, float y, float z)
{
	diff.Change(x, y, z, 1);
}

void Material::Specular(float x, float y, float z)
{
	spec.Change(x, y, z, 1);
}

void Material::Emission(float x, float y, float z)
{
	emis.Change(x, y, z, 1);
}

void Material::Shininess(float shininess)
{
	this->shininess = shininess;
}

void Material::Update()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, amb.vec);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diff.vec);
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec.vec);
	glMaterialfv(GL_FRONT, GL_EMISSION, emis.vec);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);


}