#include "Player.h"
#include "Map.h"

#define right { 1, 0 }
#define left { -1, 0 }
#define up { 0, 1 }
#define down { 0, -1 }

bool Player::chack_Direction(Vector2D Dir)
{
	if (Dir.x == Direction.x || Dir.y == Direction.y) return false;
	
	return true;
}

void Player::collision()
{
	if (pos.x > column - 3 && Direction.x == 1) pos.x = 0;
	else if (pos.y > row - 3 && Direction.y == 1) pos.y = 0;
	else if (pos.x < 2 && Direction.x == -1) pos.x = column - 1;
	else if (pos.y < 2 && Direction.y == -1) pos.y = row - 1;
}

void Player::Init(GLint x, GLint y)
{
	pos = { x, y };
	v.push_back(pos);
	test.assign(50, pos);
	temp_pos = { x, y };
	Direction = right;
}

void Player::update()
{
	collision();
	temp_pos = pos;
	
/*	v.insert(v.begin(), v.back());
	v.pop_back();*/	

	v.insert(v.begin(), pos);
	v.pop_back();

	/*index++;
	index %= 50;
	test[index] = temp_pos;*/


	//
	pos.x += Direction.x;
	pos.y += Direction.y;
	//
	
	//for (int i = 0; i < v.size(); i++)
	//{
	//	//v[i] = temp_pos;
	//	//test[i] = temp_pos;
	//	std::cout << "(" << v[i].x << "," << v[i].y << ")";
	//}
	std::cout << std::endl;
	//std::cout << v.front().x << std::endl;
	//std::cout << v.back().x << std::endl;
	std::cout << v.size() << std::endl;


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

	for (int i = 0; i < v.size(); i++)
	{
		glColor3d(0.5, 0.0, 0.5);
		glBegin(GL_POLYGON);
		glVertex2d(v[i].x - 0.5, v[i].y + 0.5);
		glVertex2d(v[i].x - 0.5, v[i].y - 0.5);
		glVertex2d(v[i].x + 0.5, v[i].y - 0.5);
		glVertex2d(v[i].x + 0.5, v[i].y + 0.5);
		glEnd();
	}

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
		if(chack_Direction(right))	Direction = left;
		break;
	case 'd':
	case 'D':
		if (chack_Direction(left))	Direction = right;
		break;
	case 'w':
	case 'W':
		if (chack_Direction(down))	Direction = up;
		break;
	case 's':
	case 'S':
		if (chack_Direction(up))	Direction = down;
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

void Player::push_back()
{
	v.push_back(temp_pos);
	//std::cout << "v.size = " << v.size() << std::endl;
}
