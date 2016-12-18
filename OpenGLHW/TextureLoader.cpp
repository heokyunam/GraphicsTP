#include "TextureLoader.h"
#include <gl/glut.h>

TextureLoader* instance = NULL;

TextureLoader::TextureLoader()
{
	index = 0;
}


TextureLoader::~TextureLoader()
{
	for (int i = 0; i < index; i++)
	{
		delete texs[i];
	}
	delete ids;
	delete texs;
}

void TextureLoader::Init(int size)
{
	texs = new AUX_RGBImageRec*[size];
	ids = new uint[size];
	this->size = size;
	glGenTextures(size, ids);
}
TextureLoader* TextureLoader::getInstance()
{
	if (!instance)
	{
		instance = new TextureLoader();
		instance->Init(20);
	}
	return instance;
}

uint TextureLoader::GetTextureByKey(char* key)
{
	MapIterator(uint) i = table.find(key);
	if (i == table.end()) return 0;
	return i->second;
}

uint TextureLoader::AddTexture(char* name, char* key)
{
	texs[index] = auxDIBImageLoad(name);

	glBindTexture(GL_TEXTURE_2D, ids[index]);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texs[index]->sizeX, texs[index]->sizeY, 0, GL_RGB,
		GL_UNSIGNED_BYTE, texs[index]->data);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	if (key)
	{
		table.insert(Pair(uint)(key, ids[index]));
	}
	return ids[index++];
}