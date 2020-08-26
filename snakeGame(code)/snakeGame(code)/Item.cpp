#include "Item.h"
#include "Map.h"

void Item::Init(GLint x, GLint y)
{
	pos = { x ,y };
}

void Item::update()
{

}

void Item::draw()
{
	glColor3d(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(pos.x - 0.5, pos.y + 0.5);
	glVertex2d(pos.x - 0.5, pos.y - 0.5);
	glVertex2d(pos.x + 0.5, pos.y - 0.5);
	glVertex2d(pos.x + 0.5, pos.y + 0.5);
	glEnd();
}

void Item::Respawn()
{
	pos.x = rnd() % (column - 2)  + 1;
	pos.y = rnd() % (row - 2) + 1;
	std::cout << pos.x << "," << pos.y << std::endl;	
}
