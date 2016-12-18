#include "GameObject.h"



GameObject::GameObject()
{
	model = 0;
}


GameObject::~GameObject()
{
}

void GameObject::Move(float x, float y, float z)
{
	pos.Change(x, y, z, 0);
}

void GameObject::Rotate(float angle, float x, float y, float z)
{
	rot.Change(angle, x, y, z);
}

void GameObject::Transformation()
{
	rot.Rotate();
	pos.Translate();
}

void GameObject::Draw()
{
	if(model) model->Draw();
}

bool GameObject::Update()
{
	glPushMatrix();
	Transformation();
	Draw();
	glPopMatrix();
	return true;
}

void GameObject::SetMaterial(float ar, float ag, float ab,
	float dr, float dg, float db, float sr, float sg, float sb)
{
	if(model) model->SetMaterial(ar, ag, ab, dr, dg, db, sr, sg, sb);
}