#include "DataBox.h"
#include "TextureLoader.h"
DataBox* instance = 0;

DataBox::DataBox()
{
}


DataBox::~DataBox()
{
}

void DataBox::Init()
{
	//texture loading
	TextureLoader* loader = TextureLoader::getInstance();
	//player texture named earth
	loader->AddTexture("textures/2k_earth_daymap.bmp", "earth");
	loader->AddTexture("textures/2k_sun.bmp", "sun");
	loader->AddTexture("textures/2k_mars.bmp", "mars");

	//model loading
	Sphere* s = new Sphere(2);//player sphere	
	s->InitTexture(loader->GetTextureByKey("earth"));
	models.insert(Pair(Model*)("player", s));

	s = new Sphere(0.5); //bullet sphere
	s->InitTexture(loader->GetTextureByKey("sun"));
	models.insert(Pair(Model*)("bullet", s));

	s = new Sphere(2);
	s->InitTexture(loader->GetTextureByKey("mars"));
	models.insert(Pair(Model*)("enemy", s));
}

Model* DataBox::getModel(String key)
{
	MapIterator(Model*) i = models.find(key);
	if (i == models.end()) return 0;
	return i->second;
}

DataBox* DataBox::getInstance()
{
	if (!instance)
	{
		instance = new DataBox();
		instance->Init();
	}
	return instance;
}