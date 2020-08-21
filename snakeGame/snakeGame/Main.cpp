#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <FreeImage.h>
#include <iostream>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#include "TextureManager.h"
#include "Map.h"
#include "player.h"

using namespace std;

Vector2D _pos = {5, 5};
Vector2D _direction = { 1, 0 };

TextureManager texturemanager;
player Player;
Map stage;

//GLfloat camera_x = 0;
//GLfloat camera_y = 0;

GLuint textureid[10];


const GLfloat vertex[] = {
	0 , 0 , 
	0 , 10 , 
	10 , 10,
	10 , 0
};

const GLfloat tex[] =
{
	0, 0,
	0, 1,
	1, 1,
	1, 0
};

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	//glRotatef(0.1, 0.1, 0.1, 0);
	//glVertexPointer(2, GL_FLOAT, 0, vertex);
	//glTexCoordPointer(2, GL_FLOAT, 0, tex);

	//glEnable(GL_TEXTURE_2D);
	//glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	//glBindTexture(GL_TEXTURE_2D, textureid[0]);
	//glDrawArrays(GL_POLYGON, 0, 4);
	//
	//glDisableClientState(GL_VERTEX_ARRAY);
	//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	//glDisable(GL_TEXTURE_2D);

	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureid[0]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex2d(10, 10);
	glTexCoord2f(0, 1); glVertex2d(10, 20);
	glTexCoord2f(1, 1); glVertex2d(20, 20);
	glTexCoord2f(1, 0); glVertex2d(20, 10);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glEnd();*/

	glPushMatrix();
	glTranslatef(0.3f, 0.3f, 0.0f);
	
	stage.Draw_Grid();
	Player.draw();
	
	glPopMatrix();
}

void reshape(GLint w, GLint h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, w / 25, 0.0, h / 25, -1.0, 1.0);
	//glOrtho(-w / 50.0, w / 50.0, -h / 50.0, h / 50.0, -1.0, 1.0);

	cout << "width:" << w << " height:" << h << endl;

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
	case 'Q':
		cout << "Input key q" << endl;
		
		break;
	//================================
	case 'a':
	case 'A':
		//_pos.x -= 1.0f;
		_direction = {-1, 0};
		break;
	case 'd':
	case 'D':
		//_pos.x += 1.0f;
		_direction = { 1, 0 };
		break;
	case 'w':
	case 'W':
		//_pos.y += 1.0f;
		_direction = { 0, 1 };
		break;
	case 's':
	case 'S':
		_pos.y -= 1.0f;
		_direction = { 0, -1 };
		break;
	//--------------------------------
	case 27:
		cout << "Input key Esc" << endl;
		exit(0);
		break;
	default:
		break;
	}
	Player.Setvector2D(_pos);
	Player.SetDirection(_direction);
	glutPostRedisplay();
}

/// <summary>
/// 
/// </summary>
void Idle()
{
	//glutPostRedisplay();
}

void Timer(int value)
{
	//cout << "test" << endl;
	_pos.x += _direction.x;
	_pos.y += _direction.y;
	Player.Setvector2D(_pos);
	
	glutPostRedisplay();
	glutTimerFunc(100, Timer, 0);
}

void init()
{
	Player.Init(_pos.x, _pos.y);
	stage.Init();

	glClearColor(0.0, 0.0, 0.0, 0);
	textureid[0] = texturemanager.CreateTexture("larst.png");
	textureid[1] = texturemanager.CreateTexture("maitetsu.jpg");
	textureid[2] = texturemanager.LoadGLTextures("opengl.jpg");
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(1200, 100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Snake Game");
	init();

	glutDisplayFunc(display);
	glutIdleFunc(Idle);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutTimerFunc(100, Timer, 0);
	
	glutMainLoop();

	return 0;
}
