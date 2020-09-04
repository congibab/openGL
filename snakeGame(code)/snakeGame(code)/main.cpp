#include "Game.h"

using namespace std;

Game game;

void init();
void TimerFunc(int value);
void updateFunce(int value);
void reshapeFunc(GLint w, GLint h);
void displayFunc();
void keyboardFunc(unsigned char key, int x, int y);

static void DrawString(string str, int w, int h, int x0, int y0)
{
	glDisable(GL_LIGHTING);
	// 平行投影にする
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// 画面上にテキスト描画
	glRasterPos2f(x0, y0);
	int size = (int)str.size();
	for (int i = 0; i < size; ++i) {
		char ic = str[i];
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ic);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(1200, 100);
	glutInitWindowSize(700, 700);
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
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, w , 0.0, h , -1.0, 1.0);


	cout << "width:" << w << " height:" << h << endl;
}

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(100.0f, 0.0f, 0.0f);
	glScalef(20, 20, 20);
	game.draw();
	glPopMatrix();
	glFinish();

	glColor3d(1, 0.5, 1);
	glRasterPos2d(10, 10);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char*>("HELLO"));
	glutSwapBuffers();

}

void keyboardFunc(unsigned char key, int x, int y)
{
	game.Input(key, x, y);
	glutPostRedisplay();
}