#pragma once

#include <gl/glut.h>
#include <math.h>
typedef struct Vector
{
	GLfloat vec[4];
	void Change(float v1, float v2, float v3, float v4)
	{
		vec[0] = v1;
		vec[1] = v2;
		vec[2] = v3;
		vec[3] = v4;
	}
	void Translate()
	{
		glTranslatef(vec[0], vec[1], vec[2]);
	}
	void Rotate()
	{
		glRotatef(vec[0], vec[1], vec[2], vec[3]);
	}
	float GetDistance(Vector v)
	{
		float d1 = vec[0] - v.vec[0];
		float d2 = vec[1] - v.vec[1];
		float d3 = vec[2] - v.vec[2];
		return sqrt(d1 * d1 + d2 * d2 + d3 * d3);
	}
}Vector, *PVector;