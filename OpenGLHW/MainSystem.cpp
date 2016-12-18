#include "MainSystem.h"
#include "Light.h"
#include "TextureLoader.h"
#include "DataBox.h"
MainSystem::MainSystem()
{
}


MainSystem::~MainSystem()
{

}

void MainSystem::Input(uchar key, int x, int y)
{
	player->Input(key);
}

void MainSystem::InputSpecial(int key, int x, int y)
{
	player->InputSpecial(key);
}

void MainSystem::Init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LESS);

	InitLight();
	TextureLoader* loader = TextureLoader::getInstance();
	DataBox* box = DataBox::getInstance();

	player = new Player();
	player->InitModel(box->getModel("player"));
	player->InitBullets(&bullets);

	for (int i = 0; i < 10; i++)
	{
		Enemy* e = new Enemy(0.1);
		e->Init(&bullets);
		e->Move(0, 0, i * 100 + 100);
		enemies.push_back(e);
	}
}

void MainSystem::InitLight()
{
	glEnable(GL_LIGHTING);

	worldlight = new Light(GL_LIGHT1);

	worldlight->Ambient(0.2, 0.2, 0.2);
	worldlight->Diffuse(0.4, 0.4, 0.4);
	worldlight->Specular(0.4, 0.4, 0.4);
	worldlight->Move(100, 100, 100);
}

void MainSystem::Display()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	player->Update();

	worldlight->Update();

	//update and kill enemies
	UPDATE_LOOP(Enemy*, enemies);
	//update and kill bullets
	UPDATE_LOOP(Bullet*, bullets);

	glPushMatrix();
	glPopMatrix();
	glFlush();
}

