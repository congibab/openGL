#include "player.h"

void player::Setvector2D(Vector2D pos)
{
	vector2D = pos;
}

void player::SetDirection(Vector2D dir)
{
	Direction = dir;
}

Vector2D player::Getvector2D()
{
	return vector2D;
}

void player::Init(GLint x, GLint y)
{
	vector2D = { x, y };
	Direction = {1, 0};
}

void player::draw()
{

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2d(vector2D.x - 0.5, vector2D.y + 0.5);
	glVertex2d(vector2D.x - 0.5, vector2D.y - 0.5);
	glVertex2d(vector2D.x + 0.5, vector2D.y - 0.5);
	glVertex2d(vector2D.x + 0.5, vector2D.y + 0.5);
	glEnd();
	glFinish();
}

