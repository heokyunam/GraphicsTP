#pragma once
#include "Vector.h"
#include "Model.h"
class GameObject
{
protected:
	Vector pos, rot;
	Model* model;
public:
	GameObject();
	~GameObject();
	void InitModel(Model* model) {
		this->model = model;
	}
	void Move(float x, float y, float z);
	void Rotate(float angle, float x, float y, float z);
	virtual void Transformation();
	virtual void Draw();
	virtual bool Update();
	void SetMaterial(float ar, float ag, float ab,
		float dr, float dg, float db, float sr, float sg, float sb);
	Vector GetPos() { return pos; }
};

