#include <stdio.h>
#include <gl/glut.h>
#include <math.h>
#include "Light.h"
#include "MainSystem.h"
#include <Windows.h>

void Display();
void Reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void keyboardSpecial(int key, int x, int y);

MainSystem* ms;
void main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutCreateWindow("window");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutIdleFunc(Display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	ms = new MainSystem();
	ms->Init();

	glutMainLoop();
}

void Display() {
	ms->Display();
	Sleep(1);
}

void keyboard(unsigned char key, int x, int y)
{
	ms->Input(key, x, y);
}

void keyboardSpecial(int key, int x, int y)
{
	ms->InputSpecial(key, x, y);
}

void Reshape(int w, int h) {
	float ratio = w / (float)h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 10, 100);
}

