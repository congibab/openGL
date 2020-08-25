#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#include "Game.h"

using namespace std;

Game game;

void init();
void TimerFunc(int value);
void updateFunce(int value);
void reshapeFunc(GLint w, GLint h);
void displayFunc();
void keyboardFunc(unsigned char key, int x, int y);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(1200, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Snake Game");
	init();
	glutDisplayFunc(displayFunc);
	glutKeyboardFunc(keyboardFunc);
	glutReshapeFunc(reshapeFunc);
	glutTimerFunc(1000/30, TimerFunc, 0);
	glutTimerFunc(1000/10, updateFunce, 0);

	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0);	
	game.Init();
}

void TimerFunc(int value)
{
	glutPostRedisplay();
	glutTimerFunc(1000/30, TimerFunc, 0);
}

void updateFunce(int value)
{
	game.update();
	glutTimerFunc(1000/10, updateFunce, 0);
}

void reshapeFunc(GLint w, GLint h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, w / 25, 0.0, h / 25, -1.0, 1.0);

	cout << "width:" << w << " height:" << h << endl;
}

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//glPushMatrix();
	//glTranslatef(0.3f, 0.3f, 0.0f);
	game.draw();

	//glPopMatrix();
	glFinish();
}

void keyboardFunc(unsigned char key, int x, int y)
{
	game.Input(key, x, y);
	glutPostRedisplay();
}