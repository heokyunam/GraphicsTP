#pragma once
#include "StdAfx.h"
#include "Model.h"
class DataBox
{
private:
	Map(Model*) models;
	//�ؽ� ���� ����
	//�𵨵��� ������ ����
public:
	DataBox();
	~DataBox();
	void Init();
	Model* getModel(String key);
	static DataBox* getInstance();
};

