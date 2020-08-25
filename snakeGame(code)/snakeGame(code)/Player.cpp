#include "Player.h"

void Player::Init(GLint x, GLint y)
{
	pos = { x, y };
	temp_pos = { x, y };
	Direction = { 1, 0 };
}

void Player::update()
{
	temp_pos = pos;
	pos.x += Direction.x;
	pos.y += Direction.y;
}

void Player::draw()
{
	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2d(pos.x - 0.5, pos.y + 0.5);
	glVertex2d(pos.x - 0.5, pos.y - 0.5);
	glVertex2d(pos.x + 0.5, pos.y - 0.5);
	glVertex2d(pos.x + 0.5, pos.y + 0.5);
	glEnd();
}

void Player::Input(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
	case 'Q':
		std::cout << "Input key q" << std::endl;
		break;
		//================================
	case 'a':
	case 'A':
		Direction = { -1, 0 };
		break;
	case 'd':
	case 'D':
		Direction = { 1, 0 };

		break;
	case 'w':
	case 'W':
		Direction = { 0, 1 };
		break;
	case 's':
	case 'S':
		Direction = { 0, -1 };
		break;
		//--------------------------------
	case 27:
		std::cout << "Input key Esc" << std::endl;
		exit(0);
		break;
	default:
		break;
	}
}
