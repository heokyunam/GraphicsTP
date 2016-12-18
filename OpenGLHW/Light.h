#pragma once
#include <gl/glut.h>
#include "Vector.h"

class Light
{
private:
	Vector amb;
	Vector diff;
	Vector spec;
	Vector pos;
	GLenum index;
public:
	Light(GLenum index);
	~Light();
	void Move(float x, float y, float z);
	void Ambient(float x, float y, float z);
	void Diffuse(float x, float y, float z);
	void Specular(float x, float y, float z);
	void Update();
};

