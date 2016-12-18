#pragma once
#include "Material.h"

typedef unsigned int uint;

class Model
{
protected:
	Material* mat;
public:
	Model() { mat = new Material(); }
	~Model() { delete mat; }
	virtual void Draw(Material* mat = 0) {}
	void SetMaterial(float ar, float ag, float ab,
		float dr, float dg, float db, float sr, float sg, float sb);
};

class Sphere : public Model
{
private:
	GLdouble radius;
	uint texIndex;
	GLUquadric* qObj;
public:
	Sphere(GLdouble radius);
	~Sphere() { delete qObj; }
	void InitTexture(uint texture) { this->texIndex = texture; }
	//default로 객체 못넣으니 null넣고 null이면 내부의 머티리얼을 사용하게 함
	void Draw(Material* mat = 0);
};
