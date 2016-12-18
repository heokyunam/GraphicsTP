#pragma once
//#include <GLAux.h>
#include "bmp.h"
#include <map>
#include "StdAfx.h"

class TextureLoader
{
private:
	AUX_RGBImageRec** texs;
	Map(uint) table;
	uint* ids;
	int size;
	int index;
public:
	TextureLoader();
	~TextureLoader();
	void Init(int size);
	uint AddTexture(char* name, char* key = 0);
	//�ش� �ؽ��İ� ���� ��� 0�� ��ȯ
	uint GetTextureByKey(char* key);
	static TextureLoader* getInstance();
};

