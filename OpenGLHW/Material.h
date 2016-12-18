#pragma once
#include "Vector.h"

class Material
{
private:
	Vector amb;
	Vector diff;
	Vector spec;
	Vector emis;
	GLfloat shininess;
public:
	Material();
	~Material();
	void Ambient(float x, float y, float z);
	void Diffuse(float x, float y, float z);
	void Specular(float x, float y, float z);
	void Emission(float x, float y, float z);
	void Shininess(float shininess);
	void Update();
};

