#pragma once
#include "StdAfx.h"
#include "Model.h"
class DataBox
{
private:
	Map(Model*) models;
	//해쉬 맵을 만들어서
	//모델들을 저장할 것임
public:
	DataBox();
	~DataBox();
	void Init();
	Model* getModel(String key);
	static DataBox* getInstance();
};

